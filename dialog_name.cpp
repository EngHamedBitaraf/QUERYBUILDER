#include "dialog_name.h"
#include "ui_dialog_name.h"
#include <QDebug>
Dialog_name::Dialog_name(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_name)
{
    ui->setupUi(this);
}

Dialog_name::~Dialog_name()
{
    delete ui;
}

void Dialog_name::on_buttonBox_accepted()
{
    name=ui->lineEdit_name->text();
}
