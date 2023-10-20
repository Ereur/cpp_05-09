#include "Base.hpp"
#include "Childs.hpp"
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <iostream>



Base * generate(void)
{
    std::srand(time(NULL));

    switch(int randNum = (std::rand() % 3) + 1)
    {
        case 1 :
            return new A();
        case 2 :
            return new B();
        case 3 :
            return new C();
    }
    return (NULL);
}

void identify(Base* p)
{
    A *checkA = dynamic_cast<A*> (p);
    if (checkA)
        std::cout << "the object pointed to by p: A" << std::endl;
    B *checkB = dynamic_cast<B*> (p);
    if (checkB)
        std::cout << "the object pointed to by p: B" << std::endl;
    C *checkC = dynamic_cast<C*> (p);
    if (checkC)
        std::cout << "the object pointed to by p: C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &checkA = dynamic_cast<A&> (p);
        (void)checkA;
        std::cout << "the object pointed to by p: A" << std::endl;
    }
    catch(...)
    {
        try
        {
            B &checkB = dynamic_cast<B&> (p);
            (void)checkB;
            std::cout << "the object pointed to by p: B" << std::endl;
        }
        catch(...)
        {
            try
            {
                C &checkC = dynamic_cast<C&> (p);
                (void)checkC;
                std::cout << "the object pointed to by p: C" << std::endl;
            }
            catch(...)
            {
                std::cout << "the object dosent point to any of : A B C" << std::endl;
            }
        }
    }
}

int main() {

    Base *type = generate();

    identify(*type);

}
