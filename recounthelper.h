#ifndef RECOUNTHELPER_H
#define RECOUNTHELPER_H

#include <QPair>
#include <QString>

class RecountHelper
{
public:
    static double recountTemperature(const QPair<double, QString> &new_temperature, const QString &current_unit);
    static double recountAtmPressure(const QPair<double, QString> &new_atmPressure, const QString &current_unit);
    static double roundToOneDecimal(const double &value);
};

#endif // RECOUNTHELPER_H
