#include "toggleswitch.hpp"
#include "menus_helpers.hpp"

ToggleSwitch::ToggleSwitch(QWidget *parent)
    : QAbstractButton(parent),
     _switch(false),
     _opacity(0.000),
     _height(25),
     _margin(2),
     _thumb("#d5d5d5"),
     _anim(new QPropertyAnimation(this, "offset", this))
{
    _y = _height / 2;
    setOffset(_height / 2);
    setBrush(QColor("#009688"));
}

ToggleSwitch::ToggleSwitch(const QBrush &brush, QWidget *parent)
    : QAbstractButton(parent),
      _switch(false),
      _opacity(0.000),
      _height(25),
      _margin(2),
      _thumb("#d5d5d5"),
      _anim(new QPropertyAnimation(this, "offset", this))
{
    _y = _height / 2;
    setOffset(_height / 2);
    setBrush(brush);
}

void ToggleSwitch::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QPainter p(this);
    p.setPen(Qt::NoPen);

    if (isEnabled())
    {
        p.setBrush(_switch ? brush() : Qt::black);
        p.setOpacity(_switch ? 0.5 : 0.38);
        p.setRenderHint(QPainter::Antialiasing, true);
        p.drawRoundedRect(QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin), 12, 12);
        p.setBrush(_thumb);
        p.setBrush(_thumb);
        p.setOpacity(50);
        p.drawEllipse(QRectF(offset() - (_height / 2), _y - (_height / 2), height(), height()));
    }
    else
    {
        p.setBrush(Qt::black);
        p.setOpacity(0.12);
        p.drawRoundedRect(QRect(_margin, _margin, width() - 2 * _margin, height() - 2 * _margin), 12, 12);
        p.setOpacity(1.0);
        p.setBrush(QColor("#BDBDBD"));
        p.drawEllipse(QRectF(offset() - (_height / 2), _y - (_height / 2), height(), height()));
    }
}

void ToggleSwitch::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() & Qt::LeftButton)
    {
        _switch = _switch ? false : true;
        _thumb = _switch ? _brush : QBrush("#d5d5d5");
        if (_switch)
        {
            _anim->setStartValue(_height / 2);
            _anim->setEndValue(width() - _height + 8);
            _anim->setDuration(120);
            _anim->start();
        }
        else
        {
            _anim->setStartValue(offset());
            _anim->setEndValue(_height / 2);
            _anim->setDuration(120);
            _anim->start();
        }
    }
    QAbstractButton::mouseReleaseEvent(e);
}

void ToggleSwitch::enterEvent(QEvent *e)
{
    setCursor(Qt::PointingHandCursor);
    QAbstractButton::enterEvent((QEnterEvent*)e);
}

QSize ToggleSwitch::sizeHint() const
{
    return QSize(2 * (_height + _margin), _height + 2 * _margin);
}

QBrush ToggleSwitch::brush() const
{
    return _brush;
}

void ToggleSwitch::setBrush(const QBrush &brsh)
{
    _brush = brsh;
}

int ToggleSwitch::offset() const
{
    return _x;
}

void ToggleSwitch::setOffset(int o)
{
    _x = o;
    update();
}
