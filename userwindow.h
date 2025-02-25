#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QPushButton>
#include <QLabel>
#include <QResizeEvent>
#include <QTimer>
#include <QVector>
#include <QString>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QStandardPaths>
#include <exception>

#include "recounthelper.h"
#include "stylehelper.h"


class UserWindow : public QGraphicsView
{
    Q_OBJECT

public:
    UserWindow();
    ~UserWindow();

private:
    QGraphicsScene *scene;
    QPushButton *plusButton;
    QPushButton *minusButton;
    QPushButton *powerButton;
    QPushButton *airDirectionButton;
    QPushButton *temperatureButton;
    QPushButton *humidityButton;
    QPushButton *atmPressureButton;
    QPushButton *changeThemeMode;
    QMenu *temperatureMenu;
    QMenu *atmPressureMenu;
    QMenu *airflowDirectionMenu;
    QLabel *temperatureValueLabel;
    QLabel *temperatureUnitLabel;
    QLabel *temperatureLabel;
    QLabel *atmPressureValueLabel;
    QLabel *systemLabel;

    QString *defaultValue;

    double *temperatureValue = nullptr;
    double *atmPressureValue = nullptr;
    QString *temperatureUnit;
    QString *atmPressureUnit;

    QGraphicsProxyWidget *proxyTemperatureButton;
    QGraphicsProxyWidget *proxyHumidityButton;
    QGraphicsProxyWidget *proxyAtmPressureButton;
    QGraphicsProxyWidget *proxyPlusButton;
    QGraphicsProxyWidget *proxyTemperatureValueLabel;
    QGraphicsProxyWidget *proxyTemperatureUnit;
    QGraphicsProxyWidget *proxyTemperatureLabel;
    QGraphicsProxyWidget *proxyMinusButton;
    QGraphicsProxyWidget *proxyPowerButton;
    QGraphicsProxyWidget *proxyAirDirectionButton;
    QGraphicsProxyWidget *proxySystemLabel;
    QGraphicsProxyWidget *proxyChangeThemeMode;

    QTimer *timer;

    bool power = false;
    bool themeIsDark = false;

    void resizeEvent(QResizeEvent* event) override;
    void setWidgetsPosition();
    void setLightModeStyle();
    void setDarkModeStyle();
    void readXml();
    void writeXml();
    double getElementXLocation(double xshift, QWidget *element) const;
    double getElementYLocation(double yshift, QWidget *element) const;

public slots:
    void onTemperatureChanged(const QPair<double, QString> new_temperature);
    void onHumidityChanged(const double new_humidity);
    void onAtmPressureChanged(const QPair<double, QString> new_atmPressure);

private slots:
    void slotAlarmTimer();
    void onPowerButtonClicked(bool checked);
    void onTemperActionTriggered();
    void onAtmPresTriggered();
    void onAirflowDirectionTriggered();
    void onChangeThemeModeClicked(bool checked);
    void onPlusMinusButtonClicked();

signals:
    void temperatureChanged(QPair<double, QString> new_temperature);

};

#endif // USERWINDOW_H
