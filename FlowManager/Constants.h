#pragma once

#include <memory>
#include <unordered_map>
#include <vector>
#include <string>

// 为了使代码更易读而定义，请以Config/stateName.yaml为准
enum {
	AT_CLASS,
	AT_OFFICE,
	MEETING,
	AT_WC,
	AT_HOME,
	NOT_ATTEND,
	OTHER,
};

	