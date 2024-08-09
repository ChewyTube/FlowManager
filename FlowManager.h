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
private slots:
    // void StuClicked();
private:
    Ui::FlowManager* ui = new Ui::FlowManager;

    fm2::ConfigLoader* configLoader = new fm2::ConfigLoader();
    fm2::NameDataLaoder* nameDataLoader = new fm2::NameDataLaoder(".//Resources", 26);
    
    std::vector<std::string> dstStyleMap = {};
    std::vector<std::string> stateName = {};

    template <typename T>
    T getConfig(
        std::vector<std::string> path, 
        fm2::ConfigLoader* loader,
        std::string file_name
    );

    void loadDstStyMap();
    void loadStateName();

    void putDestinationButtons(QFrame* frame);
    /*
    void putButtons(QFrame* frameStudent, int num);
    void putChangeColorComboBox(QWidget* widget);

    void refresh();
    void Count();

    void loadDataFromConstants();
    void initStuData();

    NameDataLaoder* loader = new NameDataLaoder(".//Resources", 26);
    std::vector<int> StuData{};
    std::vector<std::string> stateName_;
    std::vector<std::string> destinationStyleMap_;
    std::vector<bool> stateTag_AtClass_;
    std::vector<bool> stateTag_Attend_;
    int classNumber_ = 0;
    int currtenPeriod_ = 0;

    */
};

    
