#include "Sprite.h"

Sprite::Sprite() : Component() {
    texture_ = nullptr;
}

Sprite::~Sprite() {
    delete texture_;
}

void Sprite::Initialize(GraphicsDevice* graphics_device, Texture* texture) {
	graphics_device_ = graphics_device;
    texture_ = texture;

	//Add Sprite to graphics_device_
	graphics_device_->AddSprite(std::shared_ptr<Sprite>(this));


}

void Sprite::Update(float32 delta_time) {
    ;
}

void Render() {
    Vector2 position = owner->GetPosition();
    float32 angle = owner->GetAngle();
    // Not finished here
    texture_->Render(graphics_device_->GetRenderer(), view, position, angle, clip);
}
