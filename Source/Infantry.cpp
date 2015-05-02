#include "Infantry.h"

#include "GameFunctions.h"

Infantry::Infantry() : Component() {
	rotation_rate_ = 90;
}

Infantry::~Infantry() {
	;
}

void Infantry::Update(float32 delta_time) {
	float32 angle = owner_->GetAngle();
	angle += rotation_rate_ * delta_time;
	owner_->SetAngle(angle);
}

void Infantry::Initialize() {
	;
}
