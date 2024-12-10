#include "incluirdvd.h"
#include "ui_incluirdvd.h"

IncluirDVD::IncluirDVD(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IncluirDVD)
{
    ui->setupUi(this);
}

IncluirDVD::~IncluirDVD()
{
    delete ui;
}

void IncluirDVD::clear() {
    ui->lineEditNome->setText("");
    ui->lineEditPreco->setText("");
    ui->lineEditDuracao->setText("");
}
