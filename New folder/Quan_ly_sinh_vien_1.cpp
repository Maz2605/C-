#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

#define max 100
struct SinhVien{
    char msv[10];
    char name[50];
    int namsinh;
    float gpa;
};
struct List{
    int Count;
    SinhVien e[max];
};
//Khoi tao ds rong
void Initialize(List &L){
    L.Count = -1;
}
//Check ds
int Full(List L){
    return L.Count == max-1;
}
//check Ds Rong
int Emty(List L){
    return L.Count==-1;
}
int Add(List &L, SinhVien X){
    if(Full(L)== max-1)
        return 0;
    else{
        L.Count++;
        L.e[L.Count]=X;
        return 1;
    }
}

void Nhap_SinhVien(SinhVien &sv){
    cout<<"Nhap MSV: ";
    fflush(stdin);
    gets(sv.msv);
    if(strcmp(sv.msv,"***")==0){
        return;
    }
    cout<<"Ho va ten: ";
    fflush(stdin);
    gets(sv.name);
    cout<<"Nam sinh: ";
    cin>>sv.namsinh;
    cout<<"GPA: ";
    cin>>sv.gpa;
}

void Nhap_Ds(List &L){
    Initialize(L);
    SinhVien x;
    int i = 1;
    do{
        cout<<"Sinh vien thu "<<i<<endl;
        Nhap_SinhVien(x);
        if(strcmp(x.msv,"***")==0)
            return;
        if(!Add(L,x))
            return;
        i++;
    }while(true);
}
void Hien_thi_Ds(List L){
    cout<<setw(5)<<"STT";
    cout<<setw(10)<<"MSV";
    cout<<setw(25)<<"Ho va ten";
    cout<<setw(10)<<"Nam sinh";
    cout<<setw(10)<<"GPA";
    cout<<endl;
    for(int i=0;i<=L.Count;i++){
        cout<<setw(5)<<(i+1);
        cout<<setw(10)<<L.e[i].msv;
        cout<<setw(25)<<L.e[i].name;
        cout<<setw(10)<<L.e[i].namsinh;
        cout<<setw(10)<<L.e[i].gpa;
        cout<<endl;
    }
}
void Delete_first(List &L){
    if(Emty(L)==-1)
        return;
    for(int i=0;i<L.Count;i++){
        L.e[i] = L.e[i+1];
    }
    L.Count--;
    Hien_thi_Ds(L);
}
void Delete(List &L){
    char msv_can_xoa[10];
    cout<<"Nhap msv cua sv muon xoa: ";
    fflush(stdin);
    gets(msv_can_xoa);
    for(int i = 0;i<L.Count;i++){
        if(strcmp(L.e[i].msv, msv_can_xoa)==0){
            for(int j=i;j<L.Count;j++){
                L.e[j] = L.e[j+1];
            }
            L.Count--;
            break;
        }
    }
    Hien_thi_Ds(L);
}
void Insert(List &L){
    int k;
    SinhVien x;
    cout<<"Nhap vi tri muon them: ";
    cin>>k;
    Nhap_SinhVien(x);
    Add(L,x);
    for(int i=L.Count-1;i>=k;i--){
        L.e[i+1]=L.e[i];
    }
    L.e[k-1] = x;
    Hien_thi_Ds(L);
}
void Search(List &L){
    List y;
    Initialize(y);
    char name_can_tim[50];
    cout<<"Nhap ten can tim: ";
    fflush(stdin);
    gets(name_can_tim);
    for(int i=0;i<L.Count;i++){
        if(strcmp(L.e[i].name,name_can_tim)==0){
            Add(y,L.e[i]);
        }
    }
    Hien_thi_Ds(y);
}
void Sort(List &L){
        for(int i=0;i<L.Count;i++){
            for(int j = i+1;j<L.Count;j++){
                if(L.e[i].gpa>L.e[j].gpa){
                    SinhVien x = L.e[i];
                    L.e[i]=L.e[j];
                    L.e[j]=x;
                }
            }
        
    }
    Hien_thi_Ds(L);
}
int main(){
    List L;
    Nhap_Ds(L);
    cout<<"DS Sinh vien"<<endl;
    Hien_thi_Ds(L);
    //Delete_first(L);
    //Delete(L);
    //Insert(L);
    //Search(L);
    Sort(L);
    return 0;
}