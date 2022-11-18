#ifndef FETCHINGMANAGER_H
#define FETCHINGMANAGER_H

#include <QObject>

class TileSpec;

class FetchingManager : public QObject
{
    Q_OBJECT

public:
    explicit FetchingManager(QObject *parent = nullptr);
    virtual ~FetchingManager();

public slots:
    void processTileRequest(const TileSpec& spec);

signals:
    void tileRequestProcessed(const TileSpec& spec, const QByteArray &tile);
};

#endif // FETCHINGMANAGER_H
