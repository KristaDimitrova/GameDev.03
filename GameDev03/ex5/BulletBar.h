#pragma once
#ifndef BULLETBAR_H
#define BULLETBAR_H

#include "HUD.h"

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class BulletBar :
	public HUD
{
public:
	BulletBar();
	BulletBar(IrrlichtDevice* device, IVideoDriver* driver);
	BulletBar(const BulletBar& orig);
	virtual ~BulletBar();

	void draw() override;
	void create() override;
	//void drawBulletBar();
	void destroyBulletBar();

	void setBulletBar(int bullet);
	int getBulletBar() const;

private:
	int bullet = 193;

	IrrlichtDevice* device = NULL;
	IVideoDriver* driver = NULL;

	ITexture* bulletBarEmpty = NULL;
	ITexture* bulletBarFull = NULL;

};
#endif /* BULLETBAR_H */
