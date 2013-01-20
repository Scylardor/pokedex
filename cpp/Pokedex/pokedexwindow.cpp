#include "pokedexwindow.h"
#include "ui_pokedexwindow.h"

PokedexWindow::PokedexWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PokedexWindow)
{
    ui->setupUi(this);
}

PokedexWindow::~PokedexWindow()
{
    delete ui;
}
