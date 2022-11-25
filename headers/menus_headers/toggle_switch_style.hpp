#ifndef TOGGLE_SWITCH_STYLE_HPP
#define TOGGLE_SWITCH_STYLE_HPP

#include <QtCore/qeasingcurve.h>
#include <QPainter>
#include <QColor>

#define cyan500 QColor("#00bcd4")
#define gray50 QColor("#d5d5d5")
//#define black QColor("#000000")
#define gray400 QColor("#bdbdbd")

Q_DECL_IMPORT void qt_blurImage(QPainter *p, QImage &blurImage, qreal radius, bool quality, bool alphaOnly, int transposed = 0);

namespace Style
{
    using Type = QEasingCurve::Type;

    struct Animation
    {
        Animation() = default;
        Animation(Type _easing, int _duration) : easing{_easing}, duration{_duration} {}

        Type easing;
        int duration;
    };

    struct Switch
    {
        Switch() :
            height{ 44 },
            font{ QFont("Roboto medium", 13) },
            indicatorMargin{ QMargins(8, 8, 8, 8) },
            thumbOnBrush{ cyan500 },
            thumbOnOpacity{ 1 },
            trackOnBrush{ cyan500 },
            trackOnOpacity{ 0.5 },
            thumbOffBrush{ gray50 },
            thumbOffOpacity{ 1 },
            trackOffBrush{ QColor("#00000") },
            trackOffOpacity{ 0.38 },
            thumbDisabled{ gray400 },
            thumbDisabledOpacity{ 1 },
            trackDisabled{ QColor("#00000") },
            trackDisabledOpacity{ 0.12 },
            textColor{ QColor("#00000") },
            disabledTextOpacity{ 0.26 },
            thumbBrushAnimation{ Animation(Type::Linear, 150) },
            trackBrushAnimation{ Animation(Type::Linear, 150) },
            thumbPosAniamtion{ Animation(Type::InOutQuad, 150) } {}

        int       height;
        QFont     font;
        QMargins  indicatorMargin;
        QColor    thumbOnBrush;
        double    thumbOnOpacity;
        QColor    trackOnBrush;
        double    trackOnOpacity;
        QColor    thumbOffBrush;
        double    thumbOffOpacity;
        QColor    trackOffBrush;
        double    trackOffOpacity;
        QColor    thumbDisabled;
        double    thumbDisabledOpacity;
        QColor    trackDisabled;
        double    trackDisabledOpacity;
        QColor    textColor;
        double    disabledTextOpacity;
        Animation thumbBrushAnimation;
        Animation trackBrushAnimation;
        Animation thumbPosAniamtion;
    };

    inline QPixmap drawShadowEllipse(qreal radius, qreal elevation, const QColor& color)
    {
        auto px = QPixmap(radius * 2, radius * 2);
        px.fill(Qt::transparent);

        { // draw ellipes
            QPainter p(&px);
            p.setBrush(color);
            p.setPen(Qt::NoPen);
            p.setRenderHint(QPainter::Antialiasing, true);
            p.drawEllipse(QRectF(0, 0, px.size().width(), px.size().height()).center(), radius - elevation, radius - elevation);
        }

        QImage tmp(px.size(), QImage::Format_ARGB32_Premultiplied);
        tmp.setDevicePixelRatio(px.devicePixelRatioF());
        tmp.fill(0);
        QPainter tmpPainter(&tmp);
        tmpPainter.setCompositionMode(QPainter::CompositionMode_Source);
        tmpPainter.drawPixmap(QPointF(), px);
        tmpPainter.end();

        // blur the alpha channel
        QImage blurred(tmp.size(), QImage::Format_ARGB32_Premultiplied);
        blurred.setDevicePixelRatio(px.devicePixelRatioF());
        blurred.fill(0);
        {
            QPainter blurPainter(&blurred);
            qt_blurImage(&blurPainter, tmp, elevation * 4., true, false);
        }

        tmp = blurred;
        return QPixmap::fromImage(tmp);
    }

} // namespace Style

#endif // TOGGLE_SWITCH_STYLE_HPP
