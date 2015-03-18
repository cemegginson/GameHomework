#pragma once

#include <string>
#include "pugixml.hpp"
#include "Object.h"

class ObjectFactory {
protected:

public:
    ObjectFactory();
    ~ObjectFactory();
    virtual Object* Create(pugi::xml_node) = 0;
};

class InfantryFactory : ObjectFactory {
protected:

public:
    InfantryFactory();
    ~InfantryFactory();
    Object* Create(pugi::xml_node);
};

class CarrierFactory : ObjectFactory {
protected:

public:
    CarrierFactory();
    ~CarrierFactory();
    Object* Create(pugi::xml_node);
};
