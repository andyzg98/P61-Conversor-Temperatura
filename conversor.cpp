#include "conversor.h"
#include "ui_conversor.h"

Conversor::Conversor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Conversor)
{
    ui->setupUi(this);
    // Conectarel dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)), //coneccion regulador de centigrados
            this, SLOT(cent2fahr(int))); //metodo de centi fahr
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
            this, SLOT (fahr2cent(int)));
    connect(ui->inKelv, SIGNAL(valueChanged(int)),
            this, SLOT (kelv2cent(int)));
}

Conversor::~Conversor()
{
    delete ui;
}

void Conversor::cent2fahr(int grados)
{
    if (ui->inCent->hasFocus()){
        int f = (grados * 9.0/5) + 32; //centigrados a fahrenheit
        int k = (grados + 273.15);// centigrados a kelvin
        ui->inKelv->setValue(k); //
        ui->inFahr->setValue(f);
    }

}

void Conversor::fahr2cent(int grados)
{
    if (ui->inFahr->hasFocus()){
        int c = (grados - 32) * 5.0/9; //fahrenheit a centigrados
        int k =(((grados-32)*5/9)+273.15); //fahrenheit a kelvin
        ui->inKelv->setValue(k);
        ui->inCent->setValue(c);
    }
}

void Conversor::kelv2cent(int grados)
{
    if (ui->inKelv->hasFocus()){
        int c = (grados - 273.15); //kelvin a centigrados
        int f = (((grados -273.5)*9/5)+32);//kelvin a fahrenheit
        ui->inFahr->setValue(f);
        ui->inCent->setValue(c);
    }

}
