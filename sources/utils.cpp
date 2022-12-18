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

void setStyleSheet(QString path, QWidget* obj)
{
    QFile file;
    file.setFileName(path);
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    obj->setStyleSheet(styleSheet);
    file.close();
}

void setStyleSheetByTheme(QString lightStylePath, QString darkStylePath, QWidget* obj, bool isDarkTheme)
{
    QFile file;

    if (isDarkTheme)
        file.setFileName(darkStylePath);
    else
        file.setFileName(lightStylePath);

    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    obj->setStyleSheet(styleSheet);
    file.close();
}

QString removeUnderscoreInString(QString str)
{
    for (auto it = str.begin(); it != str.end(); ++it)
        if (*it == '_')
            *it = ' ';
    return str;
}

void setQLabelPictureByTheme(QLabel* label, bool isDarkTheme, QString lightThemePicturePath, QString darkThemePicturePath)
{
    if (isDarkTheme)
        label->setPixmap(QPixmap(darkThemePicturePath));
    else
        label->setPixmap(QPixmap(lightThemePicturePath));
}

void copyVector2D(CharVector2D& dest, CharVector2D& source, int size)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            dest[i][j] = source[i][j];
}

void resetCharVector2D(CharVector2D& vector2D, int size, char symbol)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            vector2D[i][j] = symbol;
}
