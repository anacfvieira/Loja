#include "incluirlivro.h"
#include "ui_incluirlivro.h"

IncluirLivro::IncluirLivro(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IncluirLivro)
{
    ui->setupUi(this);
}

IncluirLivro::~IncluirLivro()
{
    delete ui;
}

void IncluirLivro::clear() {
    ui->lineEditNome->setText("");
    ui->lineEditPreco->setText("");
    ui->lineEditAutor->setText("");
}

