#include <stdio.h>
#include <stdbool.h>


/***
* C programs all need a "main" function which is where they start.
* "main" is the last function to appear in this file.
* This is because anything that is referred to in main (such as "DoRomanToInt"
* needs to have been declared already. Hope that makes sense!
***/

int RomanToInt(char* romanString)
{
	char* startPointer = romanString;
	int intValue = 0;
	if (romanString)
	{
		while (*romanString)
		{
			switch (*romanString)
			{
				case 'M':
				{
					++romanString;
					intValue += 1000;
				}
				break;
				
				case 'D':
				{
					++romanString;
					intValue += 500;
				}
				break;

				case 'C':
				{
					++romanString;
					switch (*romanString)
					{
						case 'D':
						{
							++romanString;
							intValue += 400;
						}
						break;

						case 'M':
						{
							++romanString;
							intValue += 900;
						}
						break;

						default:
						{
							intValue += 100;
						}
						break;
					}
				}
				break;

				case 'L':
				{
					++romanString;
					intValue += 50;
				}
				break;

				case 'X':
				{
					++romanString;
					switch (*romanString)
					{
						case 'L':
						{
							++romanString;
							intValue += 40;
						}
						break;

						case 'C':
						{
							++romanString;
							intValue += 90;
						}
						break;

						default:
						{
							intValue += 10;
						}
						break;
					}
				}
				break;

				case 'V':
				{
					++romanString;
					intValue += 5;
				}
				break;

				case 'I':
				{
					++romanString;
					switch (*romanString)
					{
						case 'V':
						{
							++romanString;
							intValue += 4;
						}
						break;

						case 'X':
						{
							++romanString;
							intValue += 9;
						}
						break;

						default:
						{
							intValue += 1;
						}
						break;
					}

				}
				break;

				default:
				{
					printf("%c is a invalid here\n", *romanString);
					intValue = -1;
				}
				break;
			}
		}
	}
	return intValue;
}



int RomanToInt2(char* romanString)
{
	char* startPointer = romanString;
	int intValue = 0;
	if (romanString)
	{
		while (*romanString)
		{
			switch (*romanString++)
			{
				case 'M':
				{
					intValue += 1000;
				}
				break;

				case 'D':
				{
					intValue += 500;
				}
				break;

				case 'C':
				{
					switch (*romanString)
					{
						case 'D':
						case 'M':
						{
							intValue -= 100;
						}
						break;

						default:
						{
							intValue += 100;
						}
						break;
					}
				}
				break;

				case 'L':
				{
					intValue += 50;
				}
				break;

				case 'X':
				{
					switch (*romanString)
					{
					case 'L':
					case 'C':
					{
						intValue -= 10;
					}
					break;

					default:
					{
						intValue += 10;
					}
					break;
					}
				}
				break;

				case 'V':
				{
					intValue += 5;
				}
				break;

				case 'I':
				{
					switch (*romanString)
					{
						case 'V':
						case 'X':
						{
							intValue -= 1;
						}
						break;

						default:
						{
							intValue += 1;
						}
						break;
					}
					break;
				}
				break;

				default:
				{
					printf("%c is a invalid here\n", *romanString);
					intValue = -1;
				}
				break;
			}
		}
	}
	return intValue;
}

int GetMultiplier(char thisRomanChar, char nextRomanChar)
{
	int multiplier = 1;
	switch (thisRomanChar)
	{
		case 'C':
		{
			switch (nextRomanChar)
			{
				case 'D':
				case 'M':
				{
					multiplier = -1;
				}
				break;
			}
		}
		break;

		case 'X':
		{
			switch (nextRomanChar)
			{
				case 'L':
				case 'C':
				{
					multiplier = -1;
				}
				break;
			}
		}
		break;

		case 'I':
		{
			switch (nextRomanChar)
			{
				case 'V':
				case 'X':
				{
					multiplier = -1;
				}
				break;
			}
			break;
		}
		break;
	}
	return multiplier;
}


int GetValueFromRoman(char romanChar)
{
	switch (romanChar)
	{
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
	}
}



int GetMultiplier1(char thisRomanChar, char nextRomanChar)
{
	if ((thisRomanChar == 'C') && (nextRomanChar == 'D' || nextRomanChar == 'M')) return -1;
	if ((thisRomanChar == 'X') && (nextRomanChar == 'L' || nextRomanChar == 'C')) return -1;
	if ((thisRomanChar == 'I') && (nextRomanChar == 'V' || nextRomanChar == 'X')) return -1;
	return 1;
}




int RomanToInt3(char* romanString)
{
	char* startPointer = romanString;
	int intValue = 0;
	while (romanString && *romanString)
	{
		char thisRomanChar = *romanString++;
		char nextRomanChar = *romanString;
		intValue +=  GetValueFromRoman(thisRomanChar) * GetMultiplier1(thisRomanChar, nextRomanChar);
	}
	return intValue;
}



void DoRomanToInt(char* romanString)
{
	int result = RomanToInt3(romanString);
	printf("\nInput was:%s Result is %d\n", romanString, result);
}


int main()
{
	printf("Hello world\n");

	DoRomanToInt("III");
	DoRomanToInt("LVIII");
	DoRomanToInt("MCMXCIV");

	return 0;
}










