#include "lexer.h"

strings Lexer::lex(std::string s)
{
		strings strlst;
		char lexeme[256];

		int i=0;
		int j=0;
		State state = START;
		int done = 0;
		int len = s.length(); 
		int balance = 0;
		std::cout<<"THE SIZE iS: "<<len<<std::endl;
		while(i<len)
		{
		std::cout<<"CHAR POS: "<<s[i]<<std::endl;
		switch(state)
		{


			// Cases for the state machine
			case START:
				std::cout<<"START"<<std::endl;
							if(my_isspace(s[i]))
							{
											state = SKIP;
							} else if (isgroup(s[i]))
							{
							if(s[i] == '"')
									{
										lexeme[j] = s[i];
										j++;
										i++;
									}
									state = READBLOCK;
								} 

						else if (s[i] == '/' && s[i + 1] == '/') // Detectcomments
								{	
										i+=2;	
									state = COMMENT;
								}
								else{ 
									std::cout<<"END"<<std::endl;
									state = READCHAR;
								}

					break;




			case READCHAR:
				std::cout<<"READCHAR"<<s[i]<<std::endl;
					if(my_isspace(s[i])){
						state = DUMP;		}
					
					else if(s[i] == '\\')
					{ i += 2; } // temporal

					else if(isgroup(s[i]))
					{
						if(s[i] == '"')
						{
						
							lexeme[j] = s[i];
							i++;
							j++;
						}
						state = READBLOCK;
					}

					else if(isspecial(s[i]))
					{

							if(j ==0)
							{

								lexeme[j]= s[i];
								j++;
								i++;
							}
							state = DUMP;
					}
					
					else if (s[i] == '/' && s[i+1] == '/')
					{

						std::cout<<"***** MVKV"<<std::endl;
						i +=2;
						state = COMMENT;
					} else {
						std::cout<<"***** MVKV"<<std::endl;
						lexeme[j] = s[i];
						j++;
						i++;
					}

		
					std::cout<<"ENDREADCHAR"<<std::endl;
				break;

			case READBLOCK:

				std::cout<<"READBLOCK"<<std::endl;
				
				if(s[i] == beg_char && s[i] != '"')
				{
					balance++;
					lexeme[j] = s[i];
					j++;
					i++;
				}
				else if (s[i] == end_char)
				{
					balance--;
					lexeme[j] = s[i];
					j++;
					i++;
					if (balance<=0){
						state = DUMP;
					}

				}else if(end_char == '"' && s[i] == '\\')
				{
					i+=2;
				}
				else{
					lexeme[j] = s[i];
					j++;
					i++;
				}

				break;

			case SKIP:
					std::cout<<"SKIP"<<std::endl;
				if (my_isspace(s[i]))
				{
					i++;
				}
				else{
					state = READCHAR;
				}
				break;

			case DUMP:
					std::cout<<"DUMP"<<std::endl;
				if(j > 0){
					lexeme[j] = 0;
					strlst.push_back(lexeme);
					j=0;
				}
				state = START;
				break;

			case COMMENT:
					std::cout<<"COMMENT"<<std::endl;	
				if (s[i] != '\n')
				{
					i++; // ignore comment util gets a end line
				}
				else{
					state = READCHAR;
				}
				break;


			case END:
				std::cout<<"END"<<std::endl;
				i = len;
				break;
		}

						if(j>0){
						lexeme[j] = 0;
						strlst.push_back(lexeme);
						}
						
		}


		return strlst;
}


// define what a space is 

bool Lexer::my_isspace(char c)
{

	std::cout<<"MYSPCE"<<std::endl;
	switch(c)
	{
		case '\n':
		case '\r':
		case '\t':
		case '\v':
		case ' ':
		case '\f':
				return true;
			default:
				return false;
	}
}

// define what a group is 

bool Lexer::isgroup(char c)
{

	std::cout<<"ISGROUP"<<std::endl;
	beg_char = c;
	switch(c)
	{
			case '"':
				end_char = '"';
				return true;
			case '(':
				end_char = ')';
				return true;
			case ')':
				return true;
			default:
				return false;
	}
}

//check if is a special char
bool Lexer::isspecial(char c)
{
		std::cout<<"SPECIAL"<<std::endl;
		switch(c)
		{
			case '[':
			case ']':
				return true;
			default:
				return false;
		}
}

