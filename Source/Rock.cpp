#include "Rock.h"

#include "GameFunctions.h"

Rock::Rock() : Object() {}

Rock::~Rock() {
	world->DestroyBody(body);
}

void Rock::Update(GAME_FLT gameTime) {}

void Rock::Draw(GAME_FLT gameTime, View* view) {
	texture->Draw(gDevice->getRenderer(), view, position, angle, nullptr);
}

void Rock::Initialize(GraphicsDevice* gDev, Texture* tex, b2World* wor, GAME_VEC pos, GAME_FLT ang) {
	gDevice = gDev;
	texture = tex;
	world = wor;
	position = pos;
	angle = ang;

	// Physics stuff
	bdef.type = b2_staticBody;
	bdef.position.Set(RW2PW(position.x), RW2PW(position.y));
	bdef.angle = RW2PWAngle(angle);
	bdef.angularDamping = 0.1;
	bdef.linearDamping = 0.1;
	body = world->CreateBody(&bdef);

	int w, h;
	texture->GetDimensions(&w, &h);
	shape.m_radius = RW2PW(w/1.5f);
	shapefd.shape = &shape;
	shapefd.density = 0.1f;
	shapefd.friction = 0.5f;
	shapefd.restitution = 0.9f;
	body->CreateFixture(&shapefd);
}
