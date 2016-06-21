/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QWidget *General;
    QCheckBox *checkBox_show_fpsdccounter;
    QCheckBox *checkBox_show_virtualpad;
    QWidget *Video;
    QCheckBox *checkBox_enable_highres;
    QCheckBox *checkBox_force_bilinear_filtering;
    QComboBox *comboBox;
    QLabel *label;
    QWidget *Audio;
    QCheckBox *checkBox_enable_audio;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(612, 432);
        buttonBox = new QDialogButtonBox(SettingsDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(200, 380, 381, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        listWidget = new QListWidget(SettingsDialog);
        QIcon icon;
        icon.addFile(QStringLiteral("../../Downloads/1465576135_gear.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setKerning(true);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setIcon(icon);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../Downloads/1465576153_music.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem1->setIcon(icon1);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        QFont font1;
        font1.setStyleStrategy(QFont::PreferDefault);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem2->setFont(font1);
        __qlistwidgetitem2->setIcon(icon1);
        __qlistwidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 151, 331));
        listWidget->setEditTriggers(QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        listWidget->setIconSize(QSize(48, 48));
        stackedWidget = new QStackedWidget(SettingsDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(202, 30, 381, 331));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        General = new QWidget();
        General->setObjectName(QStringLiteral("General"));
        checkBox_show_fpsdccounter = new QCheckBox(General);
        checkBox_show_fpsdccounter->setObjectName(QStringLiteral("checkBox_show_fpsdccounter"));
        checkBox_show_fpsdccounter->setGeometry(QRect(20, 20, 351, 22));
        checkBox_show_virtualpad = new QCheckBox(General);
        checkBox_show_virtualpad->setObjectName(QStringLiteral("checkBox_show_virtualpad"));
        checkBox_show_virtualpad->setGeometry(QRect(20, 50, 351, 22));
        stackedWidget->addWidget(General);
        Video = new QWidget();
        Video->setObjectName(QStringLiteral("Video"));
        checkBox_enable_highres = new QCheckBox(Video);
        checkBox_enable_highres->setObjectName(QStringLiteral("checkBox_enable_highres"));
        checkBox_enable_highres->setGeometry(QRect(20, 20, 341, 22));
        checkBox_force_bilinear_filtering = new QCheckBox(Video);
        checkBox_force_bilinear_filtering->setObjectName(QStringLiteral("checkBox_force_bilinear_filtering"));
        checkBox_force_bilinear_filtering->setGeometry(QRect(20, 50, 341, 22));
        comboBox = new QComboBox(Video);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 100, 161, 27));
        label = new QLabel(Video);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 80, 151, 17));
        stackedWidget->addWidget(Video);
        Audio = new QWidget();
        Audio->setObjectName(QStringLiteral("Audio"));
        checkBox_enable_audio = new QCheckBox(Audio);
        checkBox_enable_audio->setObjectName(QStringLiteral("checkBox_enable_audio"));
        checkBox_enable_audio->setGeometry(QRect(20, 20, 341, 22));
        stackedWidget->addWidget(Audio);

        retranslateUi(SettingsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsDialog, SLOT(reject()));

        listWidget->setCurrentRow(0);
        stackedWidget->setCurrentIndex(1);
        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Dialog", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SettingsDialog", "General", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("SettingsDialog", "Video", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("SettingsDialog", "Audio", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        checkBox_show_fpsdccounter->setText(QApplication::translate("SettingsDialog", "Show Framerate and Draw Call Counters", 0));
        checkBox_show_virtualpad->setText(QApplication::translate("SettingsDialog", "Show Virtual Pad", 0));
        checkBox_enable_highres->setText(QApplication::translate("SettingsDialog", "Enable High Resolution", 0));
        checkBox_force_bilinear_filtering->setText(QApplication::translate("SettingsDialog", "Force Bilinear Filtering", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "Fill Screen", 0)
         << QApplication::translate("SettingsDialog", "Fit Screen", 0)
         << QApplication::translate("SettingsDialog", "Original Size", 0)
        );
        label->setText(QApplication::translate("SettingsDialog", "<html><head/><body><p>Presentation Mode:</p></body></html>", 0));
        checkBox_enable_audio->setText(QApplication::translate("SettingsDialog", "Enable Audio Output", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
