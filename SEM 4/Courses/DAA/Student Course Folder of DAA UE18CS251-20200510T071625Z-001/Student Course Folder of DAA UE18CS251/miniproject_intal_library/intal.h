// Library "intal" - Integer of arbitray length
// intal is a nonnegative integer of arbitrary length (not more than 1000 decimal digits).
// The integer is stored as a null terminated string of ASCII characters.
// String of decimal digits ('0' thru '9') are stored in big endian style.

// DO NOT modify this header file.
// Your deliverable is the implementation file.
// The implementation file has the definition of the functions decalred here.
// You can write some of your own helper functions, keep them "static".
// Use the sample test file (that has the main function) to test your implementation.

// All the functions, whenever they return an intal, it should have
// stripped off the leading zeros. For example, difference of "103" and
// "98" should be returned as "5", not as "05" or "005".

// intal as a parameter is never invalid or null and has at least a digit and a null termination.
// intal as a return type has to allocated (using malloc).
// The returning intal is expected to be less than 10^1000.
// Any other memory allocated by you should be freed by you.
// No global variables should be used.

//Converts intal to a string of decimal digits for mostly display purpose.
//Returned string has most significant non-zero digit at the head of the string.
//Returns "NaN" if the intal is null.
// char* intal2str(char* intal);

// Returns the sum of two intals.
char* intal_add(char* intal1, char* intal2);

// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(char* intal1, char* intal2);

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(char* intal1, char* intal2);

// Returns the product of two intals.
char* intal_multiply(char* intal1, char* intal2);

// Returns intal1 mod intal2
// The mod value should be in the range [0, intal2 - 1].
char* intal_mod(char* intal1, char* intal2);

// Returns intal1 ^ intal2.
// Let 0 ^ n = 0, where n is an intal.
char* intal_pow(char* intal1, char* intal2);

// Returns nth fibonacci number.
// intal_fibonacci(0) = intal "0".
// intal_fibonacci(1) = intal "1".
char* intal_fibonacci(unsigned int n);

// Returns Greatest Common Devisor of intal1 and intal2.
// Let GCD be "0" if one of intal1 and intal2 is "0".
char* intal_gcd(char* intal1, char* intal2);

// Returns the factorial of n.
char* intal_factorial(unsigned int n);

// Returns the Binomial Coefficient C(n,k).
// 0 <= k <= n
// C(n,k) < 10^1000 because the reurning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate intal values do not cross C(n.k).
char* intal_bincoeff(unsigned int n, unsigned int k);

// Returns the offset of the largest intal in the array.
// 1 <= n <= 1000
int intal_max(char **arr, int n);

// Returns the offset of the smallest intal in the array.
// 1 <= n <= 1000
int intal_min(char **arr, int n);

// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int intal_search(char **arr, int n);

// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation should be a O(log n) algorithm.
int intal_binsearch(char **arr, int n);

// Sorts the array of n intals.
// 1 <= n <= 1000
// The implementation should be a O(n log n) algorithm.
void intal_sort(char **arr, int n);

// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25
void coin_row_problem(char **arr, int n);
