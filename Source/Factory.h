#pragma once

#include <string>

class ObjectFactory {
protected:

public:
    ObjectFactory();
    ~ObjectFactory();
    virtual void Create(std::string xmlfile) = 0;
}

class InfantryFactory : ObjectFactory {
protected:

public:
    InfantryFactory();
    ~InfantryFactory();
    void Create(std::string xmlfile);
}

class CarrierFactory : ObjectFactory {
protected:

public:
    CarrierFactory();
    ~CarrierFactory();
    void Create(std::string xmlfile);
}
