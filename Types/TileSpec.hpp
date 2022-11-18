#ifndef TILESPEC_HPP
#define TILESPEC_HPP

#include "Common/Enumerations.hpp"

class TileSpec
{
public:
    explicit TileSpec();
    virtual ~TileSpec();

    unsigned int z() const;
    unsigned int y() const;
    unsigned int x() const;
    MapStyle mapStyle() const;

private:
    unsigned int mZ;
    unsigned int mY;
    unsigned int mX;
    MapStyle mMapStyle;
};

#endif // TILESPEC_HPP
