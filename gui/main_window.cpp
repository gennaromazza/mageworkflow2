#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_convert_clicked()
{
    QString inputPath = ui->inputPathLineEdit->text();
    QString outputPath = ui->outputPathLineEdit->text();
    imageConverter.convert(inputPath.toStdString(), outputPath.toStdString());
}
