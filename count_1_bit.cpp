#include <iostream>

int count_1_bit (int min, int max)
{
   int result = 0;
   for (int value = min; value <= max; ++value)
   {
       for (int i = 0; i < sizeof(int) * 8; ++i)
       {
           int is_one = value & (1 << i);
           if (is_one)
               result++;
       }
   }
   return result;
}

int main()
{
    std::cout << count_1_bit (0, 4) << std::endl;
}
