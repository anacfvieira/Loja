#include "incluircd.h"
#include "ui_incluircd.h"

IncluirCD::IncluirCD(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IncluirCD)
{
    ui->setupUi(this);
}

IncluirCD::~IncluirCD()
{
    delete ui;
}

void IncluirCD::clear() {
    ui->lineEditNome->setText("");
    ui->lineEditPreco->setText("");
    ui->lineEditNumFaixas->setText("");
}
