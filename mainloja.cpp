#include "mainloja.h"
#include "ui_mainloja.h"

MainLoja::MainLoja(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainLoja)
    , X()
    , inclLivro(new IncluirLivro(this))
    , inclCD(new IncluirCD(this))
    , inclDVD(new IncluirDVD(this))
    , total_itens(new QLabel(this))
{
    ui->setupUi(this);

    //Centralizando
    ui->labelLivros->setAlignment(Qt::AlignCenter);
    ui->labelCds->setAlignment(Qt::AlignCenter);
    ui->labelDvds->setAlignment(Qt::AlignCenter);
    // cor de fundo
    ui->labelLivros->setStyleSheet("background: lightgray");
    ui->labelCds->setStyleSheet("background: lightgray");
    ui->labelDvds->setStyleSheet("background: lightgray");

    //Barra de status
    // Insere os widgets da barra de status
    statusBar()->insertWidget(0,new QLabel("Total de itens: "));
    statusBar()->insertWidget(1,new QLabel(total_itens));

     //Mudando os nomes das colunas
    QStringList nomesColunas1;
    QStringList nomesColunas2;
    QStringList nomesColunas3;
    nomesColunas1 << "NOME" << "PRECO" << "AUTOR";
    nomesColunas2 << "NOME" << "PRECO" << "N FAIXAS";
    nomesColunas3 << "NOME" << "PRECO" << "DURACAO";

    ui->tabelaLivros->setHorizontalHeaderLabels(nomesColunas1);
    ui->tabelaCds->setHorizontalHeaderLabels(nomesColunas2);
    ui->tabelaDvds->setHorizontalHeaderLabels(nomesColunas3);

    //Como as colunas se ajustam
    for (int i = 0; i<3; ++i) {
        if (i == 0) {
            ui->tabelaLivros->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
            ui->tabelaCds->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
            ui->tabelaDvds->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
        }

        else {
            ui->tabelaLivros->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
            ui->tabelaCds->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
            ui->tabelaDvds->horizontalHeader()->setSectionResizeMode(i, QHeaderView::ResizeToContents);
        }
    }

    //Estilizando o cabeçalho das colunas
    ui->tabelaLivros->horizontalHeader()->setStyleSheet("QHeaderView::section { text-align:center }"
                                                        "QHeaderView::section { background-color:lightgray }" );
    ui->tabelaCds->horizontalHeader()->setStyleSheet("QHeaderView::section { text-align:center }"
                                                     "QHeaderView::section { background-color:lightgray }");
    ui->tabelaDvds->horizontalHeader()->setStyleSheet("QHeaderView::section { text-align:center }"
                                                      "QHeaderView::section { background-color:lightgray }");

    //Realizando conexoes
    connect(inclLivro, &IncluirLivro::signIncluirLivro, this, &MainLoja::slotIncluirLivro);
    connect(inclCD, &IncluirCD::signIncluirCD, this, &MainLoja::slotIncluirCD);
    connect(inclDVD, &IncluirDVD::signIncluirDVD, this, &MainLoja::slotIncluirDVD);
}

MainLoja::~MainLoja()
{
    delete ui;
}

void MainLoja::on_tabelaLivros_cellDoubleClicked(int row, int column) {
    if (X.excluirLivro(row)) {
        ui->tabelaLivros->removeRow(row);
    }
}

void MainLoja::on_tabelaCds_cellDoubleClicked(int row, int column) {
    if (X.excluirCD(row)) {
        ui->tabelaCds->removeRow(row);
    }
}

void MainLoja::on_tabelaDvds_cellDoubleClicked(int row, int column) {
    if (X.excluirDVD(row)) {
        ui->tabelaDvds->removeRow(row);
    }
}

void MainLoja::slotIncluirLivro(QString nome, QString preco, QString autor) {

};

void MainLoja::slotIncluirCD(QString nome, QString preco, QString numfaixas) {

};

void MainLoja::slotIncluirDVD(QString nome, QString preco, QString duracao) {

};


