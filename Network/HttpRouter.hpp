#ifndef HTTPROUTER_HPP
#define HTTPROUTER_HPP

#include <QHttpServerRouter>
#include <QHttpServerRequest>

class HttpRouter : public QHttpServerRouter
{

public:
    explicit HttpRouter();
    virtual ~HttpRouter();

    using Handler = std::function<void(const QHttpServerRequest&, QHttpServerResponder&&)>;

    bool route(const QString &path,
               const QHttpServerRequest::Methods methods, Handler &&handler);

};

#endif // HTTPROUTER_H
