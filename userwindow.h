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
#include <QString>

/// Класс основного окна
/*!
    Класс окна, через который пользователь взаимодействует с программой для настройки системы кондиционирования
*/
class UserWindow : public QGraphicsView
{
    Q_OBJECT

public:
    UserWindow();
    ~UserWindow();

private:
    QGraphicsScene *scene;              /// Сцена, в которой содержатся основные элементы интерфейса
    QPushButton *plusButton;            /// Кнопка, регулирующая температуру. Прибавляет температуру на 0.1 <ед. изм.>
    QPushButton *minusButton;           /// Кнопка, регулирующая температуру. Убавляет температуру на 0.1 <ед. изм.>
    QPushButton *powerButton;           /// Кнопка включения/выключения системы
    QPushButton *airDirectionButton;    /// Кнопка для настройки управления потоком воздуха
    QPushButton *temperatureButton;     /// Кнопка для настройки единиц измерения температуры. Также отображает текущее значение температуры
    QPushButton *humidityButton;        /// Отображение значения влажности. Сделана в виде кнопки для единообразия интерфейса. Никакой функции при нажатии не выполняет
    QPushButton *atmPressureButton;     /// Кнопка для настройки единиц измерения атмосферного давления. Также отображает текущее значение давления
    QPushButton *changeThemeMode;       /// Кнопка для переключения темы (светлая/темная)
    QMenu *temperatureMenu;             /// Меню для выбора единиц измерения температуры
    QMenu *atmPressureMenu;             /// Меню для выбора единиц измерения атмосферного давления
    QMenu *airflowDirectionMenu;        /// Меню для выбора направления воздуха
    QLabel *temperatureValueLabel;      /// Метка со значением температуры
    QLabel *temperatureUnitLabel;       /// Метка со значением единицы измерения температуры
    QLabel *temperatureLabel;           /// Метка "температура"
    QLabel *systemLabel;                /// Название системы "Кондиционер"

    QString *defaultValue;              /// Пустое значение. Нужно для отображения включенного состояния системы, которая готова принимать значения из окна, симулирующего входные значения

    double *temperatureValue = nullptr; /// Значение температуры
    double *atmPressureValue = nullptr; /// Значение атмосферного давления
    QString *temperatureUnit;           /// Текущая единица измерения температуры
    QString *atmPressureUnit;           /// Текущая единица измерения атмосферного давления

    QGraphicsProxyWidget *proxyTemperatureButton;       /// Прокси кнопка для добавления в scene
    QGraphicsProxyWidget *proxyHumidityButton;          /// Прокси кнопка для добавления в scene
    QGraphicsProxyWidget *proxyAtmPressureButton;       /// Прокси кнопка для добавления в scene
    QGraphicsProxyWidget *proxyPlusButton;              /// Прокси кнопка для добавления в scene
    QGraphicsProxyWidget *proxyTemperatureValueLabel;   /// Прокси метка для добавления в scene
    QGraphicsProxyWidget *proxyTemperatureUnit;         /// Прокси метка для добавления в scene
    QGraphicsProxyWidget *proxyTemperatureLabel;        /// Прокси метка для добавления в scene
    QGraphicsProxyWidget *proxyMinusButton;             /// Прокси кнопка для добавления в scene
    QGraphicsProxyWidget *proxyPowerButton;             /// Прокси кнопка для добавления в scene
    QGraphicsProxyWidget *proxyAirDirectionButton;      /// Прокси кнопка для добавления в scene
    QGraphicsProxyWidget *proxySystemLabel;             /// Прокси метка для добавления в scene
    QGraphicsProxyWidget *proxyChangeThemeMode;         /// Прокси кнопка для добавления в scene

    QTimer *timer;              /// Таймер для переотрисовки сцены. Срабатывает каждые 50 мс

    bool power = false;         /// Состояние системы (true = включена, false = выключена)
    bool themeIsDark = false;   /// Текущая цветовая тема системы (false = светлая, true = темная)

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
