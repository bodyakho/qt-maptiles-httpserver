#ifndef SQLDBSTILEFETCHER_HPP
#define SQLDBSTILEFETCHER_HPP

#include "Common/Enumerations.hpp"
#include "Interfaces/ITileFetcher.hpp"

class QString;

class SqlDBsTileFetcher : public ITileFetcher
{

public:
    explicit SqlDBsTileFetcher();
    virtual ~SqlDBsTileFetcher();

    virtual CacheFormat cacheFormat() override final;
    virtual QByteArray getTile(const TileSpec& spec) override final;

private:
    QByteArray retriveFromDatabase(const TileSpec &spec);
};

#endif // SQLDBSTILEFETCHER_HPP
