#ifndef TILEFETCHINGTASK_HPP
#define TILEFETCHINGTASK_HPP

#include "Interfaces/ITask.hpp"
#include "Interfaces/ITileFetcher.hpp"
#include "Types/TileSpec.hpp"

class TileFetchingTask : public ITask<QByteArray>
{
public:
    explicit TileFetchingTask(const TileSpec &spec);
    virtual ~TileFetchingTask();

    const TileSpec spec() const;

public slots:
    virtual void start() override final;
    virtual void cancel() override final;

private:
    const TileSpec mSpec;
    const ITileFetcher *mFetcher = nullptr;
};

#endif // TILEFETCHINGTASK_HPP
