#pragma once

#include <memory>
#include <unordered_map>
#include <vector>
#include <string>


namespace fm2 {
	enum StuState {
		AtClass,
		AtOffice,
		Meeting,
		WC,
		X,
		AtHome,
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
	class Constants {
	public:
		static Constants* Instance();

		static void Init();
		static void Quit();
	public:
		int btnWidth = 130;
		int btnHeight = 70;
		int btnDx = 160;
		int btnDy = 90;

        std::vector<std::string> stateName{
            "在班" , "办公室", "开会", "厕所", "去向不明", "请假", "不参加自修", "其他",
        };
        std::vector<std::string> destinationStyleMap{
            "background-color: rgb(170, 255, 255)",
            "background-color: rgb(0  , 255, 0  )",
            "background-color: rgb(255, 170, 255)",
            "background-color: rgb(255, 255, 0  )",
            "background-color: rgb(250, 100, 0  )",
            "background-color: rgb(85 , 85 , 255)",
            "background-color: rgb(200, 200, 200)",
            "background-color: rgb(250, 250, 250)",
        };
		std::vector<bool> stateTag_AtClass{ 1, 0, 0, 0, 0, 0, 0, 0 };
		std::vector<bool> stateTag_Attend{ 1, 1, 1, 1, 1, 1, 0, 1 };
		int classNumber = 1;
	private:
		Constants();

		static std::unique_ptr<Constants> instance_;
	};
}