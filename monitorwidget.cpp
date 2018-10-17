#include "monitorwidget.h"
#include "ui_monitorwidget.h"

MonitorWidget::MonitorWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorWidget)
{
    ui->setupUi(this);
}

MonitorWidget::~MonitorWidget()
{
    delete ui;
}

void MonitorWidget::setTitle(QString title)
{
    ui->groupBox->setTitle(title);
}

void MonitorWidget::addMessage(QString message)
{
    ui->plainTextEdit->appendPlainText(message);
}

