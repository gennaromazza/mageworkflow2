#ifndef CREATE_JOB_DIALOG_H
#define CREATE_JOB_DIALOG_H

#include <QDialog>

namespace Ui {
class CreateJobDialog;
}

class CreateJobDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateJobDialog(QWidget *parent = nullptr);
    ~CreateJobDialog();

private:
    Ui::CreateJobDialog *ui;
};

#endif // CREATE_JOB_DIALOG_H
