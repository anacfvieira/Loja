#include "mainloja.h"
#include "ui_incluircd.h"
#include "ui_incluirdvd.h"
#include "ui_incluirlivro.h"
#include "ui_mainloja.h"

#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

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
    mudarStatus();

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

void MainLoja::mudarStatus() {
    total_itens->setNum(X.getNumLivro() + X.getNumCD() + X.getNumDVD());
    statusBar()->insertWidget(1, total_itens);
}

void MainLoja::exibirLivros() {
    ui->tabelaLivros->clearContents();
    ui->tabelaLivros->setRowCount(X.getNumLivro());

    for (int i=0; i<X.getNumLivro(); ++i) {
        Livro L = X.getLivro(i);
        QLabel *provN = new QLabel (L.getNome().c_str());
        QLabel *provP = new QLabel (QString::number(L.getPreco(),'f',2));
        QLabel *provA = new QLabel (L.getAutor().c_str());

        provN->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        provP->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        provA->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        ui->tabelaLivros->setCellWidget(i,0,provN);
        ui->tabelaLivros->setCellWidget(i,1,provP);
        ui->tabelaLivros->setCellWidget(i,2,provA);
    }
    mudarStatus();
}

void MainLoja::exibirCDs() {
    ui->tabelaCds->clearContents();
    ui->tabelaCds->setRowCount(X.getNumCD());

    for (int i=0; i<X.getNumCD(); ++i) {
        CD c = X.getCD(i);
        QLabel *provN = new QLabel (c.getNome().c_str());
        QLabel *provP = new QLabel (QString::number(c.getPreco(),'f',2));
        QLabel *provNF = new QLabel (QString::number(c.getNumFaixas()));

        provN->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        provP->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        provNF->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        ui->tabelaCds->setCellWidget(i,0,provN);
        ui->tabelaCds->setCellWidget(i,1,provP);
        ui->tabelaCds->setCellWidget(i,2,provNF);
    }
    mudarStatus();
}

void MainLoja::exibirDVDs() {
    ui->tabelaDvds->clearContents();
    ui->tabelaDvds->setRowCount(X.getNumDVD());

    for (int i=0; i<X.getNumDVD(); ++i) {
        DVD d = X.getDVD(i);
        QLabel *provN = new QLabel (d.getNome().c_str());
        QLabel *provP = new QLabel (QString::number(d.getPreco(),'f',2));
        QLabel *provD = new QLabel (QString::number(d.getDuracao()));

        provN->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        provP->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        provD->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        ui->tabelaDvds->setCellWidget(i,0,provN);
        ui->tabelaDvds->setCellWidget(i,1,provP);
        ui->tabelaDvds->setCellWidget(i,2,provD);
    }
    mudarStatus();
}

void MainLoja::on_tabelaLivros_cellDoubleClicked(int row, int column) {
    if (X.excluirLivro(row)) {
        ui->tabelaLivros->removeRow(row);
        exibirLivros();
    }
}

void MainLoja::on_tabelaCds_cellDoubleClicked(int row, int column) {
    if (X.excluirCD(row)) {
        ui->tabelaCds->removeRow(row);
        exibirCDs();
    }
}

void MainLoja::on_tabelaDvds_cellDoubleClicked(int row, int column) {
    if (X.excluirDVD(row)) {
        ui->tabelaDvds->removeRow(row);
        exibirDVDs();
    }
}

void MainLoja::slotIncluirLivro(QString nome, QString preco, QString autor) {
    std::string NomeL = nome.toStdString();
    float PrecoL = preco.toFloat();
    std::string Autor = autor.toStdString();

    if (NomeL!="" && PrecoL>0.0 && Autor!="") {
        Livro livro(NomeL, PrecoL, Autor);
        X.incluirLivro(livro);
        exibirLivros();
    }
    else {
        QString message = QString("Nao foi possivel incluir o livro:\n"
                                  "Nome=%1\nPreco=%2\nAutor=%3")
                                .arg(nome)
                                .arg(preco)
                                .arg(autor);
        QMessageBox::critical(this, tr("Livro invalido"), (message));
    }
}


void MainLoja::slotIncluirCD(QString nome, QString preco, QString numfaixas) {
    std::string NomeC = nome.toStdString();
    float PrecoC = preco.toFloat();
    int Faixas = numfaixas.toInt();

    if (NomeC!="" && PrecoC>0.0 && Faixas>0) {
        CD cd(NomeC, PrecoC, Faixas);
        X.incluirCD(cd);
        exibirCDs();
    }
    else {
        QString message = QString("Nao foi possivel incluir o CD:\n"
                                  "Nome=%1\nPreco=%2\nN° Faixas=%3")
                                .arg(nome)
                                .arg(preco)
                                .arg(numfaixas);
        QMessageBox::critical(this, tr("Livro invalido"), (message));
    }
}

void MainLoja::slotIncluirDVD(QString nome, QString preco, QString duracao) {
    std::string NomeD = nome.toStdString();
    float PrecoD = preco.toFloat();
    int Duracao = duracao.toInt();

    if (NomeD!="" && PrecoD>0.0 && Duracao>0) {
        DVD dvd(NomeD, PrecoD, Duracao);
        X.incluirDVD(dvd);
        exibirDVDs();
    }
    else {
        QString message = QString("Nao foi possivel incluir o DVD:\n"
                                  "Nome=%1\nPreco=%2\nDuração=%3")
                                .arg(nome)
                                .arg(preco)
                                .arg(duracao);
        QMessageBox::critical(this, tr("DVD invalido"), (message));
    }
}

void MainLoja::on_actionLer_triggered() {
    QString fileName = QFileDialog::
        getOpenFileName(this,
                        "Ler estoque",
                        QString(),
                        "Estoques (*.txt)");

    if (!fileName.isEmpty()) {
        std::string file = fileName.toStdString();
        if (!X.ler(file)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not read file"));
        }
        exibirLivros();
        exibirCDs();
        exibirDVDs();
    }
}

void MainLoja::on_actionSalvar_triggered() {
    QString fileName = QFileDialog::
        getSaveFileName(this,
                        "Salvar estoque",
                        QString(),
                        "Estoques (*.txt)");

    if (!fileName.isEmpty()) {
        std::string file = fileName.toStdString();
        if (!X.salvar(file)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not read file"));
            return;
        }
    }
}

void MainLoja::on_actionSair_triggered() {
    QCoreApplication::quit();
}

void MainLoja::on_actionIncluir_Livro_triggered() {
    inclLivro->clear();
    inclLivro->show();
}

void MainLoja::on_actionIncluir_CD_triggered() {
    inclCD->clear();
    inclCD->show();
}

void MainLoja::on_actionIncluir_DVD_triggered() {
    inclDVD->clear();
    inclDVD->show();
}

void IncluirLivro::on_buttonBox_accepted() {
    QString nome = ui->lineEditNome->text();
    QString preco = ui->lineEditPreco->text();
    QString autor = ui->lineEditAutor->text();

    emit signIncluirLivro(nome, preco, autor);
}

void IncluirCD::on_buttonBox_accepted() {
    QString nome = ui->lineEditNome->text();
    QString preco = ui->lineEditPreco->text();
    QString nfaixas = ui->lineEditNumFaixas->text();

    emit signIncluirCD(nome, preco, nfaixas);
}

void IncluirDVD::on_buttonBox_accepted() {
    QString nome = ui->lineEditNome->text();
    QString preco = ui->lineEditPreco->text();
    QString duracao = ui->lineEditDuracao->text();

    emit signIncluirDVD(nome, preco, duracao);
}

