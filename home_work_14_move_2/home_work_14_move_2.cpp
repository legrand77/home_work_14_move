
#include <iostream>
#include <math.h>
#include <string>

class big_integer
{
private:
    std::string cstring{};
    std::string cstring_add{};
    std::string cstring_tmp{};
    std::string cstring_tmp_max{};
public:
    big_integer(const std::string& s) : cstring(s), cstring_tmp_max(s) {}

    big_integer(big_integer&& other) noexcept // конструктор перемещения
        : cstring(std::exchange(other.cstring, 0)), 
        cstring_tmp_max(std::exchange(other.cstring, 0)) {}


    std::string operator+(const big_integer& other){
        cstring_add.erase();
        if (cstring.size() > other.cstring.size()) {
            cstring_tmp = other.cstring;
        }
        else {
            cstring_tmp = cstring;
            cstring_tmp_max = other.cstring;
        }
         if (cstring.size() != other.cstring.size()) {
            int x = cstring.size() - other.cstring.size();
            int y = abs(x);  
            cstring_tmp.insert(cstring_tmp.begin(), y, '0');
         }
         int k{};
         int z{};
         int c{};
            for (int i = cstring_tmp_max.size()-1; i > -1; i--) {
                if (1==k) {
                    z = ((cstring_tmp_max[i]) + (cstring_tmp[i])) - 47;
                    k = 0;
                }
                else  z = ((cstring_tmp_max[i]) + (cstring_tmp[i])) - 48;
                if (z > 57) {
                  z -= 10;
                  k = 1;
                }

              cstring_add.insert(cstring_add.begin(), z);
              if ((i == 0) && k == 1) c = 1;

             }

            if ( 1 == c) cstring_add.insert(cstring_add.begin(), 49);
        return this->cstring_add;
    }

    std::string operator*(int a) {
        cstring_tmp = cstring;

        for (int i = 1; i < a; i++) { 
            int k{};
            int z{};
            cstring_add.erase();

            for (int i = cstring.size() - 1; i > -1; i--) {
                if (1 == k) {
                    z = ((cstring[i]) + (cstring_tmp[i])) - 47;
                    k = 0;
                }
                else  z = ((cstring[i]) + (cstring_tmp[i])) - 48;
                if (z > 57) {
                    z -= 10;
                    k = 1;
                }
                cstring_add.insert(cstring_add.begin(), z);
            } 
            cstring_tmp = cstring_add;
        }
        
        return this->cstring_add;
    }
    big_integer& operator=(big_integer&& other) noexcept // оператор перемещающего присваивания
    {
        std::swap(cstring, other.cstring);
        std::swap(cstring_tmp_max, other.cstring_tmp_max);
        return *this;
    }


};




int main()
{
    /*auto number1 = big_integer("7165464654654646555555554335342456788935353533354780654357886543");
    auto number2 = big_integer("1100000000554455555555557454353");
    auto result = number1 + number2;
    std::cout << result << std::endl; */
   auto number1 = big_integer("114575");
   auto number2 = big_integer("78524");
   auto  result = number1 + number2;
   std::cout << result << std::endl; // 193099
   std::cout << number1*5 << std::endl;
   auto number3(&number1);
   auto number4=&number3;
   result = number2 + number2;
   std::cout << result << std::endl; 
   result = number2 + *number3;
   std::cout << result << std::endl;
   result = number2 + **number4;
   std::cout << result << std::endl;
   return EXIT_SUCCESS;
}
