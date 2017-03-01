#ifndef POSITION_H
#define POSITION_H

enum Direction {
    UP = 0, DOWN, LEFT, RIGHT
};

struct Position
{
    int x;
    int y;

    Position(int x_, int y_) : x(x_), y(y_) {}

    Position move(Direction d)
    {
        const int dx[] = {0,0,-1,1};
        const int dy[] = {-1,1,0,0};
        return Position(x+dx[d],y+dy[d]);
    }

    bool isInsideBox(int left, int top, int width, int height) {
        return x >= left && x < left+width && y >= top && y < top+height;
    }
};

#endif // POSITION_H
