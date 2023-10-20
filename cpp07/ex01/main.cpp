#include "Iter.hpp"

int add (int a)
{
    return (a + 1);
}

int main()
{
    int f[] = {1,2,3,4,5};

    iter(f,5,add);
    for(int i = 0; i < 5; i++)
    {
        std::cout << f[i] << std::endl;
    }

}
