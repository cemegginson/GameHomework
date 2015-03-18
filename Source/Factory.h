#pragma once

#include <string>
#include "pugixml.hpp"

class ObjectFactory {
protected:

public:
    ObjectFactory();
    ~ObjectFactory();
    virtual void Create(pugi::xml_node) = 0;
}

class InfantryFactory : ObjectFactory {
protected:

public:
    InfantryFactory();
    ~InfantryFactory();
    void Create(pugi::xml_node);
}

class CarrierFactory : ObjectFactory {
protected:

public:
    CarrierFactory();
    ~CarrierFactory();
    void Create(pugi::xml_node);
}
