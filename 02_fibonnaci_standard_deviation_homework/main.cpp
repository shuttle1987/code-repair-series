#include <iostream>
#include <cmath>

const size_t SIZE_OF_GENERIC_ARRAY = 100;
const size_t SIZE_OF_FIBONACCI_ARRAY = 20;

void fillSequentialIntegersArray(float[], size_t);
void fillFibonacciArray(int[], size_t);

double mean(float[], size_t);
double mean(int[], size_t);

double standardDeviation(float[], size_t);
double standardDeviation(int[], size_t);

void outputMean(float[], size_t);
void outputMean(int[], size_t);

void outputStandardDeviation(float[], size_t);
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
       fillSequentialIntegersArray(SequentialNumbers, SIZE_OF_GENERIC_ARRAY);
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
   {
       std::cout << "\n"
            << "Invalid input. Please type 'F' or 'G'. Thank you.";
   }
   return 0;
}

void fillSequentialIntegersArray(float array_to_fill[], size_t array_size)
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

double mean(float Array[], size_t array_size)
{
   double sumOfElements = 0;

   for (size_t i = 0; i < array_size; i++)
   {
       sumOfElements += Array[i];
   }
   return sumOfElements / array_size;
}

double mean(int Array[], size_t array_size)
{
   double sumOfElements = 0;

   for (size_t i = 0; i < array_size; i++)
   {
       sumOfElements += Array[i];
   }
   return sumOfElements / array_size;
}

double standardDeviation(float Array[], size_t array_size)
{
   double tempSum = 0;

   for (size_t i = 0; i < array_size; i++)
   {
       tempSum += pow((Array[i] - mean(Array, array_size)), 2);
   }
   return sqrt(tempSum / array_size);
}

double standardDeviation(int Array[], size_t array_size)
{
   double tempSum = 0;

   for (size_t i = 0; i < array_size; i++)
   {
       tempSum += pow((Array[i] - mean(Array, array_size)), 2);
   }
   return sqrt(tempSum / array_size);
}

void outputMean(float array_to_display[], size_t array_size)
{
   std::cout << "\n";
   std::cout << "The mean is: " << mean(array_to_display, array_size);
   std::cout << std::endl;
}

void outputMean(int array_to_display[], size_t array_size)
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

void outputStandardDeviation(int array_to_display[], size_t array_size)
{
   std::cout << "\n";
   std::cout << "The standard deviation is: " << standardDeviation(array_to_display, array_size);
   std::cout << std::endl;
}
