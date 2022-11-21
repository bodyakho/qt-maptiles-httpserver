#include "Helper.hpp"

#include "Constants.hpp"

#include <QString>

MapStyle Helper::queryValueToMapStyle(const QString &val)
{
    if (val == Constants::API::SatelliteStyleValue)
    {
        return MapStyle::Satellite;
    }
    else if (val == Constants::API::HybridStyleValue)
    {
        return MapStyle::Hybrid;
    }
    else
    {
        return MapStyle::Street;
    }
}
