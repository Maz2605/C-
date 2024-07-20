#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    for(int i=1;i<=n;i++)
    {
        if(x-z>y-z)
            cout<<"Cat A";
        else if(x-z<y-z)
            cout<<"Cat B";
        else
            cout<<"Mouse C";
    }
    return 0;
    
}