#include "controller.h"
#include "throttleitem.h"

#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>


int main(int a, char **b)
{
    qputenv("QSG_RENDER_TIMING", "1");
    QGuiApplication app(a, b);
    QQuickView view;
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    ThrottleItem::registerType();

    Controller c;
    view.rootContext()->setContextProperty("_controller", &c);
    view.setSource(QUrl("qrc:/main.qml"));
    view.show();
    view.resize(500, 500);

    return app.exec();
}
