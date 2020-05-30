#ifndef BROWSERTAB_HPP
#define BROWSERTAB_HPP

#include <QWidget>
#include <QUrl>

#include "geminiclient.hpp"
#include "geminiwebpage.hpp"

namespace Ui {
class BrowserTab;
}

class MainWindow;

class BrowserTab : public QWidget
{
    Q_OBJECT

public:
    explicit BrowserTab(MainWindow * mainWindow);
    ~BrowserTab();

    void navigateTo(QUrl const & url);

private slots:
    void on_menu_button_clicked();

    void on_url_bar_returnPressed();

    void on_content_titleChanged(const QString &title);

    void on_content_loadStarted();

    void on_content_loadFinished(bool arg1);

    void on_content_urlChanged(const QUrl &arg1);

    void on_refresh_button_clicked();

    void on_gemini_complete(QByteArray const & data, QString const & mime);


    void on_protocolViolation(QString const & reason);

    void on_inputRequired(QString const & query);

    void on_redirected(QUrl const & uri, bool is_permanent);

    void on_temporaryFailure(TemporaryFailure reason, QString const & info);

    void on_permanentFailure(PermanentFailure reason, QString const & info);

    void on_transientCertificateRequested(QString const & reason);

    void on_authorisedCertificateRequested(QString const & reason);

    void on_certificateRejected(CertificateRejection reason, QString const & info);

    void on_linkHovered(const QString &url);

    void on_navigationRequest(QUrl const & url, bool & allow);

private:
    void setErrorMessage(QString const & msg);

    void pushToHistory(QUrl const & url);

    void updateUI();

    QByteArray translateGeminiToHtml(QByteArray const & input);

private:
    Ui::BrowserTab *ui;
    MainWindow * mainWindow;
    QUrl current_location;

    GeminiClient gemini_client;
    int redirection_count = 0;

    QVector<QUrl> navigation_history;

    GeminiWebPage page;
};

#endif // BROWSERTAB_HPP
