#include <iostream>

template <typename Num>
	class NumDev{
		private: Num Devkeep;			
		public:NumDev(Num o_List[]){
		for(int i=0;i<7;i++){
			if(o_List[i]<o_List[i+1]){
				Devkeep = o_List[i];
				o_List[i] = o_List[i+1];
				o_List[i+1] = Devkeep;
			}
			else{
				continue;
			}
		}
					
			}
		public:Num fn_GetRes1(){
			return;
		}
 
	};
template <typename Num>
	void printAll(Num &arr) {
   		for(auto elem : arr) {
       		std::cout << elem << "\n";
		}
	}

	
int main(){
	int Sort_List[7]={2,1,3,5,7,8,10};
	int keep=0;
	for(int k=0;k<7;k++){
		NumDev<int> o_Dev(Sort_List);

	}
	printAll(Sort_List);
	return 0;
}


