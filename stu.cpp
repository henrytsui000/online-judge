#include<iostream>
#include<string>
using namespace std;
const int maxn = 1e5+5;
int arr[maxn];
int main(){
    string str;
    getline(cin, str);
    cout << str << endl;
    str += ' ';
    int tmp = 0, itr = 0, sum = 0, mx = 0, mi = 1e9;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' ')
            arr[itr] = tmp, itr++, sum += tmp, mx = max(mx, tmp), mi = min(mi, tmp), tmp = 0;
        else 
            tmp*=10, tmp += (str[i] - '0');
    }
    cout << "Sum: "<<sum<<endl;
    cout << "Average: " << sum / itr << endl;
    cout << "Minimum: " << mi << endl;
    cout << "Maximum: " << mx << endl;
    return 0; 
}
