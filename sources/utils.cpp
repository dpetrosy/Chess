#include "utils.hpp"
#include "helpers.hpp"

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

//void setPushButtonIconByTheme(QPushButton* button, bool isDarkTheme, QString lightPixmapStr, QString darkPixmapStr)
//{
//    QPixmap pixmap;

//    if (isDarkTheme)
//        pixmap.load(darkPixmapStr);
//    else
//        pixmap.load(lightPixmapStr);

//    QIcon buttonIcon(pixmap);
//    button->setIcon(buttonIcon);
//    button->setIconSize(pixmap.rect().size());
//}

//void makeWidgetByTheme(QPushButton* button, bool isDarkTheme, QString lightStylePath, QString darkStylePath, QString lightPixmapStr, QString darkPixmapStr)
//{
//    if (!(lightPixmapStr == "" && darkPixmapStr == ""))
//        setPushButtonIconByTheme(button, isDarkTheme, lightPixmapStr, darkPixmapStr);

//    if (!(lightStylePath == "" && darkStylePath == ""))
//        setStyleSheetByTheme(lightStylePath, darkStylePath, button, isDarkTheme);
//}

void setQLabelPictureByTheme(QLabel* label, bool isDarkTheme, QString lightThemePicturePath, QString darkThemePicturePath)
{
    if (isDarkTheme)
        label->setPixmap(QPixmap(darkThemePicturePath));
    else
        label->setPixmap(QPixmap(lightThemePicturePath));
}
