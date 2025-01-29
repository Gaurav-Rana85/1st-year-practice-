#include <iostream>
using namespace std;

int main() {
    string name;
    cout<<"Enter character:-";
    getline(cin,name);
    int age;
    cout<<"Enter integer:-";
    cin>>age;
    float salary;
    cout<<"Enter decimal digit:-";
    cin>>salary;  
    cout<<"ch"<<"    int"<<"    float"<<"\n";
    cout<<name<<"\t"<<age<<"\t"<<salary;
    return 0;
}