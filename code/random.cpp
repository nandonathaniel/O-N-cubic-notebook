#include<algorithm>
#include<chrono>
#include<random>
using namespace std;
// Note: Requires C++11
// A random number generator that uses time since epoch to generate random numbers
// It is much faster than rand(), and the numbers are more uniformly generated
// Using time_since_epoch makes the seed number much more unpredictable
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	// Print a random number from 0 to 2^32 - 1 (unsigned int)
	printf("%u\n", rng());
	// Use of RNG in shuffle
	shuffle(permutation.begin(), permutation.end(), rng);
	// Generates an equiprobable random numbers in interval [a, b] inclusive
	printf("%d\n", uniform_int_distribution<int>(1, 6)(rng));
}
