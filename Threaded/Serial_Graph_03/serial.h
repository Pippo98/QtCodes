#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QVector>
#include <QQmlProperty>
#include <QQmlEngine>

#include <QThread>

#include "backend.h"

class serial : public QThread
{
    Q_OBJECT
public:
    explicit serial(QObject *parent = nullptr);
    ~serial() override;

    bool deInit();
    void parseCan();
    void parseData();
    void connection();
    void detectGraphs();
    void setLogState(bool);
    void updateGraphsNames();
    void restartSequence();
    void canSniffer();

    bool init();
    bool isSerialOpened();

    void displayHelp();

    //function used for the thread
    void run() override;

public:
    int baudRateSelected;
    int serialPortIndex;
    int serialPortBaudrate;

    QVector<int> requestedGraphs;

    QString serialPortSelected;
    //QSerialPort * serialPort;
    QStringList serialPorts;

public slots:
    QStringList detectPort();
    QStringList getSwitchNames();
    QString portInfo(QString port);
    QStringList getSecondarySwitchNames(int);
    QVector<int> getSecondarySwitchesSelections(int);
    void setSecondarySwitchesSelections(int, int, int);
    void setPrimarySwitches(int, int);

    void sendCommand(QString);

    bool getCanMode();
    void setCanMode(int);
    void manageFunctions();
    void initTextArea(QObject *);
    void initTextField(QObject *);
    void initInfoTextArea(QObject *);

    void displayPerformanceInfo();

signals:
    void dataChanged(QString data);
};

#endif // SERIAL_H
