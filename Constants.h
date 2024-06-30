#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>
#include <string>
#include <unordered_map>

#include "enum.h"

int btnWidth  = 130;
int btnHeight = 70;
int btnDx = 160;
int btnDy = 90;

std::vector<std::string> nameData{"张怡洁", "陈雨柔", "沈云诺", "陈张茜", "付羽辰", "王梓焱", "徐奕瑶", "李泽宸", "王悦宁", "顾曹菁", "马李悦", "周琳宜", "王庄好", "夏鑫桐", "汪孙怡涵", "宋方欣", "陈欣妍", "许妤晗", "沈心扬", "陈颉瑞", "黄飞扬", "杨子赫", "王浩天", "张新傲", "陆侯超", "姚一诺", "蒋亚良", "彭禹翔", "黄哲涛", "王若辰", "施正", "吕文喆", "周晨阳", "杨张锃", "沈许越", "曹潇逸", "尤启达", "丁周奕", "陈宇翔", "邵晨翔", "张怡为", "吴周然", "祁赞立", "钱柏文", "陈锦杰", "姚成", "许志博", "羊孙宁"};

std::unordered_map<StuState, std::string> StuStateMap{
    {AtClass, "在班"},
    {AtOffice, "办公室"},
    {AskQuestions, "答疑"},
    {HaveMeeting, "开会"},
    {AtWC, "厕所"},
    {WeDontKnow, "去向不明"},
    {Leave, "请假"},
    {NotAttend, "不参加自修"},
};

#endif // CONSTANTS_H
