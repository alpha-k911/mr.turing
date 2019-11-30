#include <bits/stdc++.h>
#include <zconf.h>

using namespace std;

class turing {
    int pos;
    int inp_string;
    int i;
};

unordered_set<string> final_states;

//void proceed(string inp, int pos, int tape_ptr, string ini_state,multimap<string,string> &state_map, vector<char> &tape){
//
//}

void proceed(string inp, int inp_pos, int tape_ptr, string state,multimap<string,string> &state_map, string tape){
    string safe = "                    ",tmp;
    cout<<"Proceeding..."<<endl;
    string r_transition,nxt_state;
//    while(inp_pos != inp.length()){
    while(tape_ptr != tape.length() && (final_states.find(state) == final_states.end())){
        sleep(1);
        cout<<tape<<endl;
//        cout<<tape<<" : "<<state<<endl;
        tmp = safe;
        tmp[tape_ptr] = '^';
        cout<<tmp<<endl;

        string l_map = state + tape[tape_ptr];

        if(state_map.find(l_map) != state_map.end()){
            if(state_map.count(l_map) == 1){ // for deterministic
                auto it = state_map.find(l_map);
                r_transition = it -> second;
                int r_tr_len = r_transition.length();
                state = r_transition.substr(0,r_transition.length() - 2);

                //changing value in tape according to state
                tape[tape_ptr] = r_transition[r_tr_len - 2];

                //moving to next transition
                if(r_transition[r_tr_len-1] == 'R'){
                    tape_ptr++;
                }else{
                    tape_ptr--;
                }
                if(tape_ptr == tape.length() - 1){
                    tape = tape + 'B';
                }else if(tape_ptr == 0){
                    tape = 'B' + tape;
                }
            }else{ //for non deterministic

            }
        }
    }
    cout<<"ExiTing..."<<endl;
}

int main() {
    cout << "Hello, World!" << endl;
    string a,b,state,inp,fin,out,dir;
    int i,j,k,l,p,q;

    //todo
//    vector<char> tape(1,'B'); // B for blanks as sign of left side
    string tape; // B for blanks as sign of left side


    int start = 1,end; // for starts and ends of valid

    //states are in the form of qi
    multimap<string,string> state_map;
    state = "";
    while(state != "END") {
        cin >> state;
        if(state != "IN" && state != "FINAL"){
            cin >> inp >> fin >> out >> dir;
            state_map.insert({state+inp,fin+out+dir});
        }else if(state == "IN"){
//            for(i = 0; i < inp.length(); i++){
//                tape.push_back(inp[i]);
//            }
            cin >> inp;
            tape = inp;
            tape = 'B' + tape + 'B';
            //for knowing the other end, we will extend the end if states reach here
//            tape.push_back('B');
        }else if(state == "FINAL"){
            while(state != "END"){
                cin>>state;
                if(state != "END") final_states.insert(state);
            }
        }
    }
    cout<<"done with input"<<endl;

    proceed(inp,0,1,"q0",state_map,tape);


    return 0;
}