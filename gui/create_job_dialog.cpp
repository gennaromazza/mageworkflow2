#include "create_job_dialog.h"
#include "ui_create_job_dialog.h"

CreateJobDialog::CreateJobDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateJobDialog)
{
    ui->setupUi(this);
}

CreateJobDialog::~CreateJobDialog()
{
    delete ui;
}

QString CreateJobDialog::getJobName() const
{
    return ui->jobNameLineEdit->text();
}

QDate CreateJobDialog::getJobDate() const
{
    return ui->jobDateEdit->date();
}
