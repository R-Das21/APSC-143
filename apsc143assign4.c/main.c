/******************************************************************************

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int
main ()
{
//declaring variables
  float ammConc;
  float oxyConc;
  float nitroConc;
  float waterConc;
  float initialAmmConc;
  float avgWaterConc;
  float sumConcWater;
  float rxnRate;
  float k = 0.0114;
  float time = 0;
  float counter;
  //promting user for concentration inputs
  printf ("Enter initial ammonia & oxygen concentrations: ");
  //assigning variables user input value
  scanf ("%f %f", &ammConc, &oxyConc);
  initialAmmConc = ammConc;
//while loop with condition to run infinitely
  while (5 == 5)
    {
      //calculating current reaction rate 
      rxnRate = k * ammConc * powf (oxyConc, 2);
      // incrementing or decrementing concentrations at every iteration
      ammConc = (ammConc - (rxnRate * 4 * 0.01));
      oxyConc = (oxyConc - (rxnRate * 3 * 0.01));
      nitroConc = (nitroConc + (rxnRate * 2 * 0.01));
      waterConc = (waterConc + (rxnRate * 6 * 0.01));
      // keeping track of all water concentrations at every iteration
      sumConcWater += waterConc;
      //incrementing time value at every iteration
      time += 0.01;
      // counter variable incremented at every iteration
      counter += 1;
      //runs if loop has run 38 times
      if (counter == 38)
	{
	  //prints Concentration of ammonia after 0.38 seconds
	  printf ("Concentration of ammonia after 0.38s = %0.3f mol/L\n",
		  ammConc);
	}
      //runs if rate is less than or equal to 0.040 mol/l*s
      if (rxnRate <= 0.04)
	{
	  //prints time at which rate falls below above condition
	  printf ("%0.2fs required for rate to drop below 0.040 mol/(L*s)\n",
		  time);
	  // prints nitrogen gas Concentration at the time of above condition
	  printf
	    ("Concentration of nitrogen gas after %0.2fs = %0.3f mol/L\n",
	     time, nitroConc);
	  //calculates average concentration of water over the total time interval
	  avgWaterConc = sumConcWater / counter;
	  printf
	    ("Average concentration of water after %0.2fs = %0.3f mol/L\n",
	     time, avgWaterConc);
	  //checks if concentration of ammonia is less than half the initial Concentration
	  if ((initialAmmConc * 0.5) > ammConc)
	    {
	      printf ("Reaction has passed 50%% completion\n");
	    }
	  else
	    {
	      printf ("Reaction has not passed 50%% completion\n");

	    }
	  break;
	}


    }
  return 0;
}

