#pragma once

#include <QtWidgets/QMainWindow>
#include <qframe.h>
#include "ui_FlowManager.h"
#include "FlowManager/NameDataLoader.h"
#include "FlowManager/SettingsLoader.h"

class FlowManager : public QMainWindow
{
    Q_OBJECT

public:
    FlowManager(QWidget *parent = nullptr);
    ~FlowManager() = default;
signals:
    void StuChangeStateSignal(int stateIndex, int StuIndex);
private slots:
    void StuClicked();
    void StuChangeState(int stateIndex, int StuIndex);
private:
    Ui::FlowManager* ui = new Ui::FlowManager;

    fm2::ConfigLoader* configLoader = new fm2::ConfigLoader();
    fm2::ConfigLoader* dataLoader = new fm2::ConfigLoader();
    
    std::vector<std::string> dstStyleMap = {};
    std::vector<std::string> stateName   = {};
    std::vector<std::string> periodName  = {};
    std::vector<bool> stateTag_at_class  = {};
    std::vector<bool> stateTag_at_school = {};
    std::vector<bool> stateTag_attend    = {};

    template <typename T>
    T getConfig(
        std::vector<std::string> path, 
        fm2::ConfigLoader* loader,
        std::string file_name
    );

    void loadDstStyMap();
    void loadStateName();
    void loadNameData();
    void loadStateTag();
    void loadStuData();
    void loadPeriodName();
    QMenu* initMenu(QList<QTextEdit*> textEditors, int StuIndex);

    void putDestinationButtons(QFrame* frame);
    void putButtons(QFrame* frameStudent, int num);
    void putChangeColorComboBox(QWidget* widget);
    void putTimePeriodChangeComboBox(QWidget* widget);

    std::vector<std::string> getClassNameData(int classIndex, int grade=26);

    void refreshStuFrame();
    void refreshDstFrame();
    void refreshStuData();

    void Count();
    void ChangeColor(int stateIndex);
    void ChangePeriod(int periodIndex);

    int currentClass = 2601;
    int currentIndex = 1;
    int currentPeriod = 0;

    std::vector<int> StuData;
    QComboBox* changeColorComboBox;
    QComboBox* changeTimePeriodComboBox;
};

    
