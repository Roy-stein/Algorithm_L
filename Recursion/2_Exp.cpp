#include<iostream>

using namespace std;

void fun(int n){
    int pos=0, i=0;
    int a[100]={0};
    while(n){
        int m = n % 2;
        if(m){
            a[pos++] = i;
        }
        i++; n /= 2;
    }
    for(int i = pos -1 ; i >= 0; --i){
        if(a[i] == 0)
            cout << "2(0)";
        else if(a[i] == 1)
            cout << "2";
        else if(a[i] == 2)
            cout << "2(2)";
        else{
            cout << "2(";
            fun(a[i]);
            cout << ")";
        }
        if(i != 0)
            cout << "+";
    }
}

string fun(int n){
    string ret = "";
    for(int i = 20; i >= 0; --i){
        if(n >> i & 1){
            if(ret.size())
                ret += "+";
            if(i == 0)
                ret += "2(0)";
            else if(i == 1)
                ret += "2";
            else{
                ret += "2(" + fun(i) + ")";
            }
        }
    }
    return ret;
}

int main(){
    int n;
    while(cin >> n){
        fun(n);
        cout << endl;
    }
}
