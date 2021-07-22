#include <iostream>
#include <map>

int main(){
	std::map<char,int> o_NumSet;
	int M;
	int Sum;
	std::cin>>M>>Sum;
	int Num[M-1];
	for(int i_C=0;i_C < M; i_C++){
		std::cin>>Num[i_C];
	}
	for(int i_C=0;i_C < M; i_C++){
		for(int i_F=i_C+1;i_F < M;i_F++){
			if(Num[i_C]+Num[i_F]==Sum){
				std::cout<<"("<< Num[i_C] <<","<<Num[i_F]<<")"<<std::endl;
			}
		}
	}
	
	return 0;
} 

