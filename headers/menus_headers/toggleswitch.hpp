#ifndef TOGGLE_SWITCH_HPP
#define TOGGLE_SWITCH_HPP

#include <QtWidgets>
#include "toggle_switch_style.hpp"

class Animator final : public QVariantAnimation
{
    Q_OBJECT
    Q_PROPERTY(QObject* targetObject READ targetObject WRITE setTargetObject)

public:
    Animator(QObject* target, QObject* parent = nullptr);
    ~Animator() override;

    QObject* targetObject() const;
    void     setTargetObject(QObject* target);

    inline bool isRunning() const
    {
        return state() == Running;
    }

public slots:
    void setup(int duration, QEasingCurve easing = QEasingCurve::Linear);
    void interpolate(const QVariant& start, const QVariant& end);
    void setCurrentValue(const QVariant&);

protected:
    void updateCurrentValue(const QVariant& value) override final;
    void updateState(QAbstractAnimation::State newState, QAbstractAnimation::State oldState) override final;

private:
    QPointer<QObject> target;
};

class SelectionControl : public QAbstractButton
{
    Q_OBJECT

public:
    explicit SelectionControl(QWidget* parent = nullptr);
    ~SelectionControl() override;

    Qt::CheckState checkState() const;

Q_SIGNALS:
    void stateChanged(int);

protected:
    void enterEvent(QEvent*);
    void checkStateSet() override;
    void nextCheckState() override;
    virtual void toggle(Qt::CheckState state) = 0;
};

class ToggleSwitch final : public SelectionControl
{
    Q_OBJECT

    static constexpr auto CORNER_RADIUS = 11.0;
    static constexpr auto THUMB_RADIUS = 14.5;
    static constexpr auto SHADOW_ELEVATION = 2.0;

public:
    explicit ToggleSwitch(QWidget* parent = nullptr);
    ToggleSwitch(const QString& text, QWidget* parent = nullptr);
    ToggleSwitch(const QString& text, const QBrush&, QWidget* parent = nullptr);
    ~ToggleSwitch() override;

    QSize sizeHint() const override final;
    void  enterEvent(QEnterEvent *event) override;

protected:
    void paintEvent(QPaintEvent*) override final;
    void resizeEvent(QResizeEvent*) override final;
    void toggle(Qt::CheckState) override final;

    void init();
    QRect indicatorRect();
    QRect textRect();

    static inline QColor colorFromOpacity(const QColor& c, qreal opacity)
    {
        return QColor(c.red(), c.green(), c.blue(), qRound(opacity * 255.0));
    }
    static inline bool ltr(QWidget* w)
    {
        if (nullptr != w)
            return w->layoutDirection() == Qt::LeftToRight;

        return false;
    }

private:
    Style::Switch style;
    QPixmap shadowPixmap;
    QPointer<Animator> thumbBrushAnimation;
    QPointer<Animator> trackBrushAnimation;
    QPointer<Animator> thumbPosAniamtion;
};

#endif // TOGGLE_SWITCH_HPP
