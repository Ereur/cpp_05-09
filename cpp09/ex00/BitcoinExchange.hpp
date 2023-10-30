#ifndef _BITCOINEXCHANGE_HPP
#define _BITCOINEXCHANGE_HPP

#include <map>
#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _DataCsv;

    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange&);
        BitcoinExchange& operator=(BitcoinExchange&);
        ~BitcoinExchange();

        void setDataCsv();
        bool isValidDate(const std::string& Date);
        std::map<std::string, float>& getDataCsv();
        std::ifstream& openFile(const std::string& name);
        void printExangeRate(std::string name);
};

#endif