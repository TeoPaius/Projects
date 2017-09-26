#include "ship.h"

Ship::Ship(QObject *parent) : QObject(parent)
{
    x = -1;
    y = -1;
    orientation = 1;

}

void Ship::SetLength(int l)
{
    length = l;
}

void Ship::SetPos(int _x, int _y)
{
    x = _x;
    y = _y;
}

