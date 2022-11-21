#ifndef MAPTILESERVER_HPP
#define MAPTILESERVER_HPP

#include <QCoreApplication>

class HttpServer;
class FetchingManager;

class MapTileServer : public QCoreApplication
{

public:
    explicit MapTileServer(int argc, char *argv[]);
    virtual ~MapTileServer();

private:
    HttpServer *mServer = nullptr;
    FetchingManager *mFetchingManager = nullptr;

private:
    void initialazeServer();
};

#endif // MAPTILESERVER_HPP
