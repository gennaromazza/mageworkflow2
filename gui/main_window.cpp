#include "main_window.h"
#include "create_job_dialog.h"
#include "file_manager.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    createJobButton = new QPushButton("Crea Lavoro", this);
    compareDisksButton = new QPushButton("Confronta Dischi", this);
    searchLineEdit = new QLineEdit(this);
    outputTextEdit = new QTextEdit(this);

    mainLayout->addWidget(createJobButton);
    mainLayout->addWidget(compareDisksButton);
    mainLayout->addWidget(new QLabel("Cerca (FULL):"));
    mainLayout->addWidget(searchLineEdit);
    mainLayout->addWidget(outputTextEdit);

    connect(createJobButton, &QPushButton::clicked, this, &MainWindow::createJob);
    connect(compareDisksButton, &QPushButton::clicked, this, &MainWindow::compareDisks);
    connect(searchLineEdit, &QLineEdit::returnPressed, this, &MainWindow::searchFiles);
}

MainWindow::~MainWindow() {}

void MainWindow::createJob() {
    CreateJobDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString jobName = dialog.getJobName();
        QDate jobDate = dialog.getJobDate();
        QString path = QFileDialog::getExistingDirectory(this, "Seleziona Cartella");

        if (!path.isEmpty()) {
            QString fullPath = QString("%1/%2/%3/%4").arg(path).arg(jobDate.month()).arg(jobDate.day()).arg(jobDate.year());
            FileManager::createDirectory(fullPath.toStdString());
            QMessageBox::information(this, "Successo", "Lavoro creato con successo!");
        }
    }
}

void MainWindow::compareDisks() {
    QString directory1 = QFileDialog::getExistingDirectory(this, "Seleziona il primo disco");
    QString directory2 = QFileDialog::getExistingDirectory(this, "Seleziona il secondo disco");

    if (directory1.isEmpty() || directory2.isEmpty()) {
        QMessageBox::warning(this, "Errore", "Seleziona entrambe le directory.");
        return;
    }

    std::vector<std::string> files1 = FileManager::getFiles(directory1.toStdString());
    std::vector<std::string> files2 = FileManager::getFiles(directory2.toStdString());

    QString result;
    result.append(QString("Hard Disk 1: %1 file(s)\n").arg(files1.size()));
    result.append(QString("Hard Disk 2: %2 file(s)\n").arg(files2.size()));
    outputTextEdit->setText(result);
}

void MainWindow::searchFiles() {
    QString searchTerm = searchLineEdit->text();
    QString directory1 = QFileDialog::getExistingDirectory(this, "Seleziona il primo disco");
    QString directory2 = QFileDialog::getExistingDirectory(this, "Seleziona il secondo disco");

    if (directory1.isEmpty() || directory2.isEmpty()) {
        QMessageBox::warning(this, "Errore", "Seleziona entrambe le directory.");
        return;
    }

    int count1 = FileManager::searchFiles(directory1.toStdString(), search
