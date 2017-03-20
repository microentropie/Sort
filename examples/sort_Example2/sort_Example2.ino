#include <sort_bubble.h>

int Values[] = {2, 5, 6, 7, 123, -3, 10, 20, 171, 14};
int ARRAY_SIZE = sizeof(Values) / sizeof(Values[0]);

void setup()
{
  Serial.begin(74880);
  Serial.println();
  Serial.println();
  Serial.println("Bubble Sort example 2");
  Serial.println("https://github.com/microentropie/sort");
}

void loop()
{
  ShowData("Original Array");
  
  //bubbleSort(Values, ARRAY_SIZE);
  bubbleSort<int>(Values, ARRAY_SIZE, compare_int);
 
  ShowData("Sorted Array");
  
  // sometimes the sorting algorithm target is to get min / max:
  Serial.print("Max: ");
  Serial.print(Values[ARRAY_SIZE-1]);
  Serial.print(", Min: ");
  Serial.print(Values[0]);
  Serial.println();
 
  delay(30000);
}
/*
 * output from this sketch
Bubble Sort example 2
https://github.com/microentropie/sort
Original Array:
2,5,6,7,123,-3,10,20,171,14
Sorted Array:
-3,2,5,6,7,10,14,20,123,171
Max: 171, Min: -3
*/

// sorting method
int compare_int(int *p1, int *p2)
{
  return *p1 - *p2;
}

void ShowData(const char *msg)
{
  Serial.print(msg);
  Serial.println(":");
  for(int i=0; i<ARRAY_SIZE; i++)
  {
    if(i > 0)
      Serial.print(",");
    Serial.print(Values[i]); 
  }
  Serial.println();
}

