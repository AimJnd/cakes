#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using str = std::string;

//Base-Class CAKE
class Cake {
protected:
    str name;
    std::vector<str> ingredients;
    int baking_time; // in minutes
    str size;
    double price;

public:
    Cake() : baking_time(0) {}

    virtual ~Cake() = default;

    virtual void bake() const = 0;
    virtual void frost() const = 0;
    virtual void box() const = 0;
    virtual void cost() const = 0;
    virtual void list() const = 0;

    void set_name(const str& _name) { name = _name; }
    void set_ingredients(const std::vector<str>& _ingredients) { ingredients = _ingredients; }
    void set_baking_time(int _baking_time) { baking_time = _baking_time; }
    void set_size(const str& _size) { size = _size; }
    void set_price(int _price) {price = _price; }

    str get_name() const { return name; }
    std::vector<str> get_ingredients() const { return ingredients; }
    int get_baking_time() const { return baking_time; }
    str get_size() const { return size; }
    int get_price () const {return price;}
};

// Derived ChocolateCake class
class ChocolateCake : public Cake {
public:
    ChocolateCake() {}

    void bake() const override {
        std::cout << "Baking a chocolate cake with rich cocoa flavor for " << baking_time << " minutes." << std::endl;
    }

    void frost() const override {
        std::cout << "Frosting the chocolate cake with dark chocolate ganache." << std::endl;
    }

    void box() const override {
        std::cout << "Boxing the chocolate cake in a decorative box." << std::endl;
    }

    void list() const override {
        std::cout << "List of ingredients used : " << ingredients << std::endl;
    }

    void cost() const override{
        std::cout << "All inclusive price of the product = " << price << "$." << std::endl;
    }
};


int main ()
{
    return 0;
}