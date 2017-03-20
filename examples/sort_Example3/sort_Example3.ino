#include <sort_bubble.h>

struct ntcTranslationAdcTemp
{
  unsigned short adc; // adc value
  short temp; // temperature in �C multiplied by 10
};

#define MAX_TEMP_SETPOINTS 16
ntcTranslationAdcTemp *NtcTable[MAX_TEMP_SETPOINTS];

void setup()
{
  Serial.begin(74880);
  Serial.println();
  Serial.println();
  Serial.println("Bubble Sort example 3");
  Serial.println("https://github.com/microentropie/sort");
  
  int qtNtcElem = 0;
  for (int i = 0; i < MAX_TEMP_SETPOINTS; ++i)
    NtcTable[i] = new ntcTranslationAdcTemp();

  NtcTable[qtNtcElem]->adc = 348;  NtcTable[qtNtcElem]->temp = 583;
  ++qtNtcElem;
  NtcTable[qtNtcElem]->adc = 73;   NtcTable[qtNtcElem]->temp = 266;
  ++qtNtcElem;
  NtcTable[qtNtcElem]->adc = 80;   NtcTable[qtNtcElem]->temp = 280;
  ++qtNtcElem;
  NtcTable[qtNtcElem]->adc = 1001; NtcTable[qtNtcElem]->temp = 1600;
  ++qtNtcElem;
  NtcTable[qtNtcElem]->adc = 381;  NtcTable[qtNtcElem]->temp = 634;
  ++qtNtcElem;
  NtcTable[qtNtcElem]->adc = 944;  NtcTable[qtNtcElem]->temp = 1000;
  ++qtNtcElem;
  NtcTable[qtNtcElem]->adc = 108;  NtcTable[qtNtcElem]->temp = 325;
  ++qtNtcElem;
  for (int i = qtNtcElem; i < MAX_TEMP_SETPOINTS; ++i)
  {
    NtcTable[qtNtcElem]->adc = 0; NtcTable[qtNtcElem]->temp = 0;
  }
}

void loop()
{
  ShowData("Original Array");
  
  bubbleSort<ntcTranslationAdcTemp>(NtcTable, MAX_TEMP_SETPOINTS, TempEntryCompare);
 
  ShowData("Sorted Array");
 
  delay(30000);
}
/*
 * output from this sketch
Bubble Sort example 3
https://github.com/microentropie/sort
Original Array:
1  348 583
2 73  266
3 80  280
4 1001  1600
5 381 634
6 944 1000
7 108 325
8 0 0
9 0 0
10  0 0
11  0 0
12  0 0
13  0 0
14  0 0
15  0 0
16  0 0

Sorted Array:
1 73  266
2 80  280
3 108 325
4 348 583
5 381 634
6 944 1000
7 1001  1600
8 0 0
9 0 0
10  0 0
11  0 0
12  0 0
13  0 0
14  0 0
15  0 0
16  0 0
*/

// sorting method
int TempEntryCompare(struct ntcTranslationAdcTemp *p1, struct ntcTranslationAdcTemp *p2)
{
  int adc1 = (int)p1->adc;
  int adc2 = (int)p2->adc;
  // adc==0 is considered NOT AN ENTRY, free table entry, thus will be sorted to the end
  if (adc1 == 0)
    adc1 = 32767;
  if (adc2 == 0)
    adc2 = 32767;
  return adc1 - adc2;
}



void ShowData(const char *msg)
{
  Serial.print(msg);
  Serial.println(":");

  for (int i = 0; i < MAX_TEMP_SETPOINTS; ++i)
  {
    Serial.print(i+1); Serial.print('\t');
    Serial.print(NtcTable[i]->adc); Serial.print('\t');
    Serial.print(NtcTable[i]->temp); Serial.println();
  }
  Serial.println();
}

