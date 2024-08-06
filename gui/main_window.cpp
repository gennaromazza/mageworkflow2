#include "main_window.h"
#include "ui_main_window.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->compareButton, &QPushButton::clicked, this, &MainWindow::compareDirectories);
    connect(ui->createJobButton, &QPushButton::clicked, this, &MainWindow::createJob);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::compareDirectories()
{
    hardDisk1Path = QFileDialog::getExistingDirectory(this, tr("Select Hard Disk 1"));
    hardDisk2Path = QFileDialog::getExistingDirectory(this, tr("Select Hard Disk 2"));

    if (hardDisk1Path.isEmpty() || hardDisk2Path.isEmpty()) {
        QMessageBox::warning(this, tr("Warning"), tr("Please select both directories."));
        return;
    }

    int count1 = FileManager::searchFiles(hardDisk1Path.toStdString(), "Full");
    int count2 = FileManager::searchFiles(hardDisk2Path.toStdString(), "Full");

    QMessageBox::information(this, tr("Search Results"),
                             QString("Hard Disk 1: %1 file(s)\nHard Disk 2: %2 file(s)").arg(count1).arg(count2));
}

void MainWindow::createJob()
{
    CreateJobDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString jobName = dialog.getJobName();
        QDate jobDate = dialog.getJobDate();
        QString directory = QFileDialog::getExistingDirectory(this, tr("Select Directory"));

        if (!directory.isEmpty()) {
            QString path = QString("%1/%2").arg(directory).arg(jobDate.toString("MM_dd_yyyy"));
            FileManager::createDirectory(path.toStdString());
            QMessageBox::information(this, tr("Success"), tr("Job created successfully."));
        }
    }
}
