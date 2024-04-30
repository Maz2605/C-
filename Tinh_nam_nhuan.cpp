//Đề: Tính năm nhuận
#include <iostream>

using namespace std;

int main()
{
    int year;
    cin>>year;
    if(year==0)
        cout<<"Nam 0 xac dinh"<<endl;
    else if(year%4==0 && year%100!=0 || year%400==0)
        cout<<year<<" la nam nhuan."<<endl;
    else  
        cout<<year<<" khong phai nam nhuan."<<endl;
    return 0;
}