#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webEngineView->load(QUrl("https://duckduckgo.com"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_webEngineView_urlChanged(const QUrl &url)
{
    ui->url->setText(url.toEncoded());
    this->setWindowTitle(ui->webEngineView->title() + " - OpenWeb");
}


void MainWindow::on_goBtn_clicked()
{
    QString url = ui->url->text();
    if (!url.isEmpty()) {
        if (!url.startsWith("http://") && !url.startsWith("https://"))
            url = "http://" + url;
        ui->webEngineView->load(QUrl(url));
    }
}


void MainWindow::on_url_returnPressed()
{
    QString url = ui->url->text();
    if (!url.isEmpty()) {
        if (!url.startsWith("http://") && !url.startsWith("https://"))
            url = "http://" + url;
        ui->webEngineView->load(QUrl(url));
    }
}

void MainWindow::on_backBtn_clicked()
{
    ui->webEngineView->back();
}


void MainWindow::on_forwardBtn_clicked()
{
    ui->webEngineView->forward();
}

void MainWindow::on_resreshBtn_clicked()
{
    ui->webEngineView->reload();
}

