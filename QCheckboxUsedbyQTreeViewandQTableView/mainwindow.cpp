#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstandarditemmodel.h>
#include "using_checkbox_item.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QStandardItemModel *m = new QStandardItemModel(this);
    ui->treeView->setModel(m);
    auto i1 = new UsingCheckboxItem("1");
    auto i2 = new UsingCheckboxItem("2");
    m->appendRow(i1);
    m->appendRow(i2);
    auto i11 = new UsingCheckboxItem("1-1");
    auto i12 = new UsingCheckboxItem("1-2");
    i1->appendRow(i11);
    i1->appendRow(i12);
    auto i111 = new UsingCheckboxItem("1-1-1");
    auto i112 = new UsingCheckboxItem("1-1-2");
    i11->appendRow(i111);
    i11->appendRow(i112);
    auto i121 = new UsingCheckboxItem("1-2-1");
    auto i122 = new UsingCheckboxItem("1-2-2");
    i12->appendRow(i121);
    i12->appendRow(i122);

    auto i21 = new UsingCheckboxItem("2-1");
    auto i22 = new UsingCheckboxItem("2-2");
    i2->appendRow(i21);
    i2->appendRow(i22);
    auto i211 = new UsingCheckboxItem("2-1-1");
    auto i212 = new UsingCheckboxItem("2-1-2");
    i21->appendRow(i211);
    i21->appendRow(i212);
    auto i221 = new UsingCheckboxItem("2-2-1");
    auto i222 = new UsingCheckboxItem("2-2-2");
    i22->appendRow(i221);
    i22->appendRow(i222);
}
MainWindow::~MainWindow()
{
    delete ui;
}
