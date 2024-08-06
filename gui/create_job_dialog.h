#ifndef CREATE_JOB_DIALOG_H
#define CREATE_JOB_DIALOG_H

#include <QDialog>

class CreateJobDialog : public QDialog {
    Q_OBJECT

public:
    CreateJobDialog(QWidget *parent = nullptr);
    ~CreateJobDialog();
};

#endif // CREATE_JOB_DIALOG_H
