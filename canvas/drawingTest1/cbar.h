#ifndef CBAR_H
#define CBAR_H

#include <QGraphicsItem>
#include <QPainter>


// Forward declare
class QPainter;
class QWidget;
class QStyleOptionGraphicsItem;
class QRect;



class CBar : public QGraphicsItem
{
public:
    CBar();
    CBar(const QPen &outlinePen, const QPen &topWickPen, const QPen &bottomWickPen);

    ~CBar();



    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    QColor candleOutlineColor() const;
    void setCandleOutlineColor(const QColor &candleOutlineColor);

    QColor candleBodyColor() const;
    void setCandleBodyColor(const QColor &candleBodyColor);

    QColor candleTopWickColor() const;
    void setCandleTopWickColor(const QColor &candleTopWickColor);

    QColor candleBottomWickColor() const;
    void setCandleBottomWickColor(const QColor &candleBottomWickColor);

    qreal open() const;
    void setOpen(const qreal &open);

    qreal close() const;
    void setClose(const qreal &close);

    qreal low() const;
    void setLow(const qreal &low);

    qreal high() const;
    void setHigh(const qreal &high);

    QColor upCandleBodyColor() const;
    void setUpCandleBodyColor(const QColor &upCandleBodyColor);

    QColor downCandleBodyColor() const;
    void setDownCandleBodyColor(const QColor &downCandleBodyColor);

    QPen candleOutlinepen() const;
    void setCandleOutlinepen(const QPen &candleOutlinepen);

private:
    QColor m_candleOutlineColor;
    QColor m_upCandleBodyColor;
    QColor m_downCandleBodyColor;
    QColor m_candleTopWickColor;
    QColor m_candleBottomWickColor;
    QPen m_candleOutlinepen;
    QPen m_topWickPen;
    QPen m_bottomWickPen;
    qreal m_open;
    qreal m_close;
    qreal m_low;
    qreal m_high;
};

#endif // CBAR_H
