
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

    std::string operator+(const big_integer& other){
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

              cstring_add.insert(cstring_add.begin(), z);;
             }

        return this->cstring_add;
    }
};




int main()
{
    auto number1 = big_integer("7165464654654646555555554335342456788935353533354780654357886543");
    auto number2 = big_integer("1100000000554455555555557454353");
    auto result = number1 + number2;
    std::cout << result << std::endl; 
    number1 = big_integer("114575");
    number2 = big_integer("78524");
    result = number1 + number2;
    std::cout << result << std::endl; // 193099

    return EXIT_SUCCESS;
}
