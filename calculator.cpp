#include "calculator.h"
#include "ui_calculator.h"
#include <math.h>
#include <QDebug>


calculator::calculator(QWidget *parent) :
    QDialog(parent),str("."),
    act(0),wait(false),
    ui(new Ui::calculator){
    ui->setupUi(this);
    connect(ui->s_1,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_2,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_3,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_4,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_5,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_6,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_7,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_8,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_9,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_0,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_dote,SIGNAL(clicked()),this,SLOT(showNumber()));
    connect(ui->s_sqrt,SIGNAL(clicked()),this,SLOT(s_sqr()));
    connect(ui->s_star,SIGNAL(clicked()),this,SLOT(c_star()));
    connect(ui->s_minus,SIGNAL(clicked()),this,SLOT(c_minus()));
    connect(ui->s_plus,SIGNAL(clicked()),this,SLOT(c_plus()));
    connect(ui->s_delit,SIGNAL(clicked()),this,SLOT(c_delit()));
    connect(ui->s_clear,SIGNAL(clicked()),this,SLOT(clear()));
    connect(ui->s_c,SIGNAL(clicked()),this,SLOT(c()));
    connect(ui->s_ravno,SIGNAL(clicked()),this,SLOT(c_ravno()));
}

calculator::~calculator(){
    delete ui;
}

void calculator::showNumber(){
    QString text=ui->line1->text();
    QString text1=ui->line->text();
    QPushButton * button = (QPushButton*)sender();
    if(ui->line->text() == "0" && button->text()!=str)
        ui->line->clear();
    if(ui->line1->text() == "0" && button->text()!=str)
        ui->line1->clear();
    if(wait==true){
        ui->line->clear();
        wait=false;
    }
    if(wait==false)
        ui->line->insert(button->text());
    ui->line1->insert(button->text());
    if(text.isEmpty() && button->text()==str)
        ui->line1->setText("0.");
    if(text1.isEmpty() && button->text()==str)
        ui->line->setText("0.");
}

void calculator::clear(){
    QString text = ui->line->text();
    QString text1=ui->line1->text();
    text.chop(1);
    if(text1.endsWith("-")!=true && text1.endsWith("=")!=true &&
            text1.endsWith("*")!=true && text1.endsWith("+")!=true &&
            text1.endsWith("/")!=true && text1.endsWith("√")!=true &&
            text1.endsWith(" ")!=true)
        text1.chop(1);
    if(text1.endsWith("e+")==true)
        text1.chop(1);
    if(text1.endsWith("e-")==true)
        text1.chop(1);
    if(text1.endsWith("=-")==true)
        text1.chop(1);
    if (text.isEmpty()) {
        text = "0";
    }
    ui->line->setText(text);
    ui->line1->setText(text1);
}

void calculator::c(){
    ui->line->setText("0");
    ui->line1->setText("0");
}

void calculator::s_sqr(){
    double var=ui->line->text().toDouble();
    var=sqrt(var);
    ui->line->setText(QString::number(var));
    QPushButton * button = (QPushButton*)sender();
    ui->line1->insert(button->text());
    ui->line1->insert("=");
    ui->line1->insert(QString::number(var));
    ui->line1->insert(" ");
    wait=true;

}

void calculator::c_plus(){
    if(act==1 && ui->line->text().isEmpty()==false)
        perem+=ui->line->text().toDouble();
    if(act==2 && ui->line->text().isEmpty()==false)
        perem-=ui->line->text().toDouble();
    if(act==3 && ui->line->text().isEmpty()==false)
        perem/=ui->line->text().toDouble();
    if(act==4 && ui->line->text().isEmpty()==false)
        perem*=ui->line->text().toDouble();
    if(act==0 && ui->line->text().isEmpty()==false)
        perem = ui->line->text().toDouble();
    ui->line->clear();
    act=1;
    QPushButton * button = (QPushButton*)sender();
    QString text1=ui->line1->text();
    if(text1.endsWith("+")!=true)
        ui->line1->insert(button->text());
    if(text1.endsWith("-")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("*")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("=")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("/")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("√")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
}

void calculator::c_ravno(){
    while(wait!=true){
        if(act==1)
            perem+=ui->line->text().toDouble();
        if(act==2)
            perem-=ui->line->text().toDouble();
        if(act==3)
            perem/=ui->line->text().toDouble();
        if(act==4)
            perem*=ui->line->text().toDouble();
        ui->line->setText(QString::number(perem));
        act=0;
        wait=true;
        QPushButton * button = (QPushButton*)sender();
        ui->line1->insert(button->text());
        ui->line1->insert(QString::number(perem));
        ui->line1->insert(" ");
    }
}

void calculator::c_minus(){
    if(act==1 && ui->line->text().isEmpty()==false)
        perem+=ui->line->text().toDouble();
    if(act==2 && ui->line->text().isEmpty()==false)
        perem-=ui->line->text().toDouble();
    if(act==3 && ui->line->text().isEmpty()==false)
        perem/=ui->line->text().toDouble();
    if(act==4 && ui->line->text().isEmpty()==false)
        perem*=ui->line->text().toDouble();
    if(act==0 && ui->line->text().isEmpty()==false)
        perem = ui->line->text().toDouble();
    ui->line->clear();
    act=2;
    QPushButton * button = (QPushButton*)sender();
    QString text1=ui->line1->text();
    if(text1.endsWith("-")!=true)
        ui->line1->insert(button->text());
    if(text1.endsWith("+")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("*")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("=")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("/")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("√")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
}

void calculator::c_delit(){
    if(act==1 && ui->line->text().isEmpty()==false)
        perem+=ui->line->text().toDouble();
    if(act==2 && ui->line->text().isEmpty()==false)
        perem-=ui->line->text().toDouble();
    if(act==3 && ui->line->text().isEmpty()==false)
        perem/=ui->line->text().toDouble();
    if(act==4 && ui->line->text().isEmpty()==false)
        perem*=ui->line->text().toDouble();
    if(act==0 && ui->line->text().isEmpty()==false)
        perem = ui->line->text().toDouble();
    ui->line->clear();
    act=3;
    QPushButton * button = (QPushButton*)sender();
    QString text1=ui->line1->text();
    if(text1.endsWith("/")!=true)
        ui->line1->insert(button->text());
    if(text1.endsWith("-")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("*")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("=")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("+")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("√")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
}

void calculator::c_star(){
    if(act==1 && ui->line->text().isEmpty()==false)
        perem+=ui->line->text().toDouble();
    if(act==2 && ui->line->text().isEmpty()==false)
        perem-=ui->line->text().toDouble();
    if(act==3 && ui->line->text().isEmpty()==false)
        perem/=ui->line->text().toDouble();
    if(act==4 && ui->line->text().isEmpty()==false)
        perem*=ui->line->text().toDouble();
    if(act==0 && ui->line->text().isEmpty()==false)
        perem = ui->line->text().toDouble();
    ui->line->clear();
    act=4;
    QPushButton * button = (QPushButton*)sender();
    QString text1=ui->line1->text();
    if(text1.endsWith("*")!=true)
        ui->line1->insert(button->text());
    if(text1.endsWith("-")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("+")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("=")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("/")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
    if(text1.endsWith("√")==true){
        text1.chop(1);
        ui->line1->setText(text1);
        ui->line1->insert(button->text());
    }
}
