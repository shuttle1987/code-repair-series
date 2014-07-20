#include <array>
#include <cmath>
#include <iostream>

const size_t SIZE_OF_GENERIC_ARRAY = 100;
const size_t SIZE_OF_FIBONACCI_ARRAY = 20;

typedef std::array<float, SIZE_OF_GENERIC_ARRAY> seq_array_t;
typedef std::array<int, SIZE_OF_FIBONACCI_ARRAY> fib_array_t;

void fillSequentialIntegersArray(seq_array_t&);
void fillFibonacciArray(fib_array_t&);

double mean(seq_array_t);
double mean(fib_array_t);

double standardDeviation(seq_array_t);
double standardDeviation(fib_array_t);

void outputMean(seq_array_t);
void outputMean(fib_array_t);

void outputStandardDeviation(seq_array_t);
void outputStandardDeviation(fib_array_t);

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

double mean(fib_array_t fib_container)
{
   double sumOfElements = 0;
   size_t container_size = fib_container.size();
   for (size_t i = 0; i < container_size; i++)
   {
       sumOfElements += fib_container[i];
   }
   return sumOfElements / container_size;
}

double mean(seq_array_t seq_container)
{
   double sumOfElements = 0;
   size_t container_size = seq_container.size();
   for (size_t i = 0; i < container_size; i++)
   {
       sumOfElements += seq_container[i];
   }
   return sumOfElements / container_size;
}

double standardDeviation(seq_array_t seq_container)
{
   double tempSum = 0;
   size_t container_size = seq_container.size();
   double calculated_mean = mean(seq_container);
   for (size_t i = 0; i < container_size; i++)
   {
       tempSum += pow((seq_container[i] - calculated_mean), 2);
   }
   return sqrt(tempSum / container_size);
}

double standardDeviation(fib_array_t fib_container)
{
   double tempSum = 0;
   size_t container_size = fib_container.size();
   double calculated_mean = mean(fib_container);
   for (size_t i = 0; i < container_size; i++)
   {
       tempSum += pow((fib_container[i] - calculated_mean), 2);
   }
   return sqrt(tempSum / container_size);
}

void outputMean(seq_array_t array_to_display)
{
   std::cout << "\n";
   std::cout << "The mean is: " << mean(array_to_display);
   std::cout << std::endl;
}

void outputMean(fib_array_t array_to_display)
{
   std::cout << "\n";
   std::cout << "The mean is: " << mean(array_to_display);
   std::cout << std::endl;
}

void outputStandardDeviation(seq_array_t array_to_display)
{
   std::cout << "\n";
   std::cout << "The standard deviation is: " << standardDeviation(array_to_display);
   std::cout << std::endl;
}

void outputStandardDeviation(fib_array_t array_to_display)
{
   std::cout << "\n";
   std::cout << "The standard deviation is: " << standardDeviation(array_to_display);
   std::cout << std::endl;
}
