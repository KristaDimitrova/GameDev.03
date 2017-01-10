#ifndef SUNANIM_H
#define SUNANIM_H

#include "Animation.h"

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


class SunAnim :
	public Animation
{
public:
	SunAnim();
	SunAnim(IrrlichtDevice* device, IVideoDriver* driver, u32 lastAnimationFrame);
	SunAnim(const SunAnim& orig);
	virtual ~SunAnim();

	void draw() override;
	void animate(u32 currentTime) override;

private:

	int currentRowFrame = 0;
	int currentColumnFrame = 0;
	u32 lastAnimationFrame = 0;
	int sunAnimFrameSizeW = 140;
	int sunAnimFrameSizeH = 140;


	//u32 lastAnimationFrame = this->device->getTimer()->getTime();

	IrrlichtDevice* device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* sunTexture = NULL;

	stringw sunTextureLocation = "./media/sunAnim.png";

	rect<s32> sunDimensions = rect<s32>((this->currentColumnFrame * 140), (this->currentRowFrame * 140), ((this->currentColumnFrame + 1) * 140), ((this->currentRowFrame + 1) * 140));

	position2d<s32> sunPosition = position2d<s32>(300, 200);

};



#endif /* SUNANIM_H */
