#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
//function declarations with arguments
float randomize (float min, float max);
float accelerate (float o, float h);
float deflect (float o, float h, float c);
void checkPath (float f[][3], int j);


int main ()
{
    //seeding for randomize function
  srand (2);
    //user prompt for number of trials
  unsigned int n;
  printf ("Enter number of trials: ");
  scanf ("%d", &n);

  float f[n][3];
  int l;
  for (l = 0; l < n; l = l + 1)
    {
        //gets mass of particle within range for trial l
      float h = randomize (0.001, 1.08);
      //gets charge of partcile within range for trial l 
      float o = randomize (1, 9);
      //prints mass and charge of particle for trial l
      printf ("Trial %d: %.3f kg, %.3f C\n", l + 1, h, o);
      // Calculates acceleration of particle using mass and charge for trial l
      float c = accelerate (o, h);
      //Gets deflection radius using mass charge and acceleration of particle for trial l 
      float s = deflect (o, h, c);
      //Stores trial data into array
      f[l][2] = s;
      f[l][1] = o;
      f[l][0] = h;
      checkPath (f, l);
    }
}

//Returns random float within range
float randomize (float min, float max)
{
  return ((float) rand () / RAND_MAX) * (max - min) + min;
}
//Checks if current radius is largest radius, compared to previous trials
void checkPath (float f[][3], int j)
{
  float u = 0;
  for (int m = 0; m < j; m++)
    {
      float a;
      a = f[m][2];
      if (a > u)
	{
	  u = a;
	}
    }
  if (f[j][2] > u)
    {
        //Prints if current trial radius is largest radius so far
      printf ("New largest deflection radius!\n");
    }
}
//Calculates particle velocity
float accelerate (float o, float h)
{
    //calls randomize function to return float value within range 
  float e = randomize (0.013, 2.827);
  //Computes the particle’s velocity
  float c = sqrt (o * e * 2 / h);
  //prints output
  printf ("Accelerated to %.3f m/s\n", c);
  //returns velocity value
  return c;
}
//Calculates deflection radius
float deflect (float o, float h, float c)
{
    //Calls the randomize function to get a new magnetic field value in the range
  float z = randomize (0.058, 1.603);
  //Computes the particle’s deflection radius 
  float s = (h * c) / (z * o);
  //prints output
  printf ("Deflection radius of %.3f m\n", s);
  //returns radius
  return s;
}
