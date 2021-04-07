#include <iostream>
#include <cstdlib>

template <class c1_C1>
    class Unit{
        public: c1_C1 o_Field;
        public: Unit* op_Next;
        public: Unit* op_Pre;
        public: Unit(c1_C1 o_Field){
                    this->o_Field = o_Field;
                    op_Next = nullptr;
                    op_Pre = nullptr;
                }
    };
template <class c1_C1>
    class Que{
        public: Unit<c1_C1>* op_Front;
        public: Unit<c1_C1>* op_Rear;
        public: Unit<c1_C1>* op_temp;
        public: int i_Size;

        public: Que(){
                    op_Front = nullptr;
                    op_Rear  = nullptr;
                    i_Size   = 0;
                }
                
        public: void fn_PushE(Unit<c1_C1>* op_Ele){
                    if(op_Front == op_Rear && op_Front == nullptr){// COM: nothing
                        op_Front= op_Rear = op_Ele;
                    }
                    else{// COM: existing objects
                        op_Rear->op_Next    = op_Ele;
                        op_Ele->op_Pre      = op_Rear;
                        op_Rear = op_Ele;
                    }
                    i_Size++;
                    std::cerr<< "Push the item" << op_Ele->o_Field<< "\n";
                }
        public: void fn_PopE(){
                    if(op_Front == op_Rear && op_Front == nullptr){
                        std::cerr<< "No items for popping\n";
                        return;
                    }
                    else{
                        std::cerr<< "Pop the item: " << op_Rear->o_Field << "\n";
                        if(op_Front == op_Rear){// COM: Pop the last one item
                            delete op_Rear;
                            op_Front    = nullptr;
                            op_Rear     = nullptr;
                        }
                        else{
                            Unit<c1_C1>* op_PreTmp  = op_Rear->op_Pre;
                            op_PreTmp->op_Next      = nullptr;
                            delete op_Rear;
                            op_Rear                 = op_PreTmp;
                        }
                        i_Size--;
                    }
                }
        public: void fn_InsertE(Unit<c1_C1>* op_Exi,Unit<c1_C1>* op_Ele){
					op_temp = op_Front ;
					int success=0;
        			for(int j=0;j<i_Size;j++){
        				if(op_temp->o_Field==op_Exi->o_Field){
        					success=1;
							break;
						}
						else{
							op_temp=op_temp->op_Next;
						}
					}
					if(success==0){
						std::cerr<<"Insert Failed"<<"\n";
					}
					else{
						op_Ele->op_Pre     =op_temp->op_Pre;
						op_temp->op_Pre->op_Next    =op_Ele;
						op_Ele->op_Next    =op_temp;
						op_temp->op_Pre    =op_Ele;
						i_Size++;
					}	
				} 
        public: c1_C1 fn_ShowFrE(){
                    return (op_Front!=nullptr)?op_Front->o_Field: NULL;
                }
        public: c1_C1 fn_ShowReE(){
                    return (op_Rear!=nullptr)?op_Rear->o_Field: NULL;
                }
    };


int main(){
    Que<int> o_Que;
    o_Que.fn_PushE(new Unit<int>(3));
    o_Que.fn_PushE(new Unit<int>(5));
    o_Que.fn_PushE(new Unit<int>(7));
    o_Que.fn_InsertE(new Unit<int>(7),new Unit<int>(6));
    std::cout<< "The Front element is "<< o_Que.fn_ShowFrE() <<
                "; the last one is "<< o_Que.fn_ShowReE() <<"\n";
    o_Que.fn_PopE();
    std::cout<< "The Front element is "<< o_Que.fn_ShowFrE() <<
                "; the last one is "<< o_Que.fn_ShowReE() <<"\n";
    o_Que.fn_PopE();
    std::cout<< "The Front element is "<< o_Que.fn_ShowFrE() <<
                "; the last one is "<< o_Que.fn_ShowReE() <<"\n";
    o_Que.fn_PopE();
    o_Que.fn_PopE();

    return 0;
}
