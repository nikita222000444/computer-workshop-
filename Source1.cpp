/*
* Д / З:
* Простые делители числа 13195 - это 5, 7, 13 и 29.
* Каков самый большой делитель числа 600851475143, являющийся простым числом?
*/

#include <stdio.h>
#include <math.h>

bool IsPrime(int number_)
{
   // Обработаем исключения: проверим number_ на отрицательность
   if (number_ < 2)
      return false;

   unsigned int nSqrt = (int)sqrt(number_) + 1; // т.к ф-я sqrt возвращает тип double, а нам нужно целое, то "приводим тип" к нужному с помощью (int)

   if (number_ == 2)
      return true;

   if (number_ % 2 == 0)
      return false;

   for (unsigned int i = 3; i <= nSqrt; i += 2)
   {
      if (number_ % i == 0)
         return false;
   }

   return true;
}

int main()
{
   unsigned int n = 600851475143;
   int s = 2;
   for (unsigned int i = 1; i <= ((int) sqrt(n) + 1); i += 2)
   {
      if (IsPrime(i) && n % i == 0 && i > s)
         s = i;
   }
   printf("%d ", s);
}