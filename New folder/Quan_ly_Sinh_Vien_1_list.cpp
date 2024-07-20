#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

struct SinhVien
{
    char msv[10];
    char name[50];
    char country[30];
    char gender[5];
    int Date;
    float GPA;
};
#define max 100
struct List
{
    SinhVien e[max];
    int count;
};
void Initialize(List &l){
    l.count=-1;
}
int Emty(List &l){
    return l.count==-1;
}
int Full(List &l){
    return l.count==max-1;
}
int Add(List &l, SinhVien x){
    if (Full(l)==true)
        return 0;
    else{
        l.count++;
        l.e[l.count] = x;
        return 1;                 
    } 
}
void NhapSinhVien(SinhVien &x){
    cout<<"Ma sinh vien: ";         fflush(stdin);              gets(x.msv);
    cout<<"Ho va ten: ";            fflush(stdin);              gets(x.name);
    cout<<"Gioi tinh: ";            fflush(stdin);              gets(x.gender);
    cout<<"Que quan: ";             fflush(stdin);              gets(x.country);
    cout<<"Nam sinh: ";             cin>>x.Date;   
    cout<<"GPA: "     ;             cin>>x.GPA;  
}
void NhapDanhSach(List &l){
    Initialize(l);
    SinhVien x;
    int i = 1;
    int n;
    cout<<"So luong sinh vien muon nhap: ";
    while(i<n){
        cout<<"STT: "<<i++<<endl;
        NhapSinhVien(x);
        if(strcmp(x.msv,"***")==0){
            return;
        }
        if(!Add(l, x))
            return;
    }
}
void HienThiDanhSach(List &l){
    cout<<setw(5)<<"STT";
    cout<<setw(10)<<"MSV";
    cout<<setw(25)<<"Ho va ten";
    cout<<setw(10)<<"Gioi tinh";
    cout<<setw(25)<<"Que quan";
    cout<<setw(10)<<"Nam sinh";
    cout<<setw(10)<<"GPA";
    cout<<endl;
    for(int i=0;i<=l.count;i++){
        cout<<setw(5)<<(i+1);
        cout<<setw(10)<<l.e[i].msv;
        cout<<setw(25)<<l.e[i].name;
        cout<<setw(10)<<l.e[i].gender;
        cout<<setw(25)<<l.e[i].country;
        cout<<setw(10)<<l.e[i].Date;
        cout<<setw(10)<<l.e[i].GPA;
        cout<<endl;
    }
}
int main(){
    List l;
    SinhVien x;
    NhapDanhSach(l);
    HienThiDanhSach(l);
}

