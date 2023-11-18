/******************************************************************************
*******************************************************************************/
#include <stdio.h>
#include <math.h>
#define M_PI 3.14159
int main ()
{
/*Declaring dimensions of box as variables*/
  float volume;
  float length;
  float height;
  float width;
  /*Assigning volume as the product of box dimensions */
  
  /*promting user to input box dimensions */
  printf ("Enter length, width, height of box:");
  scanf ("%f %f %f", &length, &width, &height);
  volume = length * width * height;
  printf ("The box is %0.2f cm3\n", volume);
  /*Calculating amount of cookies that fit in box*/
  float cookieHeight = 1.8;
  float numberCookies;
  numberCookies = 2*(floor(length/cookieHeight));
  printf("%.0f cookies can fit into the box\n", numberCookies);
  float spacePercentage;
  float cVolume;
  float cookieRad = 2.6;
  /*Calculating volume of one cookie */
  cVolume = M_PI* pow(cookieRad, 2)*cookieHeight;
  /*Calculating percent of space occupied by cookies*/
   spacePercentage = ((numberCookies*cVolume)/volume)*100;
   printf("Cookies take up %0.2f%% of the box\n", spacePercentage);
   float surfaceArea;
   float costCookie;
   float boxCost;
   float priceProduct;
   /*Calculating surface area of box*/
   surfaceArea = 2*(length*width)+2*(length*height)+2*(width*height);
   /*Calculating cost of the cookies*/
   costCookie = (numberCookies*cVolume)*0.0082;
   /*Calculating production cost of box*/
   boxCost = surfaceArea*0.003;
   /*Calculating the sale price of product with the markup value*/
   priceProduct = (costCookie+boxCost)*1.23;
   printf("The product price is $%0.2f", priceProduct);
  return 0 ;
}

