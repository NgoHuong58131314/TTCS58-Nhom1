#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
typedef struct NhanVien nv;
ofstream ghi("D:/output3.txt");
struct NhanVien
{
	int MaNhanVien;
	char HoLot[50],Ten[50];
	float Luong;
};

void Nhap(NhanVien a[], int sl)
{
	int i;
	for(i=0;i<sl; i++)
	{
		printf("Nhap ma nhan vien: ");
		scanf("%d",&a[i].MaNhanVien);
		printf("Nhap ho lot nhan vien: ");
		fflush(stdin);gets(a[i].HoLot);
		printf("Nhap ten nhan vien: ");
		fflush(stdin);gets(a[i].Ten);
		printf("Luong nhan vien: ");
		scanf("%f",&a[i].Luong);
	}
}
void Xuat(NhanVien a[], int n)
{
	int i;
	printf("\n----------------THONG TIN NHAN VIEN--------------------\n");
	printf("%5s%20s%12s%15s", "MaNV","Holot","Ten","Luong");
	for(i=0;i<n;i++)
	{
		printf("\n%5d%20s%12s%15.2f",a[i].MaNhanVien,a[i].HoLot,a[i].Ten,a[i].Luong);
	}
}

void TruyXuatTheoMNV(NhanVien nv[], int n)
{
	int ma;
	int dem=0;
	cout<<"\nNhap ma nhan vien : ";cin>>ma;
	for(int i=0;i<n;i++)
	{
		if(nv[i].MaNhanVien==ma) 
		{
			cout<<"Ma nhan vien"<<"\t"<<"Ho lot"<<"\t"<<"Ten"<<"\t"<<"Luong"<<endl;
			cout<<nv[i].MaNhanVien<<"\t"<<nv[i].HoLot<<"\t"<<nv[i].Ten<<"\t"<<nv[i].Luong<<endl;
			break;
		} else dem++;
	}
	if(dem!=0) cout<<"khong tim thay ten nhan vien tuong ung\n"<<endl;
	
}
void LuongNV(NhanVien nv[], int n)
{ 
	int max=nv[0].Luong;
	int min=nv[0].Luong;
	for(int i=1;i<n;i++)
	{
		if(max<nv[i].Luong) 
		{
			max = nv[i].Luong;
		} else max = max;
	}
	for(int i=1;i<n;i++)
	{
		if(nv[i].Luong<min)
		{
			min=nv[i].Luong;
		} else min=min;
	}	
	for(int i=0;i<n;i++)
	{
		if(nv[i].Luong==max) cout<<"\nNhan vien co luong cao nhat: " << nv[i].HoLot<<" "<< nv[i].Ten<< endl;
		if(nv[i].Luong==min) cout<<"\nNhan vien co luong thap nhat: "<< nv[i].HoLot<<" "<< nv[i].Ten<< endl;
	}
}
void SapXep( NhanVien a[], int sl)
{
    int i,j;
    for(i=0; i<sl-1; i++)
        for(j=i+1; j<sl; j++)
        if(a[i].Ten < a[j].Ten)
        {
            NhanVien tam = a[i];
            a[i]= a[j];
            a[j]= tam;
        }
	cout<<"\nNhan vien sap xep theo ten: "<<endl;
}
void Ghifile(NhanVien nv, int n)
{
	ofstream ghi;
	ghi.open("output3.txt", ios::out);
	ghi<<"Thong tin nhan vien: " << endl;
	ghi << "Ma nhan vien: " << "\t" << "Ho lot: " << "\t" << "Ten: " << "\t" << "Luong nhan vien: " << endl;
	for(int i=0;i<n;i++)
	{
		if(nv[i].MaNhanVien==n)
		{
			ghi << nv[i].MaNhanVien << "\t";
			ghi << nv[i].HoLot << "\t";
			ghi << nv[i].Ten << "\t";
			ghi << nv[i].Luong << endl;
		}
	}
	LuongNV(nv, n);
	ghi<<"\nNhan vien luong cao nhat:  " << endl;
	ghi<<"\nNhan vien luong thap nhat:  " << endl;	
	ghi<<"\nSap xep nhan vien tang dan theo ten: " << endl;
	ghi<<"MaNV: "<<"\t"<<"Holot: "<<"\t"<<"Ten: "<<"\t"<<"Luong: "<<endl;
	for(int i=0;i<n;i++)
	{
		ghi<<NV[i].MaNhanVien<<"\t";
		gh<<NV[i].HoLot<<"\t";
		ghi<<NV[i].Ten<<"\t";
		ghi<<NV[i].Luong<<endl;
	}
}
void ShowMenu()
{
	cout << "\n---------------------MENU---------------------\n";
	cout << "1. Truy xuat nhan vien theo ma nhan vien" << endl;
	cout << "2. Nhan vien co luong cao nhat va thap nhat" << endl;
	cout << "3. Sap xep nhan vien tang dan theo ten" << endl;
	cout << "4. Ghi ket qua vao file output3" << endl;
	cout << "5. Ket thuc" << endl;
	cout << "\n---------------------END-------------------\n";
}

void Chon()
{
	int n;
	NhanVien nv[50];
	int select;
	cout << "\nLua chon cua ban la: ";
	cin >> select;
	switch (select)
	{
		case 1:
			TruyXuatTheoMNV(nv, n);
			Chon();
			break;
		case 2:
			LuongNV(nv, n);
			Chon();
			break;
		case 3:
			SapXep(nv, n);
			Chon();
			break;
		case 4:
			Ghifile(nv, n);
			Chon();
			break;
		case 5:
			break;
	}
}

int main()
{
	int n;
	NhanVien nv[50];
	printf("Nhap so luong nhan vien: ");
	scanf("%d",&n);
	Nhap(nv,n);
	Xuat(nv,n);
	ShowMenu();
	Chon();
	
	return 0;
}

