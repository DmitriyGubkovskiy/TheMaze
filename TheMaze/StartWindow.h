#pragma once

#include <QtWidgets/QMainWindow>
#include <QtDebug>

#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

#include "TheMaze.h"

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:

    QWidget* centralWidget;
    QPushButton* NewGameButton;
    /*QPushButton* ContinueButton;*/
    QPushButton* ExitButton;
    QLabel* label;


    StartWindow(QWidget* parent = nullptr);
    ~StartWindow();



private:
    Maze* maze;

    void setup(QMainWindow* StartWindowClass);
    void retranslate(QMainWindow* StartWindowClass);

private slots:
    void on_pushNewGameButton_clicked();
    /*void on_pushContinueButton_clicked();*/
    void on_pushExitButton_clicked();
    void DeleteMaze();


};
