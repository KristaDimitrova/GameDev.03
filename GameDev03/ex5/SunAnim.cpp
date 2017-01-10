#include "SunAnim.h"

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

SunAnim::SunAnim()
{
}

SunAnim::SunAnim(IrrlichtDevice* device, IVideoDriver* driver, u32 lastAnimationFrame)
{
	this->device = device;
	this->driver = driver;
	this->sunTexture = this->driver->getTexture(this->sunTextureLocation);
	this->lastAnimationFrame = lastAnimationFrame;
}

SunAnim::SunAnim(const SunAnim& orig)
{
}

SunAnim::~SunAnim()
{
	IrrlichtDevice* device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* sunTexture = NULL;
}

void SunAnim::draw() {
	//this->driver->draw2DImage(this->rocketTexture, this->rocketPosition, this->rocketDimensions, 0, SColor(255, 255, 255, 255), true);


	this->driver->draw2DImage(sunTexture, position2d<s32>(500, 100),
		rect<s32>(currentColumnFrame * 200, 0,
		(currentColumnFrame + 1) * 200, 200), 0,
		SColor(255, 255, 255, 255), true);
}

void SunAnim::animate(u32 currentTime) {
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

