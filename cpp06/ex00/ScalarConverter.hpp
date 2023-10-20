#ifndef _SCALARCONVERTER_HPP
#define _SCALARCONVERTER_HPP




#include <iostream>

enum Type {
	FLOAT,
	DOUBLE,
	INT,
	CHAR,
};

class ScalarConverter {
    private:
		std::string	literal;
		

		Type			type;
		char _char;
		int	_int;
		float _float;
		double _double;


	public:
		ScalarConverter();
		~ScalarConverter();

		void	setType(const std::string& literal);
		int		getType(void) const;
		char	getCharValue(void) const;
      
		void	converter();

};

#endif