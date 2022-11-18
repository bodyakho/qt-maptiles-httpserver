#include "SqlDBsTileFetcher.hpp"

#include "Types/TileSpec.hpp"

#include <QByteArray>

SqlDBsTileFetcher::SqlDBsTileFetcher()
{

}

SqlDBsTileFetcher::~SqlDBsTileFetcher()
{

}

CacheFormat SqlDBsTileFetcher::cacheFormat()
{
    return CacheFormat::SQLDatabases;
}

QByteArray SqlDBsTileFetcher::getTile(const TileSpec &spec)
{
    return QByteArray{"Tile here"};
}
