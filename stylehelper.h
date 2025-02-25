#ifndef STYLEHELPER_H
#define STYLEHELPER_H

#include <QString>

/// Вспомогательный класс для установки стилей
/*!
    Класс содержит статические методы для добавления стилей для элементов основного окна.
*/
class StyleHelper
{
public:
    static QString lightModeLongButtonStyle();
    static QString lightModeRoundButtonStyle();
    static QString lightModeChangeThemeModeButtonStyle();
    static QString lightModeTemperLabelStyle();
    static QString lightModeMainLabelStyle();
    static QString lightModeTemperatureValueLabelStyle();
    static QString lightModeMenuStyle();

    static QString darkModeLongButtonStyle();
    static QString darkModeRoundButtonStyle();
    static QString darkModeChangeThemeModeButtonStyle();
    static QString darkModeTemperLabelStyle();
    static QString darkModeMainLabelStyle();
    static QString darkModeTemperatureValueLabelStyle();
    static QString darkModeMenuStyle();
};

#endif // STYLEHELPER_H
