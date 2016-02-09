#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double x1 = 40.35;
  double y1 = 74.65;
  double x2 = 48.87;
  double y2 = -2.33;

  // degree to radians
  x1 /= (180.0 / M_PI);
  y1 /= (180.0 / M_PI);
  x2 /= (180.0 / M_PI);
  y2 /= (180.0 / M_PI);
    			
  /*************************************************************************
   * Compute using law of cosines
   *************************************************************************/
  // great circle distance in radians
  double angle1 = acos(sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos(y1 - y2));

  // convert back to degrees
  angle1 *= (180.0/M_PI);

  // each degree on a great circle of Earth is 60 nautical miles
  double distance1 = 60 * angle1;

  // each nautical mile is 1.852 kilometers
  distance1 *= 1.852;

  printf("%.16f km\n", distance1);


  /*************************************************************************
  * Compute using Haverside formula
  *************************************************************************/
  double a = pow(sin((x2-x1)/2), 2) + cos(x1) * cos(x2) * pow(sin((y2-y1)/2), 2);
  double angle2;

  // great circle distance in radians
  if (sqrt(a) > 1) {
    angle2 = 2 * asin(1);
  }
  else {
    angle2 = 2 * asin(sqrt(a));
  }

  // convert back to degrees
  angle2 *= (180.0/M_PI);

  // each degree on a great circle of Earth is 60 nautical miles
  double distance2 = 60 * angle2;

  // each nautical mile is 1.852 kilometers
  distance2 *= 1.852;

  printf("%.16f km\n", distance2);

  return 0;
}
