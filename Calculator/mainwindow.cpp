#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userSecondNumber(false);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Zero, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->One, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Two, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Three, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Four, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Five, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Six, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Seven, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Eight, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->Nine, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->PlusMinus, SIGNAL(released()), this, SLOT(unary_Operation_Pressed()));
    connect(ui->Percentage, SIGNAL(released()), this, SLOT(unary_Operation_Pressed()));

    connect(ui->Plus, SIGNAL(released()), this, SLOT(operations_Released()));
    connect(ui->Minus, SIGNAL(released()), this, SLOT(operations_Released()));
    connect(ui->Multiply, SIGNAL(released()), this, SLOT(operations_Released()));
    connect(ui->Divide, SIGNAL(released()), this, SLOT(operations_Released()));

    ui->Plus->setCheckable(true);
    ui->Minus->setCheckable(true);
    ui->Multiply->setCheckable(true);
    ui->Divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton* button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    if((ui->Plus->isChecked() || ui->Minus->isChecked() || ui->Multiply->isChecked() || ui->Divide->isChecked())
            && (!userSecondNumber))
    {
        labelNumber = button->text().toDouble();
        userSecondNumber = true;
        newLabel = QString::number(labelNumber,'g',15 );
    }
    else
    {
        if(ui->label->text().contains('.') && button->text()=="0")
        {
           newLabel = ui->label->text()+button->text();
        }
        else
        {
        labelNumber = (ui->label->text()+button->text()).toDouble();
        newLabel = QString::number(labelNumber,'g',15 );
        }
    }

    ui->label->setText(newLabel);
}

void MainWindow::on_Decimal_released()
{
    ui->label->setText(ui->label->text()+".");
}

void MainWindow::unary_Operation_Pressed()
{
    QPushButton* button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if(button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

    if(button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_Clear_released()
{
    ui->Plus->setChecked(false);
    ui->Minus->setChecked(false);
    ui->Multiply->setChecked(false);
    ui->Divide->setChecked(false);

    userSecondNumber = false;

    ui->label->setText("0");

}

void MainWindow::on_Equal_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if(ui->Plus->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->Plus->setChecked(false);
    }
    else if(ui->Minus->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->Minus->setChecked(false);
    }
    else if(ui->Multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->Multiply->setChecked(false);
    }
    else if(ui->Divide->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->Divide->setChecked(false);
    }

    userSecondNumber = false;
}

void MainWindow::operations_Released()
{
    QPushButton* button = (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);
}
