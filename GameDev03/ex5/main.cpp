#include <irrlicht.h>
#include <irrKlang.h>
#include "driverChoice.h"
#include "HUD.h"
#include "HealthBar.h"
#include "Animation.h"
#include "RocketAnim.h"
#include "Bulletbar.h"
#include "SunAnim.h"


using namespace irr;
using namespace core;
using namespace gui;
using namespace io;
using namespace video;
using namespace irrklang;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
#endif


int main()
{


	// create device
	IrrlichtDevice *device = createDevice(video::EDT_DIRECT3D9,
		core::dimension2d<u32>(800, 600));

	if (device == 0)
		return 1; // could not create selected driver.

	device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

	video::IVideoDriver* driver = device->getVideoDriver();

	video::ITexture* images = driver->getTexture("./media/Background_Colorful_Galaxy-800x600.jpg");
	
	
//	int currentColumn = 0;
//	int row = 0;
//	int LastFps = -1;

	rect<s32> Background = rect<s32>(0, 0, 800, 600);

	driver->getMaterial2D().TextureLayer[0].BilinearFilter = true;
	driver->getMaterial2D().AntiAliasing = video::EAAM_FULL_BASIC;

	HUD* healthBar = new HealthBar(device, driver);
	healthBar->create();

	HUD* bulletBar = new BulletBar(device, driver);
	bulletBar->create();

	//HealthBar* healthBar = new HealthBar(device, driver);
	//BulletBar* bulletBar = new BulletBar(device, driver);

	u32 lastAnimationFrame = device->getTimer()->getTime();

	Animation* rocket = new RocketAnim(device, driver, lastAnimationFrame);

	Animation* sun = new SunAnim(device, driver, lastAnimationFrame);

	

	//Animation* rocket = new RocketAnim(device, driver, lastAnimationFrame);
	//rocket->createAnim();

//	s32 lastFPS = -1;
	u32 currentTime = 0;
	u32 lastTime = 0;
	u32 Dt = currentTime - lastTime;

	int currentColumnFrame = 0;
	int currentRowFrame = 0;
	s32 lastFPS = -1;
	//u32 lastTime = device->getTimer()->getTime();
	//u32 lastAnimationFrame = device->getTimer()->getTime();

	int previousFrame = 0;



	while (device->run() && driver)
	{
		if (device->isWindowActive())
		{
			currentTime = device->getTimer()->getTime();
			rocket->animate(currentTime);
			sun->animate(currentTime);

			driver->beginScene(true, true, video::SColor(255, 255, 255, 255));

			// draw fire & dragons background world
			driver->draw2DImage(images, core::position2d<s32>(0, 0), // start position
				Background, 0,
				video::SColor(255, 255, 255, 255), true);

	//		driver->draw2DImage(rocketTexture, position2d<s32>(225, 140),
	//			rect<s32>(0, 0, 55, 83), 0, SColor(255, 255, 255, 255), true);

			healthBar->draw();
			bulletBar->draw();
			rocket->draw();
			sun->draw();

			//hud->drawBulletBar();

			/*
			driver->draw2DImage(sun, position2d<s32>(300, 200),
				sun1, 0,
				video::SColor(255, 255, 255, 255), true);
			driver->draw2DImage;
			 draw Ship
			*/


			driver->endScene();

			lastTime = currentTime;
			//int fps = driver->getFPS();

			/*
			if (LastFps != fps){

				core::stringw stringFSP = L"Fps :";
				stringFSP += fps;
				device->setWindowCaption(stringFSP.c_str());
				LastFps = fps;
				//lastTime = currentTime;
			}
			*/

		}
	}
	//destroy HUD
	//healthBar->destroyHealthBar();
//	animation->destroyRocketAnim();
	delete healthBar;
	delete bulletBar;
	delete rocket;
	delete sun;

	device->drop();

	return 0;
}
