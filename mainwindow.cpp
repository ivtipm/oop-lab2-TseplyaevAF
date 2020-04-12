#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    timer->setInterval(100);

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(buttonStart()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(buttonStop()));
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(randomNumber()));
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, [=]() { ui->textEdit->append(ui->label->text());});
}

void MainWindow::randomNumber()
{
    int num = (qrand() % ((100 + 1) + 100) - 100);
    ui->label->setNum(num);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonStart() {
    timer->start();
    ui->pushButton->setVisible(false);
}

void MainWindow::buttonStop() {
    timer->stop();
    ui->pushButton->setVisible(true);
}
