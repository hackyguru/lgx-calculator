#include "ethereum_price_fetcher_impl.h"

// Qt headers auto-detected from method bodies / state.
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QUrl>
#include <QUrlQuery>
#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QObject>

// Private impl — holds ALL state (Qt-typed and std-typed alike)
// so the public header stays pure C++. Method bodies access these
// uniformly via d->m_<name>.
class EthereumPriceFetcherImpl::Private {
public:
    QNetworkAccessManager m_manager;
    QString m_lastPrice{ QStringLiteral("Loading...") };
};

EthereumPriceFetcherImpl::EthereumPriceFetcherImpl()
    : d(new Private())
{}

EthereumPriceFetcherImpl::~EthereumPriceFetcherImpl() {
    delete d;
}

void EthereumPriceFetcherImpl::refreshEthereumPrice()
{
    // Fetches the current Ethereum price from an external API and updates the lastPrice.
    QNetworkRequest request(QUrl(QStringLiteral("https://api.coindesk.com/v1/bpi/currentprice/ETH.json")));
    QNetworkReply* reply = d->m_manager.get(request);
    QObject::connect(reply, &QNetworkReply::finished, reply, [this, reply]() {
      if (reply->error() == QNetworkReply::NoError) {
        const QByteArray json = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(json);
        if (!doc.isNull() && doc.isObject()) {
          QJsonObject obj = doc.object();
          if (obj.contains("bpi") && obj["bpi"].isObject()) {
            QJsonObject bpi = obj["bpi"].toObject();
            if (bpi.contains("USD") && bpi["USD"].isObject()) {
              QJsonObject usd = bpi["USD"].toObject();
              if (usd.contains("rate") && usd["rate"].isString()) {
                d->m_lastPrice = usd["rate"].toString();
              }
            }
          }
        }
      }
      reply->deleteLater();
    });
}

std::string EthereumPriceFetcherImpl::getLastPrice()
{
    // Returns the last fetched Ethereum price as a string.
    return d->m_lastPrice.toStdString();
}
