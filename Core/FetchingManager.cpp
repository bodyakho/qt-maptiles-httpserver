#include "FetchingManager.hpp"

#include "Fetchers/SqlDBsTileFetcher.hpp"
#include "Types/TileSpec.hpp"

#include <QTcpSocket>
#include <QHttpServerRequest>

FetchingManager::FetchingManager(QObject *parent)
{
    mFetcher = new SqlDBsTileFetcher();
}

FetchingManager::~FetchingManager()
{

}

bool FetchingManager::onHandleTileRequest(const QHttpServerRequest &request, QTcpSocket *socket)
{
    const TileSpec spec = TileSpec::fromUrlQuery(request.query());

    if (!spec.isValid())
        return false;

    const QByteArray tile = mFetcher->getTile(spec);

    emit handleTileFinished(request, socket, tile);

    return true;
}

