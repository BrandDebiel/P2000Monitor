#ifndef MONITORWIDGET_H
#define MONITORWIDGET_H

#include <QWidget>

namespace Ui {
class MonitorWidget;
}

class MonitorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorWidget(QWidget *parent = nullptr);
    ~MonitorWidget();

public slots:
    void setTitle(QString title);
    void addMessage(QString message);

private:
    Ui::MonitorWidget *ui;
};

#endif // MONITORWIDGET_H
