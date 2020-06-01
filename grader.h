#ifndef GRADER_H
#define GRADER_H

#include <QMainWindow>
using namespace std;
namespace Ui {
    class grader;
}

class grader : public QMainWindow
{
        Q_OBJECT

    public:
        explicit grader(QWidget *parent = 0);
        ~grader();
        double PIC10C();
        double MATH164();
        double POLISCI10();
        double SPAN2();
        void chose_pic();
        void chose_math();
        void chose_poli();
        void chose_span();
        void reset();
        void enter();
        void update_a1(int y){Assignment1 = y;}
        void update_a2(int y){Assignment2 = y;}
        void update_a3(int y){Assignment3 = y;}
        void update_a4(int y){Assignment4 = y;}
        void update_a5(int y){Assignment5 = y;}
        void update_e1(int y){Exam1 = y;}
        void update_e2(int y){Exam2 = y;}
        void update_FE(int y){FinalExam = y;}
        void update_FP(int y){FinalProject = y;}
        void update_AC(int y){AssignmentCompletion = y;}
        void update_p(int y){Participation = y;}

    private:
        Ui::grader *ui;
        bool gpc;
        bool gm4;
        bool gp10;
        bool gs2;
        int Assignment1, Assignment2, Assignment3, Assignment4, Assignment5, Exam1, Exam2, FinalExam, FinalProject, AssignmentCompletion, Participation;
};

#endif // GRADER_H
