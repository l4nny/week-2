#include <iostream>  
#include <string.h> //strcpy()    
using namespace std;  
  
int main() {  
    // [C_ST21-��] ��r�Φr���X�{����  
    string text;  //��J���r��  
    int len = 0; //���h�֥y�l  
    getline(cin, text);//�ϥΪ̿�J(���Ū���]�t�ť�)  
    int arr[26];//�x�s�j�p�g�^�媺�ƶq�A[0]�j�g,[1]�p�g  
    int count = text.size();//string ����      
     char result[count]; //�s�J���G      
     strcpy(result, text.c_str());//string to char   
     for(int i = 0;i < 26;i++)//�}�C�k�s  
     {  
        arr[i] = 0;    
     }  
     for(int i = 0;i < count;i++)  
     {   
		if(122 >= result[i] && result[i] >= 97)//�p�g  
        {  
            arr[result[i]-97]++;  
        }  
          
     }      
     for(int i = 0;i < 26;i++)  
     {  
     if(arr[i] != 0){
	 
        cout << char(i+97) << " : " << arr[i]<< endl;
    }
    }  
    return 0;  
}  
