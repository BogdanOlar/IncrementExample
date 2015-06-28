#include "IncrementClass.h"
#include <QDebug>

int count = 0;

IncrementClass::IncrementClass(QObject *parent) :
    QObject(parent)
{
}

void IncrementClass::receivedFromQML(const QString &msg)
{
    qDebug() << "C++ side received: " << msg;
    count++;
    emit sendToQml(QString::number(count));
}
