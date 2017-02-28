#include <vector>
#include "PlayGround.h"

using namespace std;

PlayGround::PlayGround(int width, int height)
    : squares(height, vector<CellType>(width, CELL_EMPTY)),
      snake(this),
      status(GAME_RUNNING),
      score(0)
{
    addCherry();
}

PlayGround::~PlayGround()
{
    //dtor
}
