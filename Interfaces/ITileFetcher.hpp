#ifndef ITILEFETCHER_H
#define ITILEFETCHER_H

#include "Common/Enumerations.hpp"

class TileSpec;
class QByteArray;

class ITileFetcher
{

public:
    virtual CacheFormat cacheFormat() = 0;
    virtual QByteArray getTile(const TileSpec& spec) = 0;

protected:
    explicit ITileFetcher() = default;
};

#endif // ITILEFETCHER_H
