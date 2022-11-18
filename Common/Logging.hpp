#ifndef LOGGING_HPP
#define LOGGING_HPP

#include <QDebug>
#include <QString>

#define LOG_INFO(_CLASS_NAME_, _MSG_) qInfo() << QString("[") + typeid(_CLASS_NAME_).name() + "]: " + _MSG_;
#define LOG_CRITICAL(__CLASS_NAME__, _MSG_) qCritical() << "[" + typeid(_CLASS_NAME_).name() + "]: " + _MSG_;

#endif // LOGGING_HPP
