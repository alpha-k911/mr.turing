#include <bits/stdc++.h>
using namespace std;

class turing {
    int pos;
    int inp_string;
    int i;
};

void proceed(string inp, int pos, int tape_ptr, string ini_state,multimap<string,string> &state_map, vector<char> &tape){

}
int main() {
    cout << "Hello, World!" << endl;
    string a,b,state,inp,fin,out,dir;
    int i,j,k,l,p,q;

    //todo
    vector<char> tape(1,'B'); // B for blanks as sign of left side

    int start = 1,end; // for starts and ends of valid

    //states are in the form of qi
    multimap<string,string> state_map;
    a = "";
    b = "";
    while(a != "^^") {
        cin >> state >> inp;
        if(state != "^^"){
            cin >> fin >> out >> dir;
            state_map.insert({state+inp,fin+out+dir});
        }else{
            for(i = 0; i < inp.length(); i++){
                tape.push_back(inp[i]);
            }
            //for knowing the other end, we will extend the end if states reach here
            tape.push_back('B');
        }
    }
    cout<<"done with input";

    proceed(inp,0,1,"q0",state_map,tape);


    return 0;
}