#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> counts;
    string number;
    bool flag = true;
    int numNumbers = 0;
    
    while(cin >> number){
        if(flag) {
            counts.resize(number.length());
            flag = false;
        }
        for(int i = 0; i < number.length(); i++){
            counts[i] += (number[i] == '1');
        }
        numNumbers++;
    }

    uint64_t gammaRate = 0, epsilonRate = 0;
    for(int i = 0; i < counts.size(); i++){
        if(2 * counts[i] >= numNumbers){
            gammaRate |= (1 << (counts.size()-i-1));
        } else {
            epsilonRate |= (1 << (counts.size()-i-1));
        }
    }
    cout << gammaRate * epsilonRate << "\n";
    return 0;
}