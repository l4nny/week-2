#include <iostream>

void fn_Jos(int* ip_Men, int& i_TotMen, int& i_Length, int i_StartNum, int i_Order);

int main (){
	int i_TotMen = -1;
	int i_Length = -1;
	std::cout<<"請輸入人數:";
	std::cin>> i_TotMen;
	std::cout<<"請輸入倍數:";
	std::cin>> i_Length;
	
	int ia_Men[i_TotMen] = {};
	fn_Jos(ia_Men, i_TotMen, i_Length, 1, -1);
	
	std::cout<< "Sorted:";
	for(int i_Ct= 0; i_Ct < i_TotMen; i_Ct++) {
		std::cout<< ia_Men[i_Ct]<< " ";
	}
	return 0;
}

void fn_Jos(int* ip_Men, int& i_TotMen,int& i_Length,int i_StartNum,int i_Order) {
	if(i_StartNum <= i_TotMen){
		for(int i_Ct = 0; i_Ct < i_Length;) {
			i_Order = (i_Order + 1) % i_TotMen;
			if(ip_Men[i_Order] == 0){
				i_Ct++;
			}
		}
		ip_Men[i_Order] = i_StartNum++;
		
		fn_Jos(ip_Men, i_TotMen, i_Length, i_StartNum, i_Order);
	}
}
