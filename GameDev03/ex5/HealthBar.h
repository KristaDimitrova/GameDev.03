#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "HUD.h"

#include <irrlicht.h>
//#include "driverChoice.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class HealthBar :
	public HUD 
{
public:
	HealthBar();
	HealthBar(IrrlichtDevice *device, IVideoDriver* driver);
	HealthBar(const HealthBar& orig);
	virtual ~HealthBar();

	void draw() override;
	void create() override;
	//void drawHealthBar();
	void destroyHealthBar();

	void setHealth(int health);
	int getHealth() const;

private:
	int health = 193;

	IrrlichtDevice* device = NULL;
	IVideoDriver* driver = NULL;

	ITexture* healthBarEmpty = NULL;
	ITexture* healthBarFull = NULL;


};


#endif /* HEALTHBAR_H */

