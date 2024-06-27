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
    str size; //small/medium/large
    double price; //in $

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
        std::cout << "List of Ingredients used: ";
        for (const auto& ingredient : ingredients) {
            std::cout << ingredient << " ";
        }
        std::cout << std::endl;
    }

    void cost() const override{
        std::cout << "All inclusive price of the product = " << price << "$." << std::endl;
    }
};

// Derived VanillaCake class
class VanillaCake : public Cake {
public:
    VanillaCake() {}

    void bake() const override {
        std::cout << "Baking a vanilla cake with a light and fluffy texture for " << baking_time << " minutes." << std::endl;
    }

    void frost() const override {
        std::cout << "Frosting the vanilla cake with buttercream icing." << std::endl;
    }

    void box() const override {
        std::cout << "Boxing the vanilla cake in a simple, elegant box." << std::endl;
    }

    void list() const override {
        std::cout << "List of Ingredients used: ";
        for (const auto& ingredient : ingredients) {
            std::cout << ingredient << " ";
        }
        std::cout << std::endl;
    }

    void cost() const override{
        std::cout << "All inclusive price of the product = " << price << "$." << std::endl;
    }
};

// Derived Cheesecake class
class Cheesecake : public Cake {
public:
    Cheesecake() {}

    void bake() const override {
        std::cout << "Baking a creamy cheesecake with a graham cracker crust for " << baking_time << " minutes." << std::endl;
    }

    void frost() const override {
        std::cout << "Adding a layer of fruit topping to the cheesecake." << std::endl;
    }

    void box() const override {
        std::cout << "Boxing the cheesecake in a refrigerated box." << std::endl;
    }

    void list() const override {
        std::cout << "List of Ingredients used: ";
        for (const auto& ingredient : ingredients) {
            std::cout << ingredient << " ";
        }
        std::cout << std::endl;
    }

    void cost() const override{
        std::cout << "All inclusive price of the product = " << price << "$." << std::endl;
    }
};

// Bakery class to manage cakes and tests
class Bakery {
    std::vector<Cake*> cakes;
public:
    ~Bakery() {
        for (auto& cake : cakes) {
            delete cake;
        }
    }

    void add_cake(Cake* cake) {
        cakes.push_back(cake);
    }

    std::vector<str> process_cakes() const {
        std::vector<str> tasks;
        for (const auto& cake : cakes) {
            cake->bake();
            tasks.push_back("Baked " + cake->get_name());
            cake->frost();
            tasks.push_back("Frosted " + cake->get_name());
            cake->box();
            tasks.push_back("Boxed " + cake->get_name());
            cake->list();
            tasks.push_back("listed " + cake->get_name());
            cake->cost();
            tasks.push_back("Priced " + cake->get_name());
        }
        return tasks;
    }
};

// Test functions using assertions
void test_chocolate_cake() {
    Bakery bakery;
    ChocolateCake* chocolateCake = new ChocolateCake();
    chocolateCake->set_name("Chocolate Cake");
    chocolateCake->set_ingredients({"flour, ", "sugar, ", "cocoa powder, ", "eggs, ", "milk"});
    chocolateCake->set_baking_time(30);
    chocolateCake->set_size("Medium");
    chocolateCake->set_price(69.9);
    bakery.add_cake(chocolateCake);
    std::vector<str> tasks = bakery.process_cakes();

    assert(tasks.size() == 5);
    assert(tasks[0] == "Baked Chocolate Cake");
    assert(tasks[1] == "Frosted Chocolate Cake");
    assert(tasks[2] == "Boxed Chocolate Cake");
    assert(tasks[3] == "listed Chocolate Cake");
    assert(tasks[4] == "Priced Chocolate Cake");
    
}

