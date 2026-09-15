# include<bits/stdc++.h>
using namespace std;
class SINHVIEN{
	private:
		string MSSV;
		string TEN;
		float diem ;
		public:
			SINHVIEN(){
				TEN="Chua co";
				MSSV="Chua co";
				diem=0;
			}
			 SINHVIEN(string a,string b,float  c){
				TEN=a;
				MSSV=b;
				diem=c;
			}
			void in(){
				cout<<"TEN :"<<TEN<<endl;
				cout<<"MSSV:"<<MSSV<<endl;
				cout<<"DIEM:"<<diem<<endl;
			}
			~SINHVIEN(){
				cout<<"DA XOA SINH VIEN "<<TEN<<endl;
			}
			void xeploai(){
				if(diem<=5) cout<<"HOC SINH TRUNG BINH"<<endl;
				else if(diem>5&&diem<=8) cout<<"HOC SINH KHA"<<endl;
				else if(diem>8&&diem<=10) cout<<"HOC SINH GIOI"<<endl;
			}
			
};
int main(){
	SINHVIEN sv;
	SINHVIEN sv1("huy dep trai","B2511536",10);
	sv.in();
	sv.xeploai();
	sv1.in();
	sv1.xeploai();
}
	
