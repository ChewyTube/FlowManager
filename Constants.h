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

/*
std::vector<std::string> nameData1{"张怡洁", "陈雨柔", "沈云诺", "陈张茜", "付羽辰", "王梓焱", "徐奕瑶", "李泽宸", "王悦宁", "顾曹菁", "马李悦", "周琳宜", "王庄好", "夏鑫桐", "汪孙怡涵", "宋方欣", "陈欣妍", "许妤晗", "沈心扬", "陈颉瑞", "黄飞扬", "杨子赫", "王浩天", "张新傲", "陆侯超", "姚一诺", "蒋亚良", "彭禹翔", "黄哲涛", "王若辰", "施正", "吕文喆", "周晨阳", "杨张锃", "沈许越", "曹潇逸", "尤启达", "丁周奕", "陈宇翔", "邵晨翔", "张怡为", "吴周然", "祁赞立", "钱柏文", "陈锦杰", "姚成", "许志博", "羊孙宁"};
std::vector<std::string> nameData2{ "朱茗奕","余是谦","汤诗静","李芊锐","李欣然","李俞同","甘泉","姚航悦","曹诗哲","糜慧仪","徐聿辰","张千亦","徐楚泱","马天悦","林嘉祺","苏弋涵","俞歌","罗薇","苏天任","朱宇翔","曾梓睿","吴宇轩","鲁峻延","苏若瑜","常欢","张哲僖","陈圣杰","梅修","邵铭轩","钱周奥","叶子卿","卢家佳","浦邵哲","杨骏逸","崔佳乐","林均豪","陈磊","崔王畯辰","毛仁杰","方刘成","杨艺飞","周琦昊","张翀昊","包子铖","朱逸凡","傅煜舟","汪小龙", };

std::vector<std::vector<std::string>> nameDataList{
    nameData1, nameData2
};
*/


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


#endif // CONSTANTS_H
