#include "HttpServer.hpp"

#include "Common/Logging.hpp"

#include <QHttpServerRequest>
#include <QHttpServerResponder>

HttpServer::HttpServer(QObject *parent)
    : QAbstractHttpServer{parent}
{
    mRouter = new HttpRouter();
}

HttpServer::~HttpServer()
{

}

bool HttpServer::handleRequest(const QHttpServerRequest &request, QTcpSocket *socket)
{
    return mRouter->handleRequest(request, socket);
}

void HttpServer::missingHandler(const QHttpServerRequest &request, QTcpSocket *socket)
{
    LOG_INFO(HttpServer, QString("Unknow request - %1").arg(request.url().toString()));

    QHttpServerResponder respoder = makeResponder(request, socket);

    respoder.write(QHttpServerResponder::StatusCode::BadRequest);
}

bool HttpServer::addRoute(const QString &path, const QHttpServerRequest::Methods methods, Handler &&handler)
{
    return mRouter->route(path, methods, handler);
}
