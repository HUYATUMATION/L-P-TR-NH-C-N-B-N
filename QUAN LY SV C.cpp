# include<stdio.h>
# include<conio.h>
# include<stdlib.h>
# include<string.h>
typedef struct THONGTIN SV;
typedef struct monhoc monhoc;
struct monhoc{
	char tenmon[100];
	float diem;
};
struct THONGTIN{
	monhoc dsmon [21];
	char mssv[20];
	char hoten[100];
	char nghanh[20];
	int somon ;
};
void nhap(SV*sv);
void inthongtin(SV sv[],int n);
void timkiemsv(FILE*file1,char*nhanbiet);
float diemtrungbinh(FILE*file1,int n);
void xoasinhvien(FILE*file1,int dem);
void sapxep(FILE*file1,int k);
int main(){
	FILE*file1;
	int ngchon,luachon;
	do{
		printf("					MENU				\n");
		printf("	------------------------------------------------------------------------\n");
		printf("	CAP NHAT THEM SINH VIEN : Nhan phim :1\n");
		printf("	IN RA SO LUONG SINH VIEN DAU TIEN TRONG DANH SACH : Nhan phim: 2\n");
		printf("	TIM KIEM SINH VIEN TRONG DANH SACH : Nhan phim :3\n");
		printf("	DIEM TRUNG BINH CUA TAT CA SINH VIEN LA : Nhan phim 4\n");
		printf("	XOA THONG TINH SINH VIEN BANG MA SO SINH VIEN : Nhan phim 5\n");
		printf("\n\n");
		SV*quanly=(SV*)calloc(1,sizeof(SV));
		file1=fopen("QUAN LY SINH VIEN.bin","rb");
		int k=0;
		while(( fread(quanly,sizeof(SV),1,file1))==1){
			k++;
		}
		fclose(file1);
		free(quanly);
		printf("SO SINH VIEN DANG QUAN LY LA:%d\n",k);
		scanf("%d",&luachon);
      switch(luachon){
      	case 1: 
		  {
      	    int n;
	    	 printf("NHAP N SINH VIEN CAN CAP NHAT LA:");
			 scanf("%d",&n);
			 fflush(stdin);
			 SV sv[n];
			 for(int i=0;i<n;i++) nhap(&sv[i]);
			 file1=fopen("QUAN LY SINH VIEN.bin","ab");
			 fwrite(sv,sizeof(SV),n,file1);
			 fclose(file1);
			 file1=fopen("QUAN LY SINH VIEN.bin","rb");
			 sapxep(file1,k+n);
			 break;}
		case 2:
		{
			int k;
			printf("XUAT RA N SINH VIEN DAU TIEN :"); scanf("%d",&k);
			fflush(stdin);
	    	 SV docfile1[k];
	    	 file1=fopen("QUAN LY SINH VIEN.bin","rb");
			fread(docfile1,sizeof(SV),k,file1);
			fclose(file1);
			for(int i=0;i<k;i++){
				printf("MSSV :%s\n",docfile1[i].mssv);
				printf("HO VA TEN LA:%s\n",docfile1[i].hoten);
				printf("NGANH HOC:%s\n",docfile1[i].nghanh);
				printf("SO MON DANG KI:%d\n",docfile1[i].somon);
				printf("DIEM TB CUA SV: %f\n",docfile1[i].dsmon->diem);
			}
			break;}
		case 3:{
            char*nhanbiet=(char*)calloc(10,sizeof(char)); 
            file1=fopen("QUAN LY SINH VIEN.bin","rb");
			timkiemsv(file1,nhanbiet);
			fclose(file1);
			free(nhanbiet);
			
	        break;
	 	}
	 	case 4:{
	 		int l;
	 		file1=fopen("QUAN LY SINH VIEN.bin","rb");
	    	 printf("DIEM TB CUA TAT CA SV LA:%.2f\n",diemtrungbinh(file1,l));
	    	 fclose(file1);
	    	 break;
		                                }
		case 5:{
			int dem=0;
			file1=fopen("QUAN LY SINH VIEN.bin","rb");
			fflush(stdin);
			xoasinhvien(file1,dem);
			break;
		}
	    }
		printf("CO MUON TIEP TUC KHONG "); scanf("%d",&ngchon);
	}
	while(ngchon!=0);
}
void nhap(SV*sv){
	printf("MSSV LA :\n"); gets(sv->mssv);
	printf("\nHO VA TEN CUA SINH VIEN :\n"); gets(sv->hoten);
	printf("\nNGANH HOC LA:\n"); gets(sv->nghanh);
	printf("SO MON DANG KI LA:\n"); scanf("%d",&sv->somon);
	printf("DIEM TB CUA SV:\n"); scanf("%f",&(sv->dsmon->diem));
	fflush(stdin);
}
void inthongtin(SV sv[],int n){
	for(int i=0;i<n;i++){
	printf("HO VA TEN :%s\n",sv[i].hoten);
    printf("MSSV: %s\n",sv[i].mssv);
    printf("NGANH HOC LA: %s\n",sv[i].nghanh);
    printf("SO MO DANG KI LA:%d\n",sv[i].somon);
	}
}
void timkiemsv(FILE*file1,char*nhanbiet){
	int trangthai=0;
	SV*sv=(SV*)calloc(1,sizeof(SV));
	printf("NHAP MSSV CUA SINH VIEN CAN TIM LA:");
	fflush(stdin);
	gets(nhanbiet);
	while(( fread(sv,sizeof(SV),1,file1))==1){
		if(strcmp(nhanbiet,sv->mssv)==0){
				trangthai=1;
			printf("HO VA TEN :%s\n",sv->hoten);
			printf("MSSV :%s\n",sv->mssv);
			printf("NGANH HOC LA:%s\n",sv->nghanh);
			printf("SO MON DANG KI LA:%d\n",sv->somon);
			printf("DIEM TB CUA SV:%f\n",sv->dsmon->diem);
			break;
		}
	}
	if(trangthai==0)
	printf("KHONG TIM THAY SINH VIEN\n");
}
float diemtrungbinh(FILE*file1,int n){
	printf("NHAP SO SINH VIEN CUA LOP LA:\n"); scanf("%d",&n);
	SV*tb=(SV*)calloc(n,sizeof(SV)); 
	fread(tb,sizeof(SV),n,file1);
	 float s=0;
	 for(int i=0;i<n;i++){
	 	s+=tb[i].dsmon->diem;
	 }
	 free(tb);
	 return s/n;
}
void xoasinhvien(FILE*file1,int dem){
	SV*mangtam=(SV*)calloc(1,sizeof(SV));
	while(fread(mangtam,sizeof(SV),1,file1)==1){
		dem++;
	}
	rewind(file1);
	SV*chep=(SV*)calloc(dem,sizeof(SV));
	fread(chep,sizeof(SV),dem,file1);
	fclose(file1);
	free(mangtam);
	char*mssvcanxoa=(char*)calloc(10,sizeof(char));
	printf("NHAP MSSV CAN XOA :");
	gets(mssvcanxoa);
	int hang=0;
for(int i=0;i<dem;i++){
	if(strcmp(chep[i].mssv,mssvcanxoa)==0){
		hang=1;
		for(int j=i;j<dem-1;j++){
			chep[j]=chep[j+1];
		}
		dem--;
	}
}
if(hang==0) printf("KHONG CO MSSV PHU HOP TRONG DANH SACH!\n");
else if(hang==1) printf("DA XOA SV CO MSSV LA:%s\n",mssvcanxoa);
file1=fopen("QUAN LY SINH VIEN.bin","wb");
fwrite(chep,sizeof(SV),dem,file1);
free(chep);
fclose(file1);
}
void sapxep(FILE*file1,int k){
	SV*mangsapxep=(SV*)calloc(k,sizeof(SV));
	fread(mangsapxep,sizeof(SV),k,file1);
	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(mangsapxep[j].dsmon->diem<=mangsapxep[i].dsmon->diem){
			     SV c=mangsapxep[j];
			     mangsapxep[j]=mangsapxep[i];
			     mangsapxep[i]=c;
			}
		}
	}
	fclose(file1);
	file1=fopen("QUAN LY SINH VIEN.bin","wb");
	fwrite(mangsapxep,sizeof(SV),k,file1);
	fclose(file1);
	free(mangsapxep);
}