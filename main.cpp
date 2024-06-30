#include "FlowManager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlowManager w;
    w.show();
    return a.exec();
}
