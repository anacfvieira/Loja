#ifndef INCLUIRCD_H
#define INCLUIRCD_H

#include <QDialog>

namespace Ui {
class IncluirCD;
}

class IncluirCD : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirCD(QWidget *parent = nullptr);
    ~IncluirCD();

private:
    Ui::IncluirCD *ui;

signals:
    void signIncluirDVD(QString nomeIn, QString precoIn, QString numfaixasIn);
};



#endif // INCLUIRCD_H
