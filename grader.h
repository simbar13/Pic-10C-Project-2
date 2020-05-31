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
          void chose_poli();
        void chose_span();
        void reset();
        void enter();

    private:
        Ui::grader *ui;
        bool gpc;
        bool gm4;
        bool gp10;
        bool gs2;
};

#endif // GRADER_H
