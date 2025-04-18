#include "Base.hpp"
#include "Derived.hpp"

Base *generate(void){
    switch (rand() % 3){
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return nullptr;
    }
}

void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(std::bad_cast &e){
        try{
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(std::bad_cast &e){
            try{
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(std::bad_cast &e){
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main(){
    std::srand(std::time(NULL));
    std::cout << "------random testing------" << std::endl;
    for (int i = 0; i < 3; i++){
        Base *base = generate();
        identify(base);
        identify(*base);
        delete base;
    }
    std::cout << "-------manuel testing-------" << std::endl;
    Base *base2 = new A;
    identify(base2);
    identify(*base2);
    delete base2;

    std::cout << "------bad casting test------" << std::endl;
    Base *base3 = new B;
    try{
        (void)dynamic_cast<A&>(*base3);
    }
    catch(std::bad_cast &e){
        try{
            if (!dynamic_cast<A*>(base3))
                throw std::bad_cast();
        }
        catch(std::bad_cast &e){
            std::cout << "bad casting" << std::endl;
        }
    }
}
