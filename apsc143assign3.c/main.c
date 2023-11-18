/******************************************************************************
 
*******************************************************************************/
#include <stdio.h>
#include <math.h>
int
main ()
{
  //declaring variables
  float time;
  float current;
  //prompting user for time value and storing value to memory
  printf ("Enter time: ");
  scanf ("%f" , &time);
  //calculating current
  current = fabs (sin (time / 4) / 6);
  //declaring variables
  float resistance;
  float voltage;

  if (time < 0)
    {
      //printing output
      printf ("The circuit is shut off");
    }
  if (time > 14.9)
    {
      //setting value of resistance when switch is closed
      resistance = 30;
      //calculating voltage
      voltage = (current * resistance);
      //printing outputs
      printf ("The circuit is active\n");
      printf ("Circuit current = %0.3f A\n", current);
      printf ("The switch is closed\n");
      printf ("Circuit voltage = %.3f V\n", voltage);
      //nested if to check if voltage falls in range for LED to illuminate
      if (voltage < 2.2 || voltage > 4.7)
	{
	  printf ("The LED is not illuminated ");
	}
      else
	printf ("The LED is illuminated ");


    }
  if (time >= 0 && time < 14.9)
    {
      //setting value of resistance when switch is open
      resistance = 50;
      // calculating voltage
      voltage = (current * resistance);
      //printing outputs
      printf ("The circuit is active\n");
      printf ("Circuit current = %0.3f A\n", current);
      printf ("The switch is open\n");
      printf ("Circuit voltage = %.3f V\n", voltage);
      //nested if to check if voltage falls in range for LED to illuminate
      if (voltage < 2.2 || voltage > 4.7)
	{
	  printf ("The LED is not illuminated ");
	}
      else
	printf ("The LED is illuminated ");


    }



  return 0;
}

