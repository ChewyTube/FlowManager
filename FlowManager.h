#ifndef FLOWMANAGER_H
#define FLOWMANAGER_H

#include <QMainWindow>
#include <QObject>
#include <QFrame>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QTimer>

#include <vector>
#include <functional>

#include <Windows.h>
#include <WinUser.h>

#include <stdlib.h>

#include "enum.h"
#include "NameDataLoader.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class FlowManager;
}
QT_END_NAMESPACE

// @TODO 添加预设 座位映射 存储

class FlowManager : public QMainWindow
{
    Q_OBJECT

public:
    FlowManager(QWidget *parent = nullptr);
    ~FlowManager();

private slots:
    void StuClicked();
    void allowMinClicked(bool clicked);
    void showSysTimeClicked(bool clicked);

    void changeStateToAtClass();
    void changeStateToAtOffice();
    void changeStateToAskQuestions();
    void changeStateToHaveMeeting();
    void changeStateToAtWC();
    void changeStateToWeDontKnow();
    void changeStateToLeave();
    void changeStateToNotAttend();
    void changeStateToOther();

    void PeriodChanged(QString text);
    void ClassChanged(QString text);

    //统计应到实到
    void Count();
    //计时器触发
    void onTimeout();
private:
    Ui::FlowManager *ui;

    QMenu* initMenu(QList<QTextEdit *> textEditors);

    QMenu* rawMenu;
    void putButtons(QFrame* frameStudent, int num);

    void refreshStuData();
    void initSoltFuncMap();
    void initStyleMap();
    void initPeriodMap();
    void initDestinationMap();
    void initDestination();
    void initTimer();

    void refresh();
    void refreshAfterInit();

    void doConnect();

    std::vector<StuState> StuData = std::vector<StuState> {};
    std::unordered_map<StuState, std::function<void(int)>, StuStateHash, StuStateEqual> soltFuncMap;
    std::unordered_map<StuState, std::string, StuStateHash, StuStateEqual> styleMap;
    std::unordered_map<QString, TimePeriod> periodMap;
    std::unordered_map<std::string, StuState> destinationMap;

    int currtenIndex = 0;
    TimePeriod currtenPeriod;

    QTimer *timer = new QTimer(this);
    NameDataLaoder* loader = new NameDataLaoder(".//Resources", 26);

    int classNumber = 1;
};
#endif // FLOWMANAGER_H
