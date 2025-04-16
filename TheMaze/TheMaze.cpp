#include "TheMaze.h"
#include <QtDebug>
#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>

Maze::Maze(QWidget* parent)
{

    scene = new QGraphicsScene();

    ViewMap();
    this->character = new Block(&(this->level_map), this->block_size,
        this->size);

    this->character->setRect(0, block_size, block_size, block_size);
    this->character->setBrush(QBrush(Qt::green));
    scene->addItem(this->character);


    this->character->setFlag(QGraphicsItem::ItemIsFocusable);

    this->character->setFocus();

    connect(this->character, SIGNAL(TheEnd()), this,
        SLOT(GameWin()));

    view = new QGraphicsView(scene);

    view->show();
}

Maze::~Maze()
{
}


void Maze::ViewMap()
{

    CreateMazeMap("Data/level1.txt");
    int y = 0;
    for (int i = 0; i < this->size; i++)
    {
        int x = 0;
        for (int j = 0; j < this->size; j++)
        {
            QGraphicsRectItem* rect = new QGraphicsRectItem();
            rect->setRect(x, y, this->block_size, this->block_size);

            switch (this->level_map[i][j])
            {
            case 0:
                break;
            case 1:
                rect->setBrush(QBrush(Qt::black));
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                rect->setBrush(QBrush(Qt::red));
                break;
            }
            x += block_size;
            scene->addItem(rect);
        }
        y += block_size;
    }

}

void Maze::GameWin()
{
    qDebug() << "Win";
    QMessageBox msgBox;
    msgBox.setText("You have won!");
    msgBox.exec();
    delete character;
    delete scene;
    delete view;
    emit MazeClose();
}

void Maze::CreateMazeMap(const string& file_name)
{
    ifstream task_file;
    task_file.open(file_name);
    string line;
    this->level_map = vector<vector<int>>(this->size, vector<int>(this->size));
    if (!(task_file.is_open()))
    {
        qDebug() << "file not found ";
        return;
    }
    qDebug() << "file opened";
    for (int i = 0; i < this->size; i++)
    {
        for (int j = 0; j < this->size; j++)
        {
            getline(task_file, line);
            int el = stoi(line);
            this->level_map[i][j] = el;
        }
    }

}





