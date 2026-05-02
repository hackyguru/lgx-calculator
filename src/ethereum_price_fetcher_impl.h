#ifndef ETHEREUM_PRICE_FETCHER_IMPL_H
#define ETHEREUM_PRICE_FETCHER_IMPL_H

// Universal module — public API uses only standard C++ types
// (std::string, double, bool, void). All Qt usage is hidden in the
// .cpp behind a private pimpl, so logos-cpp-generator can parse this
// header to emit the QML/IPC glue.

#include <string>

class EthereumPriceFetcherImpl {
public:
    EthereumPriceFetcherImpl();
    ~EthereumPriceFetcherImpl();

    // Fetches the current Ethereum price from an external API and updates the lastPrice.
    void refreshEthereumPrice();
    // Returns the last fetched Ethereum price as a string.
    std::string getLastPrice();

private:
    class Private;
    Private* d;
};

#endif // ETHEREUM_PRICE_FETCHER_IMPL_H
