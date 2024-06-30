#include "FlowManager.h"
#include "./ui_FlowManager.h"
#include "./ui_time.h"

#include "Constants.h"
#include <QTimer>
#include <QDebug>
#include <QVBoxLayout>

FlowManager::FlowManager(QWidget *parent)
    : QMainWindow(parent, Qt::Widget | Qt::WindowStaysOnTopHint) // 始终置于顶层
    , ui(new Ui::FlowManager)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
    // ui->tabWidget->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint);

    auto frame = ui->Destination;
    auto destination = frame->findChildren<QTextEdit *>();

    refreshStuData();
    initSoltFuncMap();
    initStyleMap();
    initPeriodMap();
    initDestinationMap();

    initDestination();

    rawMenu = initMenu(destination);

    auto frameStudent = ui->Students;
    //frameStudent->setFrameShadow(QFrame::Raised);

    putButtons(frameStudent);
    initTimer();

    refreshAfterInit();

    doConnect();
}

void FlowManager::StuClicked(){
    refresh();

    auto Stu = static_cast<QPushButton*>(sender());
    QRect buttonGeometry = Stu->geometry();

    int ix = buttonGeometry.x() / btnDx;
    int iy = buttonGeometry.y() / btnDy;
    currtenIndex = ix+iy*8;
    // qDebug()<<ix<<" "<<iy<<"\n";

    auto frame = ui->Destination;
    auto destination = frame->findChildren<QTextEdit *>();
    auto menu = initMenu(destination);

    int x = buttonGeometry.x() + btnWidth  + 30;
    int y = buttonGeometry.y() + btnHeight + 210;

    if((y + menu->sizeHint().height()) > ui->tabWidget->height()){
        y -= menu->sizeHint().height();
    }

    menu->exec(mapToGlobal(QPoint(x, y))); // 使用 exec 方法弹出菜单
}
QMenu* FlowManager::initMenu(QList<QTextEdit *> textEditors){
    auto menu = new QMenu(this);

    menu->setWindowFlags(menu->windowFlags() | Qt::FramelessWindowHint);
    menu->setObjectName("ChangeState");
    for(int i = 0; i < StuState::StateCount; i++){
        auto state = static_cast<StuState>(i);
        std::string text;

        if(state==StuState::AskQuestions){
            continue;//删去答疑
        }

        if(state==StuState::Other){
            //若是其他，获取字符串 这里是屎山，要改TODO
            StuState state_ = StuState::Other;
            for(auto edit : textEditors){
                text = edit->toPlainText().toStdString();
                if(destinationMap.find(text) != destinationMap.end()){
                    state_ = destinationMap[text];
                }else{
                    state_ = StuState::Other;
                }
                if(state_==StuState::Other){
                    break;
                }
            }
        }else{
            text = StuStateMap[state];
        }

        QAction* action = new QAction(QString::fromStdString(text), this);
        menu->addAction(action);
        auto soltFunc = soltFuncMap[state];
        // connect(action, &QAction::triggered, this, soltFunc);
        connect(action, &QAction::triggered, this, soltFunc);
    }
    return menu;
}
FlowManager::~FlowManager()
{
    timer->stop();
    delete ui;
}

void FlowManager::changeStateToAtClass(){
    StuData.at(currtenIndex) = StuState::AtClass;
    refresh();
}
void FlowManager::changeStateToAtOffice(){
    StuData.at(currtenIndex) = StuState::AtOffice;
    refresh();
}
void FlowManager::changeStateToAskQuestions(){
    StuData.at(currtenIndex) = StuState::AskQuestions;
    refresh();
}
void FlowManager::changeStateToHaveMeeting(){
    StuData.at(currtenIndex) = StuState::HaveMeeting;
    refresh();
}
void FlowManager::changeStateToAtWC(){
    StuData.at(currtenIndex) = StuState::AtWC;
    refresh();
}
void FlowManager::changeStateToWeDontKnow(){
    StuData.at(currtenIndex) = StuState::WeDontKnow;
    refresh();
}
void FlowManager::changeStateToLeave(){
    StuData.at(currtenIndex) = StuState::Leave;
    refresh();
}
void FlowManager::changeStateToNotAttend(){
    StuData.at(currtenIndex) = StuState::NotAttend;
    refresh();
}
void FlowManager::changeStateToOther(){
    StuData.at(currtenIndex) = StuState::Other;
    refresh();
}

