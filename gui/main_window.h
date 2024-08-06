#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include "image_converter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_convert_clicked();

private:
    QPushButton *button_convert;
    QLineEdit *inputPathLineEdit;
    QLineEdit *outputPathLineEdit;
    ImageConverter imageConverter;
};

#endif // MAIN_WINDOW_H
