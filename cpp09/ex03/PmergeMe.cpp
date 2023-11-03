#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{

}

PmergeMe::~PmergeMe()
{

}


// [0,1,3,2]
void PmergeMe::sort_V_by_second()
{
    for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = _V.begin(); it != _V.end(); it++)
    {
        std::pair<unsigned int, unsigned int> key = *it;
        int j = it - _V.begin() - 1;
        while (j >= 0 && _V[j].second > key.second)
        {
            _V[j + 1] = _V[j];
            j--;
        }
        _V[j + 1] = key;
    }
    
}

void PmergeMe::make_SP()
{
    //take second elements of _V and put them in _S
    for (std::vector< std::pair<unsigned int, unsigned int> >::iterator it = _V.begin(); it != _V.end(); it++)
    {
        _S.push_back(it->second);
        _pend.push_back(it->first);
    }
}

void PmergeMe::sort_Q_by_second()
{
    for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = _D.begin(); it != _D.end(); it++)
    {
        std::pair<unsigned int, unsigned int> key = *it;
        int j = it - _D.begin() - 1;
        while (j >= 0 && _D[j].second > key.second)
        {
            _D[j + 1] = _D[j];
            j--;
        }
        _D[j + 1] = key;
    }
}

void PmergeMe::make_SP_deque()
{
    //take second elements of _D and put them in _S_deque
    for (std::deque< std::pair<unsigned int, unsigned int> >::iterator it = _D.begin(); it != _D.end(); it++)
    {
        _S_deque.push_back(it->second);
        _pend_deque.push_back(it->first);
    }
}

void PmergeMe::fjmi()
{
    sort_V_by_second();
    make_SP();
   //insert pend elements in _S using lower_bound
    for (std::vector<unsigned int>::iterator it = _pend.begin(); it != _pend.end(); it++)
    {
         std::vector<unsigned int>::iterator low = std::lower_bound(_S.begin(), _S.end(), *it);
         _S.insert(low, *it);
    }
}

void PmergeMe::fjmi_deque()
{
    sort_Q_by_second();
    make_SP_deque();
   //insert pend elements in _S using lower_bound
    for (std::deque<unsigned int>::iterator it = _pend_deque.begin(); it != _pend_deque.end(); it++)
    {
         std::deque<unsigned int>::iterator low = std::lower_bound(_S_deque.begin(), _S_deque.end(), *it);
         _S_deque.insert(low, *it);
    }
}

void PmergeMe::print_S()
{
    for (std::vector<unsigned int>::iterator it = _S.begin(); it != _S.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::print_S_deque()
{
    for (std::deque<unsigned int>::iterator it = _S_deque.begin(); it != _S_deque.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}



PmergeMe::PmergeMe(std::vector<unsigned int>& v)
{
    //check if vectore is odd 
    if (v.size() % 2 != 0)
    {
        _stragller = true;
        _stragler_value = v.back();
        v.pop_back();
    }
    //split the vector in pairs of 2 elements and put them in _V
    for (std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); it += 2)
    {
     
            //insert element in a sorted order
            if (*it < *(it + 1))
                _V.push_back(std::make_pair(*it, *(it + 1)));
            else
                _V.push_back(std::make_pair(*(it + 1), *it));
    }
}

PmergeMe::PmergeMe(std::deque<unsigned int>& d)
{
    if (d.size() % 2 != 0)
    {
        _stragller = true;
        _stragler_value = d.back();
        d.pop_back();
    }
    //split the deque in pairs of 2 elements and put them in _D
    for (std::deque<unsigned int>::iterator it = d.begin(); it != d.end(); it += 2)
    {
      
            //insert element in a sorted order
            if (*it < *(it + 1))
                _D.push_back(std::make_pair(*it, *(it + 1)));
            else
                _D.push_back(std::make_pair(*(it + 1), *it));
    
    }
        
}

PmergeMe::PmergeMe(const PmergeMe& object)
{
    *this = object;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& object)
{
    _V = object._V;
    _D = object._D;
    _S = object._S;
    _S_deque = object._S_deque;
    _pend = object._pend;
    _pend_deque = object._pend_deque;
    _stragller = object._stragller;
    _stragler_value = object._stragler_value;
    return *this;
}

