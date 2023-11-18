#include <stdio.h>
// function definitions
float getIntensity (float d, float i, int x);
float getVelocity (float i, int x);

// declare maximum tolerable intensity and velocity variables
float d;
float i;

// array to hold the wave velocity modifiers
float v[] = { -3, -18, 34, 0, -23, -31, 18, 3, -8, -21, -10, 25 };

int
main ()
{
  // user prompt to enter the maximum tolerable relative intensity and wave velocity
  printf ("Enter max relative intensity & wave velocity: ");
  scanf ("%f %f", &d, &i);

  // gets and prints the maximum wave velocity at the blast site
  printf ("Vibrations have max initial velocity of %.3f m/s\n",
	  getVelocity (i, 0));
  printf ("Blast site has max relative intensity of %.3f\n",
	  getIntensity (d, i, 0));
}


float
getIntensity (float d, float i, int x)
{
  // check if the index is beyond the final rock band
  if (11 < x)
    {
      return d;
    }
  // call the getVelocity function to compute the wave velocity at the current rock band
  float r = getVelocity (i, x);
  // return the relative intensity I0
  return getIntensity (d, i, x + 1) + x / r;
}

float
getVelocity (float i, int x)
{
  // check if the index is beyond the final rock band
  if (x > 11)
    {
      return i;
    }
  // return the wave velocity before it passes through the current rock band
  return getVelocity (i, x + 1) / (1 + v[x] / 100);
}
