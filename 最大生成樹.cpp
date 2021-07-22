#include <algorithm>
#include <iostream>
#include <limits>

struct AdList{
    public: int** cl2p_Ptr;
    public: char* cp_Name;
    public: int i_Size;

    private: int* ip_Parent;

    public: AdList(char* cp_Name, int i_Size){
        cl2p_Ptr= new int*[i_Size];
        for(int i_Ct=0; i_Ct< i_Size; i_Ct++){
            cl2p_Ptr[i_Ct] = new int[i_Size];
            std::fill(cl2p_Ptr[i_Ct], cl2p_Ptr[i_Ct]+ i_Size,
                      std::numeric_limits<int>::min());
        }
        this->cp_Name = cp_Name;
        this->i_Size = i_Size;

        ip_Parent = new int[i_Size];
    }

    public: bool fn_InsVet(char c_NameA, char c_NameB,
                           int i_Weight){
        int i_RInd = -1;
        int i_CInd = -1;
        for(int i_Ct= 0; i_Ct < i_Size; i_Ct++){
            if(c_NameA == cp_Name[i_Ct]){
                i_RInd = i_Ct;
                break;
            }
        }
        for(int i_Ct= 0; i_Ct < i_Size; i_Ct++){
            if(c_NameB == cp_Name[i_Ct]){
                i_CInd = i_Ct;
                break;
            }
        }
        if(i_RInd == -1 || i_CInd == -1){
            return false;
        }
        cl2p_Ptr[i_RInd][i_CInd] = i_Weight;
        cl2p_Ptr[i_CInd][i_RInd] = i_Weight;
    }

    public: ~AdList(){
        for(int i_Ct =0; i_Ct< i_Size; i_Ct++){
            delete [] cl2p_Ptr[i_Ct];
        }
        delete [] cl2p_Ptr;
        delete [] ip_Parent;
    }

    public: void fn_GetMSTByKruskal(int** i2p_Cost){
        int i_MinCost = 0;

        for (int i_Ct = 0; i_Ct < i_Size; i_Ct++){
            ip_Parent[i_Ct] = i_Ct;
        }

        for (int i_EdgeCount = 0; i_EdgeCount < i_Size - 1;
                i_EdgeCount++) {
            int i_MinC = std::numeric_limits<int>::min();
            int i_IInd = -1;
            int i_JInd = -1;
            for (int i_TmpIInd = 0; i_TmpIInd < i_Size; i_TmpIInd++) {
                for (int i_TmpJInd = 0; i_TmpJInd < i_Size; i_TmpJInd++) {
                    if (fn_FindInd(i_TmpIInd) != fn_FindInd(i_TmpJInd) &&
                        i2p_Cost[i_TmpIInd][i_TmpJInd] > i_MinC) {

                            i_MinC = i2p_Cost[i_TmpIInd][i_TmpJInd];
                            i_IInd = i_TmpIInd;
                            i_JInd = i_TmpJInd;
                    }
                }
            }

            fn_Union(i_IInd, i_JInd);
            for(int i_Ct = 0; i_Ct < i_Size; i_Ct++){
                std::cout <<ip_Parent[i_Ct] << "\t";
            }
            std::cout<< "\n\n";
            std::cout<<"Edge "<< i_EdgeCount << ":("<<
                    cp_Name[i_IInd]<< ", "<< cp_Name[i_JInd] << ") cost:"<<
                    i_MinC<<"\n";
            i_MinCost += i_MinC;
        }
        std::cout<< "\nMaximum cost= "<< i_MinCost<< "\n";
    }


    private: int fn_FindInd(int i_Ind){
        for(;ip_Parent[i_Ind] != i_Ind;){
            i_Ind = ip_Parent[i_Ind];
        }
        return i_Ind;
    }

    private: void fn_Union(int i_TmpIInd,
                         int i_TmpJInd){
        int i_IInd = fn_FindInd(i_TmpIInd);
        int i_JInd = fn_FindInd(i_TmpJInd);
        ip_Parent[i_IInd] = i_JInd;
    }
};

int main(){
    char c_Arr[] = {'A', 'B', 'C', 'D', 'E'};
    int i_Size  = sizeof(c_Arr)/sizeof(char);
    AdList o_List = AdList(c_Arr, i_Size);
    o_List.fn_InsVet('A', 'A', 2);
    o_List.fn_InsVet('A', 'B', 3);
    o_List.fn_InsVet('A', 'C', 7);
    o_List.fn_InsVet('A', 'D', 3);

    o_List.fn_InsVet('B', 'C', 11);
    o_List.fn_InsVet('B', 'E', 8);

    o_List.fn_InsVet('C', 'D', 8);
    o_List.fn_InsVet('C', 'E', 6);

    for(int i_Ct= 0; i_Ct < i_Size; i_Ct++){
        for(int i_Ct2= 0; i_Ct2 < i_Size; i_Ct2++){
            std::cout<< o_List.cl2p_Ptr[i_Ct][i_Ct2] << " ";
        }
        std::cout<< "\n";
    }

    std::cout<< "\n";

    o_List.fn_GetMSTByKruskal(o_List.cl2p_Ptr);

    return 0;
}
