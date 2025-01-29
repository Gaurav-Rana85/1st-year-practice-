#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number elements:-";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements:-";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int b;
    cout<<"Enter the element to be searched:-";
    cin>>b;
    int a=0;
    for(int i=0;i<n;i++){
        if(arr[i]==b){
            a=1;
            break;
        }
    }
    if(a==1){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}