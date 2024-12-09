#ifndef INCLUIRDVD_H
#define INCLUIRDVD_H

#include <QDialog>

namespace Ui {
class IncluirDVD;
}

class IncluirDVD : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirDVD(QWidget *parent = nullptr);
    ~IncluirDVD();

private:
    Ui::IncluirDVD *ui;

signals:
    void signIncluirDVD(QString nomeIn, QString precoIn, QString numfaixasIn);
};

#endif // INCLUIRDVD_H
