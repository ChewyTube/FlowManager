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

struct StuStateHash {
    std::size_t operator()(const StuState& s) const {
        return static_cast<std::size_t>(s);
    }
};

struct StuStateEqual {
    bool operator()(const StuState& s1, const StuState& s2) const {
        return s1 == s2;
    }
};

struct TimePeriodHash {
    std::size_t operator()(const TimePeriod& p) const {
        return static_cast<std::size_t>(p);
    }
};

struct TimePeriodEqual {
    bool operator()(const TimePeriod& p1, const TimePeriod& p2) const {
        return p1 == p2;
    }
};
