#include "main_window.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    QLabel *inputLabel = new QLabel("Input Path:");
    inputPathLineEdit = new QLineEdit();
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputPathLineEdit);

    QHBoxLayout *outputLayout = new QHBoxLayout();
    QLabel *outputLabel = new QLabel("Output Path:");
    outputPathLineEdit = new QLineEdit();
    outputLayout->addWidget(outputLabel);
    outputLayout->addWidget(outputPathLineEdit);

    button_convert = new QPushButton("Convert", this);
    connect(button_convert, &QPushButton::clicked, this, &MainWindow::on_button_convert_clicked);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(outputLayout);
    mainLayout->addWidget(button_convert);
}

MainWindow::~MainWindow()
{
    // Cleanup code if needed
}

void MainWindow::on_button_convert_clicked()
{
    QString inputPath = inputPathLineEdit->text();
    QString outputPath = outputPathLineEdit->text();
    imageConverter.convert(inputPath.toStdString(), outputPath.toStdString());
}
