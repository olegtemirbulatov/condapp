#include "stylehelper.h"


/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах светлой темы.
Используется для установки стилей на кнопках:
- Температуры
- Влажности
- Атмосферного давления
- Включения/выключения системы
- Управления потоком воздуха
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::lightModeLongButtonStyle()
{
    return "QPushButton#longButton{" // first row button
           "    width: 170px; "
           "    height: 50px; "
           "    background-color: #ffffff; "
           "    border: 2px solid #cccccc; "
           "    border-radius: 25px; "
           "    font-size: 16px;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах светлой темы.
Используется для установки стилей на кнопках увеличения и уменьшения температуры.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::lightModeRoundButtonStyle()
{
    return "QPushButton#roundButton{" // round button
           "    width: 80px; "
           "    height: 80px; "
           "    background-color: #ffffff; "
           "    border: 2px solid #cccccc; "
           "    border-radius: 40px; "
           "    font-size: 40px;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах светлой темы.
Используется для установки стилей на кнопке изменения цветовой темы.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::lightModeChangeThemeModeButtonStyle()
{
    return "QPushButton#colorThemeButton{" // changeThemeModeButton
           "    width: 50px; "
           "    height: 50px; "
           "    background-color: #ffffff; "
           "    border: 2px solid #cccccc; "
           "    border-radius: 10px; "
           "    font-size: 16px;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах светлой темы.
Используется для установки стиля на метках подписи "температура" и отображения единицы измерения температуры в центре главного окна.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::lightModeTemperLabelStyle()
{
    return "QLabel#temperatureLabel{" // TemperLabelStyle and units in the center
           "    font-family: Arial; "
           "    font-size: 16px;"
           "    color: #333333; "
           "    background-color: #ffffff;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах светлой темы.
Используется для установки стиля на заголовке "Кондиционер" основного окна
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::lightModeMainLabelStyle()
{
    return "QLabel#mainLabel{" // main label
           "    font-family: Arial; "
           "    font-size: 24px; "
           "    font-weight: bold; "
           "    color: #333333; "
           "    background-color: #ffffff;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах светлой темы.
Используется для установки стиля на метке со значением температуры в центре основного окна.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::lightModeTemperatureValueLabelStyle()
{
    return "QLabel#temperatureValueLabel{" // temperature value in the center
           "    font-family: Arial; "
           "    font-size: 56px;"
           "    color: #333333; "
           "    background-color: #ffffff;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах светлой темы.
Используется для установки стиля на опциях меню под кнопками температуры, давления и направления воздуха.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::lightModeMenuStyle()
{
    return "QMenu{" // menu
           "    width: 170px; "
           "    background-color: #ffffff; "
           "    border: 2px solid #cccccc; "
           "    font-size: 16px;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах темной темы.
Используется для установки стилей на кнопках:
- Температуры
- Влажности
- Атмосферного давления
- Включения/выключения системы
- Управления потоком воздуха
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::darkModeLongButtonStyle()
{
    return "QPushButton#longButton{" // first row button
           "    width: 170px; "
           "    height: 50px; "
           "    background-color: #333333; "
           "    border: 2px solid #555555; "
           "    border-radius: 25px; "
           "    font-size: 16px;"
           "    color: #ffffff;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах темной темы.
Используется для установки стилей на кнопках увеличения и уменьшения температуры.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::darkModeRoundButtonStyle()
{
    return "QPushButton#roundButton{" // round button
           "    width: 80px; "
           "    height: 80px; "
           "    background-color: #333333; "
           "    border: 2px solid #555555; "
           "    border-radius: 40px; "
           "    font-size: 40px;"
           "    color: #ffffff;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах темной темы.
Используется для установки стилей на кнопке изменения цветовой темы.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::darkModeChangeThemeModeButtonStyle()
{
    return "QPushButton#colorThemeButton{" // changeThemeModeButton
           "    width: 50px; "
           "    height: 50px; "
           "    background-color: #333333; "
           "    border: 2px solid #555555; "
           "    border-radius: 10px; "
           "    font-size: 16px;"
           "    color: #ffffff;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах темной темы.
Используется для установки стиля на метках подписи "температура" и отображения единицы измерения температуры в центре главного окна.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::darkModeTemperLabelStyle()
{
    return "QLabel#temperatureLabel{" // TemperLabelStyle and units in the center
           "    font-family: Arial; "
           "    font-size: 16px;"
           "    color: #ffffff; "
           "    background-color: #333333;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах темной темы.
Используется для установки стиля на заголовке "Кондиционер" основного окна
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::darkModeMainLabelStyle()
{
    return "QLabel#mainLabel{" // main label
           "    font-family: Arial; "
           "    font-size: 24px; "
           "    font-weight: bold; "
           "    color: #ffffff; "
           "    background-color: #333333;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах темной темы.
Используется для установки стиля на метке со значением температуры в центре основного окна.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::darkModeTemperatureValueLabelStyle()
{
    return "QLabel#temperatureValueLabel{" // temperature value in the center
           "    font-family: Arial; "
           "    font-size: 56px;"
           "    color: #ffffff; "
           "    background-color: #333333;"
           "}";
}

/*!
Метод, возвращающий строку в формате StyleSheet для установки стиля в тонах темной темы.
Используется для установки стиля на опциях меню под кнопками температуры, давления и направления воздуха.
\return Строка типа QString в формате StyleSheet
*/
QString StyleHelper::darkModeMenuStyle()
{
    return "QMenu{" // menu
           "    width: 170px; "
           "    background-color: #333333; "
           "    border: 2px solid #555555; "
           "    font-size: 16px;"
           "    color: #ffffff;"
           "}";
}
