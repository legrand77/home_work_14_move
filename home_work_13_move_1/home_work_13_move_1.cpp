
#include <iostream>
#include <vector>

template <class T>
void move_vectors(std::vector<T>& lhs, std::vector<T>& rhs){
lhs = std::move(rhs);
}

int main()
{
std::vector <std::string> one = { "test_string1", "test_string2" };
std::vector <std::string> two;
move_vectors(two,one);

for (auto i : two)
{
std::cout << i << std::endl;
}
return EXIT_SUCCESS;
}
