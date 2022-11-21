#ifndef HELPER_HPP
#define HELPER_HPP

#include "Enumerations.hpp"

class QString;

class Helper
{

public:
    static MapStyle queryValueToMapStyle(const QString& val);

private:
    Helper() = default;
};

#endif // HELPER_HPP
