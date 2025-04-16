#pragma once
#include <QtWidgets>
#include <vector> 
#include <fstream>
#include <QRect>
#include <QPaintEvent>
#include <QGraphicsRectItem>
#include "Bl.h"

using namespace std;

class Maze :
    public QWidget
{
    Q_OBJECT
public:
    Maze(QWidget* parent = nullptr);
    ~Maze();

private:
      
    friend Block;
    QGraphicsScene* scene;
    QGraphicsView* view;

    Block* character;

    const int block_size = 64;

    vector<vector<int>> level_map;

    const int size = 21;

    void ViewMap();

    void CreateMazeMap(const string& file_name);

public slots:
    void GameWin();
    
signals:
    void MazeClose();
};

