#ifndef TOGGLE_SWITCH_HPP
#define TOGGLE_SWITCH_HPP

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QtWidgets>
#include <QAbstractButton>

class ToggleSwitch : public QAbstractButton
{
    Q_OBJECT
    Q_PROPERTY(int offset READ offset WRITE setOffset)
    Q_PROPERTY(QBrush brush READ brush WRITE setBrush)

public:
    ToggleSwitch(QWidget* parent = nullptr);
    ToggleSwitch(const QBrush& brush, QWidget* parent = nullptr);

    // Public util functions
    QSize sizeHint() const override;
    QBrush brush() const;
    void setBrush(const QBrush &brsh);
    int offset() const;
    void setOffset(int o);

protected:
    void paintEvent(QPaintEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void enterEvent(QEvent*);

private:
    bool    _switch;
    qreal   _opacity;
    int     _x;
    int     _y;
    int     _height;
    int     _margin;
    QBrush  _thumb;
    QBrush  _track;
    QBrush  _brush;

    QPropertyAnimation* _anim = nullptr;
};

#endif // TOGGLE_SWITCH_HPP
