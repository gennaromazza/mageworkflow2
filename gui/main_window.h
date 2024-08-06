#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void createJob();
    void compareDisks();
    void searchFiles();

private:
    QPushButton *createJobButton;
    QPushButton *compareDisksButton;
    QLineEdit *searchLineEdit;
    QTextEdit *outputTextEdit;
};

#endif // MAIN_WINDOW_H
