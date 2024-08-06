#include "main_window.h"
#include "file_manager.h"
#include "create_job_dialog.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // Setup UI and connect signals/slots
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("Crea Nuovo Lavoro", this);
    layout->addWidget(label);

    QLineEdit *nameEdit = new QLineEdit(this);
    nameEdit->setPlaceholderText("Nome del Lavoro");
    layout->addWidget(nameEdit);

    QLineEdit *dateEdit = new QLineEdit(this);
    dateEdit->setPlaceholderText("Data (MM/GG/AAAA)");
    layout->addWidget(dateEdit);

    QPushButton *createJobButton = new QPushButton("Crea Lavoro", this);
    layout->addWidget(createJobButton);

    connect(createJobButton, &QPushButton::clicked, this, [this, nameEdit, dateEdit]() {
        QString name = nameEdit->text();
        QString date = dateEdit->text();
        if (name.isEmpty() || date.isEmpty()) {
            QMessageBox::warning(this, "Errore", "Nome del lavoro e data sono obbligatori.");
            return;
        }
        FileManager::createJob(name.toStdString(), date.toStdString(), "/path/to/baseDir");
        QMessageBox::information(this, "Successo", "Lavoro creato con successo.");
    });

    QLabel *searchLabel = new QLabel("Cerca File (Full):", this);
    layout->addWidget(searchLabel);

    QLineEdit *searchEdit = new QLineEdit(this);
    searchEdit->setText("Full");
    layout->addWidget(searchEdit);

    QPushButton *searchButton = new QPushButton("Cerca", this);
    layout->addWidget(searchButton);

    connect(searchButton, &QPushButton::clicked, this, [this, searchEdit]() {
        QString searchTerm = searchEdit->text();
        int count1 = FileManager::searchFiles("/path/to/harddisk1", searchTerm.toStdString());
        int count2 = FileManager::searchFiles("/path/to/harddisk2", searchTerm.toStdString());
        QMessageBox::information(this, "Risultati Ricerca", 
                                 QString("Hard Disk 1: %1 file(s)\nHard Disk 2: %2 file(s)")
                                 .arg(count1).arg(count2));
    });

    setWindowIcon(QIcon(":/gui/logo.png"));
    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow() {
    // Cleanup
}
