#include "TileSpec.hpp"

TileSpec::TileSpec()
{

}

TileSpec::~TileSpec()
{

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
