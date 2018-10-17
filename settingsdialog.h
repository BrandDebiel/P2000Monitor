#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QGridLayout>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();
    void addTab(QWidget *widget, QString tabName);

private:
    Ui::SettingsDialog *ui;
    QGridLayout *m_mainLayout;

};

#endif // SETTINGSDIALOG_H
