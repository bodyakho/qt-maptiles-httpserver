#include "TileSpec.hpp"

#include "Common/Helper.hpp"

#include <QUrlQuery>

TileSpec::TileSpec()
{

}

TileSpec::~TileSpec()
{

}

bool TileSpec::operator==(const TileSpec &other) const
{
    return (mMapStyle == other.mMapStyle &&
            mZ == other.mZ &&
            mY == other.mY &&
            mX == other.mX );
}

unsigned int TileSpec::z() const
{
    return mZ;
}

unsigned int TileSpec::y() const
{
    return mY;
}

unsigned int TileSpec::x() const
{
    return mX;
}

MapStyle TileSpec::mapStyle() const
{
    return mMapStyle;
}

TileSpec TileSpec::fromUrlQuery(const QUrlQuery &q)
{
    TileSpec spec;

    if (!q.hasQueryItem("s") || !q.hasQueryItem("z") ||
        !q.hasQueryItem("y") || !q.hasQueryItem("x") )
    {
        return spec;
    }

    spec.mMapStyle = Helper::queryValueToMapStyle(q.queryItemValue("s"));
    spec.mZ = q.queryItemValue("z").toUInt();
    spec.mY = q.queryItemValue("y").toUInt();
    spec.mX = q.queryItemValue("x").toUInt();

    return spec;
}

bool TileSpec::isValid() const
{
    return mMapStyle != MapStyle::NoMap &&
           mZ != UINT_MAX &&
           mY != UINT_MAX &&
           mX != UINT_MAX ;
}

size_t qHash(const TileSpec &spec, size_t seed)
{
    uint h1 = ::qHash(spec.x(), seed);
    uint h2 = ::qHash(spec.y(), seed);
    uint h3 = ::qHash(spec.z(), seed);

    return ((h1 << 16) | (h2 >> 16)) ^ h3 ^ seed;
}
