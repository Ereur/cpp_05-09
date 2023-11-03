#include "PmergeMe.hpp"
#include <ctime>
#include <sys/time.h>

int main(int ac, char **argv)
{
   // put agrv data in a vector of unsigned int
    if (ac > 1)
    {
        std::vector<unsigned int> v;
        for (int i = 1; i < ac; i++)
        {
            std::stringstream ss(argv[i]);
            // check if the argument is a number
            long long n;
            if (ss >> n && n >= 0 && n <= std::numeric_limits<unsigned int>::max())
            {
                    v.push_back(n);
            }
            else
            {
                std::cout << "Invalid argument: " << argv[i] << std::endl;
                return 1;
            }   
        }
        std::cout << "Befor:" ;
        // print the vector
        for (std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        PmergeMe p(v);
        //count time of execution of fjmi
        struct timeval start, end;
        gettimeofday(&start, NULL);
        p.fjmi();
        gettimeofday(&end, NULL);
        std::cout << "After:" ;
        p.print_S();

        double time_taken = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
        std::cout << "Time taken by vector is : " << time_taken << " microseconds" << std::endl;


        // // print the vector
        // for (std::vector<unsigned int>::iterator it = v.begin(); it != v.end(); it++)
        //     std::cout << *it << std::endl;  

        std::cout << "-------------------" << std::endl;
        std::deque<unsigned int> d;
        for (int i = 1; i < ac; i++)
        {
            std::stringstream ss(argv[i]);
            // check if the argument is a number
            long long n;
            if (ss >> n && n >= 0 && n <= std::numeric_limits<unsigned int>::max())
            {
                    d.push_back(n);
            }
            else
            {
                std::cout << "Invalid argument: " << argv[i] << std::endl;
                return 1;
            }   
        }

        std::cout << "Befor:" ;
        // print the deque
        for (std::deque<unsigned int>::iterator it = d.begin(); it != d.end(); it++)
            std::cout << *it << " ";
        PmergeMe p2(d);
        //count time of execution of fjmi
        struct timeval start2, end2;
        gettimeofday(&start2, NULL);
        p2.fjmi_deque();
        gettimeofday(&end2, NULL);
        std::cout << "After:" ;
        p2.print_S_deque();

        double time_taken2 = (end2.tv_sec - start2.tv_sec) * 1000000 + (end2.tv_usec - start2.tv_usec);
        std::cout << "Time taken by deque is : " << time_taken2 << " microseconds" << std::endl;
    }
    else
        std::cout << "No arguments" << std::endl;
    return 0;
}
