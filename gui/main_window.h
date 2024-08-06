#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include "image_converter.h"  // Corretto percorso per image_converter.h

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_convert_clicked();

private:
    Ui::MainWindow *ui;  // Dichiarazione della classe Ui::MainWindow
    ImageConverter imageConverter;
};

#endif // MAIN_WINDOW_H
