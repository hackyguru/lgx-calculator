#include "london_time_fetcher_impl.h"

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
#include <QString>
#include <QStringList>
#include <QObject>

// Private impl — holds ALL state (Qt-typed and std-typed alike)
// so the public header stays pure C++. Method bodies access these
// uniformly via d->m_<name>.
class LondonTimeFetcherImpl::Private {
public:
    QString m_lastLondonTime{ QStringLiteral("Fetching...") };
    QNetworkAccessManager m_manager;
};

LondonTimeFetcherImpl::LondonTimeFetcherImpl()
    : d(new Private())
{}

LondonTimeFetcherImpl::~LondonTimeFetcherImpl() {
    delete d;
}

void LondonTimeFetcherImpl::fetchLondonTime()
{
    // Fetches the current time in London and updates the state.
    QNetworkRequest request(QUrl("http://worldtimeapi.org/api/timezone/Europe/London")); QNetworkReply* reply = d->m_manager.get(request); QObject::connect(reply, &QNetworkReply::finished, reply, [this, reply]() { if (reply->error() == QNetworkReply::NoError) { QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll()); QJsonObject jsonObj = jsonDoc.object(); QString dateTime = jsonObj["datetime"].toString(); d->m_lastLondonTime = dateTime.mid(11, 5); } reply->deleteLater(); });
}

std::string LondonTimeFetcherImpl::lastLondonTime()
{
    // Returns the last fetched London time.
    return d->m_lastLondonTime.toStdString();
}
