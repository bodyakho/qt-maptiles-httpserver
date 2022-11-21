#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

struct Constants
{
    struct Network
    {
        static constexpr const unsigned int DefaultPort = 65111;
    };

    struct API
    {
        static constexpr const char* StreetStyleValue= "m";
        static constexpr const char* SatelliteStyleValue = "s";
        static constexpr const char* HybridStyleValue = "h";
        static constexpr const char* Tiles = "/v1/tiles/<arg>/z<arg>/y<arg>/x<arg>";
    };

    struct Cache
    {

    };
};

#endif // CONSTANTS_HPP
