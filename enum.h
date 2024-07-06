#pragma once
#include <xhash>

#include <QString>

enum StuState {
    AtClass,
    AtOffice,
    AskQuestions,
    HaveMeeting,
    AtWC,
    WeDontKnow,
    Leave,
    NotAttend,
    Other,
    StateCount,
};
enum TimePeriod {
    Morning,
    Lunchtime,
    Evening,
    Others,
    SmallWeekend,
    PeriodCount,
};

