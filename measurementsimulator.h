#ifndef MEASUREMENTSIMULATOR_H
#define MEASUREMENTSIMULATOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

/// Класс дополнительного окна (симулятор входных значений)
/*!
    Класс окна, через который можно симулировать входные значения в систему управления кондиционированием.
*/
class MeasurementSimulator : public QWidget
{
    Q_OBJECT

private:
    QVBoxLayout *mainLayout;        /// Основной макет
    QGridLayout *gridLayout;        /// Дополнительный макет для размещения меток, полей ввода и comboBox'ов на окне
    QPushButton *applyButton;       /// Кнопка для отправки показаний в систему
    QLineEdit *temperatureEdit;     /// Поле для ввода температуры
    QLineEdit *humidityEdit;        /// Поле для ввода влажности
    QLineEdit *pressureEdit;        /// Поле для ввода атмосферного давления
    QComboBox *temperatureUnit;     /// КомбоБокс для выбора единицы измерения температуры
    QComboBox *atmPressureUnit;     /// КомбоБокс для выбора единицы измерения атмосферного давления

    void applyChanges();

public:
    MeasurementSimulator(QWidget *parent = nullptr);
    ~MeasurementSimulator() = default;

public slots:
    void onTemperatureChanged(const QPair<double, QString> &new_temperature);

signals:
    void temperatureChanged(const QPair<double, QString> &new_temperature);
    void humidityChanged(const double &new_humidity);
    void atmPressureChanged(const QPair<double, QString> &new_atmPressure);
};

#endif // MEASUREMENTSIMULATOR_H
