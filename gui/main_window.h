#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDate>
#include "file_manager.h"
#include "../image_converter.h"
#include "create_job_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void compareDirectories();
    void createJob();

private:
    Ui::MainWindow *ui;
    QString hardDisk1Path;
    QString hardDisk2Path;
};

#endif // MAIN_WINDOW_H
