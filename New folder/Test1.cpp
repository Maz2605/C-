#include <bits/stdc++.h>

using namespace std;
class NCC{
	private:
		char maNCC[15];
		char tenNCC[30];
		char dc[40];
	public:
		void nhap();
		void xuat();
	
};
class hang{
	private:
		char tenhang[20];
		float dongia;
		float soluong;
	public:
		void nhap();
		void xuat();
		float thanhtien()
		{
			return dongia*soluong;
		}
};
class phieu{
	private:
		char maphieu[15];
		char ngaylap[20];
		NCC x; //truy xuat doi tuong ncc
		hang *y;
		int n;
	public:
		void nhap();
		void xuat();
		
};
void NCC::nhap()
{
	cout<<"\nnhap ma NCC :";                    fflush(stdin);             gets(maNCC);
	cout<<"\nnhap ten NCC :";                    fflush(stdin);             gets(tenNCC);
	cout<<"\nnhap dia chi :";					  fflush(stdin);             gets(dc);

}
void hang::nhap()
{
	cout<<"\nnhap ten hang :";                  fflush(stdin);             gets(tenhang);
	cout<<"\nnhap don gia :";                   cin>>dongia;
	cout<<"\nnhap so luong :";                   cin>>soluong;
}
void hang::xuat()
{
	cout<<tenhang<<setw(20)<<dongia<<setw(20)<<soluong<<setw(20)<<thanhtien()<<endl;
}
void phieu::nhap()
{
	cout<<"\nnhap ma phieu :"; 					  fflush(stdin);             gets(maphieu);	
	cout<<"\nnhap ngay lap :";                    fflush(stdin);             gets(ngaylap);	
	x.nhap();
	y=new hang[n];
	for (int i=0;i<n;i++)
	{
		cout<<"hang thu "<<i+1<<endl;
		y[i].nhap();
	}
}
void phieu::xuat()
{
	cout<<setw(15)<<"ma phieu :"<<maphieu<<setw(20)<<"ngay lap :"<<ngaylap<<endl;
	x.xuat();
	cout<<"tenhang"<<setw(20)<<"dongia"<<setw(20)<<"soluong"<<setw(20)<<"thanhtien"<<endl;
	for(int i=0;i<n;i++)
	{
		y[i].xuat();
	}
	float tong=0;
	for(int i=0;i<n;i++)
	{
		tong = tong + y[i].thanhtien();
	}
	cout<<setw(45)<<"tong thanh tien :"<<tong<<endl;
}
int main()
{
	phieu a;
	a.nhap();
	cout<<"++++++++++++++++++++++++++PHIEU NHAP HANG++++++++++++++++++++++++++"<<endl;
	a.xuat();
	return 0;
}