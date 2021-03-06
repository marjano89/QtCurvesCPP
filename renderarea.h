#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType { Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line };

    void setBackgroundColor(QColor color) { mBackgroundColor = color; }
    QColor backgroundColor() const { return mBackgroundColor; }

    void setShapeColor(QColor color) { mShapeColor = color; }
    QColor shapeColor() const { return mShapeColor; }

    void setShape(ShapeType shape) { mShape = shape; on_shape_changed();}
    ShapeType shape() const { return mShape; }

    void setScale(float scale) { mScale = scale; repaint(); }
    float scale() const { return mScale; }

    void setInterval(float interval) { mIntervalLength = interval; repaint(); }
    float interval() const { return mIntervalLength; }

    void setStepCount(int count) {mStepCount = count; repaint();}
    int stepCount() const { return mStepCount; }

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

private:
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line(float t);

    void on_shape_changed();

    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mScale;
    float mIntervalLength;
    int   mStepCount;
};

#endif // RENDERAREA_H
