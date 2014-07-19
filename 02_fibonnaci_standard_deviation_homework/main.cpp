#include <iostream>
#include <cmath>
using namespace std;

const int SIZE_OF_GENERIC_ARRAY = 100;
const int SIZE_OF_FIBONACCI_ARRAY = 20;

double arithmeticAverage;
char sequenceType;

float Array[SIZE_OF_GENERIC_ARRAY];
int Fibonacci[SIZE_OF_FIBONACCI_ARRAY];

void fillGenericArray(int SIZE_OF_GENERIC_ARRAY);
void fillFibonacciArray(int SIZE_OF_FIBONACCI_ARRAY);

double mean(float[], int);
double mean(int[], int);

double standardDeviation(float[], int);
double standardDeviation(int[], int);

void outputMean();
void outputStandardDeviation();

int main(int argc, char* argv[])
{
   cout << "Would you like to generate a generic sequence or a Fibonacci sequence?"
       << endl
       << "\n"
       << "Type [G] + [ENTER] for a generic sequence, or;" << endl
       << "Type [F] + [ENTER] for a Fibonacci sequence: ";
   cin >> sequenceType;

   if (sequenceType == 'G' || sequenceType == 'g')
   {
       fillGenericArray(SIZE_OF_GENERIC_ARRAY);
       outputMean();
       outputStandardDeviation();
   }

   else if (sequenceType == 'F' || sequenceType == 'f')
   {
       fillFibonacciArray(SIZE_OF_FIBONACCI_ARRAY);
       outputMean();
       outputStandardDeviation();
   }

   else
       cout << "\n"
            << "Invalid input. Please type 'F' or 'G'. Thank you.";

   return 0;
}

void fillGenericArray(int SIZE_OF_GENERIC_ARRAY)
{
   Array[0] = 1;

   for (int i = 0; i < SIZE_OF_GENERIC_ARRAY; i++)
       Array[i] = i + 1;

   return;
}

void fillFibonacciArray(int SIZE_OF_FIBONACCI_ARRAY)
{
   Array[0] = 0;
   Array[1] = 1;

   for (int i = 2; i < SIZE_OF_FIBONACCI_ARRAY; i++)
       Array[i] = Array[i - 1] + Array[i - 2];

   return;
}

double mean(float Array[], int SIZE_OF_GENERIC_ARRAY)
{
   double sumOfElements = 0;
   int i;

   for (i = 0; i < SIZE_OF_GENERIC_ARRAY; i++)
   {
       sumOfElements += Array[i];
   }
   arithmeticAverage = sumOfElements / i;
   return (arithmeticAverage);
}

double mean(int Array[], int SIZE_OF_FIBONACCI_ARRAY)
{
   double sumOfElements = 0;
   int i;

   for (i = 0; i < SIZE_OF_FIBONACCI_ARRAY; i++)
   {
       sumOfElements += Array[i];
   }
   arithmeticAverage = sumOfElements / i;
   return (arithmeticAverage);
}

double standardDeviation(float Array[], int SIZE_OF_GENERIC_ARRAY)
{
   double standardDeviation;
   double tempSum = 0;

   for (int i = 0; i < SIZE_OF_GENERIC_ARRAY; i++)
   {
       tempSum += pow((Array[i] - mean(Array, SIZE_OF_GENERIC_ARRAY)), 2);
   }
   standardDeviation = sqrt(tempSum / (SIZE_OF_GENERIC_ARRAY));
   return (standardDeviation);
}

double standardDeviation(int Array[], int SIZE_OF_FIBONACCI_ARRAY)
{
   double standardDeviation;
   double tempSum = 0;

   for (int i = 0; i < SIZE_OF_FIBONACCI_ARRAY; i++)
   {
       tempSum += pow((Array[i] - mean(Array, SIZE_OF_FIBONACCI_ARRAY)), 2);
   }
   standardDeviation = sqrt(tempSum / (SIZE_OF_FIBONACCI_ARRAY));
   return (standardDeviation);
}

void outputMean()
{
   cout << "\n";
   cout << "The mean is: " << mean(Array, SIZE_OF_GENERIC_ARRAY);
   cout << endl;
}

void outputStandardDeviation()
{
   cout << "\n";
   cout << "The standard deviation is: " << standardDeviation(Array,
    SIZE_OF_GENERIC_ARRAY);
   cout << endl;
}
