#include <iostream>

template <class CTy>
CTy fn_Partition(CTy* cp_Arr, int i_LowI, int i_HighI){
	CTy c_Pivot = cp_Arr[i_LowI]; // COMP: pivot
	int i_I = (i_LowI - 1);
	int j_I = (i_HighI + 1);

    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i_I++;
        } while (cp_Arr[i_I] > c_Pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j_I--;
        } while (cp_Arr[j_I] < c_Pivot);
 
        // If two pointers met.
        if (i_I >= j_I)
            return j_I;
 
//        swap(cp_Arr[i_I], cp_Arr[j_I]); 
	CTy o_Tmp         =   cp_Arr[i_I];
    cp_Arr[i_I]    =   cp_Arr[j_I];
    cp_Arr[j_I]      =   o_Tmp;
    }
}

template <class CTy>
void fn_QuickSortHoare(CTy* cp_Arr, int i_LowI, int i_HighI){
	
	if (i_LowI < i_HighI){
		int i_PI = fn_Partition<CTy>(cp_Arr, i_LowI, i_HighI);

		fn_QuickSortHoare(cp_Arr, i_LowI, i_PI);
		fn_QuickSortHoare(cp_Arr, i_PI + 1, i_HighI);
	}
}

int main(){
	int i_Arr[] = {10, 7, 8, 9, 1, 5};
	int i_Num = sizeof(i_Arr)/sizeof(int);

	fn_QuickSortHoare<int>(i_Arr, 0, i_Num-1);
	std::cout<< "Sorted Results\n";

	for (int i_Ct=0; i_Ct < i_Num; i_Ct++)
		std::cout<< i_Arr[i_Ct]<< " ";
	std::cout<< "\n";
	return 0;
}
