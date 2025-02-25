#ifndef MEASUREMENTSIMULATOR_H
#define MEASUREMENTSIMULATOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>


class MeasurementSimulator : public QWidget
{
    Q_OBJECT

public:
    MeasurementSimulator(QWidget *parent = nullptr);
    ~MeasurementSimulator() = default;

public slots:
    void onTemperatureChanged(QPair<double, QString> new_temperature);

private:
    QVBoxLayout *mainLayout;
    QGridLayout *gridLayout;
    QPushButton *applyButton;
    QLineEdit *temperatureEdit;
    QLineEdit *humidityEdit;
    QLineEdit *pressureEdit;
    QComboBox *temperatureUnit;
    QComboBox *atmPressureUnit;

    void applyChanges();

signals:
    void temperatureChanged(QPair<double, QString> new_temperature);
    void humidityChanged(double new_humidity);
    void atmPressureChanged(QPair<double, QString> new_atmPressure);
};

#endif // MEASUREMENTSIMULATOR_H
