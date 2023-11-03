#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange& object)
{
    *this = object;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& copy)
{
    _DataCsv = copy.getDataCsv();
    return (*this);
}

std::map<std::string, float>& BitcoinExchange::getDataCsv()
{
    return (_DataCsv);
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::setDataCsv()
{
    
    std::string line;
    std::ifstream   input;
    input.open("./data.csv");
    // std::cout << line << std::endl;
    getline(input, line);
    while(getline(input, line))
    {
        // std::cout << "line :  " << line << std::endl;
        size_t end = line.find(",");
        _DataCsv[line.substr(0, end)] = std::atof(line.substr(end+1).c_str());
    }
    input.close();
}

bool isFloatOrDigit(const std::string &str) {
    bool decimalPointFound = false; // to track if a decimal point is encountered
    bool digit = false;
    
    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        // Check if the character is a digit or a valid decimal point
        if (std::isdigit(c)) {
            digit = true;
            continue; // It's a digit, continue checking
        } else if (c == '.' && !decimalPointFound) {
            decimalPointFound = true;
        } else {
            return false; // Character is not a digit or a valid decimal point
        }
    }

    // Ensure there is at least one digit
    return decimalPointFound || digit;
}


std::string removeWhitespace(const std::string &input) {
    std::string result;
    
    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isspace(input[i])) {
            result += input[i];
        }
    }
    return result;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date) {
    // check if the date has the correct format "yyyy-mm-dd"
    if (date.length() != 10) {
        return false;
    }

    int year, month, day;
    char dash;
    std::istringstream ss(date);

    // Attempt to parse the date
    if (ss >> year >> dash >> month >> dash >> day) {
        // check if the parsed values in a reasonable bounds
        if (ss.eof() && year >= 0 && month >= 1 && month <= 12 && day >= 1) {
            int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            // adjust february days for leap years
            if (isLeapYear(year)) {
                daysInMonth[2] = 29;
            }

            if (day <= daysInMonth[month]) {
                return true;
            }
        }
    }

    return false;
}

void BitcoinExchange::printExangeRate(std::string name)
{
    std::string line;
    std::ifstream   input;
    input.open(name.c_str());
    getline(input, line);
    // std::cout<< "line:" << line;
    if (std::strcmp(line.c_str(), "date | value"))
        throw "the header is missing";
    while(getline(input, line))
    {
        try
        {
            size_t end = line.find("|");
            std::string date = removeWhitespace(line.substr(0, end));
            std::string value = removeWhitespace(line.substr(end+1));
            // std::cout << "Date : " << date << std::endl;
            // std::cout << "Value : " << value << std::endl;  
            if (!isValidDate(date))
                throw "Error: date is not valide";
            if (!isFloatOrDigit(value))
                throw "Error: value is not valide";
            
            std::map<std::string, float>::iterator it = _DataCsv.find(date);
            float val = std::atof(value.c_str());
            if (val < 0 || val > 1000)
                throw "Error: value is not valide";

            if (it != _DataCsv.end())
            {
                std::cout << date << " => " << value << " = " << val * it->second << std::endl;
            }
            else
            {

                std::map<std::string, float>::iterator lowest = _DataCsv.lower_bound(date);

                    // Check if the iterator is valid and if it's not the first element in the map
                    if (lowest != _DataCsv.begin() && lowest != _DataCsv.end()) {
                        --lowest;  // Decrement the iterator to get the lower bound
                        std::cout << date << " => " << value << " = " << val * lowest->second << std::endl;
                    } 
                    else {
                        std::cout << "No lowest rate found in database " << std::endl;
                    }
            }
        }
        catch(char const *e)
        {
            std::cout << e << std::endl;
        }
    }

    // for(std::map<std::string, float>::iterator it = _DataCsv.begin(); it != _DataCsv.end(); it++)
    // {
    //     std::cout << it->first << ":" << it->second << std::endl;
    // }
}