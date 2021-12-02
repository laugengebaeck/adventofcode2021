#include<bits/stdc++.h>

using namespace std;

int aim = 0;

pair<int, int> forward_one(pair<int, int> pos, int move){
    pos.first += move;
    return pos;
}

pair<int, int> down_one(pair<int, int> pos, int move){
    pos.second += move;
    return pos;
}

pair<int, int> up_one(pair<int, int> pos, int move){
    pos.second -= move;
    return pos;
}

pair<int, int> forward_two(pair<int, int> pos, int move){
    pos.first += move;
    pos.second += aim * move;
    return pos;
}

pair<int, int> down_two(pair<int, int> pos, int move){
    aim += move;
    return pos;
}

pair<int, int> up_two(pair<int, int> pos, int move){
    aim -= move;
    return pos;
}

// because C++ doesn't allow for strings in switch-case, we'll use this slightly overengineered solution
map<string, pair<int,int>(*)(pair<int,int>, int)> move_funcs_one {{"forward", forward_one}, {"down", down_one}, {"up", up_one}};
map<string, pair<int,int>(*)(pair<int,int>, int)> move_funcs_two {{"forward", forward_two}, {"down", down_two}, {"up", up_two}};

int main(){
    string direction;
    int move;
    pair<int, int> position_one = {0,0}, position_two = {0,0};
    while(cin >> direction >> move){
        position_one = move_funcs_one[direction](position_one, move);
        position_two = move_funcs_two[direction](position_two, move);
    }
    cout << position_one.first * position_one.second << "\n";
    cout << position_two.first * position_two.second << "\n";
    return 0;
}