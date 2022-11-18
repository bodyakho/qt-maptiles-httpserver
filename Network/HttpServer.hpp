#ifndef HTTPSERVER_HPP
#define HTTPSERVER_HPP

#include "HttpRouter.hpp"

#include <QAbstractHttpServer>

class HttpRequestRouter;

class HttpServer : public QAbstractHttpServer
{
    Q_OBJECT

public:
    explicit HttpServer(QObject *parent = nullptr);
    virtual ~HttpServer();

    using Handler = std::function<void(const QHttpServerRequest&, QHttpServerResponder&&)>;

    bool addRoute(const QString &path,
               const QHttpServerRequest::Methods methods, Handler &&handler);

protected:
    virtual bool handleRequest(const QHttpServerRequest &request, QTcpSocket *socket) override final;
    virtual void missingHandler(const QHttpServerRequest &request, QTcpSocket *socket) override final;

private:
    HttpRouter *mRouter = nullptr;
};

#endif // HTTPSERVER_HPP
