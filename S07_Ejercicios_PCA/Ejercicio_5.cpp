#include <iostream>
#include <string.h>

using namespace std;


int main() {

    string number; 
    int sum = 0;

    cin>>number;

    for(int i=0; i < number.length(); i++) {
        if(isdigit(number[i])) {
            sum += number[i] - '0';
        }
    }

    cout<<sum;

    return 0;
}


