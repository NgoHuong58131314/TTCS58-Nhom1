#include<stdio.h>
#include<conio.h>
int a[50];
int n;
int t[50]; //chua trang thai la 0 hoac 1
int P;
FILE *f;
void NhapMang(){
	printf("\nNhap P = ");
	scanf("%d", &P);
	do{
		printf("\nNhap vao n = ");
		scanf("%d",&n);
		if(n<=2 || n>=20){
			printf("\nGia tri n khong hop le. Xin nhap lai!");
		}
	}while(n<=2 || n>=20);
	for(int i=0; i<n; i++){
		printf("Nhap a[i] = ");
		scanf("%d",&a[i]);
	}
}

void DocFile()
{
	f = fopen("D:\\input4.txt", "r");
	if(f==NULL){
		printf("\nMo file khong thanh cong!");		
	}
	else{
		fscanf(f, "%d", &n);
		for(int i=1; i<=n; i++){
			fscanf(f, "%d", &a[i]);
		}
	}
	fclose(f);
}
void InKQ()
{
	f=fopen("D:\\output4.txt","w");
	int j, s = 0;
	for(j=0; j<n; j++)
		if(t[j] == 1)
			s = s + a[j];
			
	if(s==P){
		for(j=0; j<n; j++){
			if(t[j] == 1){
				printf("1");
				fprintf(f, "1");			
				}
			else
				printf("0");
				fprintf(f, "0");				
		}printf("\n");
	}
	fclose(f);
}

void Thu(int i)
{
	int j;
	for(j=0; j<=1; j++){
		t[i] = j;
		if(i<n-1)	Thu(i+1);
		else	InKQ();
				t[i] = 0;
	}
	
}
int main()
{
	//NhapMang();
	DocFile();
	InKQ();
	Thu(0);
	getch();
	return 0;
}
