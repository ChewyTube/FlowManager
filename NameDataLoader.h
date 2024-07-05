#pragma once

#include <vector>
#include <string>

#include <iostream>
#include <sstream>
#include <istream>
#include <fstream>

#include <QDebug>

class NameDataLaoder {
public:
	NameDataLaoder(std::string path, int year) {
		nameData.resize(15);
		for (int i = 1; i <= 14; ++i) {
			getDataFromFile(path, i, year);
		}
	}
	std::vector<std::vector<std::string>> data() {
		return nameData;
	}
	std::vector<std::string> getClassData(int num) {
		return nameData[num];
	}
private:
	std::vector<std::vector<std::string>> nameData;

	void getDataFromFile(std::string path, int num, int year) {
		std::string realPath = path + "//" + std::to_string(year);
		if (num < 10) {
			realPath += "0";
		}
		realPath += std::to_string(num) + ".txt";;

		std::string s;
		std::vector<std::string> v1;
		std::ifstream inf(realPath, std::ios::in);

		if (!inf.is_open())
		{
			qDebug() << "读取文件失败：" << realPath << "\n";
			
			return;
		}

		while (std::getline(inf, s))
		{
			inf >> s;
			nameData[num].push_back(s);
		}

		inf.close();
	}

};