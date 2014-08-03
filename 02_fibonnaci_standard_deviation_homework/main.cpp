#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <type_traits>

const size_t SIZE_OF_GENERIC_ARRAY = 100;
const size_t SIZE_OF_FIBONACCI_ARRAY = 20;

typedef std::array<float, SIZE_OF_GENERIC_ARRAY> seq_array_t;
typedef std::array<int, SIZE_OF_FIBONACCI_ARRAY> fib_array_t;

/** Fills an array with sequential integers
 * @param reference to the array that we are filling
 */
void fillSequentialIntegersArray(seq_array_t&);

/** Fills an array with sequential fibonacci numbers
 * @param reference to the array that we are filling
 */
void fillFibonacciArray(fib_array_t&);

/** Calculate the mean for a collection of items
 *@tparam the type of the collection
 *@param the collection of items for which we are calculating the mean
 */
template< typename containerT >
double mean(containerT const& items);

/** Calculate the standard deviation for a collection of items
 *@tparam the type of the collection
 *@param the collection of items for which we are calculating the standard deviation
 */
template< typename containerT >
double standardDeviation(containerT const& items);

/** Calculates the mean of a container of items then outputs it to console
 *@param the collection of items we are calculating then displaying the mean of
 */
template< typename containerT >
void outputMean(containerT const& items);

/** Calculates the standard deviation of a container of items then outputs it to console
 *@param the collection of items we are calculating then displaying the standard deviation of
 */
template< typename containerT >
void outputStandardDeviation(containerT const& items);

/** Asserts that 2 floating point numbers are within epsilon of each other */
template< typename T >
void assert_floats_equality(T f1, T f2, T epsilon){
   assert((f1 < f2 + epsilon) && (f1 > f2 - epsilon));
}

bool run_unit_tests(){
   seq_array_t SequentialNumbers;
   fib_array_t FibonacciNumbers;

   fillSequentialIntegersArray(SequentialNumbers);
   fillFibonacciArray(FibonacciNumbers);

   double epsilon = 0.01;

   assert_floats_equality(mean(SequentialNumbers), 50.5, epsilon);
   assert_floats_equality(mean(FibonacciNumbers), 547.25, epsilon);

   assert_floats_equality(standardDeviation(SequentialNumbers), 28.8661, epsilon);
   assert_floats_equality(standardDeviation(FibonacciNumbers), 1055.81, epsilon);

   return true;
}

int main(int argc, char* argv[])
{
   std::array<int*, 10> array_of_pointers;
   outputMean(array_of_pointers);
   outputStandardDeviation(array_of_pointers);

   /*
   run_unit_tests();
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
   }*/
   return 0;
}

void fillSequentialIntegersArray(seq_array_t& array_to_fill)
{
   const size_t array_size = array_to_fill.size();
   for (size_t i = 0; i < array_size; i++){
       array_to_fill[i] = i + 1;
   }
}

void fillFibonacciArray(fib_array_t& array_to_fill)
{
   array_to_fill[0] = 0;
   array_to_fill[1] = 1;

   const size_t array_size = array_to_fill.size();
   for (size_t i = 2; i < array_size; i++){
       array_to_fill[i] = array_to_fill[i - 1] + array_to_fill[i - 2];
   }
}

template< typename containerT >
double mean(containerT const& items)
{
   static_assert(std::is_arithmetic< typename containerT::value_type >::value,
                 "This function only operates on containers with numeric types");
   double sumOfElements = 0;
   const size_t container_size = items.size();
   for (size_t i = 0; i < container_size; i++)
   {
       sumOfElements += items[i];
   }
   return sumOfElements / container_size;
}

template< typename containerT >
double standardDeviation(containerT const& items)
{
   static_assert(std::is_arithmetic< typename containerT::value_type >::value,
                 "This function only operates on containers with numeric types");
   double tempSum = 0;
   const size_t container_size = items.size();
   const double calculated_mean = mean(items);
   for (size_t i = 0; i < container_size; i++)
   {
       tempSum += pow((items[i] - calculated_mean), 2);
   }
   return sqrt(tempSum / container_size);
}

template< typename containerT >
void outputMean(containerT const& items)
{
   std::cout << "\n";
   std::cout << "The mean is: " << mean(items);
   std::cout << std::endl;
}

template< typename containerT >
void outputStandardDeviation(containerT const& items)
{
   std::cout << "\n";
   std::cout << "The standard deviation is: " << standardDeviation(items);
   std::cout << std::endl;
}
