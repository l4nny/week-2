#include <iostream>  
#include <string.h> //strcpy()    
using namespace std;  
  
int main() {  
    // [C_ST21-易] 文字及字母出現次數  
    string text;  //輸入的字串  
    int len = 0; //有多少句子  
    getline(cin, text);//使用者輸入(整行讀取包含空白)  
    int arr[26];//儲存大小寫英文的數量，[0]大寫,[1]小寫  
    int count = text.size();//string 長度      
     char result[count]; //存入結果      
     strcpy(result, text.c_str());//string to char   
     for(int i = 0;i < 26;i++)//陣列歸零  
     {  
        arr[i] = 0;    
     }  
     for(int i = 0;i < count;i++)  
     {   
		if(122 >= result[i] && result[i] >= 97)//小寫  
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
