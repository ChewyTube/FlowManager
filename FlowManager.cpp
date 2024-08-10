#include "FlowManager.h"
#include "FlowManager/Color.h"

#include <qboxlayout.h>
#include <qcombobox.h>
#include <qdebug.h>
#include <qcolordialog.h>

#include <iostream>
#include <iomanip>

// TODO 每次点击的时候都会创建一个menu对象，但是要到程序关闭的时候才销毁，会导致内存占用极其缓慢地上升
// 为了使代码更易读而定义，请以Config/stateName.yaml为准
enum {
    AT_CLASS,
    AT_OFFICE,
    MEETING,
    AT_WC,
    WE_DONT_KNOW,
    AT_HOME,
    NOT_ATTEND,
    OTHER,
};
enum {
    MORNING,
    LUNCH_TIME,
    EVENING,
    OTHERS,
    SMALL_WEEKEND,
};

FlowManager::FlowManager(QWidget *parent)
    : QMainWindow(parent)
{
    configLoader->LoadConfigFile("Config/config.yaml"   , "config"   );
    configLoader->LoadConfigFile("Config/DstBotton.yaml", "dstBtnCfg");
    configLoader->LoadConfigFile("Config/stateName.yaml", "stateName");
    configLoader->LoadConfigFile("Config/stateTag.yaml" , "stateTag" );

    if (getConfig<bool>({ "nogui" }, configLoader, "config")) {
        return;
    }

    loadDstStyMap();
    loadStateName();
    loadNameData();
    loadStateTag();
    loadStuData();

    ui->setupUi(this);

    putDestinationButtons(ui->Destination);
    putButtons(ui->Students, getConfig<int>({ "default_class" }, configLoader, "config"));
    putChangeColorComboBox(ui->Settings);

    refreshStuFrame();
    refreshDstFrame();

    connect(changeColorComboBox, &QComboBox::currentIndexChanged, this, &FlowManager::ChangeColor);
}
template <typename T>
T FlowManager::getConfig(
    std::vector<std::string> path, 
    fm2::ConfigLoader* loader, 
    std::string file_name
) {
    T value;
    if (!loader->getValue(file_name, path, &value)) {
        std::string whole_path = "";
        for (auto s : path) {
            whole_path += s;
            whole_path += "\\";
        }
        throw std::runtime_error(std::string("without ") + whole_path + std::string(" config"));
    }
    return value;
}

void FlowManager::putDestinationButtons(QFrame* frame) {
    QVBoxLayout layout(frame);

    int x_ = 10;
    int y_ = 40;
    int dy = 40;
    
    for (int i = 0; i < dstStyleMap.size(); i++) {
        QTextEdit* edit = new QTextEdit();

        edit->setText(QString::fromStdString(stateName[i]));
        edit->setStyleSheet(QString::fromStdString(dstStyleMap[i]));
        edit->setGeometry(x_, y_ + i * dy, 150, 31);
        edit->setFont(QFont("微软雅黑", 12));

        layout.addWidget(edit);
    }
    
}
void FlowManager::putButtons(QFrame* frameStudent, int num) {
    QVBoxLayout layout(frameStudent);
    auto data = getClassNameData(num);
    auto size = data.size() - 1;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 6; y++) {
            int btnDx     = getConfig<int>({ "btnDx" },     configLoader, "config");
            int btnDy     = getConfig<int>({ "btnDy" },     configLoader, "config");
            int btnWidth  = getConfig<int>({ "btnWidth" },  configLoader, "config");
            int btnHeight = getConfig<int>({ "btnHeight" }, configLoader, "config");

            int index = 8 * y + x;

            QString name = QString::fromStdString(data.at(index));
            QFont font("微软雅黑", 22);
            QPushButton* button = new QPushButton(name);
            button->move(20 + btnDx * x, 20 + btnDy * y);
            button->setFixedSize(btnWidth, btnHeight);
            button->setFont(font);

            connect(button, &QPushButton::clicked, this, &FlowManager::StuClicked);

            layout.addWidget(button);
        }
    }
}
void FlowManager::putChangeColorComboBox(QWidget* widget) {
    QVBoxLayout layout(widget);

    changeColorComboBox = new QComboBox;

    changeColorComboBox->addItem("修改状态颜色");
    for (auto state : stateName) {
        changeColorComboBox->addItem(QString::fromStdString(state));
    }
    changeColorComboBox->setCurrentIndex(0);
    changeColorComboBox->setGeometry(60, 470, 120, 31);

    layout.addWidget(changeColorComboBox);
}


