#include "monitormainwindow.h"
#include "ui_monitormainwindow.h"

MonitorMainWindow::MonitorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MonitorMainWindow)
{
    ui->setupUi(this);
    m_numberOfMonitors = 3;
    m_applicationName = "P2000 Monitor";

    buildInterface();

    connect(&m_closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(&m_settingsButton, SIGNAL(clicked()), this, SLOT(editSettings()));

}

MonitorMainWindow::~MonitorMainWindow()
{
    delete ui;
}

void MonitorMainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, m_applicationName,
                                                                tr("Applicatie sluiten?\n"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

void MonitorMainWindow::buildInterface()
{
    m_closeButton.setText("Sluiten");
    m_settingsButton.setText("Instellingen");

    m_mainGridLayout = new QGridLayout(this);
    m_mainGridLayout->addWidget(&m_settingsButton,   0,0,1,1);
    m_mainGridLayout->addWidget(&m_closeButton,      0,15,1,1);

    for(int i = 0; i < m_numberOfMonitors; i++)
    {
        m_monitorWidgetList.append(new MonitorWidget);
        m_mainGridLayout->addWidget(m_monitorWidgetList.last(), i+1,0,1,16);

        m_filterWidgetList.append(new FilterWidget);
        m_settingsDialog.addTab(m_filterWidgetList.last(), QString("Monitor %1").arg(i+1));
    }

    QWidget *mainWindow = new QWidget();
    mainWindow->setLayout(m_mainGridLayout);

    setCentralWidget(mainWindow);
}

void MonitorMainWindow::editSettings()
{
    m_settingsDialog.open();
}
