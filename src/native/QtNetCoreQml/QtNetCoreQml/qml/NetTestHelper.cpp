#include <QtNetCoreQml/qml/NetTestHelper.h>
#include <QQmlComponent>
#include <QDebug>

extern "C" {

void net_test_helper_runQml(QQmlApplicationEngineContainer* qmlEngineContainer, LPWSTR qml) {
    QQmlComponent component(qmlEngineContainer->qmlEngine.data());
    QString qmlString = QString::fromUtf16(qml);
    component.setData(qmlString.toUtf8(), QUrl());
    QObject *object = component.create();

    if(object == NULL) {
        qWarning() << "Couldn't create qml object.";
        return;
    }

    delete object;
}

}
