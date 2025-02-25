#include <QAction>
#include <QMenu>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>

#include "userwindow.h"

typedef void (UserWindow::*UserWindowMethod)();

void trySaveOrLoadXml(UserWindow* window, UserWindowMethod method)
{
    try
    {
        (window->*method)();
    }
    catch (std::runtime_error& e)
    {
        QMessageBox msgBox = QMessageBox(QMessageBox::Warning,
                                         "Error while opening saved units file",
                                         e.what());
        msgBox.exec();
    }
    catch (std::exception& e)
    {
        QMessageBox msgBox = QMessageBox(QMessageBox::Warning,
                                         "Unknown error while saving or "
                                         "loading used units",
                                         e.what());
        msgBox.exec();
    }
}


UserWindow::UserWindow()
{
    // settings of the window
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setMaximumHeight(768);
    setMinimumHeight(600);
    setMaximumWidth(1024);
    setMinimumWidth(800);

    // Creation QGraphicsScene
    scene = new QGraphicsScene(this);
    setScene(scene);

    // Definitions of saved values
    defaultValue = new QString("--");
    temperatureUnit = new QString();
    atmPressureUnit = new QString();

    // Definitions of buttons
    systemLabel = new QLabel("Кондиционер");
    changeThemeMode = new QPushButton();
    changeThemeMode->setCheckable(true);
    temperatureButton = new QPushButton();
    humidityButton = new QPushButton();
    atmPressureButton = new QPushButton();
    powerButton = new QPushButton();
    powerButton->setCheckable(true);
    airDirectionButton = new QPushButton();
    plusButton = new QPushButton("+");
    minusButton = new QPushButton("-");

    // Definitions of labels
    temperatureValueLabel = new QLabel();
    temperatureValueLabel->setMinimumWidth(160);
    temperatureValueLabel->setMaximumWidth(190);
    temperatureValueLabel->setAlignment(Qt::AlignHCenter);
    temperatureUnitLabel = new QLabel(*temperatureUnit);
    temperatureLabel = new QLabel("Температура");

    // Definitions of menus
    temperatureMenu = new QMenu(temperatureButton);
    atmPressureMenu = new QMenu(atmPressureButton);
    airflowDirectionMenu = new QMenu(airDirectionButton);

    // Adding actions for menus
    QAction *celsius = new QAction("°C", temperatureMenu);
    QAction *fahrenheit = new QAction("°F", temperatureMenu);
    QAction *kelvin = new QAction("K", temperatureMenu);
    QAction *mmHg = new QAction("мм.рт.ст.", atmPressureMenu);
    QAction *pascal = new QAction("Па", atmPressureMenu);
    QAction *_0_30_degrees = new QAction("0°-30°", airflowDirectionMenu);
    QAction *_30_60_degrees = new QAction("30°-60°", airflowDirectionMenu);
    QAction *_60_90_degrees = new QAction("60°-90°", airflowDirectionMenu);

    temperatureMenu->addAction(celsius);
    temperatureMenu->addAction(fahrenheit);
    temperatureMenu->addAction(kelvin);
    atmPressureMenu->addAction(mmHg);
    atmPressureMenu->addAction(pascal);
    airflowDirectionMenu->addAction(_0_30_degrees);
    airflowDirectionMenu->addAction(_30_60_degrees);
    airflowDirectionMenu->addAction(_60_90_degrees);

    temperatureButton->setMenu(temperatureMenu);
    atmPressureButton->setMenu(atmPressureMenu);
    airDirectionButton->setMenu(airflowDirectionMenu);

    // setting styles and icons
    systemLabel->setObjectName("mainLabel");
    changeThemeMode->setObjectName("colorThemeButton");
    temperatureButton->setObjectName("longButton");
    humidityButton->setObjectName("longButton");
    atmPressureButton->setObjectName("longButton");
    plusButton->setObjectName("roundButton");
    minusButton->setObjectName("roundButton");
    temperatureValueLabel->setObjectName("temperatureValueLabel");
    temperatureUnitLabel->setObjectName("temperatureLabel");
    temperatureLabel->setObjectName("temperatureLabel");
    powerButton->setObjectName("longButton");
    airDirectionButton->setObjectName("longButton");

    setLightModeStyle();

    changeThemeMode->setIcon(QIcon(":/icons/icon_dark.png"));
    temperatureButton->setIcon(QIcon(":/icons/icon_temperature.png"));
    humidityButton->setIcon(QIcon(":/icons/icon_humidity.png"));
    atmPressureButton->setIcon(QIcon(":/icons/icon_atmospheric.png"));
    powerButton->setIcon(QIcon(":/icons/icon_power_button.png"));
    airDirectionButton->setIcon(QIcon(":/icons/icon_conditioner.png"));

    changeThemeMode->setIconSize(QSize(32, 32));
    temperatureButton->setIconSize(QSize(32, 32));
    humidityButton->setIconSize(QSize(32, 32));
    atmPressureButton->setIconSize(QSize(32, 32));
    powerButton->setIconSize(QSize(32, 32));
    airDirectionButton->setIconSize(QSize(32, 32));

    // setting connections of buttons and actions
    connect(powerButton, &QPushButton::clicked, this, &UserWindow::onPowerButtonClicked);
    connect(changeThemeMode, &QPushButton::clicked, this, &UserWindow::onChangeThemeModeClicked);
    connect(plusButton, &QPushButton::clicked, this, &UserWindow::onPlusMinusButtonClicked);
    connect(minusButton, &QPushButton::clicked, this, &UserWindow::onPlusMinusButtonClicked);
    connect(celsius, &QAction::triggered, this, &UserWindow::onTemperActionTriggered);
    connect(fahrenheit, &QAction::triggered, this, &UserWindow::onTemperActionTriggered);
    connect(kelvin, &QAction::triggered, this, &UserWindow::onTemperActionTriggered);
    connect(mmHg, &QAction::triggered, this, &UserWindow::onAtmPresTriggered);
    connect(pascal, &QAction::triggered, this, &UserWindow::onAtmPresTriggered);
    connect(_0_30_degrees, &QAction::triggered, this, &UserWindow::onAirflowDirectionTriggered);
    connect(_30_60_degrees, &QAction::triggered, this, &UserWindow::onAirflowDirectionTriggered);
    connect(_60_90_degrees, &QAction::triggered, this, &UserWindow::onAirflowDirectionTriggered);

    // adding widgets to scene using proxy widgets
    proxySystemLabel = scene->addWidget(systemLabel);
    proxyChangeThemeMode = scene->addWidget(changeThemeMode);
    proxyTemperatureButton = scene->addWidget(temperatureButton);
    proxyHumidityButton = scene->addWidget(humidityButton);
    proxyAtmPressureButton = scene->addWidget(atmPressureButton);
    proxyPlusButton = scene->addWidget(plusButton);
    proxyTemperatureValueLabel = scene->addWidget(temperatureValueLabel);
    proxyTemperatureUnit = scene->addWidget(temperatureUnitLabel);
    proxyTemperatureLabel = scene->addWidget(temperatureLabel);
    proxyMinusButton = scene->addWidget(minusButton);
    proxyPowerButton = scene->addWidget(powerButton);
    proxyAirDirectionButton = scene->addWidget(airDirectionButton);

    // set widgets position
    setWidgetsPosition();

    // setting timer for widgets' position resetting
    timer = new QTimer();
    timer->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &UserWindow::slotAlarmTimer);
    timer->start(50);
}

