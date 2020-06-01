#include "grader.h"
#include "ui_grader.h"
using namespace std;
grader::grader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grader)
{
    gpc =false;
    gm4=false;
    gp10 = false;
    gs2=false;

    ui->setupUi(this);


    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(enter()));


        QObject::connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(chose_pic()));

        QObject::connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(chose_math()));

        QObject::connect(ui->radioButton_3, SIGNAL(clicked()), this, SLOT(chose_poli()));

        QObject::connect(ui->radioButton_4, SIGNAL(clicked()), this, SLOT(chose_span()));

        QObject::connect(ui->A1B, SIGNAL(valueChanged(int)), this, SLOT(update_a1(int)));

        QObject::connect(ui->A2B, SIGNAL(valueChanged(int)), this, SLOT(update_a2(int)));

        QObject::connect(ui->A3B, SIGNAL(valueChanged(int)), this, SLOT(update_a3(int)));

        QObject::connect(ui->A4B, SIGNAL(valueChanged(int)), this, SLOT(update_a4(int)));

        QObject::connect(ui->A5B, SIGNAL(valueChanged(int)), this, SLOT(update_a5(int)));

        QObject::connect(ui->E1B, SIGNAL(valueChanged(int)), this, SLOT(update_e1(int)));

        QObject::connect(ui->E2B, SIGNAL(valueChanged(int)), this, SLOT(update_e2(int)));

        QObject::connect(ui->FPB, SIGNAL(valueChanged(int)), this, SLOT(update_fp(int)));

        QObject::connect(ui->FEB, SIGNAL(valueChanged(int)), this, SLOT(update_fe(int)));

        QObject::connect(ui->ACB, SIGNAL(valueChanged(int)), this, SLOT(update_ac(int)));

        QObject::connect(ui->PB, SIGNAL(valueChanged(int)), this, SLOT(update_p(int)));




        ui->A1B->setMaximum(100);
        ui->A2B->setMaximum(100);
        ui->A3B->setMaximum(100);
        ui->A4B->setMaximum(100);
        ui->A5B->setMaximum(100);
        ui->E1B->setMaximum(100);
        ui->E2B->setMaximum(100);
        ui->FEB->setMaximum(100);
        ui->PB->setMaximum(100);
        ui->FPB->setMaximum(100);
        ui->ACB->setMaximum(100);




}

grader::~grader()
{
    delete ui;
}

void grader::chose_pic()
{
    gpc=true;
}

void grader::chose_math()
{
    gm4=true;
}

void grader::chose_poli()
{
    gp10=true;
}

void grader::chose_span()
{
    gs2=true;
}

double grader::PIC10C()
{
    double hw_grade=(Assignment1+Assignment2+Assignment3)/3;
    double midterm_grade=Exam1;
    double final_grade=FinalExam;
    double final_project_grade=FinalProject;
    double g1 = .15*hw_grade+.25*midterm_grade+.3*final_grade+.35*final_project_grade;
    double g2 = .15*hw_grade+.5*final_grade+.35*final_project_grade;

    return (g1>g2?g1:g2);
}

double grader::MATH164()
{
    double hw_grade=(Assignment1+Assignment2+Assignment3+Assignment4+Assignment5)/5;
    double midterm_grade=(Exam1+Exam2)/2;
    double final_grade=FinalExam;
    double g1 = .2*hw_grade+.5*midterm_grade+.3*final_grade;
    return g1;
}

double grader::POLISCI10()
{
    double hw_grade=(Assignment1+Assignment2)/2;
    double midterm_grade=Exam1;
    double final_grade=FinalExam;
    double g1 = .2*hw_grade+.4*midterm_grade+.4*final_grade;
    return g1;
}

double grader::SPAN2()
{
    double hw_grade=AssignmentCompletion;
    double midterm_grade=Exam1;
    double final_grade=FinalExam;
    double participation_grade=Participation;
    double g1 = .2*hw_grade+.3*midterm_grade+.3*final_grade+.2*participation_grade;
    return g1;
}

void grader::enter(){
double final_grade=0;
    if(gpc)
        final_grade = PIC10C();
    if(gm4)
        final_grade=MATH164();
    if(gp10)
        final_grade=POLISCI10();
    if(gs2)
        final_grade=SPAN2();
    ui->FinalGrade->display(final_grade);


}
