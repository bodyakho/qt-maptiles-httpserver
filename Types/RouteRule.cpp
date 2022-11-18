#include "RouteRule.hpp"

#include <QHttpServerRequest>

Endpoint Endpoint::fromRegExp(const QString &expression)
{
    return Endpoint();
}

Endpoint Endpoint::fromRequest(const QHttpServerRequest &request)
{
    return Endpoint();
}

bool Endpoint::operator==(const Endpoint &other) const
{
    return mPattern == other.mPattern;
}

bool Endpoint::isValid()
{
    return mPattern.isValid();
}
