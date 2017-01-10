#include "HealthBar.h"
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace video;
 

HealthBar::HealthBar() {

}

HealthBar::HealthBar(IrrlichtDevice *device, IVideoDriver* driver) {
	this->device = device;
	this->driver = driver;

}

HealthBar::HealthBar(const HealthBar& orig) {

}

HealthBar::~HealthBar() {
	IrrlichtDevice *device = NULL;
	IVideoDriver* driver = NULL;
	ITexture* healthBarEmpty = NULL;
	ITexture* healthBarFull = NULL;
}
void HealthBar::create()
{
	this->healthBarEmpty = this->driver->getTexture("./media/empty-health.png");
	this->healthBarFull = this->driver->getTexture("./media/full-health.png");
}


void HealthBar::draw() {
	rect<s32> emptybar(0, 0, 100, 22);
	rect<s32> fullbar(this->health, 0, 95, 16);
	this->driver->draw2DImage(healthBarEmpty, position2d<s32>(20, 10), emptybar, 0, SColor(255, 255, 255, 255), true);
	this->driver->draw2DImage(healthBarFull, position2d<s32>(22, 12), fullbar, 0, SColor(255, 255, 255, 255), true);
}

void HealthBar::destroyHealthBar() {
	delete this;
}

void HealthBar::setHealth(int health) {
	this->health = health;
}

int HealthBar::getHealth() const {
	return this->health;
}
