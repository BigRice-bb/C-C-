#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;


int main() {
    srand(static_cast<unsigned>(time(0)));
    int random_number = rand() % 2;
    cout << random_number << std::endl;

    return 0;
}
