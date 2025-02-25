#include "userwindow.h"
#include "measurementsimulator.h"
#include "stylehelper.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserWindow userWindow;
    MeasurementSimulator measurementSimulator;

    QObject::connect(&measurementSimulator, &MeasurementSimulator::temperatureChanged,
                     &userWindow, &UserWindow::onTemperatureChanged);
    QObject::connect(&measurementSimulator, &MeasurementSimulator::humidityChanged,
                     &userWindow, &UserWindow::onHumidityChanged);
    QObject::connect(&measurementSimulator, &MeasurementSimulator::atmPressureChanged,
                     &userWindow, &UserWindow::onAtmPressureChanged);

    QObject::connect(&userWindow, &UserWindow::temperatureChanged,
                     &measurementSimulator, &MeasurementSimulator::onTemperatureChanged);

    userWindow.show();
    measurementSimulator.show();

    return a.exec();
}
