#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    cout<<"Please enter a sentence : ";
    char sentence[100];
    char newsentence[100];
    int i;
    cin.get(sentence, 100);
    sentence[0] = toupper(sentence[0]);

    for(i = 1 ;i < sizeof(sentence); i++){
        if(isupper(sentence[i])){
            sentence[i] = tolower(sentence[i]);
        }
    }
    int cnt = 0;
    int flag = 0;
    for(i = 0; i < sizeof(sentence); i++){
        if (sentence[i] != ' '){
            newsentence[cnt] = sentence[i];
            flag = 0;
            cnt += 1;
        }else{
            if (flag == 0){
                newsentence[cnt] = ' ';
                cnt += 1;
            }
            flag = 1;
        }

    }
    for (i = 0; newsentence[i]!='\0'; i++){
        cout<<newsentence[i];
    }
    cout<<endl;

    return 0;
}