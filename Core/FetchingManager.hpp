#ifndef FETCHINGMANAGER_H
#define FETCHINGMANAGER_H

#include <QObject>

class ITileFetcher;
class QTcpSocket;
class QHttpServerRequest;

class FetchingManager : public QObject
{
    Q_OBJECT

public:
    explicit FetchingManager(QObject *parent = nullptr);
    virtual ~FetchingManager();

public slots:
    bool onHandleTileRequest(const QHttpServerRequest &request, QTcpSocket *socket);

signals:
    void handleTileFinished(const QHttpServerRequest &request, QTcpSocket *socket, const QByteArray &tile);

private:
    ITileFetcher* mFetcher = nullptr;
};

#endif // FETCHINGMANAGER_H
