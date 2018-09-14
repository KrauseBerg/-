#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

calculator *calc;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    calc=new calculator();
    connect(ui->Start,SIGNAL(clicked(bool)),this,SLOT(showCalculator()));
    connect(ui->Close,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->Close,SIGNAL(clicked(bool)),calc,SLOT(close()));
    connect(ui->CloseMenu,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->StartMenu,SIGNAL(triggered(bool)),this,SLOT(showCalculator()));
}



MainWindow::~MainWindow(){
    delete ui;
    delete calc;
}

void MainWindow::showCalculator(){
    calc->show();
}
