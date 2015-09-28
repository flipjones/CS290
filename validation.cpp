/***********************
 * Author: Philip Jones
 * Date: 5/23/2015
 * Description: A set of functions that will check to see if the input 
   provided by the user is valid.
 * Input: Standard string
 * Output: True/False depending on the validity.
 * *******************/

#include <string>
#include <iostream>

using namespace std;

int size, i, dot;
bool isint, isfloat;

//This function checks to see if the string is a valid integer.
bool stringIsInt(std::string input)
{
bool status;
size = input.length();
i = 0;
status = true;

	if (input.empty())
		{status = false;
		return status;}
	if (isspace(input[i]))
		{{while (isspace(input[i+1]))
			{i++;}}
		i++;
		//cout <<"Spaces in front taken care of." <<endl;
		}
	if ((input[i] == '-') || (input[i] == '+'))
		{
		//cout <<"Plus/Minus taken care of." <<endl;
		if (isspace(input[i+1]))
			{while (isspace(input[i+1]))
			{i++;}
			//cout <<"Space in middle taken care of." <<endl;
			}
		i++;}
	else if (input.at(i) >= '0' && input.at(i)<= '9')
		{i++;
		//cout <<"Good first number noted" <<endl;
		}
	else	
		{status = false;
		//cout <<"Bad input, shoudl end program" <<endl;
		return status;}
		
		
	while (i<=(size-1))
	{
		if (input[i] >= '0' && input[i] <= '9')
			{i++;
			//cout <<"Good number noted." <<endl;
			}
			
		else if (isspace(input[i]))
			{if (isspace(input[i+1]))
				{i++;
				//cout <<"Good space at the end" <<endl;
				}
			else if (i+1 == size)
				{return status;}
			else 
			{status = false;
			//cout <<"No spaces in between numbers" <<endl;
			return status;}}
		else
			{status = false;
			//cout <<"Bad input in the middle." <<endl;
			return status;}
	}		

return status;

}

//This function checks to see if the string is a valid float number.

bool stringIsFloat(std::string input)
{
bool status;
size = input.length();
i = 0;
dot = 0;
status = true;

	if (input.empty())
		{status = false;
		return status;}

	if (isspace(input[i]))
		{{while (isspace(input[i+1]))
			{i++;}}
		i++;
		//cout <<"Spaces in front taken care of." <<endl;
		}
	if ((input[i] == '-') || (input[i] == '+'))
		{
		//cout <<"Plus/Minus taken care of." <<endl;
		if (isspace(input[i+1]))
			{while (isspace(input[i+1]))
			{i++;}
			//cout <<"Space in middle taken care of." <<endl;
			}
		i++;}
	else if (input[i] == '.')
		{dot++; i++;
		//cout <<"First decimal point OK." <<endl;
		}
	else if (input.at(i) >= '0' && input.at(i)<= '9')
		{i++;
		//cout <<"Good first number noted" <<endl;
		}
	else	
		{status = false;
		//cout <<"Bad input, shoudl end program" <<endl;
		return status;}
				
	while (i<=(size-1))
	{
		if (input[i] >= '0' && input[i] <= '9')
			{i++;
			//cout <<"Good number noted." <<endl;
			}
					
		else if (input[i] == '.')
			{i++; dot++;
			if (dot>1)
				{status = false;
				return status;}
			else if (i == size)
				{status = false;
				return status;}
			else if (isspace(input[i+1]))
				{status = false;
				return status;}
			}
		else if (isspace(input[i]))
			{if (isspace(input[i+1]))
				{i++;
				//cout <<"Good space at the end" <<endl;
				}
			else if (i+1 == size)
				{return status;}
			else 
			{status = false;
			//cout <<"No spaces in between numbers" <<endl;
			return status;}}
		else
			{status = false;
			//cout <<"Bad input in the middle." <<endl;
			return status;}
	}		
	
return status;
}
