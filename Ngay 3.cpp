# include<bits/stdc++.h>
using namespace std;
const int mk=12345;
const string tk="THANH HUY";
class taikhoan{
	private:
	 string chutk;
     int mstk;
     long double sodu;
     public:
     	double gettien(){
     		return sodu;
		 }
     	void capnhattaikhoan(){
     		cout<<"TEN TAI KHOAN BAN MUON DAT LA:"<<endl;
	        getline(cin,chutk);
	        cout<<"SO TIEN BAN DA GUI"<<endl;
	        cin>>sodu;
	        cout<<"SO TAI KHOAN BAN MUON DAT LA:"<<endl;
	        cin>>mstk;}
	    void intk(){
	    	cout<<"TEN TAI KHOAN LA: "<<chutk<<endl;
	    	cout<<"SO TIEN DANG GUI: "<<sodu<<endl;
	    	cout<<"SO TAI KHOAN LA: "<<mstk<<endl;
		}
		double naptien(double k){
			sodu+=k;
			return sodu;
		}
		double chuyentien(double k){
			sodu-=k;
			return sodu;
		}
};
int dangnhap();
int main(){
	taikhoan nganhang;
	int bien;
	int hang =0;
	while(bien==0){
		bien=dangnhap();
		if(bien==0){
			cout<<"TAI KHOAN KHONG HOP LAI"<<endl;
			fflush(stdin);
		}
	}
	cout<<"					CAP NHAT THEM TAI KHOAN --Nhan phim:1"<<endl;
	cout<<"					IN THONG TIN TAI KHOAN--Nhan phim--2"<<endl;
	cout<<"					NAP TIEN VAO TAI KHOAN--Nhan phim--3"<<endl;
	cout<<"					RUT TIEN TU TAI KHOAN--Nhan phim--3"<<endl;
    while(hang!=7){
    	int chedo=0;
    	cout<<"MOI BANH NHAP YEU CAU"<<endl;
    	cin>>chedo;
    	fflush(stdin);
    	switch(chedo){
    		case 1:
    			nganhang.capnhattaikhoan();
    		    break;
    		case 2:
    			nganhang.intk();
    			break;
			case 3:
			   double k;
			   cout<<"MHAP SO TIEN MUON NAP VAO TAI KHOAN LA:"<<endl;
			   cin>>k;
			   nganhang.naptien(k);
			   break;
			case 4:
			   double h;
			   cout<<"SO TIEN BAN MUON RUT RA"<<endl;
			   cin>>h;
			   if(h>nganhang.gettien())
			   	cout<<"TAI KHOAN KHONG DU TIEN"<<endl;
	    	   else
			   nganhang.chuyentien(h);
			   break;
		}
    cout<<"BAN CO MUON TIEP TUC KHONG "<<endl;
    cin>>hang;
	}
	
}
int dangnhap(){
	string tennhap;
	int matkhau;
	cout<<"TEN DANG NHAP LA:"<<endl;
	getline(cin,tennhap);
	cout<<"MAT KHAU LA:"<<endl;
	cin>>matkhau;
	if(matkhau==mk&&tennhap==tk) return 1;
	else return 0;
}

