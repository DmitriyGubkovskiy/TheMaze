#pragma once
#include <QtWidgets>
#include <vector> 
#include <QRect>
#include <QPaintEvent>
#include <QGraphicsRectItem>
using namespace std;

class Block : public QObject,
    public QGraphicsRectItem
{
    Q_OBJECT
public:
    Block(vector<vector<int>>* level_map, const int character_size,
        const int size);
    ~Block();

private:
    //QWidget* maze;

    int size;
    vector<vector<int>>* level_map;
    void keyPressEvent(QKeyEvent* event);
    int character_size;
    bool CheckNextStep(int x, int y);

signals:
    void TheEnd();
};