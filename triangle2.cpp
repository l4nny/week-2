#include <iostream>

void fn_Fib(int* ip_Arr,int i_N, int i_NowI);

int main(){
	int i_Num;
	std::cin>>i_Num;
	int ia_Arr[(i_Num + 1)]= {0,2};
	fn_Fib(ia_Arr, i_Num,2);
	std::cout<< ia_Arr[i_Num];
	
	return 0;
}

void fn_Fib(int* ip_Arr, int i_N, int i_NowI){
	if(i_NowI <= i_N){
		ip_Arr[i_NowI] = ip_Arr[i_NowI-1] + 2*i_NowI;
		fn_Fib(ip_Arr, i_N, i_NowI+1);
	}
}
