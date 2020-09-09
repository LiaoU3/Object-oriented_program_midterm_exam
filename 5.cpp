#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    int i, cnt;
    double num1, num2;
    char n1[100];
    char n2[100];
    char op;
    cout<<"Please input an equation : ";
    while(getline(cin, line)){
        for (i=0;i<100;i++){
            n1[i] = {'\0'};
            n2[i] = {'\0'};
        }
        cnt = 0;
        for (i = 0;i<line.length();i++){            
            if (isdigit(line[i]) || line[i] =='.'){
                n1[cnt] = line[i];
                cnt ++;
            }
            if (line[i] == '+'||line[i] == '-'||line[i] == '*'||line[i] == '/'){
                op = line[i];
                break;
            }
        }
        cnt = 0;
        for(;i<line.length();i++){
            if (isdigit(line[i]) || line[i] =='.'){
                n2[cnt] = line[i];
                cnt++;
            }            
        }
        num1 = atof(n1);
        num2 = atof(n2);
        if (op == '+'){
            cout<<num1+num2<<endl;
        }else if (op == '-'){
            cout<<num1-num2<<endl;
        }else if (op == '*'){
            cout<<num1*num2<<endl;
        }else if (op == '/'){
            cout<<num1/num2<<endl;
        }else{
            cout<<"Wrong operator! "<<endl;
        }
        cout<<"Please input an equation : ";
    }       
    return 0;
}