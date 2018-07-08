#include "cbar.h"
#include <QWidget>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include <QLine>

// TODO



CBar::CBar():
    m_candleOutlinepen(QPen(Qt::black, 1, Qt::SolidLine)),
    m_bottomWickPen(QPen(Qt::red, m_candleOutlinepen.width(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)),
    m_topWickPen(QPen(Qt::green, m_candleOutlinepen.width(), Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin))

{

}

CBar::CBar(const QPen &outlinePen, const QPen &topWickPen, const QPen &bottomWickPen):
    m_candleOutlinepen(outlinePen),
    m_topWickPen(topWickPen),
    m_bottomWickPen(bottomWickPen)
{

}

CBar::~CBar()
{


}



QRectF CBar::boundingRect() const
{
    return QRectF(-10 - m_candleOutlinepen.width() / 2, -10 - m_candleOutlinepen.width() / 2,
                  20 + m_candleOutlinepen.width(), 20 + m_candleOutlinepen.width());
}




void CBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    int width = 15;
    QLine topWick;
    QLine bottomWick;
    QRect bodyRect;
    QColor bodyColor;


    if(close() > open()){ // Bullish Candle
        qreal topWickY0 = widget->y();
        qreal topWickY1 = topWickY0 - (high() - close());
        qreal bottomWickY0 = widget->y() + (close() - open());
        qreal bottomWickY1 = bottomWickY0 + (open() - low());
        bodyColor = m_upCandleBodyColor;

        topWick.setLine(widget->x(), topWickY0, widget->x(), topWickY1);
        bottomWick.setLine(widget->x(), bottomWickY0, widget->x(), bottomWickY1);

        bodyRect.setRect(widget->x()-(width/2), widget->y(), width, close()-open());
    }
    else if(close() < open()){ // Bearish Candle
        qreal bottomWickY0 = widget->y() + (open() - close());
        qreal bottomWickY1 = bottomWickY0 + (close() - low());
        qreal topWickY0 = widget->y();
        qreal topWickY1 = topWickY0 - (high() - open());
        bodyColor = m_downCandleBodyColor;

        topWick.setLine(widget->x(), topWickY0, widget->x(), topWickY1);
        bottomWick.setLine(widget->x(), bottomWickY0, widget->x(), bottomWickY1);

        bodyRect.setRect(widget->x()-(width/2), widget->y(), width, open()-close());
    }
    else{ // Neutral Candle
        qreal topWickY0 = widget->y();
        qreal topWickY1 = topWickY0 - (high() - close());
        qreal bottomWickY0 = widget->y() + (close() - open());
        qreal bottomWickY1 = bottomWickY0 + (open() - low());
        topWick.setLine(widget->x(), topWickY0, widget->x(), topWickY1);
        bottomWick.setLine(widget->x(), bottomWickY0, widget->x(), bottomWickY1);

        bodyRect.setRect(widget->x()-(width/2), widget->y(), width, 1);
    }

    painter->setPen(m_bottomWickPen);
    painter->drawLine(bottomWick);
    painter->setPen(m_topWickPen);
    painter->drawLine(topWick);

    painter->setPen(m_candleOutlinepen);
    painter->setBrush(bodyColor);
    painter->drawRect(bodyRect);
}







QColor CBar::candleOutlineColor() const
{
    return m_candleOutlineColor;
}

void CBar::setCandleOutlineColor(const QColor &candleOutlineColor)
{
    m_candleOutlineColor = candleOutlineColor;
}






QColor CBar::candleTopWickColor() const
{
    return m_candleTopWickColor;
}

void CBar::setCandleTopWickColor(const QColor &candleTopWickColor)
{
    m_candleTopWickColor = candleTopWickColor;
}






QColor CBar::candleBottomWickColor() const
{
    return m_candleBottomWickColor;
}

void CBar::setCandleBottomWickColor(const QColor &candleBottomWickColor)
{
    m_candleBottomWickColor = candleBottomWickColor;
}







qreal CBar::open() const
{
    return m_open;
}

void CBar::setOpen(const qreal &open)
{
    m_open = open;
}








qreal CBar::close() const
{
    return m_close;
}

void CBar::setClose(const qreal &close)
{
    m_close = close;
}








qreal CBar::low() const
{
    return m_low;
}

void CBar::setLow(const qreal &low)
{
    m_low = low;
}








qreal CBar::high() const
{
    return m_high;
}

void CBar::setHigh(const qreal &high)
{
    m_high = high;
}




QColor CBar::upCandleBodyColor() const
{
    return m_upCandleBodyColor;
}


void CBar::setUpCandleBodyColor(const QColor &upCandleBodyColor)
{
    m_upCandleBodyColor = upCandleBodyColor;
}





QColor CBar::downCandleBodyColor() const
{
    return m_downCandleBodyColor;
}


void CBar::setDownCandleBodyColor(const QColor &downCandleBodyColor)
{
    m_downCandleBodyColor = downCandleBodyColor;
}





QPen CBar::candleOutlinepen() const
{
    return m_candleOutlinepen;
}

void CBar::setCandleOutlinepen(const QPen &candleOutlinepen)
{
    m_candleOutlinepen = candleOutlinepen;
}



