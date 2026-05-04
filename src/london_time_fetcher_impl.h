#ifndef LONDON_TIME_FETCHER_IMPL_H
#define LONDON_TIME_FETCHER_IMPL_H

// Universal module — public API uses only standard C++ types
// (std::string, double, bool, void). All Qt usage is hidden in the
// .cpp behind a private pimpl, so logos-cpp-generator can parse this
// header to emit the QML/IPC glue.

#include <string>

class LondonTimeFetcherImpl {
public:
    LondonTimeFetcherImpl();
    ~LondonTimeFetcherImpl();

    // Fetches the current time in London and updates the state.
    void fetchLondonTime();
    // Returns the last fetched London time.
    std::string lastLondonTime();

private:
    class Private;
    Private* d;
};

#endif // LONDON_TIME_FETCHER_IMPL_H
