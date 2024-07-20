#include<iostream>

using namespace std;

int main()
{
   int n, dem, sum=0;
   cin>>n;
   for(int i=0;i<n;i++)
   {
        if(i%3==0)
        {
            sum+=i;
            dem++;
        }
   }
   cout<<sum/dem;
   return 0;
    
}