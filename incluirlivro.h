#ifndef INCLUIRLIVRO_H
#define INCLUIRLIVRO_H

#include <QDialog>

namespace Ui {
class IncluirLivro;
}

class IncluirLivro : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirLivro(QWidget *parent = nullptr);
    ~IncluirLivro();

private:
    Ui::IncluirLivro *ui;

signals:
    void signIncluirLivro();
};

#endif // INCLUIRLIVRO_H
