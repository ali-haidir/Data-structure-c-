
#include "iostream"
using namespace std;

void multiply(int array[], int n)
{
int x = 1;


for (int i = 0; i < n; ++i) {
x *= array[i];
}

for (int i = 0; i < n; ++i) {
array[i] = x / array[i];
}
}

int main()
{
int array[] = { 1 , 2 , 3};
int n = sizeof(array) / sizeof(array[0]);

multiply(array, n);

for (int i = 0; i < n; ++i) {
cout << array[i] << " ";
}
return 0;
}
