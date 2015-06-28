#ifndef INCREMENTCLASS_H
#define INCREMENTCLASS_H

#include <QObject>
#include <QVariant>
#include <QString>

class IncrementClass : public QObject
{
    Q_OBJECT
public:
    explicit IncrementClass(QObject *parent = 0);

signals:
    void sendToQml(QVariant str);

public slots:
    void receivedFromQML(const QString &msg);
};

#endif // INCREMENTCLASS_H
