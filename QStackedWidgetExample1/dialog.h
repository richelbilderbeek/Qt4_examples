#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

  signals:
  ///The Dialog creates another QDialog
  void add_me(QDialog * const dialog) const;

  ///The Dialog creates another QDialog
  void remove_me(QDialog * const dialog) const;

private slots:

  void on_button_add_clicked();
  void on_button_close_clicked();

private:
  Ui::Dialog *ui;
};

#endif // DIALOG_H
