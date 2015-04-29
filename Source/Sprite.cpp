#include "Sprite.h"

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::~Sprite() {
    delete texture;
}

void Sprite::Initialize(GraphicsDevice* gDevice, std::string imPath) {
	this->gDevice = gDevice;

	//Add Sprite to gDevice
	gDevice->AddSprite(this);

	//Load the Art Asset
	texture = new Texture();
	texture->Initialize(gDevice->GetRenderer(), imPath);
}

void Sprite::Update(float32 deltaTime) {
    ;
}

void Render() {
    vector2 position = owner->GetPosition();
    float32 angle = owner->GetAngle();
    // Not finished here
    texture->Render(gDevice->GetRenderer(), view, position, angle, clip);
}
