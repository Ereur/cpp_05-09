#pragma once

#include <vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <deque>
// this class will be used to sorte a vectore of unsigned int using FJMI algorithm
class PmergeMe
{
    private:
        std::vector< std::pair<unsigned int, unsigned int> > _V;
        std::vector<unsigned int> _S;
        std::vector<unsigned int> _pend;
        bool _stragller;
        int _stragler_value;

        std::deque< std::pair<unsigned int, unsigned int> > _D;
        std::deque<unsigned int> _S_deque;
        std::deque<unsigned int> _pend_deque;
        
        void sort_V_by_second();
        void make_SP();

        void sort_Q_by_second();
        void make_SP_deque();
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& object);
        PmergeMe& operator=(const PmergeMe& object);
        PmergeMe(std::vector<unsigned int>& v);
        PmergeMe(std::deque<unsigned int>& d);
        ~PmergeMe();

        void fjmi();
        void fjmi_deque();
        void print_S();
        void print_S_deque();
};
