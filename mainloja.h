#ifndef MAINLOJA_H
#define MAINLOJA_H

#include <QMainWindow>
#include "loja.h"
#include "incluirlivro.h"
#include "incluircd.h"
#include "incluirdvd.h"
#include "qlabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainLoja; }
QT_END_NAMESPACE

class MainLoja : public QMainWindow
{
    Q_OBJECT

public:
    MainLoja(QWidget *parent = nullptr);
    ~MainLoja();


private:
    Ui::MainLoja *ui;
    Loja X;
    IncluirLivro *inclLivro;
    IncluirCD *inclCD;
    IncluirDVD *inclDVD;
    QLabel *total_itens;


private slots:
    void on_tabelaLivros_cellDoubleClicked(int row, int column);

    void on_tabelaCds_cellDoubleClicked(int row, int column);

    void on_tabelaDvds_cellDoubleClicked(int row, int column);

    void slotIncluirLivro(QString nome, QString preco, QString autor);

    void slotIncluirCD(QString nome, QString preco, QString duracao);

    void slotIncluirDVD(QString nome, QString preco, QString duracao);

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionIncluir_Livro_triggered();

    void on_actionIncluir_CD_triggered();

    void on_actionIncluir_DVD_triggered();

    void exibirLivros();

    void exibirCDs();

    void exibirDVDs();

    void mudarStatus();

};
#endif // MAINLOJA_H
