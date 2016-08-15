#ifndef MASTERDIALOG_H
#define MASTERDIALOG_H

#include <QDialog>

namespace Ui {
class MasterDialog;
}

class MasterDialog : public QDialog
{
  Q_OBJECT

public:
  explicit MasterDialog(QWidget *parent = 0);
  ~MasterDialog();

private:
  Ui::MasterDialog *ui;

private slots:
  ///Add a new dialog
  void add_new(QDialog * const dialog);

  ///Remove an existing dialog
  void remove(QDialog * const dialog);
};

#endif // MASTERDIALOG_H
