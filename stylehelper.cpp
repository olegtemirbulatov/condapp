#include "stylehelper.h"

// light mode
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

QString StyleHelper::lightModeTemperLabelStyle()
{
    return "QLabel#temperatureLabel{" // TemperLabelStyle and units in the center
           "    font-family: Arial; "
           "    font-size: 16px;"
           "    color: #333333; "
           "    background-color: #ffffff;"
           "}";
}

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

QString StyleHelper::lightModeTemperatureValueLabelStyle()
{
    return "QLabel#temperatureValueLabel{" // temperature value in the center
           "    font-family: Arial; "
           "    font-size: 56px;"
           "    color: #333333; "
           "    background-color: #ffffff;"
           "}";
}

QString StyleHelper::lightModeMenuStyle()
{
    return "QMenu{" // menu
           "    width: 170px; "
           "    background-color: #ffffff; "
           "    border: 2px solid #cccccc; "
           "    font-size: 16px;"
           "}";
}

// dark mode
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

QString StyleHelper::darkModeTemperLabelStyle()
{
    return "QLabel#temperatureLabel{" // TemperLabelStyle and units in the center
           "    font-family: Arial; "
           "    font-size: 16px;"
           "    color: #ffffff; "
           "    background-color: #333333;"
           "}";
}

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

QString StyleHelper::darkModeTemperatureValueLabelStyle()
{
    return "QLabel#temperatureValueLabel{" // temperature value in the center
           "    font-family: Arial; "
           "    font-size: 56px;"
           "    color: #ffffff; "
           "    background-color: #333333;"
           "}";
}

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
