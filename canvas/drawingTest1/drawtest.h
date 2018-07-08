#ifndef DRAWTEST_H
#define DRAWTEST_H

#include <QWidget>


namespace Ui {
class DrawTest;
}

class DrawTest : public QWidget
{
    Q_OBJECT

public:
    explicit DrawTest(QWidget *parent = 0);
    ~DrawTest();

private:
    Ui::DrawTest *ui;

};

#endif // DRAWTEST_H