UserWindow::~UserWindow()
{
    //save units for next starting of this program
    if (temperatureUnit && atmPressureUnit)
        trySaveOrLoadXml(this, &UserWindow::writeXml);

    // delete proxy buttons
    delete proxyAirDirectionButton;
    delete proxyPowerButton;
    delete proxyMinusButton;
    delete proxyTemperatureLabel;
    delete proxyTemperatureUnit;
    delete proxyTemperatureValueLabel;
    delete proxyPlusButton;
    delete proxyAtmPressureButton;
    delete proxyHumidityButton;
    delete proxyTemperatureButton;
    delete proxyChangeThemeMode;
    delete proxySystemLabel;

    // delete timer
    delete timer;

    // delete data fields
    delete atmPressureUnit;
    delete temperatureUnit;
    delete atmPressureValue;
    delete temperatureValue;
    delete defaultValue;
}

void UserWindow::slotAlarmTimer()
{
    scene->setSceneRect(0, 0, this->width(), this->height());
    setWidgetsPosition();
}

void UserWindow::setWidgetsPosition()
{
    // label
    proxySystemLabel->setPos(getElementXLocation(0.5, systemLabel), 10);

    // change dark/ligth mode button
    proxyChangeThemeMode->setPos(scene->width() - 70, 20);

    // first row
    proxyTemperatureButton->setPos(getElementXLocation(0.25, temperatureButton),
                                   getElementYLocation(0.25, temperatureButton));
    proxyHumidityButton->setPos(getElementXLocation(0.5, humidityButton),
                                getElementYLocation(0.25, humidityButton));
    proxyAtmPressureButton->setPos(getElementXLocation(0.75, atmPressureButton),
                                   getElementYLocation(0.25, atmPressureButton));

    // second row
    proxyMinusButton->setPos(getElementXLocation(0.25, minusButton),
                             getElementYLocation(0.5, minusButton));
    proxyTemperatureValueLabel->setPos(getElementXLocation(0.5, temperatureValueLabel),
                                       getElementYLocation(0.5, temperatureValueLabel));
    proxyTemperatureUnit->setPos(getElementXLocation(0.5, temperatureValueLabel) +
                                     temperatureValueLabel->width() + 20,
                                 temperatureValueLabel->y());
    proxyTemperatureLabel->setPos(getElementXLocation(0.5, temperatureLabel),
                                  getElementYLocation(0.5, temperatureLabel) + 40);
    proxyPlusButton->setPos(getElementXLocation(0.75, plusButton),
                            getElementYLocation(0.5, plusButton));

    // third row
    proxyPowerButton->setPos(getElementXLocation(0.33, powerButton),
                             getElementYLocation(0.75, powerButton));
    proxyAirDirectionButton->setPos(getElementXLocation(0.67, airDirectionButton),
                                    getElementYLocation(0.75, airDirectionButton));
}

