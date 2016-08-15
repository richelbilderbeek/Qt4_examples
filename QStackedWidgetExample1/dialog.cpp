#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::on_button_close_clicked()
{
  emit remove_me(this);
}

void Dialog::on_button_add_clicked()
{
  Dialog * const d = new Dialog;
  d->ui->label_value->setText(
    QString::number(this->ui->label_value->text().toInt() + 1)
  );
  emit add_me(d);
}
