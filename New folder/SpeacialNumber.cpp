/*Số được coi là đặc biệt nếu như số đó cs thể phân tích thành các tổng các lũy thừa cơ số k riêng biệt*/
#include <iostream>
#include <math.h>
using namespace std;

bool isSpecial(int n){
    for (int  i = 2; i < sqrt(n); i++)
    {
        int count = 0;
        while (n%i==0)
        {
            n/=i;
            count++;
        }
        if(count>1) return false;
    }
    return true;
}
int findNextSpecial(int n, int k) {
    int special = 1;
    int power = k;

    while (special <= n) {
        if (isSpecial(power)) {
            special = power;
        }
        power++;
    }

    return special;
}
int main(){
    int n;
    cin>>n;
    cout<<findNextSpecial(n,k);
    return 0;
}