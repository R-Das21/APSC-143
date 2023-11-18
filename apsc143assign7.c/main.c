#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* f;
  //Reads parts file
  f = fopen("parts.txt", "r");

  unsigned int partsNum;
  //scans for number of parts
  fscanf(f, "%d", &partsNum);
    //Allocates memory for array of parts
  float** arr = malloc(sizeof(float*) * partsNum);
  for (int i = 0; i < partsNum; i++) {
    arr[i] = malloc(4 * sizeof(float));
  }
    //prints parts array with cost calculated for each part
  for (int i = 0; i < partsNum; i++) {
    fscanf(f, "%f %f %f", &arr[i][0], &arr[i][1], &arr[i][2]);
    arr[i][3] = arr[i][1] * arr[i][2];
    printf("%.0f %.2f %.0f %.2f\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
  }

  int swapped;
  //While loop to compair cost of each part and rearranges array to ascending cost order
  while (1) {
       
    swapped = 0;
    for (int i = 0; i < partsNum - 1; i++) {
           //compairs cost of part with cost of following part
      if (arr[i][3] > arr[i + 1][3]) {
               //sorts array
        float tmp[4];
        memcpy(tmp, arr[i], sizeof(float[4]));
        memcpy(arr[i], arr[i + 1], sizeof(float[4]));
        memcpy(arr[i + 1], tmp, sizeof(float[4]));
        swapped = 1;
      }
    }
    //breaks while loop if swap equals zero, meaning no swap can be made 
    if (!swapped) {
      break;
    }
  }
    //prints parts file with parts array and  column included
  printf("Serial / Price / Units / Total\n");
  for (int i = 0; i < partsNum; i++) {
    printf("%.0f %.2f %.0f %.2f\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
  }
    //prints orders file with parts array arranged in ascending order
  f = fopen("orders.txt", "w");
  fprintf(f, "Serial / Price / Units / Total\n");
  for (int i = 0; i < partsNum; i++) {
    fprintf(f, "%.0f %.2f %.0f %.2f\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
  }
    //frees memory allocated for array
  free(arr);

}
