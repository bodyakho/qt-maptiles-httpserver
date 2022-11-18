#ifndef SETTINGSMANAGER_HPP
#define SETTINGSMANAGER_HPP

#include "Common/Constants.hpp"

#include <QObject>

using Port = quint32;

class SettingsManager : public QObject
{
    Q_OBJECT

public:
    virtual ~SettingsManager();

    static SettingsManager &instance(QObject *parent = nullptr);

    bool save() const;

    Port port() const;
    QString pathStreet() const;
    QString pathSatellite() const;
    QString pathHybrid() const;

private:
    static SettingsManager *sInstance;

    Port mPort = Constants::Network::DefaultPort;
    QString mPathStreet = "./map";
    QString mPathSatellite = "./sat";
    QString mPathHybrid = "./Both";

private:
    explicit SettingsManager(QObject *parent);
    void load();
};

#endif // SETTINGSMANAGER_HPP
