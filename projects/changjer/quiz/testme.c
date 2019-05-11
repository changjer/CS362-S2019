#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	//Generate a random character from ascii table 32 to 122
	int upper = 125;
	int lower = 32;
	int randomNumber = (rand() % (upper - lower + 1) + lower);
//	printf("random Number = %d\n", randomNumber);
	char randomCharacter= (char)randomNumber;

     return randomCharacter;
}

char *inputString()
{
	//Create random string of characters based on ascii characters from 'e' to 't' 
	int upper = 117;
	int lower = 101;
	int randomNumber;
	char *string;
	int stringLength = 5;
     char newString[stringLength];
	for(int i = 0; i < stringLength; i++){
		randomNumber = (rand() % (upper - lower + 1) + lower);
		newString[i] = randomNumber;
	}
	newString[5] = '\0';
	string = newString;
	return string;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();

    return 0;
}
