#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QQuickItem>
#include "IncrementClass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:///Main.qml")));
    view.setResizeMode(QQuickView::SizeRootObjectToView);


    QObject *root = view.rootObject();
    QObject *button = root->findChild<QObject*>(QString("button"));
    QObject *label = root->findChild<QObject*>(QString("label"));

    IncrementClass incrementer;

    // from QML to C++
    QObject::connect(button, SIGNAL(sendToCpp(QString)),
                     &incrementer, SLOT(receivedFromQML(QString)));
    // from C++ to QML
    QObject::connect(&incrementer, SIGNAL(sendToQml(QVariant)),
                     label, SLOT(receivedFromCpp(QVariant)));

    view.show();
    return app.exec();
}

