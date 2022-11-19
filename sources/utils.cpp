#include "utils.hpp"

void setPushButtonSize(QPushButton *button, int width, int height)
{
    button->setSizeIncrement(width, height);
    button->setMinimumSize(width, height);
}

void setPushButtonFont(QPushButton *button, int font)
{
    QFont buttonFont = button->font();
    buttonFont.setPointSize(font);
    button->setFont(buttonFont);
}

void setLabelTextFont(QLabel* label, int font)
{
    QFont buttonFont = label->font();
    buttonFont.setPointSize(font);
    label->setFont(buttonFont);
}
