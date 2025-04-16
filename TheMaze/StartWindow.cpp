#include "StartWindow.h"
#include <QtDebug>
#include <iostream>


StartWindow::StartWindow(QWidget* parent)
    : QMainWindow(parent)
{

    setup(this);

    connect(ExitButton, SIGNAL(clicked()), this,
        SLOT(on_pushExitButton_clicked()));

    connect(NewGameButton, SIGNAL(clicked()), this,
        SLOT(on_pushNewGameButton_clicked()));


}

StartWindow::~StartWindow()
{
}

void StartWindow::setup(QMainWindow* StartWindowClass)
{
    if (StartWindowClass->objectName().isEmpty())
        StartWindowClass->setObjectName(QString::fromUtf8("StartWindowClass"));
    StartWindowClass->resize(280, 360);
    StartWindowClass->setMinimumSize(QSize(280, 360));
    StartWindowClass->setMaximumSize(QSize(280, 360));
    centralWidget = new QWidget(StartWindowClass);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));

    NewGameButton = new QPushButton(centralWidget);
    NewGameButton->setObjectName(QString::fromUtf8("NewGameButton"));
    NewGameButton->setGeometry(QRect(60, 80, 160, 60));

    /*ContinueButton = new QPushButton(centralWidget);
    ContinueButton->setObjectName(QString::fromUtf8("ContinueButton"));
    ContinueButton->setGeometry(QRect(60, 160, 160, 60));*/

    ExitButton = new QPushButton(centralWidget);
    ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
    ExitButton->setGeometry(QRect(60, 240, 160, 60));
    label = new QLabel(centralWidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 10, 261, 61));
    label->setTextFormat(Qt::RichText);
    label->setScaledContents(false);
    label->setAlignment(Qt::AlignCenter);
    label->setMargin(1);
    StartWindowClass->setCentralWidget(centralWidget);


    retranslate(StartWindowClass);

    //QMetaObject::connectSlotsByName(StartWindowClass);
}

void StartWindow::retranslate(QMainWindow* StartWindowClass)
{
    StartWindowClass->setWindowTitle(QApplication::translate("StartWindowClass",
        "StartWindow", nullptr));
    NewGameButton->setText(QApplication::translate("StartWindowClass",
        "New Game", nullptr));
    /*ContinueButton->setText(QApplication::translate("StartWindowClass", "Continue", nullptr));*/
    ExitButton->setText(QApplication::translate("StartWindowClass",
        "Exit", nullptr));
    label->setText(QApplication::translate("StartWindowClass",
        "The Maze", nullptr));

}

void StartWindow::on_pushNewGameButton_clicked()
{
    maze = new Maze();
    connect(maze, SIGNAL(MazeClose()), this, SLOT(DeleteMaze()));
    this->hide();
}
//void StartWindow::on_pushContinueButton_clicked()
//{
//    int level;
//    delete this->maze;
//    this->maze = new Maze(nullptr, level);
//    this->maze->show();
//    this->close();
//}

void StartWindow::on_pushExitButton_clicked()
{
    this->close();
    qDebug() << "Game was closed";
}

void StartWindow::DeleteMaze()
{
    maze->hide();
    this->show();
}
