#include "SpiderFishGame.h"
#define img_resource(P) "resources/images/"P

int main(int argc, char * args[])
{
	SpiderFishGame game;
	bool result = game.start();

	if (result)
		return 0;
	else
		return 1;
}
