#include "TaskManager.hpp"

TaskManager *TaskManager::sInstance = nullptr;

TaskManager::~TaskManager()
{

}

TaskManager &TaskManager::instance(QObject *parent)
{
    if (!sInstance)
    {
        sInstance = new TaskManager(parent);
    }

    return *sInstance;
}

TaskManager::TaskManager(QObject *parent)
{

}
