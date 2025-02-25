#ifndef RECOUNTHELPER_H
#define RECOUNTHELPER_H

#include <QPair>
#include <QString>

/// Вспомогательный класс для пересчета
/*!
    Класс со статическими методами для пересчета значений температуры и атмосферного давления из одной единицы измерения в другую.
    Дополнительно содержит метод для округления до 1 значения после запятой для отображения на основном окне.
*/
class RecountHelper
{
public:
    static double recountTemperature(const QPair<double, QString> &new_temperature, const QString &current_unit);
    static double recountAtmPressure(const QPair<double, QString> &new_atmPressure, const QString &current_unit);
    static double roundToOneDecimal(const double &value);
};

#endif // RECOUNTHELPER_H
