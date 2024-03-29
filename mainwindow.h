#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_webEngineView_urlChanged(const QUrl &arg1);

    void on_goBtn_clicked();

    void on_url_returnPressed();

    void on_url_selectionChanged();

    void on_backBtn_clicked();

    void on_forwardBtn_clicked();

    void on_resreshBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