void UserWindow::readXml()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/units.xml";
    if (!QFile::exists(filePath))
    {
        filePath = ":/units_template.xml";
    }
    QFile file(filePath);
    file.open(QFile::ReadOnly | QFile::Text);
    if (!file.isOpen())
        throw std::runtime_error("Can not open file with saved units (units.xml).");

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&file);
    xmlReader.readNext();

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())
        {
            if(xmlReader.name() == "temperature")
            {
                if (temperatureUnit)
                    *temperatureUnit = xmlReader.readElementText();
                else
                    temperatureUnit = new QString(xmlReader.readElementText());
            }
            else if (xmlReader.name() == "pressure")
            {
                if (atmPressureUnit)
                    *atmPressureUnit = xmlReader.readElementText();
                else
                    atmPressureUnit = new QString(xmlReader.readElementText());
            }
        }
        xmlReader.readNext();
    }
    file.close();
}

void UserWindow::writeXml()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    QDir dir;
    if (!dir.exists(filePath))
    {
        dir.mkdir(filePath);
    }
    filePath.append("/units.xml");

    QFile file(filePath);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);

    if (!file.isOpen())
        throw std::runtime_error("Can not open file with saved units (units.xml).");

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("units");

    xmlWriter.writeStartElement("temperature");
    xmlWriter.writeCharacters(*temperatureUnit);
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("pressure");
    xmlWriter.writeCharacters(*atmPressureUnit);
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
    file.close();
}

double UserWindow::getElementXLocation(double xshift, QWidget *element) const
{
    return (this->scene->width() * xshift - (element->width() / 2));
}

double UserWindow::getElementYLocation(double yshift, QWidget *element) const
{
    return (this->scene->height() * yshift - (element->height() / 2));
}

void UserWindow::resizeEvent(QResizeEvent* event)
{
    timer->start(50);
    QGraphicsView::resizeEvent(event);
}

