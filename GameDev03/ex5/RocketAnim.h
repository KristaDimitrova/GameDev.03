#ifndef ROCKETANIM_H
#define ROCKETANIM_H

#include "Animation.h"

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


class RocketAnim :
	public Animation
{
public:
	RocketAnim();
	RocketAnim(IrrlichtDevice* device, IVideoDriver* driver, u32 lastAnimationFrame);
	RocketAnim(const RocketAnim& orig);
	virtual ~RocketAnim();

	void draw() override;
	void animate(u32 currentTime) override;

private:

	int currentRowFrame = 0;
	int currentColumnFrame = 0;
	u32 lastAnimationFrame = 0;
	int rocketAnimFrameSizeW = 55;
	int rocketAnimFrameSizeH = 83;
	

	//u32 lastAnimationFrame = this->device->getTimer()->getTime();

	IrrlichtDevice* device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* rocketTexture = NULL;

	stringw rocketTextureLocation = "./media/rocket_spritesheet.png";

	rect<s32> rocketDimensions = rect<s32>((this->currentColumnFrame * 55), (this->currentRowFrame * 83), ((this->currentColumnFrame + 1) * 55), ((this->currentRowFrame + 1) * 83));

	position2d<s32> rocketPosition = position2d<s32>(225, 140);

};



#endif /* ROCKETANIM_H */