void FlowManager::PeriodChanged(QString text){
    currtenPeriod = periodMap[text];
    // qDebug()<<currtenPeriod;
    refreshStuData();
    refresh();
}

void FlowManager::refreshStuData(){
    StuData.resize(48, StuState::AtClass);
    std::fill(StuData.begin(), StuData.end(), StuState::AtClass);
    StuData[30] = StuState::NotAttend;
    if (currtenPeriod == TimePeriod::Evening){
        StuData[11] = StuState::NotAttend;
        StuData[30] = StuState::NotAttend;
        StuData[32] = StuState::NotAttend;
        StuData[34] = StuState::NotAttend;
        StuData[44] = StuState::NotAttend;
    }else if(currtenPeriod == TimePeriod::SmallWeekend){
        std::fill(StuData.begin(), StuData.end(), StuState::NotAttend);
        StuData[3]  = StuState::AtClass;
        StuData[14] = StuState::AtClass;
        StuData[20] = StuState::AtClass;
        StuData[23] = StuState::AtClass;
        StuData[29] = StuState::AtClass;
        StuData[37] = StuState::AtClass;
        StuData[41] = StuState::AtClass;
        StuData[38] = StuState::AtClass;
        StuData[45] = StuState::AtClass;
    }
}

void FlowManager::refresh(){
    auto StudentsFrame = ui->Students;
    auto Students = StudentsFrame->children();
    int x = 0;
    int y = 0;
    // 不知道按照横向顺序放置，遍历时却变成了竖向顺序遍历
    for(auto s:Students){
        int index = 8*y+x;
        auto stu = static_cast<QPushButton*>(s);
        stu->setStyleSheet(QString::fromStdString(styleMap[StuData[index]]));
        y++;
        if(y>=6){
            y=0;x++;
        }
    }
    Count();
}
void FlowManager::refreshAfterInit(){
    QTimer *timer = new QTimer(this);

    // 将timeout信号连接到自定义槽函数
    connect(timer, &QTimer::timeout, this, &FlowManager::refresh);
    // 设置计时器超时时间（例如：0毫秒）
    timer->setSingleShot(true);
    timer->start(0);
}

void FlowManager::putButtons(QFrame* frameStudent){
    QVBoxLayout layout(frameStudent);
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 6; y++){
            int index = 8*y+x;
            QString name = QString::fromStdString(nameData.at(index));
            // QString name = QString::number(index);
            QPushButton* button = new QPushButton(name);
            button->move(20+btnDx*x, 20+btnDy*y);
            button->setFixedSize(btnWidth, btnHeight);
            QFont font("微软雅黑", 22);
            button->setFont(font);

            connect(button, &QPushButton::clicked, this, &FlowManager::StuClicked);

            layout.addWidget(button);
        }
    }
}

