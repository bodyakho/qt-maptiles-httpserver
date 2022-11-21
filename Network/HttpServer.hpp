#ifndef HTTPSERVER_HPP
#define HTTPSERVER_HPP

#include <QAbstractHttpServer>
#include <QHash>

class QHttpServerRequest;

class TileSpec;

class HttpServer : public QAbstractHttpServer
{
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);
    virtual ~HttpServer();

public slots:
    void onHandleTileFinished(const QHttpServerRequest &request, QTcpSocket *socket, const QByteArray &tile);

signals:
    bool handleTileRequest(const QHttpServerRequest &request, QTcpSocket *socket);

protected:
    virtual bool handleRequest(const QHttpServerRequest &request, QTcpSocket *socket) override final;
    virtual void missingHandler(const QHttpServerRequest &request, QTcpSocket *socket) override final;
};

#endif // HTTPSERVER_HPP
