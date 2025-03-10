#include <QLabel>
#include <QString>
#include <QPair>
#include <QFormLayout>
#include "recounthelper.h"

#include "measurementsimulator.h"


/*!
Конструктор класса MeasurementSimulator.
В конструкторе:
- Определяются кнопки, метки и комбобоксы для выбора единиц измерения
- Настраивается соединение сигнала нажатия кнопки "Применить" со слотом applyChanges
*/
MeasurementSimulator::MeasurementSimulator(QWidget *parent)
    : QWidget{parent}
{
    mainLayout = new QVBoxLayout(this);
    gridLayout = new QGridLayout();

    temperatureEdit = new QLineEdit(this);
    humidityEdit = new QLineEdit(this);
    pressureEdit = new QLineEdit(this);

    temperatureUnit = new QComboBox(this);
    temperatureUnit->addItem("°C");
    temperatureUnit->addItem("°F");
    temperatureUnit->addItem("K");
    temperatureUnit->setCurrentIndex(0);

    atmPressureUnit = new QComboBox(this);
    atmPressureUnit->addItem("мм.рт.ст.");
    atmPressureUnit->addItem("Па");
    atmPressureUnit->setCurrentIndex(0);

    gridLayout->addWidget(new QLabel("Температура:"), 0, 0);
    gridLayout->addWidget(temperatureEdit, 0, 1);
    gridLayout->addWidget(temperatureUnit, 0, 2);

    gridLayout->addWidget(new QLabel("Влажность:"), 1, 0);
    gridLayout->addWidget(humidityEdit, 1, 1);
    gridLayout->addWidget(new QLabel("%"), 1, 2);

    gridLayout->addWidget(new QLabel("Давление:"), 2, 0);
    gridLayout->addWidget(pressureEdit, 2, 1);
    gridLayout->addWidget(atmPressureUnit, 2, 2);

    applyButton = new QPushButton("Применить", this);
    connect(applyButton, &QPushButton::clicked, this, &MeasurementSimulator::applyChanges);

    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(applyButton);
    setLayout(mainLayout);

    setWindowTitle("Симулятор входных значений");
    resize(300, 200);
}

/*!
Слот для отправки симулированных значений на вход системы кондиционирования.
Вызывает сигналы temperatureChanged, humidityChanged, atmPressureChanged с передаваемыми значениями.
*/
void MeasurementSimulator::applyChanges()
{
    QPair<double, QString> temperature = qMakePair(temperatureEdit->text().toDouble(),
                                                   temperatureUnit->currentText());
    QPair<double, QString> atmPressure = qMakePair(pressureEdit->text().toDouble(),
                                                   atmPressureUnit->currentText());

    emit temperatureChanged(temperature);
    emit humidityChanged(humidityEdit->text().toDouble());
    emit atmPressureChanged(atmPressure);
}

/*!
Слот для изменения температуры в окне MeasurementSimulator'а.
\param[in] new_temperature Значение температуры, которое было настроено на основном окне
*/
void MeasurementSimulator::onTemperatureChanged(const QPair<double, QString> &new_temperature)
{
    temperatureEdit->setText(QString::number(RecountHelper::recountTemperature(new_temperature, temperatureUnit->currentText())));
}
