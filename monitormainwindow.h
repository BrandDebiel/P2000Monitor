#ifndef MONITORMAINWINDOW_H
#define MONITORMAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QCloseEvent>
#include <QMessageBox>
#include "monitorwidget.h"
#include "settingsdialog.h"
#include "filterwidget.h"

namespace Ui {
class MonitorMainWindow;
}

class MonitorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MonitorMainWindow(QWidget *parent = nullptr);
    ~MonitorMainWindow();

private:
    Ui::MonitorMainWindow *ui;
    QGridLayout *m_mainGridLayout;
    QList<MonitorWidget *> m_monitorWidgetList;
    QList<FilterWidget *> m_filterWidgetList;
    quint8 m_numberOfMonitors;
    QString m_applicationName;
    QPushButton m_closeButton;
    QPushButton m_settingsButton;
    SettingsDialog m_settingsDialog;

    void buildInterface();
    void closeEvent(QCloseEvent *event);

private slots:
    void editSettings();

};

#endif // MONITORMAINWINDOW_H
