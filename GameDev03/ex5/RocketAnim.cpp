#include "RocketAnim.h"

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

RocketAnim::RocketAnim()
{
}

RocketAnim::RocketAnim(IrrlichtDevice* device, IVideoDriver* driver, u32 lastAnimationFrame)
{
	this->device = device;
	this->driver = driver;
	this->rocketTexture = this->driver->getTexture(this->rocketTextureLocation);
	this->lastAnimationFrame = lastAnimationFrame;
}

RocketAnim::RocketAnim(const RocketAnim& orig)
{
}

RocketAnim::~RocketAnim()
{
	IrrlichtDevice* device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* rocketTexture = NULL;
}

	void RocketAnim::draw() {
	//this->driver->draw2DImage(this->rocketTexture, this->rocketPosition, this->rocketDimensions, 0, SColor(255, 255, 255, 255), true);


		this->driver->draw2DImage(rocketTexture, position2d<s32>(350, 200),
		rect<s32>(currentColumnFrame * rocketAnimFrameSizeW, currentRowFrame * rocketAnimFrameSizeH,
		(currentColumnFrame + 1) * rocketAnimFrameSizeW, (currentRowFrame + 1) * rocketAnimFrameSizeH), 0,
		SColor(255, 255, 255, 255), true);
}

void RocketAnim::animate(u32 currentTime) {
	if (currentTime - this->lastAnimationFrame >= (1000 / 60)) {
		this->currentColumnFrame++;
		this->lastAnimationFrame = currentTime;

	}
	if (this->currentColumnFrame >= 10) {
		this->currentColumnFrame = 0;
		this->currentRowFrame++;
	}
	if (this->currentRowFrame >= 6) {
		this->currentRowFrame = 0;
	}
}

