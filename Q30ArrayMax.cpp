#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;Q
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }    
    }
    cout<<"Maximum element: "<<max<<"\n";
    int min=arr[0];
    for (int i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }    
    }
    cout<<"Minimum element: "<<min<<"\n";
    return 0;
}