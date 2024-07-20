#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

struct SinhVien
{
    char MaSV[10];
    char HoDem[30];
    char Ten[20];
    int NamSinh;
    float GPA;
};
struct Node
{
    SinhVien infor;
    Node *next;
};
typedef Node *Tro;
void Khoitao(Tro &L){
    L==NULL;
}
bool Emty(Tro &L){
    return L==NULL;
}
void NhapSinhVien(SinhVien &sv){
    cout<<"Ma sin vien: ";  fflush(stdin);  gets(sv.MaSV);
    if(strcmp(sv.MaSV, "***")==0)
        return;
    cout<<"Ho ten: ";   fflush(stdin);      gets(sv.HoDem);
    cout<<"Ten: ";      fflush(stdin);      gets(sv.Ten);
    cout<<"Nam sinh: ";                     cin>>sv.NamSinh;
    cout<<"GPA: ";                          cin>>sv.GPA;
}
void NhapDS(Tro &L){
    Khoitao(L);
    SinhVien x;
    Tro P, Q;
    int i = 1;
    do{
        cout<<"STT: "<<i++;
        NhapSinhVien(x);
        if (strcmp(x.MaSV,"***")==0)
            return;
        P = new Node;
        P->infor = x;
        P->next = NULL;
        if (L == NULL)
        {
            L = P;
        }
        else
            Q->next = P;
        Q=P;
    }while (true);
}
void HienThiDS(Tro &L){
    if(L==NULL){
        cout<<"Danh sach rong";
        return;
    }
    cout<<"STT"<<setw(5);
    cout<<setw(10)<<"Ma SV";
    cout<<setw(25)<<"Ho va ten";
    cout<<setw(10)<<"Nam sinh";
    cout<<setw(10)<<"GPA";
    Tro Q=L;
    int i=0;
    while (Q!=NULL)
    {
        SinhVien x = Q->infor;
        cout<<
    }
    

}
int main(int argc, char const *argv[])
{
    cout<<"STT"<<setw(5);
    cout<<setw(10)<<"Ma SV";
    cout<<setw(25)<<"Ho va ten";
    cout<<setw(10)<<"Nam sinh";
    cout<<setw(10)<<"GPA";
    return 0;
}


