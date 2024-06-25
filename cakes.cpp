#include <iostream>
#include <vector>
#include <string>
#include <gtest/gtest.h>

using str = std::string;

//Base-Class CAKE
class Cake {
protected:
    str name;
public:
    Cake(const str& _name) : name(_name) {}
    virtual ~Cake() = default;

    virtual void bake() const = 0;
    virtual void frost() const = 0;
    virtual void box() const = 0;

    str get_name() const { return name; }
};