#include <bits/stdc++.h>

using namespace std;
#define MAX 500 
int result[MAX] ;
int result_size ;

void multiply(int x)
{
  int carry = 0 ;
  for(int i=0; i<result_size; i++)
  {
    int res = result[i]*x + carry ;
    result[i] = res%10 ;
    carry = res/10 ;
  }

  while(carry)
  {
    result[result_size++] = carry%10 ;
    carry /= 10 ;
  }
}
// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) 
{
  result[0] = 1 ;
  result_size = 1 ;
  for(int i=2; i<=n; i++)
    multiply(i) ;

  for(int i=result_size - 1; i>=0; i--)
    cout << result[i] ;  

}

int main()
{
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}
