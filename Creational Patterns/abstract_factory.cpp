#include<iostream> 

using namespace std;

enum PizzaSyte{PizzaSyteNy, PizzaSyteChicago};

class Cheese {}; 

class RegianoCheese: public Cheese{};
class MozzarvellaCheese: public Cheese{};

class Sauce{}; 

class MarinaraSauce: public Sauce{};
class PlumSauce: public Sauce{};

class Dough{}; 

class ThinCrustDough: public Dough{}; 
class ThickCrustDough: public Dough{};

// PizzaIngredientFactory is the abstract factory.
// All the object creation happens inside factory method.
class PizzaIngredientFactory {
    public: 
        virtual Cheese createCheese() = 0; 
        virtual Dough createDough() = 0; 
        virtual Sauce createSauce() = 0;
};


class NYPizzaIngredientFactory: public PizzaIngredientFactory {
    Cheese createCheese() {
        return RegianoCheese(); 
    }

    Dough createDough() {
        return ThinCrustDough(); 
    }

    Sauce createSauce() {
        return MarinaraSauce(); 
    }
};

class ChicagoPizzaIngredientFactory: public PizzaIngredientFactory {
    Cheese createCheese() {
        return MozzarvellaCheese(); 
    }

    Dough createDough() {
        return ThickCrustDough(); 
    }

    Sauce createSauce() {
        return PlumSauce(); 
    }
};


class Pizza{
    PizzaIngredientFactory* ingrediantFactory; 

    public:
    void prepare(PizzaSyte style) {
        if (style == PizzaSyteNy) {
           ingrediantFactory  = new NYPizzaIngredientFactory; 
        } 

        if (style == PizzaSyteChicago) {
            ingrediantFactory = new ChicagoPizzaIngredientFactory;
        }
            
        Dough dough = ingrediantFactory->createDough();
        Cheese cheese = ingrediantFactory->createCheese(); 
        Sauce sauce = ingrediantFactory->createSauce();
    } 
};

int main() {
    // client interacts only with the Pizza object 
    Pizza pizza;
    pizza.prepare(PizzaSyteNy);
}
