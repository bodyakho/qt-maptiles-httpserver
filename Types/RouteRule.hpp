#ifndef ROUTERULE_H
#define ROUTERULE_H

#include <QRegularExpression>

class QHttpServerRequest;

class Endpoint
{

public:
    static Endpoint fromRegExp(const QString& expression);
    static Endpoint fromRequest(const QHttpServerRequest& request);

    bool operator==(const Endpoint& other) const;

    bool isValid();

protected:
    explicit Endpoint() = default;

private:
    QRegularExpression mPattern;
};

#endif // ROUTERULE_H
