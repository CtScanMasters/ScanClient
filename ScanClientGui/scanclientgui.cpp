#include "scanclientgui.h"
#include "ui_scanclientgui.h"



ScanClientGui::ScanClientGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ScanClientGui)
{
    ui->setupUi(this);



}

ScanClientGui::~ScanClientGui()
{
    delete ui;
}

