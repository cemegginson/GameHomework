#include "Infantry.h"

#include "GameFunctions.h"

Infantry::Infantry() : Object() {}

Infantry::~Infantry() {
	world->DestroyBody(body);
	delete texture;
}

void Infantry::Update(float32 deltaTime) {
	b2Vec2 physPosition;
	physPosition = body->GetPosition();

	body->SetTransform(physPosition, RW2PWAngle(PW2RWAngle(body->GetAngle()) + rotation * deltaTime));

	position.x = (int)PW2RW(physPosition.x) - w/2.0;
	position.y = (int)PW2RW(physPosition.y) - h/2.0;
	angle = PW2RWAngle(body->GetAngle());
}

void Infantry::Render(float32 gameTime, View* view) {
	texture->Render(gDevice->GetRenderer(), view, position, angle, nullptr);
}

void Infantry::Initialize(GraphicsDevice* gDev, Texture* tex, b2World* wor, Vector2 pos, float32 ang) {
	gDevice = gDev;
	texture = tex;
	world = wor;
	position = pos;
	angle = ang;
	rotation = 100;

	// Physics stuff
	bdef.type = b2_dynamicBody;
	bdef.position.Set(RW2PW(position.x), RW2PW(position.y));
	bdef.angle = RW2PWAngle(angle);
	bdef.angularDamping = 10.0;
	bdef.linearDamping = 10.0;
	body = world->CreateBody(&bdef);

	texture->GetDimensions(&w, &h);
	shape.m_radius = RW2PW(w/2.0f);
	shapefd.shape = &shape;
	shapefd.density = 0.1f;
	shapefd.friction = 0.0f;
	shapefd.restitution = 0.0f;
	body->CreateFixture(&shapefd);
}
