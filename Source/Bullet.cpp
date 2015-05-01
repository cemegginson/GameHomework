#include "Bullet.h"
#include "GameFunctions.h"

Bullet::Bullet() : Object() {}

Bullet::~Bullet() {
	delete texture;
	world->DestroyBody(body);
}

void Bullet::Update(float32 deltaTime) {
	//position.x += velocity.x;
	//position.y += velocity.y;
	life += deltaTime;

	b2Vec2 physPosition;
	physPosition = body->GetPosition();

	body->SetTransform(physPosition, body->GetAngle());

	position.x = (int)PW2RW(physPosition.x) - w/2.0;
	position.y = (int)PW2RW(physPosition.y) - h/2.0;
	angle = PW2RWAngle(body->GetAngle());
}

void Bullet::Render(float32 gameTime, View* view) {
	texture->Render(gDevice->GetRenderer(), view, position, NULL, nullptr);
}

void Bullet::Initialize(GraphicsDevice* gDev, Texture* tex, b2World* wor, Vector2 origin, Vector2 ivelocity) {
	gDevice = gDev;
	texture = tex;
	world = wor;
	position = origin;
	velocity.x = ivelocity.x * 2;
	velocity.y = ivelocity.y * 2;
	life = 0;

	// Physics stuff
	bdef.type = b2_dynamicBody;
	bdef.position.Set(RW2PW(position.x), RW2PW(position.y));
	bdef.angle = RW2PWAngle(angle);
	bdef.bullet = true;
	bdef.angularDamping = 0.1;
	bdef.linearDamping = 0.1;
	bdef.linearVelocity = velocity;
	body = world->CreateBody(&bdef);

	texture->GetDimensions(&w, &h);
	shape.m_radius = RW2PW(w/1.5f);
	shapefd.shape = &shape;
	shapefd.density = 10.0f;
	shapefd.friction = 0.0f;
	shapefd.restitution = 1.1f;
	body->CreateFixture(&shapefd);
}

int Bullet::GetLife() {
	return life;
}