void test_vanilla_cake() {
    Bakery bakery;
    VanillaCake* vanillaCake = new VanillaCake();
    vanillaCake->set_name("Vanilla Cake");
    vanillaCake->set_ingredients({"flour", "sugar", "vanilla extract", "eggs", "milk"});
    vanillaCake->set_baking_time(25);
    vanillaCake->set_size("Large");
    vanillaCake->set_price(420);
    bakery.add_cake(vanillaCake);
    std::vector<str> tasks = bakery.process_cakes();

    assert(tasks.size() == 5);
    assert(tasks[0] == "Baked Vanilla Cake");
    assert(tasks[1] == "Frosted Vanilla Cake");
    assert(tasks[2] == "Boxed Vanilla Cake");
    assert(tasks[3] == "listed Vanilla Cake");
    assert(tasks[4] == "Priced Vanilla Cake");
    
}

void test_cheesecake() {
    Bakery bakery;
    Cheesecake* cheesecake = new Cheesecake();
    cheesecake->set_name("Cheesecake");
    cheesecake->set_ingredients({"cream cheese", "sugar", "eggs", "graham crackers"});
    cheesecake->set_baking_time(45);
    cheesecake->set_size("Small");
    cheesecake->set_price(666);
    bakery.add_cake(cheesecake);
    std::vector<str> tasks = bakery.process_cakes();

    assert(tasks.size() == 5);
    assert(tasks[0] == "Baked Cheesecake");
    assert(tasks[1] == "Frosted Cheesecake");
    assert(tasks[2] == "Boxed Cheesecake");
    assert(tasks[3] == "listed Cheesecake");
    assert(tasks[4] == "Priced Cheesecake");
    
}

//Big test, testing all the classes using polymorphism
void test_all() {
    Bakery bakery;

    Cake* chocolateCake = new ChocolateCake();
    chocolateCake->set_name("Chocolate Cake");
    chocolateCake->set_ingredients({"flour", "sugar", "cocoa powder", "eggs", "milk"});
    chocolateCake->set_baking_time(30);
    chocolateCake->set_size("Medium");
    chocolateCake->set_price(69.9);
    bakery.add_cake(chocolateCake);

    Cake* vanillaCake = new VanillaCake();
    vanillaCake->set_name("Vanilla Cake");
    vanillaCake->set_ingredients({"flour", "sugar", "vanilla extract", "eggs", "milk"});
    vanillaCake->set_baking_time(25);
    vanillaCake->set_size("Large");
    vanillaCake->set_price(420);
    bakery.add_cake(vanillaCake);

    Cake* cheesecake = new Cheesecake();
    cheesecake->set_name("Cheesecake");
    cheesecake->set_ingredients({"cream cheese", "sugar", "eggs", "graham crackers"});
    cheesecake->set_baking_time(45);
    cheesecake->set_size("Small");
    cheesecake->set_price(666);
    bakery.add_cake(cheesecake);

    std::vector<str> tasks = bakery.process_cakes();

    assert(tasks.size() == 15);
    assert(tasks[0] == "Baked Chocolate Cake");
    assert(tasks[1] == "Frosted Chocolate Cake");
    assert(tasks[2] == "Boxed Chocolate Cake");
    assert(tasks[3] == "listed Chocolate Cake");
    assert(tasks[4] == "Priced Chocolate Cake");
    assert(tasks[5] == "Baked Vanilla Cake");
    assert(tasks[6] == "Frosted Vanilla Cake");
    assert(tasks[7] == "Boxed Vanilla Cake");
    assert(tasks[8] == "listed Vanilla Cake");
    assert(tasks[9] == "Priced Vanilla Cake");
    assert(tasks[10] == "Baked Cheesecake");
    assert(tasks[11] == "Frosted Cheesecake");
    assert(tasks[12] == "Boxed Cheesecake");
    assert(tasks[13] == "listed Cheesecake");
    assert(tasks[14] == "Priced Cheesecake");

}


int main ()
{
    test_chocolate_cake();
    test_vanilla_cake();
    test_cheesecake();
    test_all();
    std::cout << "Mission complete. Repsect++" << std::endl;
    return 0;
}