#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>

namespace Ui {
    class grade_calculator;
}

class grade_calculator : public QMainWindow
{
        Q_OBJECT

    public:
        explicit grade_calculator(QWidget *parent = 0);
        ~grade_calculator();
        double PIC10C();
        double MATH164();
        double POLISCI10();
        double SPAN2();

    signals:
        void compute_overall();

    public slots:
        void update_overall(int);
        
    private slots:
        void chose_pic();
        void chose_math();
        void chose_poli();
        void chose_span();

    private:
        Ui::grade_calculator *ui;
        bool gpc;
        bool gm4;
        bool gp10;
        bool gs2;
};

#endif // GRADE_CALCULATOR_H
