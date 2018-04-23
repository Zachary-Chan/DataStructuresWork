#include <iostream>  
#include <vector>  
#include <stack>  
#include <string>  
#include <sstream>  
#include <iomanip>  
#include <math.h>  
using namespace std;  
  
bool isop(string s){  
    if(s=="+"||s=="-"||s=="*"|s=="/")  
        return true;  
    return false;  
}  
double stringToNum(string s){  
    stringstream tmp;  
    tmp<<s;  
    double x;  
    tmp>>x;  
    return x;  
}  
string numToString(double num){  
    stringstream tmp;  
    tmp<<num;  
    string s;  
    tmp>>s;  
    return s;  
}  
int main(){  
    vector<string> svec;  
    string s;  
    cin>>s;  
    while(cin){  
        svec.push_back(s);  
        cin>>s;  
    }  
    int n=svec.size();  
    stack<string> sstk;  
  
    double a=0,b=0;  
    for(int i=n-1;i>=0;i--){  
        if(!isop(svec[i])){  
            sstk.push(svec[i]);  
        }  
        else{  
            if(sstk.size()<2){  
                cout<<"ERROR";  
                return 0;  
            }else{  
                a=stringToNum(sstk.top());  
                sstk.pop();  
                b=stringToNum(sstk.top());  
                sstk.pop();  
            }  
            switch(svec[i][0]){  
            case '+':  
                a=a+b;  
                sstk.push(numToString(a));  
                break;  
            case '-':  
                a=a-b;  
                sstk.push(numToString(a));  
                break;  
            case '*':  
                a=a*b;  
                sstk.push(numToString(a));  
                break;  
            case '/':  
                if(fabs(b)<=1e-6){  
                    cout<<"ERROR";  
                    return 0;  
                }  
                a=a/b;  
                sstk.push(numToString(a));  
                break;  
            default:  
                cout<<"ERROR";  
                return 0;  
            }  
        }  
    }  
  
    if(sstk.size()==1){  
        cout<<fixed;  
        cout.precision(1);  
        cout<<stringToNum(sstk.top());  
    }else{  
        cout<<"ERROR";  
    }  
    return 0;  
}  
