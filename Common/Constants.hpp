#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

struct Constants
{
    struct Network
    {
        static constexpr const unsigned int DefaultPort = 65111;
    };

    struct EndPoints
    {
        static constexpr const char* Tiles = "/v1/tiles/<arg>/z<arg>/y<arg>/x<arg>";
    };
};

#endif // CONSTANTS_HPP
