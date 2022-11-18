#ifndef SERVERAPI_HPP
#define SERVERAPI_HPP

#include <QObject>

class ServerAPI : public QObject
{
    Q_OBJECT

public:
    explicit ServerAPI();
    virtual ~ServerAPI();

//public slots:
//    void onTileRequestProcessed(
//            )

//signals:
//    void tilesRequest(quint8 s, quint32 z, quint32 y, quint32 x);


};

#endif // SERVERAPI_HPP
