#include <QApplication>
#include "StartWindow.h"
#include <iostream>
#include "TheMaze.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    StartWindow w;
    w.show();


    return app.exec();
}
