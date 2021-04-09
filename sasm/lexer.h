#ifndef LEXER
#define LEXER

#include <iostream>
#include <vector>

typedef int8_t byte;
typedef std::vector<string> strings; 

enum State : byte 
{
	START,
	READCHAR,
	READBLOCK,
	SKIP,
	DUMP,
	COMMENT,
	END
}

class Lexer 
{
	bool my_isspace(char c);
	bool isspecial(char c);
	bool isgroup(char c);
	char end_char,beg_char;
	public:
		strings existd(std::string s);
};

#endif
