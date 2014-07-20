#include <iostream>
#include <cmath>

const int SIZE_OF_GENERIC_ARRAY = 100;
const int SIZE_OF_FIBONACCI_ARRAY = 20;

void fillGenericArray(float[], size_t);
void fillFibonacciArray(int[], size_t);

double mean(float[], int);
double mean(int[], int);

double standardDeviation(float[], int);
double standardDeviation(int[], int);

void outputMean(float[], size_t);
void outputStandardDeviation(float[], size_t);

void outputMean(int[], size_t);
void outputStandardDeviation(int[], size_t);

int main(int argc, char* argv[])
{
   char sequenceType;
   float SequentialNumbers[SIZE_OF_GENERIC_ARRAY];
   int FibonacciNumbers[SIZE_OF_FIBONACCI_ARRAY];
   std::cout << "Would you like to generate a generic sequence or a Fibonacci sequence?"
       << std::endl
       << "\n"
       << "Type [G] + [ENTER] for a generic sequence, or;" << std::endl
       << "Type [F] + [ENTER] for a Fibonacci sequence: ";
   std::cin >> sequenceType;

   if (sequenceType == 'G' || sequenceType == 'g')
   {
       fillGenericArray(SequentialNumbers, SIZE_OF_GENERIC_ARRAY);
       outputMean(SequentialNumbers, SIZE_OF_GENERIC_ARRAY);
       outputStandardDeviation(SequentialNumbers, SIZE_OF_GENERIC_ARRAY);
   }

   else if (sequenceType == 'F' || sequenceType == 'f')
   {
       fillFibonacciArray(FibonacciNumbers, SIZE_OF_FIBONACCI_ARRAY);
       outputMean(FibonacciNumbers, SIZE_OF_FIBONACCI_ARRAY);
       outputStandardDeviation(FibonacciNumbers, SIZE_OF_FIBONACCI_ARRAY);
   }

   else
       std::cout << "\n"
            << "Invalid input. Please type 'F' or 'G'. Thank you.";

   return 0;
}

void fillGenericArray(float array_to_fill[], size_t array_size)
{
   for (size_t i = 0; i < array_size; i++){
       array_to_fill[i] = i + 1;
   }
}

void fillFibonacciArray(int array_to_fill[], size_t array_size)
{
   array_to_fill[0] = 0;
   array_to_fill[1] = 1;

   for (size_t i = 2; i < array_size; i++){
       array_to_fill[i] = array_to_fill[i - 1] + array_to_fill[i - 2];
   }
}

double mean(float Array[], int SIZE_OF_GENERIC_ARRAY)
{
   double sumOfElements = 0;
   int i;

   for (i = 0; i < SIZE_OF_GENERIC_ARRAY; i++)
   {
       sumOfElements += Array[i];
   }
   return sumOfElements / i;
}

double mean(int Array[], int SIZE_OF_FIBONACCI_ARRAY)
{
   double sumOfElements = 0;
   int i;

   for (i = 0; i < SIZE_OF_FIBONACCI_ARRAY; i++)
   {
       sumOfElements += Array[i];
   }
   return sumOfElements / i;
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

void outputMean(float array_to_display[], size_t array_size)
{
   std::cout << "\n";
   std::cout << "The mean is: " << mean(array_to_display, array_size);
   std::cout << std::endl;
}

void outputStandardDeviation(float array_to_display[], size_t array_size)
{
   std::cout << "\n";
   std::cout << "The standard deviation is: " << standardDeviation(array_to_display, array_size);
   std::cout << std::endl;
}

void outputMean(int array_to_display[], size_t array_size)
{
   std::cout << "\n";
   std::cout << "The mean is: " << mean(array_to_display, array_size);
   std::cout << std::endl;
}

void outputStandardDeviation(int array_to_display[], size_t array_size)
{
   std::cout << "\n";
   std::cout << "The standard deviation is: " << standardDeviation(array_to_display, array_size);
   std::cout << std::endl;
}


