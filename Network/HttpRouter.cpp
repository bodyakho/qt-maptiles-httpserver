#include "HttpRouter.hpp"

#include <QTcpSocket>
#include <QHttpServerRequest>
#include <QHttpServerRouterRule>

HttpRouter::HttpRouter()
    : QHttpServerRouter()
{

}

HttpRouter::~HttpRouter()
{

}

bool HttpRouter::route(const QString &path, const QHttpServerRequest::Methods methods, Handler &&handler)
{
    auto callback = [this, vh = std::forward<Handler>(handler)](const QRegularExpressionMatch &match,
            const QHttpServerRequest &request,
            QTcpSocket *socket) mutable
    {
        auto bounded = bindCaptured<Handler>(std::move(vh), match);
        bounded();
    };

    auto rule = std::make_unique<QHttpServerRouterRule>(path, methods, callback);

    qDebug() << addRule<Handler>(std::move(rule));
}
