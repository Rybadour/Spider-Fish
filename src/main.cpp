#include "SpiderFishGame.h"

int main(int argc, char * args[])
{
	SpiderFishGame game;
	bool result = game.start();

	if (result)
		return 0;
	else
		return 1;
}