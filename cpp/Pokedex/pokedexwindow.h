#ifndef POKEDEXWINDOW_H
#define POKEDEXWINDOW_H

#include <QMainWindow>

namespace Ui {
class PokedexWindow;
}

class PokedexWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PokedexWindow(QWidget *parent = 0);
    ~PokedexWindow();
    
private:
    Ui::PokedexWindow *ui;
};

#endif // POKEDEXWINDOW_H
