#include <iostream>
#include <utility>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std ;
using boost::multiprecision::cpp_int;

cpp_int fact(cpp_int n)
{
    if(n <= 1)
        return 1 ;
    return n*fact(n-1) ;
}

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    unsigned int n;

    cin >> n;
    cout << fact(n);
    
    return 0 ;
}
