#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#define PREFERENCE_UI_SHOWFPS "ui.showfps"
#define PREFERENCE_UI_SHOWVIRTUALPAD "ui.showvirtualpad"
#define PREFERENCE_AUDIO_ENABLEOUTPUT "audio.enableoutput"
#define PREF_CGSH_OPENGL_ENABLEHIGHRESMODE        "renderer.opengl.enablehighresmode"
#define PREF_CGSH_OPENGL_FORCEBILINEARTEXTURES    "renderer.opengl.forcebilineartextures"
#define PREF_CGSHANDLER_PRESENTATION_MODE		"renderer.presentationmode"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    //Not needed, as it can be set in the ui editor, but left for ease of ui edit.
    ui->stackedWidget->setCurrentIndex(0);

    RegisterPreferences();
    LoadPreferences();
    connect(ui->listWidget, &QListWidget::currentItemChanged, this, &SettingsDialog::changePage);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
        current = previous;

    ui->stackedWidget->setCurrentIndex(ui->listWidget->row(current));
}


void SettingsDialog::RegisterPreferences()
{
    CAppConfig::GetInstance().RegisterPreferenceBoolean(PREFERENCE_UI_SHOWFPS, true);
    CAppConfig::GetInstance().RegisterPreferenceBoolean(PREFERENCE_UI_SHOWVIRTUALPAD, false);
    CAppConfig::GetInstance().RegisterPreferenceBoolean(PREFERENCE_AUDIO_ENABLEOUTPUT, true);
}

void SettingsDialog::LoadPreferences()
{
    ui->checkBox_show_fpsdccounter->setChecked(CAppConfig::GetInstance().GetPreferenceBoolean(PREFERENCE_UI_SHOWFPS));
    ui->checkBox_show_virtualpad->setChecked(CAppConfig::GetInstance().GetPreferenceBoolean(PREFERENCE_UI_SHOWVIRTUALPAD));

    ui->checkBox_enable_highres->setChecked(CAppConfig::GetInstance().GetPreferenceBoolean(PREF_CGSH_OPENGL_ENABLEHIGHRESMODE));
    ui->checkBox_force_bilinear_filtering->setChecked(CAppConfig::GetInstance().GetPreferenceBoolean(PREF_CGSH_OPENGL_FORCEBILINEARTEXTURES));

    ui->checkBox_enable_audio->setChecked(CAppConfig::GetInstance().GetPreferenceBoolean(PREFERENCE_AUDIO_ENABLEOUTPUT));
}

void SettingsDialog::on_checkBox_show_fpsdccounter_clicked(bool checked)
{
    CAppConfig::GetInstance().SetPreferenceBoolean(PREFERENCE_UI_SHOWFPS, checked);
}

void SettingsDialog::on_checkBox_show_virtualpad_clicked(bool checked)
{
    CAppConfig::GetInstance().SetPreferenceBoolean(PREFERENCE_UI_SHOWVIRTUALPAD, checked);

}

void SettingsDialog::on_checkBox_enable_highres_clicked(bool checked)
{

    CAppConfig::GetInstance().SetPreferenceBoolean(PREF_CGSH_OPENGL_ENABLEHIGHRESMODE, checked);
}

void SettingsDialog::checkBox_force_bilinear_filtering(bool checked)
{

    CAppConfig::GetInstance().SetPreferenceBoolean(PREF_CGSH_OPENGL_FORCEBILINEARTEXTURES, checked);
}

void SettingsDialog::on_checkBox_enable_audio_clicked(bool checked)
{
    CAppConfig::GetInstance().SetPreferenceBoolean(PREFERENCE_AUDIO_ENABLEOUTPUT, checked);
}

void SettingsDialog::on_comboBox_currentIndexChanged(int index)
{
    CAppConfig::GetInstance().SetPreferenceInteger(PREF_CGSHANDLER_PRESENTATION_MODE, index);
}
