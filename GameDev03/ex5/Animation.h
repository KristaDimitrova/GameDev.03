#ifndef ANIMATION_H
#define ANIMATION_H

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Animation {
public:
	Animation();
	Animation(const Animation& orig);
	virtual ~Animation();

	//virtual void createAnim() = 0;
	virtual void draw() = 0;
	virtual void animate(u32 time) = 0;

private:

};

#endif /* ANIMATION_H */