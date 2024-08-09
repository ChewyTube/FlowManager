#pragma once
#include <string>

namespace fm2 {
	struct Color
	{
		Color(int r_, int g_,int b_) {
			r = r_;
			g = g_;
			b = b_;
		}
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 0;

		std::string ToStyleSheet() {
			std::string result =
				std::string("background-color: rgb(") +
				std::to_string(r) + std::string(",") +
				std::to_string(g) + std::string(",") +
				std::to_string(b) +
				std::string(")");
			return result;
		}
	};
}