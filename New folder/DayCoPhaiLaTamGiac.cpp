#include<bits/stdc++.h>

using namespace std;

//check tam giac trên xuôi theo đường chéo chính
bool checkTrenXuoi(vector<vector<int>> matrix,int n){
    for (int i = 1; i < n; i++)
    {
        for ( int j = 0; j < i; j++)
        {
            if(matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}
//check tam giac dưới xuôi theo đường chéo chính
bool checkDuoiXuoi(vector<vector<int>> matrix, int n){
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}
//check tam giác trên ngược theo đường chéo phụ
bool checkTrenNguoc(vector<vector<int>> matrix, int n){
   for (int  i = n - 1; i > 0; i--)
   {
       for (int j = n - 1 ; j > n - i ; j--)
       {
           if(matrix[i][j]!=0)
               return false;
       }
   }
    return true;
}
//Check ma trận đường chéo
bool checkDuoiNguoc(vector<vector<int>> matrix, int n){
    for(int i = 0; i< n - 2; i++){
        for( int j  = 0; j < n - i - 2;j++){
            if(matrix[i][j]!= 0 )
                return false;
        }
    }
    return true;
}
bool checkCheoChinh(vector<vector<int>> matrix, int n){
    if(checkDuoiXuoi(matrix, n) && checkTrenXuoi(matrix, n))
        return true;
    return false;
}
bool checkCheoPhu(vector<vector<int>> matrix, int n){
    if(checkDuoiNguoc(matrix, n) && checkDuoiXuoi(matrix, n))
        return true;
    return false;
}

bool check(vector<vector<int>> matrix, int n){
    if(checkCheoChinh(matrix, n))
        return false;
    else if(checkCheoPhu(matrix, n))
        return false;
    else if(checkDuoiNguoc(matrix, n))
        return true;
    else if(checkTrenNguoc(matrix, n))
        return true;
    else if(checkTrenXuoi(matrix, n))
        return true;
    else if(checkDuoiXuoi(matrix, n))
        return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int >(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
    }
    if(!check(matrix, n))
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}
