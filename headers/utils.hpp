#ifndef UTILS_HPP
#define UTILS_HPP

#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QFile>

#include "pieces_helpers.hpp"

void     setPushButtonSize(QPushButton *button, int width, int height);
void     setPushButtonFont(QPushButton *button, int font);
void     setLabelTextFont(QLabel* label, int font);
void     setStyleSheet(QString path, QWidget* obj);
void     setStyleSheetByTheme(QString lightStylePath, QString darkStylePath, QWidget* obj, bool isDarkTheme);
QString  removeUnderscoreInString(QString str);
void     setQLabelPictureByTheme(QLabel* label, bool isDarkTheme, QString lightThemePicturePath, QString darkThemePicturePath);
void     copyVector2D(CharVector2D& dest, CharVector2D& source, int size);
void     resetCharVector2D(CharVector2D& vector2D, int size, char symbol);

#endif // UTILS_HPP