void FlowManager::loadDstStyMap() {
    int         count       = getConfig<int>(        { "count"},        configLoader, "dstBtnCfg");
    bool        hasChinese  = getConfig<bool>(       { "hasChinese" } , configLoader, "dstBtnCfg");
    std::string targetName  = getConfig<std::string>({ "target_name" }, configLoader, "dstBtnCfg");

    for (int i = 1; i <= count; i++) {
        std::string target = targetName + std::to_string(i);
        int r = getConfig<int>({ target + std::string("_r") }, configLoader, "dstBtnCfg");
        int g = getConfig<int>({ target + std::string("_g") }, configLoader, "dstBtnCfg");
        int b = getConfig<int>({ target + std::string("_b") }, configLoader, "dstBtnCfg");

        auto color = fm2::Color(r, g, b);
        auto styleSheet = color.ToStyleSheet();
        dstStyleMap.push_back(styleSheet);
    }
}
void FlowManager::loadStateName() {
    int         count       = getConfig<int>(        { "count" }      , configLoader, "stateName");
    bool        hasChines   = getConfig<bool>(       { "hasChinese" } , configLoader, "stateName");
    std::string targetName  = getConfig<std::string>({ "target_name" }, configLoader, "stateName");

    for (int i = 1; i <= count; i++) {
        std::string target = targetName + std::to_string(i);
        stateName.push_back(getConfig<std::string>({ target }, configLoader, "stateName"));
    }
}
void FlowManager::loadNameData() {
    auto grade = getConfig<int>({ "grade" }, configLoader, "config");
    std::string targetFile = std::string("total_number_of_class_grade") + std::to_string(grade);
    auto num = getConfig<int>({ targetFile }, configLoader, "config");

    for (int i = 1; i <= num; i++) {
        std::string target    = "Resources\\" + std::to_string(grade);
        if (i < 10) { target += std::to_string(0); }
        target += std::to_string(i);
        target += std::string(".yaml");

        std::string name    = std::to_string(grade);
        if (i < 10) { name += std::to_string(0); }
        name += std::to_string(i);

        dataLoader->LoadConfigFile(target, name);
    }
}
void FlowManager::loadStateTag() {
    int count = getConfig<int>({ "state_count" }, configLoader, "config");
    std::vector<std::string> tag_name = { "at_class", "at_school", "attend" };

    stateTag_attend.resize(count, 0);
    stateTag_at_class.resize(count, 0);
    stateTag_at_school.resize(count, 0);

    for (auto tag : tag_name) {
        for (int i = 1; i <= count; i++) {
            std::string target = "state" + std::to_string(i) + "_" + tag;
            auto value = getConfig<bool>({ target }, configLoader, "stateTag");
            if (tag == "at_class") {
                stateTag_at_class[i - 1]  = value;
            }
            else if(tag == "at_school")
            {
                stateTag_at_school[i - 1] = value;
            }
            else if (tag == "attend")
            {
                stateTag_attend[i - 1]    = value;
            }
            else {
                throw std::runtime_error("unknown tag");
            }
        }
    }
}
void FlowManager::loadStuData() {
    int count        = getConfig<int>({ "count" },         dataLoader,   std::to_string(currentClass));
    int defaultState = getConfig<int>({ "default_state" }, configLoader, "config");
    StuData.resize(count, defaultState);

    if (currentClass != 2601) {
        return;
    }
    StuData[30] = NOT_ATTEND;
    
    // TODO 提取至yaml
    if (currentPeriod == EVENING) {
        StuData[11] = NOT_ATTEND;
        StuData[30] = NOT_ATTEND;
        StuData[32] = NOT_ATTEND;
        StuData[34] = NOT_ATTEND;
        StuData[44] = NOT_ATTEND;
    }
    else if (currentPeriod == SMALL_WEEKEND) {
        std::fill(StuData.begin(), StuData.end(), NOT_ATTEND);
        StuData[3 ] = AT_CLASS;
        StuData[14] = AT_CLASS;
        StuData[20] = AT_CLASS;
        StuData[23] = AT_CLASS;
        StuData[29] = AT_CLASS;
        StuData[37] = AT_CLASS;
        StuData[41] = AT_CLASS;
        StuData[38] = AT_CLASS;
        StuData[45] = AT_CLASS;
    }
}

QMenu* FlowManager::initMenu(QList<QTextEdit*> textEditors, int StuIndex) {
    auto menu = new QMenu(this);

    menu->setWindowFlags(menu->windowFlags() | Qt::FramelessWindowHint);
    menu->setObjectName("ChangeState");

    auto state_count = getConfig<int>({ "state_count" }, configLoader, "config");

    for (int i = 0; i < state_count; i++) {
        std::string text;

        text = stateName[i];
        
        QAction* action = new QAction(QString::fromStdString(text), this);
        menu->addAction(action);
        connect(action, &QAction::triggered, this, 
            [=](){ StuChangeState(i, StuIndex); }
        , Qt::QueuedConnection);
    }
    return menu;
}

