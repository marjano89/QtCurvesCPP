#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(0 , 0, 255),
    mShapeColor(255, 255, 255),
    mShape(Astroid)
{
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

QPointF RenderArea::compute_astroid(float t)
{
    float cos_t = cos(t);
    float sin_t = sin(t);

    float x = 2 * pow(cos_t, 3);
    float y = 2 * pow(sin_t, 3);

    return QPointF(x, y);
}

void RenderArea::on_shape_changed()
{
    switch (mShape)
    {
        case Astroid:
            mScale = 40;
            mIntervalLength = 2 * M_PI;
            break;

        case Cycloid:
            break;

        case HuygensCycloid:
            break;

        case HypoCycloid:
            break;

        default:
            break;
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);


    painter.setBrush(mBackgroundColor);
    painter.setPen(mShapeColor);

    //drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();
    int stepCount = 256;

    float step = mIntervalLength / stepCount;

    for( float t = 0; t < mIntervalLength; t += step)
    {
        QPointF point = compute_astroid(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        painter.drawPoint(pixel);
    }

}

