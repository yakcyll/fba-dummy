#include "controlmodule.h"
#include "ui_controlmodule.h"

ControlModule::ControlModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlModule)
{
    ui->setupUi(this);
}

ControlModule::~ControlModule()
{
    delete ui;
}
