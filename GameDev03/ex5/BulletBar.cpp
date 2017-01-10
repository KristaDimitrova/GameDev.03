#include "BulletBar.h"

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

BulletBar::BulletBar() {

}

BulletBar::BulletBar(IrrlichtDevice*device, IVideoDriver*driver)
{
	this->device = device;
	this->driver = driver;
}
BulletBar::BulletBar(const BulletBar& orig)
{
}


BulletBar::~BulletBar()
{
	IrrlichtDevice*device = NULL;
	IVideoDriver*driver = NULL;

	ITexture*BulletBarEmpty = NULL;
	ITexture*BulletBarFull = NULL;
}

void BulletBar::create()
{
	this->bulletBarEmpty = this->driver->getTexture("./media/empty-bullet.png");
	this->bulletBarFull = this->driver->getTexture("./media/full-bullet.png");
}
void BulletBar::draw()
{
	rect<s32> emptybar(0, 0, 100, 22);
	rect<s32> fullbar(this->bullet, 0, 95, 16);
	this->driver->draw2DImage(bulletBarEmpty, position2d<s32>(20, 40), emptybar, 0, SColor(255, 255, 255, 255), true);
	this->driver->draw2DImage(bulletBarFull, position2d<s32>(64, 22), fullbar, 0, SColor(255, 255, 255, 255), true);
}

void BulletBar::destroyBulletBar()
{
	delete this;
}
void BulletBar::setBulletBar(int bullet)
{
	this->bullet = bullet;
}
int BulletBar::getBulletBar() const
{
	return this->bullet;
}
