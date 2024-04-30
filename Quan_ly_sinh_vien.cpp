#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

#define max 100

struct SinhVien
{
    string msv;
    string name;
    string Que_quan;
    int nam_sinh;
    float GPA;
};
struct List
{
    int Count;
    SinhVien arr[max];
};
int Initialize(List &L){
    return  L.Count==-1;
}
int Full(List&L){
    return L.Count==max-1;
}
int Emty(List  &L){
    return L.Count==-1;
}
int Add(List &L, SinhVien X){
    if(Full(L)== max - 1)
        return 0;
    else{
        L.Count++;
        L.arr[L.Count] = X;
        return 1;
    }
}
void Nhap_sinh_vien(SinhVien &sv){
    cout<<"Msv: ";
    cin.ignore();
    getline(cin,sv.msv);
    cout<<"Ho va ten: ";
    getline(cin, sv.name);
    cout<<"Que quan: ";
    getline(cin,sv.Que_quan);
    cout<<"Nam sinh: ";
    cin>>sv.nam_sinh;
    cout<<"GPA: ";
    cin>>sv.GPA;
}
void Nhap_DS(List &L){
    SinhVien sv;
    if(Full(L)== max -1){
        Nhap_sinh_vien(sv);
    }
    else{
        
    }
}

