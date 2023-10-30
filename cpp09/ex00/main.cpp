#include "BitcoinExchange.hpp"

int main(int ac, char **argv)
{
    BitcoinExchange btc;
    if (ac == 2)
    {   
        try
        {
            btc.setDataCsv();
            btc.printExangeRate(argv[1]);
        }
        catch(char const *e)
        {
            std::cout << e << std::endl;
        }
    }
    return (0);
}
