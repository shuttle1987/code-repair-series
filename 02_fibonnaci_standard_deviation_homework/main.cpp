#include <array>
#include <cmath>
#include <iostream>

const size_t SIZE_OF_GENERIC_ARRAY = 100;
const size_t SIZE_OF_FIBONACCI_ARRAY = 20;

typedef std::array<float, SIZE_OF_GENERIC_ARRAY> seq_array_t;
typedef std::array<int, SIZE_OF_FIBONACCI_ARRAY> fib_array_t;

void fillSequentialIntegersArray(seq_array_t&);
void fillFibonacciArray(fib_array_t&);

template< typename containerT >
double mean(containerT items);

template< typename containerT >
double standardDeviation(containerT items);

template< typename containerT >
void outputMean(containerT items);

template< typename containerT >
void outputStandardDeviation(containerT items);

int main(int argc, char* argv[])
{
   char sequenceType;
   seq_array_t SequentialNumbers;
   fib_array_t FibonacciNumbers;
   std::cout << "Would you like to generate a generic sequence or a Fibonacci sequence?"
       << std::endl
       << "\n"
       << "Type [G] + [ENTER] for a generic sequence, or;" << std::endl
       << "Type [F] + [ENTER] for a Fibonacci sequence: ";
   std::cin >> sequenceType;

   if (sequenceType == 'G' || sequenceType == 'g')
   {
       fillSequentialIntegersArray(SequentialNumbers);
       outputMean(SequentialNumbers);
       outputStandardDeviation(SequentialNumbers);
   }
   else if (sequenceType == 'F' || sequenceType == 'f')
   {
       fillFibonacciArray(FibonacciNumbers);
       outputMean(FibonacciNumbers);
       outputStandardDeviation(FibonacciNumbers);
   }
   else
   {
       std::cout << "\n"
            << "Invalid input. Please type 'F' or 'G'. Thank you.";
   }
   return 0;
}

void fillSequentialIntegersArray(seq_array_t& array_to_fill)
{
   size_t array_size = array_to_fill.size();
   for (size_t i = 0; i < array_size; i++){
       array_to_fill[i] = i + 1;
   }
}

void fillFibonacciArray(fib_array_t& array_to_fill)
{
   array_to_fill[0] = 0;
   array_to_fill[1] = 1;

   size_t array_size = array_to_fill.size();
   for (size_t i = 2; i < array_size; i++){
       array_to_fill[i] = array_to_fill[i - 1] + array_to_fill[i - 2];
   }
}

template< typename containerT >
double mean(containerT items)
{
   double sumOfElements = 0;
   size_t container_size = items.size();
   for (size_t i = 0; i < container_size; i++)
   {
       sumOfElements += items[i];
   }
   return sumOfElements / container_size;
}

template< typename containerT >
double standardDeviation(containerT items)
{
   double tempSum = 0;
   size_t container_size = items.size();
   double calculated_mean = mean(items);
   for (size_t i = 0; i < container_size; i++)
   {
       tempSum += pow((items[i] - calculated_mean), 2);
   }
   return sqrt(tempSum / container_size);
}

template< typename containerT >
void outputMean(containerT items)
{
   std::cout << "\n";
   std::cout << "The mean is: " << mean(items);
   std::cout << std::endl;
}

template< typename containerT >
void outputStandardDeviation(containerT items)
{
   std::cout << "\n";
   std::cout << "The standard deviation is: " << standardDeviation(items);
   std::cout << std::endl;
}
