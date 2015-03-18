#include "Factory.h"
#include "pugixml.hpp"
#include <stdlib.h>

ObjectFactory::ObjectFactory() {

}

ObjectFactory::~ObjectFactory() {

}


InfantryFactory::InfantryFactory() {

}

InfantryFactory::~InfantryFactory() {

}

Object::Object* InfantryFactory::Create(pugi::xml_node tag) {
    Object* infantry = new Infantry();
    GAME_VEC vec;
    GAME_FLT ang;
    vec.x = atof(tag.attribute("x"));
    vec.y = atof(tag.attribute("y"));
    ang = atof(tag.attribute("angle"));
    infantry->Initialize(tex, vec, ang);
    return infantry;
}


CarrierFactory::CarrierFactory() {

}

CarrierFactory::~CarrierFactory() {

}

Object::Object* CarrierFactory::Create(pugi::xml_node tag) {
    Object* carrier = new Carrier();
    GAME_VEC vec;
    GAME_FLT ang;
    vec.x = atof(tag.attribute("x"));
    vec.y = atof(tag.attribute("y"));
    ang = atof(tag.attribute("angle"));
    carrier->Initialize(tex, vec, ang);
    return carrier;
}
