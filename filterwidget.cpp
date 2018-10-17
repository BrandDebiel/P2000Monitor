#include "filterwidget.h"
#include "ui_filterwidget.h"

FilterWidget::FilterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterWidget)
{
    ui->setupUi(this);

    m_numberOfFilters = 16;
    buildInterface();
}

FilterWidget::~FilterWidget()
{
    delete ui;
}

void FilterWidget::buildInterface()
{
    m_gridLayout = new QGridLayout(this);
    m_titleLabel.setText("Monitor titel: ");
    m_titleLineEdit.setPlaceholderText("Geef hier de titel op");

    m_gridLayout->addWidget(&m_titleLabel,      0,0,1,1);
    m_gridLayout->addWidget(&m_titleLineEdit,   0,1,1,1);

    for(int i = 0; i < m_numberOfFilters; i++)
    {
        QString number;
        number = QString::number(i+1).rightJustified(2, ' ');

        m_capCodeLineEditList.append(new QLineEdit);
        m_capCodeLineEditList.last()->setPlaceholderText(QString("0 - 9999999"));
        m_capCodeLineEditList.last()->setValidator(new QIntValidator(0, 9999999, this));

        m_capCodeLabelList.append(new QLabel);
        m_capCodeLabelList.last()->setText(QString("Capcode %1:").arg(number));

        m_gridLayout->addWidget(m_capCodeLabelList.last(),      i+1,0,1,1);
        m_gridLayout->addWidget(m_capCodeLineEditList.last(),   i+1,1,1,1);
    }
}

quint32 FilterWidget::getCapcode(quint8 capcodeNumber)
{
    bool ok = false;

    quint32 value = m_capCodeLineEditList.at(capcodeNumber)->text().toULong(&ok);
    if(ok && capcodeNumber < 16)
        return value;
    else
        return ok;
}

//void FilterWidget::setCapcode(quint8 capCodeNumber, quint32 capcode)
//{
//    m_capCodeLineEditList.at(capCodeNumber)->setText(QString::number(capcode));
//}


