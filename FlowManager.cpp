#include "FlowManager.h"

#include <qboxlayout.h>
#include <qcombobox.h>
#include <qdebug.h>


FlowManager::FlowManager(QWidget *parent)
    : QMainWindow(parent)
{
    configLoader->LoadConfigFile("config.yaml", "config");
    
    if (!getConfig<bool>({ "nogui" }, configLoader)) {
        ui->setupUi(this);
    }
    // loadDataFromConstants();
    // initStuData();
    // 
    // putButtons(ui->Students, 1);
    // putDestinationButtons(ui->Destination);
    // putChangeColorComboBox(ui->Settings);
}
template <typename T>
T FlowManager::getConfig(std::vector<std::string> path, fm2::ConfigLoader* loader) {
    T value;
    if (!loader->getValue("config", path, &value)) {
        std::string whole_path = "";
        for (auto s : path) {
            whole_path += s;
        }
        throw std::runtime_error(std::string("without ") + whole_path + std::string(" config"));
    }
    return value;
}

/*
void FlowManager::loadDataFromConstants() {
    fm2::Constants::Init();
    auto ins = fm2::Constants::Instance();

    stateName_ = ins->stateName;
    destinationStyleMap_ = ins->destinationStyleMap;
    classNumber_ = ins->classNumber;
    stateTag_AtClass_   = ins->stateTag_AtClass;
    stateTag_Attend_ = ins->stateTag_Attend;
}

void FlowManager::putButtons(QFrame* frameStudent, int num) {
    QVBoxLayout layout(frameStudent);
    auto data = loader->data()[num];
    auto size = data.size() - 1;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 6; y++) {
            int index = 8 * y + x;

            if (index >= 48) {
                return;
            }

            QString name = QString::fromStdString(data.at(index));
            QPushButton* button = new QPushButton(name);
            button->move(20 + fm2::Constants::Instance()->btnDx * x, 20 + fm2::Constants::Instance()->btnDy * y);
            button->setFixedSize(fm2::Constants::Instance()->btnWidth, fm2::Constants::Instance()->btnHeight);
            QFont font("微软雅黑", 22);
            button->setFont(font);

            connect(button, &QPushButton::clicked, this, &FlowManager::StuClicked);

            layout.addWidget(button);
        }
    }
}
void FlowManager::StuClicked() {
    /*
        refresh();

    auto Stu = static_cast<QPushButton*>(sender());
    QRect buttonGeometry = Stu->geometry();

    int ix = buttonGeometry.x() / btnDx;
    int iy = buttonGeometry.y() / btnDy;
    currentIndex = ix + iy * 8;
    // qDebug()<<ix<<" "<<iy<<"\n";

    auto frame = ui->Destination;
    auto destination = frame->findChildren<QTextEdit*>();
    auto menu = initMenu(destination);

    int x = buttonGeometry.x() + btnWidth + 30;
    int y = buttonGeometry.y() + btnHeight + 210;

    if ((y + menu->sizeHint().height()) > ui->tabWidget->height()) {
        y -= menu->sizeHint().height();
    }

    menu->exec(mapToGlobal(QPoint(x, y))); // 使用 exec 方法弹出菜单
    
}
void FlowManager::refresh(){
    auto StudentsFrame = ui->Students;
    auto Students = StudentsFrame->children();
    int x = 0;
    int y = 0;
    // 不知道按照横向顺序放置，遍历时却变成了竖向顺序遍历
    for (auto s : Students) {
        int index = 8 * y + x;
        auto stu = static_cast<QPushButton*>(s);
        stu->setStyleSheet(QString::fromStdString(destinationStyleMap_[StuData[index]]));
        y++;
        if (y >= 6) {
            y = 0; x++;
        }
    }
    Count();
}

void FlowManager::putDestinationButtons(QFrame* frame) {
    QVBoxLayout layout(frame);

    int x_ = 10;
    int y_ = 40;
    int dy = 40;

    for (int i = 0; i < destinationStyleMap_.size(); i++) {
        QTextEdit* edit = new QTextEdit();

        edit->setText(QString::fromStdString(stateName_[i]));
        edit->setStyleSheet(QString::fromStdString(destinationStyleMap_[i]));
        edit->setGeometry(x_, y_ + i * dy, 150, 31);
        edit->setFont(QFont("微软雅黑", 12));

        layout.addWidget(edit);
    }
}
void FlowManager::putChangeColorComboBox(QWidget* widget) {
    QVBoxLayout layout(widget);

    QComboBox* changeColorComboBox = new QComboBox;

    changeColorComboBox->addItem("修改状态颜色");
    for (auto state : stateName_) {
        changeColorComboBox->addItem(QString::fromStdString(state));
    }
    changeColorComboBox->setCurrentIndex(0);
    changeColorComboBox->setGeometry(60, 470, 120, 31);

    layout.addWidget(changeColorComboBox);
}

void FlowManager::Count() {
    std::unordered_map<int, int> stateCount;
    auto classSize = loader->getClassData(classNumber_).size() - 1;
    for (int index = 0; index < StuData.size(); index++) {
        auto state = StuData[index];
        stateCount[state] += 1;
    }
    
    int countExpected = 0;
    int countAtClass = 0;
    for (int i = 0; i < stateName_.size(); i++) {
        if (stateTag_AtClass_[i]) {
            countAtClass += stateCount[i];
        }
        if (stateTag_Attend_[i]) {
            countExpected += stateCount[i];
        }
    }
    ui->EditExpected->setText(QString::number(countExpected));
    ui->EditActual->setText(QString::number(countAtClass));
}
void FlowManager::initStuData() {
    StuData.resize(48, fm2::StuState::AtClass);
    std::fill(StuData.begin(), StuData.end(), fm2::StuState::AtClass);
    if (classNumber_ != 1) {
        return;
    }
    StuData[30] = fm2::StuState::NotAttend - 1;
    if (currtenPeriod_ == fm2::TimePeriod::Evening) {
        StuData[11] = fm2::StuState::NotAttend - 1;
        StuData[30] = fm2::StuState::NotAttend - 1;
        StuData[32] = fm2::StuState::NotAttend - 1;
        StuData[34] = fm2::StuState::NotAttend - 1;
        StuData[44] = fm2::StuState::NotAttend - 1;
    }
    else if (currtenPeriod_ == fm2::TimePeriod::SmallWeekend) {
        std::fill(StuData.begin(), StuData.end(), fm2::StuState::NotAttend - 1);
        StuData[3] = fm2::StuState::AtClass;
        StuData[14] = fm2::StuState::AtClass;
        StuData[20] = fm2::StuState::AtClass;
        StuData[23] = fm2::StuState::AtClass;
        StuData[29] = fm2::StuState::AtClass;
        StuData[37] = fm2::StuState::AtClass;
        StuData[41] = fm2::StuState::AtClass;
        StuData[38] = fm2::StuState::AtClass;
        StuData[45] = fm2::StuState::AtClass;
    }
}

*/
