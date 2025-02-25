#include <cmath>

#include "recounthelper.h"


/*!
Метод для пересчета температуры из одной единицы измерения в другую.
\param[in] new_temperature Пара нового значения и единицы измерения температуры
\param[in] current_unit Текущая единица измерения температуры
\return Пересчитанное значение температуры
*/
double RecountHelper::recountTemperature(const QPair<double, QString> &new_temperature, const QString &current_unit)
{
    if (current_unit != new_temperature.second)
    {
        if (current_unit == "°C")
        {
            if (new_temperature.second == "°F")
                return (new_temperature.first - 32.) * 5. / 9.;
            else if (new_temperature.second == "K")
                return new_temperature.first - 273.16;
        }
        else if (current_unit == "°F")
        {
            if (new_temperature.second == "°C")
                return (9. / 5.) * new_temperature.first + 32.;
            else if (new_temperature.second == "K")
                return (9. / 5.) * (new_temperature.first - 273.16) + 32.;
        }
        else if (current_unit == "K")
        {
            if (new_temperature.second == "°C")
                return new_temperature.first + 273.16;
            else if (new_temperature.second == "°F")
                return (5. / 9.) * (new_temperature.first - 32.) + 273.16;
        }
    }

    return new_temperature.first;
}

/*!
Метод для пересчета атмосферного давления из одной единицы измерения в другую.
\param[in] new_temperature Пара нового значения и единицы измерения атмосферного давления
\param[in] current_unit Текущая единица измерения атмосферного давления
\return Пересчитанное значение атмосферного давления
*/
double RecountHelper::recountAtmPressure(const QPair<double, QString> &new_atmPressure, const QString &current_unit)
{
    if (current_unit != new_atmPressure.second)
    {
        if (current_unit == "мм.рт.ст.")
        {
            return new_atmPressure.first / 133.32;
        }
        else if (current_unit == "Па")
        {
            return new_atmPressure.first * 133.32;
        }
    }

    return new_atmPressure.first;
}

/*!
Метод для округления числа до 1 значения после запятой.
\param[in] value Число, которое нужно округлить
\return Число, округленное до 1 знака после запятой
*/
double RecountHelper::roundToOneDecimal(const double &value)
{
    double result_value = value * 10;
    result_value = std::round(result_value);
    result_value /= 10;
    return result_value;
}
