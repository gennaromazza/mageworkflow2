#ifndef CREATE_JOB_DIALOG_H
#define CREATE_JOB_DIALOG_H

#include <QDialog>

class CreateJobDialog : public QDialog {
    Q_OBJECT

public:
    CreateJobDialog(QWidget *parent = nullptr);
    ~CreateJobDialog() override; // Assicurarsi che il distruttore sia virtuale
};

#endif // CREATE_JOB_DIALOG_H
