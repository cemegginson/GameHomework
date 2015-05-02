#include "Rock.h"

#include "GameFunctions.h"

Rock::Rock() : Component() {}

Rock::~Rock() {
	world->DestroyBody(body);
}

void Rock::Update(float32 gameTime) {}

void Rock::Render(float32 gameTime, View* view) {
	texture->Render(gDevice->GetRenderer(), view, position, angle, nullptr);
}

void Rock::Initialize(GraphicsDevice* gDev, Texture* tex, b2World* wor, Vector2 pos, float32 ang) {
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
