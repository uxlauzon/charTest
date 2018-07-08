#include "drawtest.h"
#include "ui_drawtest.h"


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QRect>
#include <QPen>
#include <QtWidgets>
#include <QGraphicsScene>

#include "cbar.h"


DrawTest::DrawTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawTest)
{
    ui->setupUi(this);
    QGraphicsScene *m_scene = new QGraphicsScene;

    //m_scene->addText("Hello, world!");
    //m_scene.setForegroundBrush(QBrush(Qt::black, Qt::CrossPattern));

    QPen pen(QColor(150, 150, 150), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPen penTopWick(Qt::red, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QPen penBottomWick(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    CBar *tempBar = new CBar(pen, penTopWick, penBottomWick);
    //tempBar->setCandleOutlinepen(QPen(QColor(255,0,0),3,Qt::DashDotDotLine,Qt::RoundCap,Qt::RoundJoin));
    tempBar->setOpen(45);
    tempBar->setClose(65);
    tempBar->setLow(30);
    tempBar->setHigh(70);
    tempBar->setUpCandleBodyColor(Qt::green);
    tempBar->setDownCandleBodyColor(Qt::red);
    tempBar->setCandleOutlineColor(QColor(150, 150, 150));
    m_scene->addItem(tempBar);

    ui->myView->setScene(m_scene);

}

DrawTest::~DrawTest()
{
    delete ui;
}
