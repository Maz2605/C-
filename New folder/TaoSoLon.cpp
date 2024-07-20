#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void findMaxNum(string &s, int swapNums){
    if(swapNums == 0)
        return;
    for(int i = 0 ;i < s.length() && swapNums > 0; i++){
        int maxDigit = s[i];
        for(int j = i; j < s.length(); j++){
            if(s[j] > maxDigit){
                maxDigit = s[j];
            }
        }
        for(int j = s.length() - 1; j >=0 ; j--){
            if(s[j] == maxDigit){
                swap(s[i],s[j]);
                break;
            }
        }
        swapNums--;
    }
}

int main(){
    int swapNums;
    string s;
    cin >> swapNums >> s;
    findMaxNum(s, swapNums);
    cout<<s;
    return 0;
}
