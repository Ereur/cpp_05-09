#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
    {
        std::cout << "--------------test with default underlaying container" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

     
        std::stack<int> s(mstack);
    }

    {
        std::cout << "--------------test with list underlaying container" << std::endl;
	    
        std::vector<int, std::list<int> > ms1;
        MutantStack<int, std::list<int> > ms;

	    ms.push(5);
        ms.push(10);
        ms.push(51);
        ms.push(232);
        ms.push(442);
        ms.push(2423);
        ms.push(23432);

	    std::cout << ms.top() << std::endl;
        ms.pop();

        for (MutantStack<int,std::list<int> >::iterator it = ms.begin(); it != ms.end(); it++)
        {
            std::cout << *it << std::endl;
        }
    }

    {
        std::cout << "--------------test with VECTOR underlaying container" << std::endl;
	    MutantStack<int, std::vector<int> > ms;

	    ms.push(5);
        ms.push(10);
        ms.push(51);
        ms.push(232);
        ms.push(442);
        ms.push(2423);
        ms.push(23432);

	    std::cout << ms.top() << std::endl;
        ms.pop();

        for (MutantStack<int,std::vector<int> >::iterator it = ms.begin(); it != ms.end(); it++)
        {
            std::cout << *it << std::endl;
        }
    }
    return 0;
}