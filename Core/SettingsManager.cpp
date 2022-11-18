#include "SettingsManager.hpp"

SettingsManager* SettingsManager::sInstance = nullptr;

SettingsManager::SettingsManager(QObject *parent)
    : QObject(parent)
{
    load();
}

void SettingsManager::load()
{

}

SettingsManager::~SettingsManager()
{

}

SettingsManager &SettingsManager::instance(QObject *parent)
{
    if (!sInstance)
    {
        sInstance = new SettingsManager(parent);
    }

    return *sInstance;
}

bool SettingsManager::save() const
{
    return true;
}

Port SettingsManager::port() const
{
    return mPort;
}

QString SettingsManager::pathStreet() const
{
    return mPathStreet;
}

QString SettingsManager::pathSatellite() const
{
    return mPathSatellite;
}

QString SettingsManager::pathHybrid() const
{
    return mPathHybrid;
}
