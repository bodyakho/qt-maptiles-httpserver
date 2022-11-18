#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include <QObject>

class TaskManager : public QObject
{
    Q_OBJECT

public:
    virtual ~TaskManager();

    static TaskManager &instance(QObject *parent = nullptr);

private:
    static TaskManager *sInstance;

private:
    explicit TaskManager(QObject *parent);

};

#endif // TASKMANAGER_HPP
