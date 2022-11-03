#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
double uniform_rv()
{
   int j = 1 + (int)(100000.0 * rand() / (RAND_MAX + 1.0));
   double value = (double)j / 100000;
   return value;
}
float box_muller(float m, float s) /* normal random variate generator */
{ /* mean m, standard deviation s */
   float x1, x2, w, y1;
   static float y2;
   static int use_last = 0;
   if (use_last) /* use value from previous call */
   {
      y1 = y2;
      use_last = 0;
   }
   else
   {
      do {
         x1 = 2.0 * uniform_rv() - 1.0;
         x2 = 2.0 * uniform_rv() - 1.0;
         w = x1 * x1 + x2 * x2;
      } while (w >= 1.0);
      w = sqrt((-2.0 * log(w)) / w);
      y1 = x1 * w;
      y2 = x2 * w;
      use_last = 1;
   }
   return(m + y1 * s);
}

int main() {
   int i;
   float sent, received, noise;
   long int num_error = 0;
   long int num_iteration = 100000000;
   for (i = 0; i < num_iteration; i++) {
      if (box_muller(0, 2) - 5 > 0) {
         num_error++;
      }
   }
   printf("Number of Error = %ld\n", num_error);
   printf("Prob.of Error = %f\n", (float)num_error / num_iteration);
   return 0;
}