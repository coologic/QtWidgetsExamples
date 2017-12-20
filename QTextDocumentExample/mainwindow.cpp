#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextDocument>
#include <QTextFrame>
#include <QTextBlock>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QTextDocument* doc = ui->textEdit->document();
    QTextFrame *root_frame = doc->rootFrame();
    QTextFrameFormat root_frame_format = root_frame->frameFormat();//创建框架格式
    root_frame_format.setBorderBrush(Qt::darkBlue);//设置边界颜色
    root_frame_format.setBorder(5);//设置边界宽度
    root_frame->setFrameFormat(root_frame_format); //给框架使用格式
    QTextFrameFormat frame_format;
    frame_format.setBackground(Qt::darkRed);//设置背景色
    frame_format.setMargin(10);//设置边距
    frame_format.setPadding(5);//设置填充
    frame_format.setBorder(2);//设置边界宽度
    frame_format.setBorderStyle(
                QTextFrameFormat::BorderStyle_Solid);//设置边框样式
    frame_format.setPosition(QTextFrameFormat::FloatRight);//右侧
    frame_format.setWidth(QTextLength(
                QTextLength::PercentageLength, 40));//宽度设置
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.insertText("A company");
    cursor.insertBlock();
    cursor.insertText("321 City Street");
    cursor.insertBlock();
    cursor.insertFrame(frame_format);
    cursor.insertText("Industry Park");
    cursor.insertBlock();
    cursor.insertText("Another country");
}

MainWindow::~MainWindow() {
    delete ui;
}
