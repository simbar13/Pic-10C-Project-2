#include "grade_calculator.h"
#include "ui_grade_calculator.h"
using namespace std;
grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    gpc =false;
    gm4=false;
    gp10 = false;
    gs2=false;

    ui->setupUi(this);

    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));

    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(enter()));

        QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(reset()))
        QObject::connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(chose_pic()));

        QObject::connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(chose_math()));

        QObject::connect(ui->radioButton_3, SIGNAL(clicked()), this, SLOT(chose_poli()));

        QObject::connect(ui->radioButton_4, SIGNAL(clicked()), this, SLOT(chose_span()));


        ui->Assignment1->setMaximum(100);
        ui->Assignment2->setMaximum(100);
        ui->Assignment3->setMaximum(100);
        ui->Assignment4->setMaximum(100);
        ui->Assignment5->setMaximum(100);
        ui->AssignmentCompletion->setMaximum(100);
        ui->Exam1->setMaximum(100);
        ui->Exam2->setMaximum(100);
        ui->FinalExam->setMaximum(100);
        ui->Participation->setMaximum(100);
        ui->FinalProject->setMaximum(100);




}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::chose_pic()
{
    gpc=true;
}

void grade_calculator::chose_math()
{
    gm4=true;
}

void grade_calculator::chose_poli()
{
    gp10=true;
}

void grade_calculator::chose_span()
{
    gs2=true;
}

double grade_calculator::PIC10C()
{
    double hw_grade=((ui->Assignment1->text()).toDouble()+(ui->Assignment2->text()).toDouble()+(ui->Assignment3->text()).toDouble())/3;
    double midterm_grade=(ui->Exam1->text()).toDouble();
    double final_grade=(ui->FinalExam->text()).toDouble();
    double final_project_grade=(ui->FinalProject->text()).toDouble();
    double g1 = .15*hw_grade+.25*midterm_grade+.3*final_grade+.35*final_project_grade;
    double g2 = .15*hw_grade+.5*final_grade+.35*final_project_grade;

    return (g1>g2?g1:g2);
}

double grade_calculator::MATH164()
{
    double hw_grade=((ui->Assignment1->text()).toDouble()+(ui->Assignment2->text()).toDouble()+(ui->Assignment3->text()).toDouble()+(ui->Assignment4->text()).toDouble()+(ui->Assignment5->text()).toDouble())/5;
    double midterm_grade=((ui->Exam1->text()).toDouble()+(ui->Exam2->text()).toDouble())/2;
    double final_grade=(ui->FinalExam->text()).toDouble();
    double g1 = .2*hw_grade+.5*midterm_grade+.3*final_grade;
    return g1;
}

double grade_calculator::POLISCI10()
{
    double hw_grade=((ui->Assignment1->text()).toDouble()+(ui->Assignment2->text()).toDouble())/2;
    double midterm_grade=(ui->Exam1->text()).toDouble();
    double final_grade=(ui->FinalExam->text()).toDouble();
    double g1 = .2*hw_grade+.4*midterm_grade+.4*final_grade;
    return g1;
}

double grade_calculator::SPAN2()
{
    double hw_grade=(ui->Assignment1->text()).toDouble()
    double midterm_grade=((ui->Exam1->text()).toDouble()+(ui->Exam2->text()).toDouble())/2;
    double final_grade=(ui->FinalExam->text()).toDouble();
    double participation_grade=(ui->Participation->text()).toDouble();
    double g1 = .2*hw_grade+.3*midterm_grade+.3*final_grade+.2*participation_grade;
    return g1;
}

void grade_calculator::enter()(int unused){
double final_grade;
    if(gpc) 
        final_grade = PIC10C();
    if(gm4)
        final_grade=MATH164();
    if(gp10)
        final_grade=POLISCI10();
    if(gs2)
        final_grade=SPAN2();
    ui->lineEdit->setText(QString::number(final_grade)+"% is your final grade in the class.");
    
//you are here big fella.

}
