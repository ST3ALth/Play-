#include "mainwindow.h"
#include "settingsdialog.h"

#include "openglwindow.h"

#include <QFileDialog>
#include <QTimer>
#include <QWindow>

#include "global.h"
#include "GSH_OpenGLQt.h"
#include "tools/PsfPlayer/Source/SH_OpenAL.h"

#include "ui_mainwindow.h"

#define PREFERENCE_UI_SHOWFPS "ui.showfps"
#define PREFERENCE_UI_SHOWVIRTUALPAD "ui.showvirtualpad"
#define PREFERENCE_AUDIO_ENABLEOUTPUT "audio.enableoutput"
#define PREF_CGSH_OPENGL_ENABLEHIGHRESMODE        "renderer.opengl.enablehighresmode"
#define PREF_CGSH_OPENGL_FORCEBILINEARTEXTURES    "renderer.opengl.forcebilineartextures"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createOpenGlPanel()
{
    QSurfaceFormat format;
    format.setVersion(3, 2);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);

    openglpanel = new OpenGLWindow;
    openglpanel->show();
    QWidget * newo = QWidget::createWindowContainer(openglpanel);
    ui->gridLayout->addWidget(newo);
    connect(openglpanel, SIGNAL(heightChanged(int)), this, SLOT(openGLWindow_resized()));
    connect(openglpanel, SIGNAL(widthChanged(int)), this, SLOT(openGLWindow_resized()));

    connect(openglpanel, SIGNAL(keyUp(QKeyEvent*)), this, SLOT(keyReleaseEvent(QKeyEvent*)));
    connect(openglpanel, SIGNAL(keyDown(QKeyEvent*)), this, SLOT(keyPressEvent(QKeyEvent*)));
}

void MainWindow::initEmu(){
    g_virtualMachine = new CPS2VM();
    g_virtualMachine->Initialize();

    g_virtualMachine->CreateGSHandler(CGSH_OpenGLQt::GetFactoryFunction(openglpanel));
    SetupSoundHandler();

    g_virtualMachine->CreatePadHandler(CPH_HidUnix::GetFactoryFunction());
    padhandler = (CPH_HidUnix*)g_virtualMachine->GetPadHandler();

    StatsManager = new CStatsManager();
    g_virtualMachine->m_ee->m_gs->OnNewFrame.connect(boost::bind(&CStatsManager::OnNewFrame, StatsManager, _1));

    createStatusBar();

    fpstimer = new QTimer(this);
    connect(fpstimer, SIGNAL(timeout()), this, SLOT(setFPS()));

    Setupfpscounter();
}

void MainWindow::setOpenGlPanelSize()
{
    openGLWindow_resized();
}

void MainWindow::SetupSoundHandler()
{
    if(g_virtualMachine != nullptr){
        bool audioEnabled = CAppConfig::GetInstance().GetPreferenceBoolean(PREFERENCE_AUDIO_ENABLEOUTPUT);
        if(audioEnabled)
        {
            g_virtualMachine->CreateSoundHandler(&CSH_OpenAL::HandlerFactory);
        }
        else
        {
            g_virtualMachine->DestroySoundHandler();
        }
    }
}

void MainWindow::Setupfpscounter()
{
    if(g_virtualMachine != nullptr){
        bool fpsEnabled = CAppConfig::GetInstance().GetPreferenceBoolean(PREFERENCE_UI_SHOWFPS);
        if(fpsEnabled)
        {
            fpsLabel->show();
            dcLabel->show();
            fpstimer->stop();
            fpstimer->start(1000);
        }
        else
        {
            fpstimer->stop();
            fpsLabel->hide();
            dcLabel->hide();
        }
    }
}

void MainWindow::openGLWindow_resized()
{
    if (g_virtualMachine != nullptr && g_virtualMachine->m_ee != nullptr  && g_virtualMachine->m_ee->m_gs != nullptr )
        {

            GLint w = openglpanel->size().width(), h = openglpanel->size().height();

            CGSHandler::PRESENTATION_PARAMS presentationParams;
            presentationParams.mode 			= (CGSHandler::PRESENTATION_MODE)CAppConfig::GetInstance().GetPreferenceInteger(PREF_CGSHANDLER_PRESENTATION_MODE);
            presentationParams.windowWidth 		= w;
            presentationParams.windowHeight 	= h;
            g_virtualMachine->m_ee->m_gs->SetPresentationParams(presentationParams);
            g_virtualMachine->m_ee->m_gs->Flip();
        }
}

void MainWindow::on_actionOpen_Game_triggered()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("ISO/CSO/ISZ files (*.iso *cso *.isz)"));
    QString fileName;
    if (dialog.exec())
    {
        fileName = dialog.selectedFiles().first();
        CAppConfig::GetInstance().SetPreferenceString(PS2VM_CDROM0PATH, fileName.toStdString().c_str());
    }
}

void MainWindow::on_actionStart_Game_triggered()
{

    if (g_virtualMachine != nullptr)
    {
        g_virtualMachine->Pause();
        g_virtualMachine->Reset();
        g_virtualMachine->m_ee->m_os->BootFromCDROM();
        g_virtualMachine->Resume();
        setOpenGlPanelSize();
    }
}

void MainWindow::on_actionBoot_ELF_triggered()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("ELF files (*.elf)"));
            QString fileName;
    if (dialog.exec())
    {
        fileName = dialog.selectedFiles().first();

        if (g_virtualMachine != nullptr)
        {
            g_virtualMachine->Pause();
            g_virtualMachine->Reset();
            g_virtualMachine->m_ee->m_os->BootFromFile(fileName.toStdString().c_str());
            g_virtualMachine->Resume();
            setOpenGlPanelSize();
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    if (g_virtualMachine != nullptr)
    {
        g_virtualMachine->Pause();
        g_virtualMachine->DestroySoundHandler();
    }
    exit(0);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (padhandler != nullptr)
            CPH_HidUnix::InputValueCallbackPressed(padhandler, event->key());
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (padhandler != nullptr)
            CPH_HidUnix::InputValueCallbackReleased(padhandler, event->key());
}

void MainWindow::createStatusBar()
{
    fpsLabel = new QLabel(" fps:00 ");
    fpsLabel->setAlignment(Qt::AlignHCenter);
    fpsLabel->setMinimumSize(fpsLabel->sizeHint());

    dcLabel = new QLabel(" dc:0000 ");
    dcLabel->setAlignment(Qt::AlignHCenter);
    dcLabel->setMinimumSize(dcLabel->sizeHint());

    statusBar()->addWidget(fpsLabel);
    statusBar()->addWidget(dcLabel);
}

void MainWindow::setFPS()
{
    int frames = StatsManager->GetFrames();
    int drawCalls = StatsManager->GetDrawCalls();
    int dcpf = (frames != 0) ? (drawCalls / frames) : 0;
    //fprintf(stderr, "%d f/s, %d dc/f\n", frames, dcpf);
    StatsManager->ClearStats();
    fpsLabel->setText(QString(" fps: %1 ").arg(frames));
    dcLabel->setText(QString(" dc: %1 ").arg(dcpf));
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsDialog sd;
    sd.exec();
    SetupSoundHandler();
    Setupfpscounter();
    CAppConfig::GetInstance().Save();
}
