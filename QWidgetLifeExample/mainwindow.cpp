#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    qDebug()<<"Befor ui->setupUi(this)";
    ui->setupUi(this);
    qDebug()<<"After ui->setupUi(this)";

}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::event(QEvent *event) {
    qDebug()<<event->type();
    QMainWindow::event(event);
}
