#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QKeyEvent>

#include "AppConfig.h"
#include "PS2VM_Preferences.h"
#include "StatsManager.h"
#include "PH_HidUnix.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    WId getOpenGLPanel();
    void setOpenGlPanelSize();
    void createStatusBar();
    void initEmu();
    void SetupSoundHandler();
    void Setupfpscounter();
    void createOpenGlPanel();

    QWindow* openglpanel;

    QLabel* fpsLabel;
    QLabel* dcLabel;
    CStatsManager* StatsManager;
    CPH_HidUnix* padhandler = nullptr;

public slots:
    void openGLWindow_resized();
    void setFPS();

private slots:
    void on_actionOpen_Game_triggered();

    void on_actionStart_Game_triggered();

    void on_actionBoot_ELF_triggered();

    void on_actionExit_triggered();
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    void on_actionSettings_triggered();
protected:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