std::vector<std::string> FlowManager::getClassNameData(int class_index, int grade) {
    std::vector<std::string> data = {};
    std::stringstream filename;
    filename << grade << std::setw(2) << std::setfill('0') << class_index;
    auto number = getConfig<int>({ "count" }, dataLoader, filename.str());

    for (int i = 1; i <= number; i++) {
        std::stringstream stu;
        stu << "s20" << grade << std::setw(2) << std::setfill('0') << class_index
            << std::setw(2) << std::setfill('0') << i;
        data.push_back(getConfig<std::string>({ stu.str()}, dataLoader, filename.str()));
    }
    
    return data;
}

void FlowManager::StuClicked() {
    refreshStuFrame();
    int btnDx     = getConfig<int>({ "btnDx" },     configLoader, "config");
    int btnDy     = getConfig<int>({ "btnDy" },     configLoader, "config");
    int btnWidth  = getConfig<int>({ "btnWidth" },  configLoader, "config");
    int btnHeight = getConfig<int>({ "btnHeight" }, configLoader, "config");

    auto Stu = static_cast<QPushButton*>(sender());
    QRect buttonGeometry = Stu->geometry();

    int ix = buttonGeometry.x() / btnDx;
    int iy = buttonGeometry.y() / btnDy;
    int index = ix + iy * 8;
    // qDebug()<<ix<<" "<<iy<<"\n";

    auto frame = ui->Destination;
    auto destination = frame->findChildren<QTextEdit*>();
    auto menu = initMenu(destination, index);

    int x = buttonGeometry.x() + btnWidth + 30;
    int y = buttonGeometry.y() + btnHeight + 210;

    if ((y + menu->sizeHint().height()) > ui->tabWidget->height()) {
        y -= menu->sizeHint().height();
    }

    menu->exec(mapToGlobal(QPoint(x, y))); // 使用 exec 方法弹出菜单
}
void FlowManager::StuChangeState(int stateIndex, int StuIndex) {
    StuData[StuIndex] = stateIndex;
    refreshStuFrame();
}

void FlowManager::refreshStuFrame(){
    auto StudentsFrame = ui->Students;
    auto Students = StudentsFrame->children();
    int x = 0;
    int y = 0;
    // 不知道为什么按照横向顺序放置，遍历时却变成了竖向顺序遍历
    for (auto s : Students) {
        int index = 8 * y + x;
        auto stu = static_cast<QPushButton*>(s);
        stu->setStyleSheet(QString::fromStdString(dstStyleMap[StuData[index]]));
        y++;
        if (y >= 6) {
            y = 0; x++;
        }
    }
    Count();
}
void FlowManager::refreshDstFrame() {
    auto edits = ui->Destination->children();
    int index = 0;
    for (auto edit : edits) {
        if (QTextEdit* textEditPtr = qobject_cast<QTextEdit*>(edit)) {
            QTextEdit* e = static_cast<QTextEdit*>(edit);
            e->setStyleSheet(QString::fromStdString(dstStyleMap[index]));
            index++;
        }
    }
}

void FlowManager::Count() {
    std::vector<int> eachStatePeopleCount = {};
    auto state_count = getConfig<int>({ "state_count" }, configLoader, "config");
    eachStatePeopleCount.resize(state_count, 0);
    auto classSize = getConfig<int>({ "count" }, dataLoader, std::to_string(currentClass));
    for (int index = 0; index < classSize; index++) {
        auto state = StuData[index];
        eachStatePeopleCount[state] += 1;
    }

    int countExpected = 0;
    int countAtClass = 0;
    for (int i = 0; i < state_count; i++) {
        if (stateTag_at_class[i]) {
            countAtClass += eachStatePeopleCount[i];
        }
        if (stateTag_attend[i]) {
            countExpected += eachStatePeopleCount[i];
        }
    }
    ui->EditExpected->setText(QString::number(countExpected));
    ui->EditActual->setText(QString::number(countAtClass));
}
void FlowManager::ChangeColor(int stateIndex) {
    auto initialState = windowFlags();
    // allowMinMaxClose(true);
    changeColorComboBox->setCurrentIndex(0);
    if (stateIndex == 0) {
        return;
    }
    stateIndex--; // 第一格用于显示“修改状态颜色”，计算index时应减去
    std::string title = "选择颜色:";
    title += stateName[stateIndex];
    QColor color = QColorDialog::getColor(Qt::white, nullptr, QString::fromStdString(title));
    if (color.isValid()) {
        // 如果用户选择了有效颜色
        QString styleSheet = QString("background-color: %1").arg(color.name());
        dstStyleMap[stateIndex] = styleSheet.toStdString();
    }
    refreshStuFrame();
    refreshDstFrame();
    setWindowFlags(initialState);
    if (!this->isVisible())
    {
        setVisible(true);
    }
}


