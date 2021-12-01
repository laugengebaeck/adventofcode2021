#include<bits/stdc++.h>

using namespace std;

int main(){
    ifstream cin("01.in");
    vector<int> numbers;
    int x;

    while(cin >> x){
        numbers.push_back(x);
    }

    int first_counter = 0;
    for(int i = 1; i < numbers.size(); i++){
        if(numbers[i] > numbers[i-1]) first_counter++;
    }

    int second_counter = 0;
    for(int i = 0; i < numbers.size() - 2; i++){
        if(numbers[i+3] > numbers[i]) second_counter++;
    }

    cout << first_counter << " " << second_counter << "\n";
}