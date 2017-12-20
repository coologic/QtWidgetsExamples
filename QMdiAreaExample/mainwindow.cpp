#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include <QList>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setTabsMovable(true);
    ui->mdiArea->setTabShape(QTabWidget::Triangular);
    //默认不全屏，否则在TabbedView就只显示一个窗口而且没有标题栏
    ui->mdiArea->setOption(QMdiArea::DontMaximizeSubWindowOnActivation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    QMdiSubWindow *mdi = new QMdiSubWindow;
    ui->mdiArea->addSubWindow(mdi);
    //关闭之后不会自动释放空间，需要此函数让其在close后自动释放
    mdi->setAttribute(Qt::WA_DeleteOnClose);
    //add以后也不自动显示，需要主动show
    mdi->show();
}

void MainWindow::on_pushButton_deletecurrent_clicked() {
    ui->mdiArea->closeActiveSubWindow();
}

void MainWindow::on_pushButton_deleteall_clicked() {
    auto subs = ui->mdiArea->subWindowList();
    qDebug()<<"before delete sub size:"<<subs.size();
    ui->mdiArea->closeAllSubWindows();
    subs = ui->mdiArea->subWindowList();
    //可以查看在setAttribute是否设置状态下list是否变动
    //使用以后此处为0，不使用为新建窗口数且内存不会减少
    qDebug()<<"after delete sub size:"<<subs.size();
}

void MainWindow::on_pushButton_change1_clicked() {
    if(ui->mdiArea->viewMode() == QMdiArea::TabbedView)
        ui->mdiArea->setViewMode(QMdiArea::SubWindowView);
    else
        ui->mdiArea->setViewMode(QMdiArea::TabbedView);
}

void MainWindow::on_pushButton_change2_clicked() {
    delete ui->mdiArea->layout();
    QHBoxLayout *mLayout=new QHBoxLayout(ui->mdiArea);
    auto subs = ui->mdiArea->subWindowList();
    for(auto sub : subs) {
        sub->hide();
        mLayout->addWidget(sub);
        //不隐藏显示就不能生效，update不管用
        sub->show();
    }
    ui->mdiArea->setLayout(mLayout);
}
