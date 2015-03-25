#include <math.h>
#include "Carrier.h"

Carrier::Carrier() : Object() {}

Carrier::~Carrier() {}

void Carrier::Update(GAME_FLT gameTime) {
	angle += .5;
	if(angle > 360) {
		angle -= 360;
	} else if(angle < 0) {
		angle += 360;
	}
	float rAngle = PI / 180.0;

}

void Carrier::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Carrier::Initialize(GraphicsDevice* gDev, Texture* tex, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	position = pos;
	angle = ang;
}
