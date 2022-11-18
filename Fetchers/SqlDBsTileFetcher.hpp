#ifndef SQLDBSTILEFETCHER_HPP
#define SQLDBSTILEFETCHER_HPP

#include "Common/Enumerations.hpp"
#include "Interfaces/ITileFetcher.hpp"

class SqlDBsTileFetcher : public ITileFetcher
{

public:
    explicit SqlDBsTileFetcher();
    virtual ~SqlDBsTileFetcher();

    virtual CacheFormat cacheFormat() override final;
    virtual QByteArray getTile(const TileSpec& spec) override final;
};

#endif // SQLDBSTILEFETCHER_HPP
