#include "Bl.h"


void Block::keyPressEvent(QKeyEvent* event)
{

    switch (event->key())
    {
    case Qt::Key_Right:
        if (CheckNextStep(x() + character_size, y()))
        {
            this->setPos(x() + character_size, y());
        }
        if (x() == 1280 && y() == 1152)
        {
            qDebug() << "win";
            emit TheEnd();
        }
        break;
    case Qt::Key_Left:
        if (CheckNextStep(x() - character_size, y()))
        {
            this->setPos(x() - character_size, y());
        }
        break;
    case Qt::Key_Up:
        if (CheckNextStep(x(), y() - character_size))
        {
            this->setPos(x(), y() - character_size);
        }
        break;
    case Qt::Key_Down:
        if (CheckNextStep(x(), y() + character_size))
        {
            this->setPos(x(), y() + character_size);
        }
        break;
    default:
        break;
    }


}


bool Block::CheckNextStep(int x, int y)
{

    qDebug() << x << y;
    y += character_size;
    if (y < 0 || x < 0) { return false; }
    int new_x = (character_size * size - (character_size * size - x))
        / character_size;
    int new_y = (character_size * size - (character_size * size - y))
        / character_size;
    if (x < character_size * size &&
        y < character_size * size && ((*level_map)[new_y][new_x] == 0))
    {
        return true;
    }
    return false;
}

Block::Block(vector<vector<int>>* level_map, const int character_size,
    const int size)
{
    this->level_map = level_map;
    this->character_size = character_size;
    this->size = size;
}

Block::~Block()
{
}