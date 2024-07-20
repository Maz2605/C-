/*Trong nhà sách ddangbans một bộ sách gồm n cuốn sách mỗi cuốn sách có giá là a[i]. Nhà sách đang có uuuw đãi là mua 3 cuốn giảm thì miễn phí cho quyển sách rẻ nhất trong 3 cuốn sách đó. Tìm chi phí tốt nhất để mua n cuốn sách */
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    int S=0;
    for (int  i = 0; i < n; i++)
    {
        if((i+1)%3==0)
            continue;
        S+=a[i];
    }
    cout<<endl;
    cout<<S;
    return 0;
}