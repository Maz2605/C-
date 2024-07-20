#include<iostream>
#include<math.h>

using namespace std;

double SQRT(double a){
    double x_n = a;
    double x_n_1;
    while (true)
    {
        x_n_1 = (x_n * x_n + a) / (2 * x_n);
        if(abs((x_n_1 - x_n)/x_n) < 0.00001)
            break;
        x_n = x_n_1;
    }
    return x_n_1;
}


int main(){
    double a;
    cin>>a;
    cout<<SQRT(a);
    return 0;
}
