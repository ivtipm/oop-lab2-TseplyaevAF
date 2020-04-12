#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void randomNumber();

    void buttonStart();

    void buttonStop();

private:
    Ui::MainWindow *ui;
    QTimer* timer;

};
#endif // MAINWINDOW_H
