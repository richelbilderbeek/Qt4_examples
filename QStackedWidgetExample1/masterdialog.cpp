#include "masterdialog.h"
#include <cassert>

#include "ui_masterdialog.h"
#include "dialog.h"

MasterDialog::MasterDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MasterDialog)
{
  ui->setupUi(this);
  assert(ui->stackedWidget->count() == 0);

  Dialog * const dialog = new Dialog(this);
  QObject::connect(dialog, SIGNAL(add_me(QDialog*const)), this, SLOT(add_new(QDialog*const)));
  QObject::connect(dialog, SIGNAL(remove_me(QDialog*const)), this, SLOT(remove(QDialog*const)));

  ui->stackedWidget->addWidget(dialog);
  assert(ui->stackedWidget->count() == 1);
}

MasterDialog::~MasterDialog()
{
  delete ui;
}

void MasterDialog::add_new(QDialog * const dialog)
{
  const int new_index = ui->stackedWidget->addWidget(dialog);
  ui->stackedWidget->setCurrentIndex(new_index);
  ui->lcdNumber->display(new_index);
  QObject::connect(
    ui->stackedWidget->currentWidget(),
    SIGNAL(add_me(QDialog*const)),
    this,
    SLOT(add_new(QDialog*const))
  );
  QObject::connect(dialog, SIGNAL(remove_me(QDialog*const)), this, SLOT(remove(QDialog*const)));
}

void MasterDialog::remove(QDialog * const dialog)
{
  ui->stackedWidget->removeWidget(dialog);
  delete dialog;

  const int new_index = ui->stackedWidget->count() - 1;
  ui->stackedWidget->setCurrentIndex(new_index);
  ui->lcdNumber->display(new_index);
}
