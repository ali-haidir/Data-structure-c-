#include<iostream>
#include<string>

using namespace std;


class fact
{
public:
    int factorial(int n)
    {
        int pro = 1;
        if(n == 0 || n == 1)
        {
            return 1;
        }
        return n * factorial(n-1);
    }
};
int main()
{
    fact f;
    int n;
    cout<<"Enter the number you want  ";
    cin>>n;
    cout<<"Factorial of  is = "<<f.factorial(n);
    return 0;
}
