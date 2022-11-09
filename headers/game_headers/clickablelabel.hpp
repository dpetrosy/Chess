#ifndef CLICKABLELABEL_HPP
#define CLICKABLELABEL_HPP

#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <Qt>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

// 99% delete from here
//public slots:
//    void processLeftButtonClick();

signals:
    void    clickedLeftButton();

private:
    // Mouse press events
    void    mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL_HPP
