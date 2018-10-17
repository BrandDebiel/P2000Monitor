#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QList>

namespace Ui {
class FilterWidget;
}

class FilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilterWidget(QWidget *parent = nullptr);
    ~FilterWidget();

private:
    Ui::FilterWidget *ui;
    QGridLayout *m_gridLayout;
    QLabel m_titleLabel;
    QLineEdit m_titleLineEdit;
    QList<QLineEdit *> m_capCodeLineEditList;
    QList<QLabel *> m_capCodeLabelList;
    quint8 m_numberOfFilters;

    void buildInterface();
    quint32 getCapcode(quint8 capcodeNumber);
    void setCapcode(quint8 capCodeNumber, quint32 capCode);

#endif // FILTERWIDGET_H
