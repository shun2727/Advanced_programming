#include <iostream>
#include <random>
#include <ctime>
//only works for c++ 17 and above 

typedef struct a{

} t_a;

struct b{

};

//field of union will share the same memory
// writing to i and f will write to the same locaiotn 
union var{
	int i;
	float f;
};

int main()
{
	std::normal_distribution<> normal1();
}