#include <iostream>
#include <math.h>
using namespace std;
int f_number(char *input_a){
	int sum=0;
	for(int i=0; input_a[i]!=0; i++){
		if(input_a[i]=='I' && (input_a[i+1]=='V' || input_a[i+1]=='X'))	sum = sum - 1;
		else if(input_a[i]=='I')	sum = sum + 1;
		else if(input_a[i]=='V')	sum = sum + 5;
		else if(input_a[i]=='X' && (input_a[i+1]=='L' || input_a[i+1]=='C'))	sum = sum - 10;
		else if(input_a[i]=='X')	sum = sum + 10;
		else if(input_a[i]=='L')	sum = sum + 50;
		else if(input_a[i]=='C' && (input_a[i+1]=='D' || input_a[i+1]=='M'))	sum = sum - 100;
		else if(input_a[i]=='C')	sum = sum + 100;
		else if(input_a[i]=='D')	sum = sum + 500;
		else if(input_a[i]=='M')	sum = sum + 1000;
	return sum;
	}
}
void f_word(int R){
	for(int i=0; i<4; i++){
		//for(int j=0; j<3; j++){
			if(R/pow(10,3-i)!=0){
				if(i==0){
					cout<<"M";
					R = R - 1000;
				}
				else if(i==1 && R/pow(10,3-i) == 9){
					cout<<"CM";
					R = R - 900;
				}
				else if(i==1 && R/pow(10,3-i) >= 5){
					cout<<"D";
					R = R - 500;
				}
				else if(i==1 && R/pow(10,3-i) == 4){
					cout<<"CD";
					R = R - 400;
				}
				else if(i==1){
					cout<<"C";
					R = R - 100;
				}
				else if(i==2 && R/pow(10,3-i) == 9){
					cout<<"XC";
					R = R - 90;
				}
				else if(i==2 && R/pow(10,3-i) >= 5){
					cout<<"L";
					R = R - 50;
				}
				else if(i==2 && R/pow(10,3-i) == 4){
					cout<<"XL";
					R = R - 40;
				}
				else if(i==2){
					cout<<"X";
					R = R - 10;
				}
				else if(i==3 && R/pow(10,3-i) == 9){
					cout<<"IX";
					R = R - 9;
				}
				else if(i==3 && R/pow(10,3-i) >= 5){
					cout<<"V";
					R = R - 5;
				}
				else if(i==3 && R/pow(10,3-i) == 4){
					cout<<"IV";
					R = R - 4;
				}
				else if(i==3){
					cout<<"I";
					R = R - 1;
				}
			}
			else break;	
		//}
	}
}
int main(){
	int i, A, R;
	char input_a[15], input_b[15];
	while(1){
		cin >> input_a>> input_b;
		if(input_a[0]=='#')
			break;
		int RA, RB;
		RA = f_number(input_a);
		RB = f_number(input_b);
		if(RA == RB){
			cout << "ZERO" ;
			break;
		}
		if(RA < RB)
			R = RB - RA;
		if(RA > RB)
			R = RA - RB;
		f_word(R);
		break;
	}
} 
