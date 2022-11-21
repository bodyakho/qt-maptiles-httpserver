#include "HttpServer.hpp"

#include "Common/Logging.hpp"

#include <QHttpServerRequest>
#include <QHttpServerResponse>
#include <QHttpServerResponder>

HttpServer::HttpServer(QObject *parent)
    : QAbstractHttpServer{parent}
{

}

HttpServer::~HttpServer()
{

}

void HttpServer::onHandleTileFinished(const QHttpServerRequest &request, QTcpSocket *socket, const QByteArray &tile)
{
    auto resp = makeResponder(request, socket);

    QHttpServerResponse::StatusCode status = !tile.isEmpty() ? QHttpServerResponse::StatusCode::Ok
                                                             : QHttpServerResponse::StatusCode::NotFound;
    QHttpServerResponse r(std::move(tile), status);

    r.write(std::move(resp));
}


bool HttpServer::handleRequest(const QHttpServerRequest &request, QTcpSocket *socket)
{
    const QUrlQuery query = request.query();
    LOG_INFO(HttpServer, request.query().toString())
    if (!request.url().toString().contains("tiles") || query.isEmpty())
        return false;

    return emit handleTileRequest(request, socket);
}

void HttpServer::missingHandler(const QHttpServerRequest &request, QTcpSocket *socket)
{
    LOG_INFO(HttpServer, QString("Unknow request - %1").arg(request.url().toString()));

    QHttpServerResponder respoder = makeResponder(request, socket);

    respoder.write(QHttpServerResponder::StatusCode::BadRequest);
}


