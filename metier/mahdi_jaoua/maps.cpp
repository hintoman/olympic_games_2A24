#include "maps.h"
#include "ui_maps.h"

maps::maps(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::maps)//,m_view(new QWebEngineView(this))
{
  //  ui->setupUi(this);
 /*   setCentralWidget(m_view);

    QWebEnginePage *page = m_view->page();

    connect(page, &QWebEnginePage::featurePermissionRequested,
            [this, page](const QUrl &securityOrigin, QWebEnginePage::Feature feature) {


            page->setFeaturePermission(
                securityOrigin, feature, QWebEnginePage::PermissionGrantedByUser);

    });

    page->load(QUrl(QStringLiteral("https://maps.google.com")));*/
}

maps::~maps()
{
    delete ui;
    deleteLater();
}
