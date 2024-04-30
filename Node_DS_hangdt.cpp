#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct HangDienTu
{
    char maHang[10];
    char tenHang[30];
    char tenNSX[30];
    int namSX;
    float giaBan;
};
struct Node
{
    HangDienTu infor;
    Node *next;
};
typedef Node *TRO;
//khởi tạo
void creat(TRO &l){
    l = NULL;
}
//Kiểm tra danh sách rỗng
int Emty(TRO l){
    return l==NULL;
}
void NhapHangDienTu(HangDienTu &x){
    cout<<"Ma hang: ";      fflush(stdin);          gets(x.maHang);
    cout<<"Ten: ";          fflush(stdin);          gets(x.tenHang);
    cout<<"Ten NSX: ";      fflush(stdin);          gets(x.tenNSX);
    cout<<"Nam san xuat: "; cin>>x.namSX;
    cout<<"Gia ban: ";      cin>>x.giaBan;
}
void NhapDanhSach(TRO &l ){
    int n;
    cout<<"Nhap so lương hang muon nhap: ";
    cin>>n;
    creat(l);
    HangDienTu x;
    TRO Q, P;
    int i = 1;
    do{
        cout<<"STT: "<<i<<endl;
        NhapHangDienTu(x);
        P = new (Node);
        P->infor = x;
        P->next=NULL;
        if(l==NULL)
            l = P;
        else    
            Q->next = P;
        Q = P;
        i++;
    }while(i<=n);
}
void HienThiDanhSach(TRO &l){
    if(l==NULL){
        cout<<"Danh sach rong"<<endl;
        return;
    }
    cout<<setw(5)<<"STT ";
    cout<<setw(10)<<"Ma Hang";
    cout<<setw(20)<<"Ten Hang";
    cout<<setw(20)<<"Ten NSX";
    cout<<setw(15)<<"Nam San xuat";
    cout<<setw(10)<<"Gia ban";
    cout<<endl;
    TRO Q = l;
    int i=1;
    while(Q != NULL){
        HangDienTu x  = Q->infor;
        cout<<setw(5)<<i++;
        cout<<setw(10)<<x.maHang;
        cout<<setw(20)<<x.tenHang;
        cout<<setw(20)<<x.tenNSX;
        cout<<setw(15)<<x.namSX;
        cout<<setw(10)<<x.giaBan;
        cout<<endl;
        Q = Q->next;
    }
}
int Length(TRO &l){
    int n = 0;
    TRO Q = l;
    while (Q!=NULL)
    {
        Q = Q->next;
        n++;
    }
    return n;
}
void Add(TRO &l){
    int k;
    cout<<"Nhap vi tri muon them: ";
    cin>>k;
    if(k<0 ||k>Length(l))
        return;
    cout<<"Nhap mat hang can them: "<<endl;
    HangDienTu x;
    NhapHangDienTu(x); 
    TRO P = new (Node);
    P->infor=x;
    TRO Q=l;
    int d=0;
    while(Q!= NULL){
        if(d==k)
            break;
        Q=Q->next;
        d++;
    }
    P->next = Q->next;
    Q->next = P;
}
int main(){
    TRO L;
    NhapDanhSach(L);
    HienThiDanhSach(L);
    Add(L);
    HienThiDanhSach(L);
}



