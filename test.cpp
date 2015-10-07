#include <vector>
#include <iostream>
#include <boost/any.hpp>

int main() {
    std::vector<double> v;
    v.push_back(1.1);
    std::cout << v.size() << std::endl;
}