void UserWindow::setLightModeStyle()
{
    scene->setBackgroundBrush(QBrush(QColor().fromRgb(255, 255, 255, 255)));
    systemLabel->setStyleSheet(StyleHelper::lightModeMainLabelStyle());
    changeThemeMode->setStyleSheet(StyleHelper::lightModeChangeThemeModeButtonStyle());
    temperatureButton->setStyleSheet(StyleHelper::lightModeLongButtonStyle());
    humidityButton->setStyleSheet(StyleHelper::lightModeLongButtonStyle());
    atmPressureButton->setStyleSheet(StyleHelper::lightModeLongButtonStyle());
    plusButton->setStyleSheet(StyleHelper::lightModeRoundButtonStyle());
    minusButton->setStyleSheet(StyleHelper::lightModeRoundButtonStyle());
    temperatureValueLabel->setStyleSheet(StyleHelper::lightModeTemperatureValueLabelStyle());
    temperatureUnitLabel->setStyleSheet(StyleHelper::lightModeTemperLabelStyle());
    temperatureLabel->setStyleSheet(StyleHelper::lightModeTemperLabelStyle());
    powerButton->setStyleSheet(StyleHelper::lightModeLongButtonStyle());
    airDirectionButton->setStyleSheet(StyleHelper::lightModeLongButtonStyle());
    temperatureMenu->setStyleSheet(StyleHelper::lightModeMenuStyle());
    atmPressureMenu->setStyleSheet(StyleHelper::lightModeMenuStyle());
    airflowDirectionMenu->setStyleSheet(StyleHelper::lightModeMenuStyle());
}

void UserWindow::setDarkModeStyle()
{
    scene->setBackgroundBrush(QBrush(QColor().fromRgb(51, 51, 51, 255)));
    systemLabel->setStyleSheet(StyleHelper::darkModeMainLabelStyle());
    changeThemeMode->setStyleSheet(StyleHelper::darkModeChangeThemeModeButtonStyle());
    temperatureButton->setStyleSheet(StyleHelper::darkModeLongButtonStyle());
    humidityButton->setStyleSheet(StyleHelper::darkModeLongButtonStyle());
    atmPressureButton->setStyleSheet(StyleHelper::darkModeLongButtonStyle());
    plusButton->setStyleSheet(StyleHelper::darkModeRoundButtonStyle());
    minusButton->setStyleSheet(StyleHelper::darkModeRoundButtonStyle());
    temperatureValueLabel->setStyleSheet(StyleHelper::darkModeTemperatureValueLabelStyle());
    temperatureUnitLabel->setStyleSheet(StyleHelper::darkModeTemperLabelStyle());
    temperatureLabel->setStyleSheet(StyleHelper::darkModeTemperLabelStyle());
    powerButton->setStyleSheet(StyleHelper::darkModeLongButtonStyle());
    airDirectionButton->setStyleSheet(StyleHelper::darkModeLongButtonStyle());
    temperatureMenu->setStyleSheet(StyleHelper::darkModeMenuStyle());
    atmPressureMenu->setStyleSheet(StyleHelper::darkModeMenuStyle());
    airflowDirectionMenu->setStyleSheet(StyleHelper::darkModeMenuStyle());
}

void UserWindow::onTemperActionTriggered()
{
    if (power)
    {
        QAction *action = qobject_cast<QAction*>(QObject::sender());
        if (*temperatureUnit != action->text())
        {
            QString prevTemperUnit = *temperatureUnit;
            *temperatureUnit = action->text();
            temperatureUnitLabel->setText(*temperatureUnit);
            if (temperatureValue)
            {
                *temperatureValue = RecountHelper::recountTemperature(qMakePair(*temperatureValue, prevTemperUnit), *temperatureUnit);
                QString value_to_be_set = QString::number(RecountHelper::roundToOneDecimal(*temperatureValue));
                temperatureValueLabel->setText(value_to_be_set);
                temperatureButton->setText(value_to_be_set + " " + *temperatureUnit);
            }
            else
            {
                temperatureButton->setText(*defaultValue + *temperatureUnit);
            }
        }
    }
}

void UserWindow::onAtmPresTriggered()
{
    if (power)
    {
        QAction *action = qobject_cast<QAction*>(QObject::sender());
        if (*atmPressureUnit != action->text())
        {
            QString prevAtmPresUnit = *temperatureUnit;
            *atmPressureUnit = action->text();
            if (atmPressureValue)
            {
                *atmPressureValue = RecountHelper::recountAtmPressure(qMakePair(*atmPressureValue, prevAtmPresUnit), *atmPressureUnit);
                atmPressureButton->setText(QString::number(RecountHelper::roundToOneDecimal(*atmPressureValue)) + " " + *atmPressureUnit);
            }
            else
            {
                atmPressureButton->setText(*defaultValue + *atmPressureUnit);
            }
        }
    }
}

