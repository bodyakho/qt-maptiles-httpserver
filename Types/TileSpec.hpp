#ifndef TILESPEC_HPP
#define TILESPEC_HPP

#include "Common/Enumerations.hpp"

#include <limits.h>

class QUrlQuery;

class TileSpec
{
public:
    explicit TileSpec();
    virtual ~TileSpec();

    bool operator==(const TileSpec& other) const;

    static TileSpec fromUrlQuery(const QUrlQuery& q);

    bool isValid() const;

    unsigned int z() const;
    unsigned int y() const;
    unsigned int x() const;
    MapStyle mapStyle() const;


private:
    unsigned int mZ = UINT_MAX;
    unsigned int mY = UINT_MAX;
    unsigned int mX = UINT_MAX;
    MapStyle mMapStyle = MapStyle::NoMap;
};

size_t qHash(const TileSpec& spec, size_t seed = 0);

#endif // TILESPEC_HPP
