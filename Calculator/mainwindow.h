#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_Decimal_released();
    void unary_Operation_Pressed();
    void on_Clear_released();
    void on_Equal_released();
    void operations_Released();
};

#endif // MAINWINDOW_H
