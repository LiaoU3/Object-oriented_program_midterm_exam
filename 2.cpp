#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    cout<<"Please enter a string : ";
    char line[100]={'\0'};
    int alpha_cnt[26]={0};
    char alpha[26];
    int i, j;
    for (i=0;i<26;i++){
        alpha[i] = (char)(i+97);
    }  
    cin.getline(line, 100);
    int cnt=1;
    for(i = 0;i < sizeof(line); i++){
        if (isalpha(line[i])){
            line[i] = tolower(line[i]);
            alpha_cnt[((int)line[i])-97] += 1;
        }else if (line[i] == ' '){
            cnt++;
        }
    }
    int tmp_num;
    char tmp_alpha;
    for(i = 0;i < 26; i++){
        for(j = 0;j < 26-i-1;j++)
            if (alpha_cnt[j] < alpha_cnt[j+1]){
                tmp_num = alpha_cnt[j];
                tmp_alpha = alpha[j];
                alpha_cnt[j] = alpha_cnt[j+1];
                alpha[j] = alpha[j+1];
                alpha_cnt[j+1] = tmp_num; 
                alpha[j+1] = tmp_alpha;                   
            }
    }
    for(i=0;i < 26 ;i++){
        if (alpha_cnt[i] > 0){
            cout<<alpha[i]<<' '<<alpha_cnt[i]<<endl;
        }
    }
    cout<<cnt<<" words"<<endl;
    return 0;
}