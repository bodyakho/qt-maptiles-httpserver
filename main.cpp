#include "MapTileServer.hpp"

int main(int argc, char *argv[])
{
    MapTileServer *service = new MapTileServer(argc, argv);

    return service->exec();
}
