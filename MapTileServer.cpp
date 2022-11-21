#include "MapTileServer.hpp"

#include "Common/Constants.hpp"
#include "Network/HttpServer.hpp"
#include "Core/TaskManager.hpp"
#include "Core/SettingsManager.hpp"
#include "Core/FetchingManager.hpp"

#include <QtCore>
#include <QHttpServer>

#include <QDebug>

MapTileServer::MapTileServer(int argc, char *argv[])
    : QCoreApplication(argc, argv)
{
    SettingsManager::instance(this);
    TaskManager::instance(this);

    mFetchingManager = new FetchingManager(this);

    mServer = new HttpServer(this);

    connect(mServer, &HttpServer::handleTileRequest, mFetchingManager, &FetchingManager::onHandleTileRequest);
    connect(mFetchingManager, &FetchingManager::handleTileFinished, mServer, &HttpServer::onHandleTileFinished);

    initialazeServer();
}

MapTileServer::~MapTileServer()
{

}

void MapTileServer::initialazeServer()
{
//   qDebug() << mServer->route(Constants::EndPoints::Tiles, [] (const quint8 s, const qint32 z, const quint32 y, const quint32 x) {
//        qDebug() << "Req";
//    });

    quint32 requestedPort = SettingsManager::instance().port();

    const auto port = mServer->listen(QHostAddress::Any, requestedPort);

    if (!port)
        qFatal(QString("Server failed to listen on a port ").arg(requestedPort).toLatin1());

    qInfo() << QString("MapTiles server running on http://127.0.0.1:%1/").arg(port);
}
