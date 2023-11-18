// Assigns keyword
#define KEYWORD "LEXICON"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int
main ()
{
  char secretMessage[50];
  //prompts user input
  printf ("Enter secret message:");
  // Takes input and stores to string of max size 50 characters
  fgets (secretMessage, 50, stdin);
  //creates string equal to length of input string
  char spaceRemoval[strlen (secretMessage)];
  int q = 0;
  //Loop to remove space characters from input string
  for (int i = 0; i < strlen (secretMessage); i++)
    {
      // checks if character is not space, and stores value if true
      if (!isspace (secretMessage[i]))
	{
	  spaceRemoval[q] = secretMessage[q];
	  q++;
	}
    }
  spaceRemoval[q] = '\0';

  int length = strlen (spaceRemoval);
  // declares new string equal to one plus length of input string without spaces 
  char encryptKey[length + 1];
  int k = 0;
  // constructs encryption key
  for (int i = 0; i < length; i++)
    {
      //checks if character is uppercase and ignores non uppercase characters
      if (isupper (spaceRemoval[i]))
	{
	  encryptKey[i] = KEYWORD[k % strlen (KEYWORD)];
	  k++;
	}
      else
	{

	  encryptKey[i] = spaceRemoval[i];
	}

    }

  encryptKey[length] = '\0';

  char encryptMessage[length + 1];

  for (int i = 0; i < length; i++)
    {
      //checks distance between stated strings at each value of i
      int dist = encryptKey[i] - spaceRemoval[i];
      // sets movement distance of character to be encrypted
      char move = dist + encryptKey[i];

      if (dist != 0)
	{
	  // nested if structure which sets movement value to be within bounds of uppercase Alphabet
	  if (move > 'Z')
	    {
	      move -= 26;
	    }
	  else if (move < 'A')
	    {
	      move += 26;
	    }
	}
      //constructs encrypted message using character displacement values at each instance of i
      encryptMessage[i] = move;
    }
  encryptMessage[length] = '\0';
  //Length of output string plus the begin and end message values
  int finalLength = length + 31;
  char finalMessage[finalLength];
  //constructs final message to be printed begin message concataneted with encrypted message and end message
  strcpy (finalMessage, "*BEGIN_MESSAGE*\n");
  strcat (finalMessage, encryptMessage);
  strcat (finalMessage, "\n*END_MESSAGE*");
  // Outputs the final message
  printf ("%s\n", finalMessage);

  return 0;
}