void UserWindow::onAirflowDirectionTriggered()
{
    if (power)
    {
        QAction *action = qobject_cast<QAction*>(QObject::sender());
        airDirectionButton->setText(action->text());
    }
}

void UserWindow::onChangeThemeModeClicked(bool checked)
{
    themeIsDark = checked;
    if (themeIsDark)
    {
        changeThemeMode->setIcon(QIcon(":/icons/icon_light.png"));
        setDarkModeStyle();
    }
    else
    {
        changeThemeMode->setIcon(QIcon(":/icons/icon_dark.png"));
        setLightModeStyle();
    }
    changeThemeMode->setIconSize(QSize(32, 32));
}

void UserWindow::onPowerButtonClicked(bool checked)
{
    power = checked;
    if (power)
    {
        trySaveOrLoadXml(this, &UserWindow::readXml);
        temperatureValueLabel->setText(*defaultValue);
        temperatureButton->setText(*defaultValue + *temperatureUnit);
        temperatureUnitLabel->setText(*temperatureUnit);
        humidityButton->setText(*defaultValue + "%");
        atmPressureButton->setText(*defaultValue + *atmPressureUnit);
        airDirectionButton->setText("0°-90°");
    }
    else
    {
        trySaveOrLoadXml(this, &UserWindow::writeXml);
        delete temperatureValue;
        delete atmPressureValue;
        delete temperatureUnit;
        delete atmPressureUnit;
        temperatureValue = nullptr;
        atmPressureValue = nullptr;
        temperatureUnit = nullptr;
        atmPressureUnit = nullptr;
        temperatureValueLabel->setText("");
        temperatureUnitLabel->setText("");
        temperatureButton->setText("");
        humidityButton->setText("");
        atmPressureButton->setText("");
        airDirectionButton->setText("");
    }
}

void UserWindow::onTemperatureChanged(QPair<double, QString> new_temperature)
{
    if (power)
    {
        if (temperatureValue) *temperatureValue = RecountHelper::recountTemperature(new_temperature, *temperatureUnit);
        else temperatureValue = new double(RecountHelper::recountTemperature(new_temperature, *temperatureUnit));

        QString value_to_be_set = QString::number(RecountHelper::roundToOneDecimal(*temperatureValue));
        temperatureValueLabel->setText("");
        temperatureButton->setText("");
        temperatureValueLabel->setText(value_to_be_set);
        temperatureButton->setText(value_to_be_set + " " + *temperatureUnit);
    }
}

void UserWindow::onHumidityChanged(const double new_humidity)
{
    if (power)
    {
        QString text_to_be_set = QString::number(new_humidity) + " %";
        humidityButton->setText("");
        humidityButton->setText(text_to_be_set);
    }
}

void UserWindow::onAtmPressureChanged(QPair<double, QString> new_atmPressure)
{
    if (power)
    {
        if (atmPressureValue) *atmPressureValue = RecountHelper::recountAtmPressure(new_atmPressure, *atmPressureUnit);
        else atmPressureValue = new double(RecountHelper::recountAtmPressure(new_atmPressure, *atmPressureUnit));

        QString text_to_be_set = QString::number(RecountHelper::roundToOneDecimal(*atmPressureValue)) + " " + *atmPressureUnit;
        atmPressureButton->setText("");
        atmPressureButton->setText(text_to_be_set);
    }
}

void UserWindow::onPlusMinusButtonClicked()
{
    if (power && temperatureValue)
    {
        QPushButton *button = qobject_cast<QPushButton*>(QObject::sender());
        if (button->text() == "-")       *temperatureValue -= 0.1;
        else if (button->text() == "+")  *temperatureValue += 0.1;

        QString value_to_be_set = QString::number(RecountHelper::roundToOneDecimal(*temperatureValue));
        temperatureValueLabel->setText(value_to_be_set);
        temperatureButton->setText(value_to_be_set + " " + *temperatureUnit);
        emit temperatureChanged(qMakePair(*temperatureValue, *temperatureUnit));
    }
}


