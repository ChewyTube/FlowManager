#include "FlowManager.h"
#include <QtWidgets/QApplication>

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlowManager w;
    w.show();
    return a.exec();
}