void FlowManager::Count(){
    std::unordered_map<StuState, int> stateCount;
    for(int index = 0; index<StuData.size(); index++){
        auto state = StuData[index];
        stateCount[state] += 1;
    }
    int countExpected = StuData.size() - stateCount[StuState::NotAttend];
    int countActual = stateCount[StuState::AtClass];
    ui->EditExpected->setText(QString::number(countExpected));
    ui->EditActual->setText(QString::number(countActual));
}
void FlowManager::initDestination() {
    auto frame = ui->Destination;
    auto destination = frame->findChildren<QTextEdit*>();
    StuState state = StuState::Other;
    for (auto edit : destination) {
        std::string text = edit->toPlainText().toStdString();
        if (destinationMap.find(text) != destinationMap.end()) {
            state = destinationMap[text];
        }
        std::string style = styleMap[state];
        edit->setStyleSheet(QString::fromStdString(style));
    }
}
void FlowManager::initSoltFuncMap() {
    soltFuncMap[StuState::AtClass] = std::bind(&FlowManager::changeStateToAtClass, this);
    soltFuncMap[StuState::AtOffice] = std::bind(&FlowManager::changeStateToAtOffice, this);
    soltFuncMap[StuState::AskQuestions] = std::bind(&FlowManager::changeStateToAskQuestions, this);
    soltFuncMap[StuState::HaveMeeting] = std::bind(&FlowManager::changeStateToHaveMeeting, this);
    soltFuncMap[StuState::AtWC] = std::bind(&FlowManager::changeStateToAtWC, this);
    soltFuncMap[StuState::WeDontKnow] = std::bind(&FlowManager::changeStateToWeDontKnow, this);
    soltFuncMap[StuState::Leave] = std::bind(&FlowManager::changeStateToLeave, this);
    soltFuncMap[StuState::NotAttend] = std::bind(&FlowManager::changeStateToNotAttend, this);
    soltFuncMap[StuState::Other] = std::bind(&FlowManager::changeStateToOther, this);
}
void FlowManager::initStyleMap() {
    styleMap[StuState::AtClass] = "background-color: rgb(170, 255, 255)";
    styleMap[StuState::AtOffice] = "background-color: rgb(170, 255, 127)";
    styleMap[StuState::AskQuestions] = "background-color: rgb(0  , 255, 0  )";
    styleMap[StuState::HaveMeeting] = "background-color: rgb(255, 170, 255)";
    styleMap[StuState::AtWC] = "background-color: rgb(255, 255, 0  )";
    styleMap[StuState::WeDontKnow] = "background-color: rgb(250, 100, 0  )";
    styleMap[StuState::Leave] = "background-color: rgb(85 , 85 , 255)";
    styleMap[StuState::NotAttend] = "background-color: rgb(200, 200, 200)";
    styleMap[StuState::Other] = "background-color: rgb(250, 250, 250)";
}
void FlowManager::initPeriodMap() {
    periodMap["早自修"] = TimePeriod::Morning;
    periodMap["午自修"] = TimePeriod::Lunchtime;
    periodMap["晚自修"] = TimePeriod::Evening;
    periodMap["自修课"] = TimePeriod::Others;
    periodMap["小礼拜"] = TimePeriod::SmallWeekend;

    currtenPeriod = TimePeriod::Lunchtime;
}
void FlowManager::initDestinationMap() {
    destinationMap["在班"] = StuState::AtClass;
    destinationMap["办公室"] = StuState::AtOffice;
    destinationMap["开会"] = StuState::HaveMeeting;
    destinationMap["厕所"] = StuState::AtWC;
    destinationMap["去向不明"] = StuState::WeDontKnow;
    destinationMap["请假"] = StuState::Leave;
    destinationMap["不参加"] = StuState::NotAttend;
    destinationMap["其他"] = StuState::Other;
}
void FlowManager::initTimer() {
    timer->setInterval(1000);//10ms
    timer->start();
}

void FlowManager::doConnect() {
    connect(timer, &QTimer::timeout, this, &FlowManager::onTimeout);
    connect(ui->allowMin, &QCheckBox::clicked, this, &FlowManager::allowMinClicked);
    connect(ui->showSysTime, &QCheckBox::clicked, this, &FlowManager::showSysTimeClicked);
}

void FlowManager::onTimeout() {
    
    auto frame = ui->centralwidget;
    SetWindowPos((HWND)frame->winId(), HWND_TOPMOST, frame->pos().x(), frame->pos().y(),
        frame->width(), frame->height(), SWP_SHOWWINDOW);
}
void FlowManager::allowMinClicked(bool clicked) {
    Qt::WindowFlags m_flags = windowFlags();
    // qDebug() << m_flags;
    if (!clicked) {
        setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
        setWindowFlags(m_flags & ~Qt::WindowMinMaxButtonsHint);//禁止最大和最小化
    }
    else {
        setWindowFlags(m_flags & ~Qt::WindowStaysOnTopHint);
        setWindowFlags(m_flags | Qt::WindowMinMaxButtonsHint);
    }
    if (!this->isVisible())
    {
        setVisible(true);
    }
}

void FlowManager::showSysTimeClicked(bool clicked) {
    if (clicked) {

    }
    else {

    }
}