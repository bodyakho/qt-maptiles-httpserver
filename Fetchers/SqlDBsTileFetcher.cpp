#include "SqlDBsTileFetcher.hpp"

#include "Types/TileSpec.hpp"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QByteArray>
#include <QString>
#include <QFile>

static QString db = QString("D:/SASPlanet/cache_sqlite/map");

SqlDBsTileFetcher::SqlDBsTileFetcher()
{

}

SqlDBsTileFetcher::~SqlDBsTileFetcher()
{

}

CacheFormat SqlDBsTileFetcher::cacheFormat()
{
    return CacheFormat::SQLDatabases;
}

QByteArray SqlDBsTileFetcher::getTile(const TileSpec &spec)
{
    return retriveFromDatabase(spec);
}


QByteArray SqlDBsTileFetcher::retriveFromDatabase(const TileSpec &spec)
{
    QString fileName = db
            + "/z" + QString::number(spec.z() + 1)
            + "/"  + QString::number(spec.x() / 1024)
            + "/"  + QString::number(spec.y() / 1024)
            + "/"  + QString::number(spec.x() / 256)
            + "."  + QString::number(spec.y() / 256)
            + ".sqlitedb";

    QFile file(fileName);

    if (fileName.isEmpty() || !file.exists())
        return QByteArray();

    const QString sqlDriverName("QSQLITE");

    QByteArray bytes;

    static int connectionNumber = 0;

    QString cName = QString::number(100 + connectionNumber++);
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(sqlDriverName, cName);
        db.setDatabaseName(fileName);
        db.setConnectOptions("QSQLITE_OPEN_READONLY");

        if (!db.open())
            return bytes;

        QString req = QString("select b from t where x = '%1' and y = '%2'").arg(spec.x()).arg(spec.y());

        QSqlQuery query(db);

        if (!query.exec(req))
        {
            db.close();
            return bytes;
        }

        if(!query.first())
        {
            db.close();
            return bytes;
        }

        bytes = query.value("b").toByteArray();

    }

    QSqlDatabase::removeDatabase(cName);

    return bytes;
}
