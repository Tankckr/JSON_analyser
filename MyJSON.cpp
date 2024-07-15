#include"MyJSON.h"

namespace MyJSON
{
	JSON_error GlobalError;
	/*----------类函数----------*/
	JSON_value* JSON_value::Parser(std::stringstream& ss)
	{
		switch (type)
		{
			case Jinitial:{
				char ch = ss.peek();
				if (ch == '{')
				{
					
				}
			}
		}
	}
	
	/*----------类函数----------*/
}