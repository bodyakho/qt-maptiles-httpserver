#ifndef ITASK_HPP
#define ITASK_HPP

#include <QObject>

template<typename ResultType>
class ITask : public QObject
{
public:
    const ResultType result() const;
    void setResult(ResultType &result);

public slots:
    virtual void start() = 0;
    virtual void cancel() = 0;

signals:
    void started(ITask *task);
    void finished(ITask *task);

protected:
    explicit ITask() = default;

private:
    ResultType mResult;
};

#endif // ITASK_HPP
