#include <bits/stdc++.h>
#include <zconf.h>

using namespace std;

class turing {
    int pos;
    int inp_string;
    int i;
};

unordered_set<string> final_states;

void print_tabs(int n){
    for(int i = 0; i < n; i++){
        cout<<"    ";
    }
}

//void proceed(string inp, int pos, int tape_ptr, string ini_state,multimap<string,string> &state_map, vector<char> &tape){
//
//}

void proceed(int tape_ptr, string state,multimap<string,string> &state_map, string tape,int tabs){
    string spaces = "                    ",tmp,tmp_tape,l_map;
    bool done = false, final = false;
    int r_tr_len,tmp_tape_ptr;

    print_tabs(tabs);
    cout<<"Proceeding...>>>>"<<endl;

    string r_transition,tmp_r_transition,nxt_state,tmp_state;
//    while(inp_pos != inp.length()){
    while(tape_ptr != tape.length() && !done){
        sleep(1);

        print_tabs(tabs);
        cout<<tape<<" : "<<state<<" "<<tabs<<endl;

        tmp = spaces;
        tmp[tape_ptr] = '^';

        print_tabs(tabs);
        cout<<tmp<<endl;

        l_map = state + tape[tape_ptr];

        if(state_map.find(l_map) != state_map.end()){
            if(state_map.count(l_map) == 1){ // for deterministic
                auto it = state_map.find(l_map);
                r_transition = it -> second;
                r_tr_len = r_transition.length();
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
            }else if(state_map.count(l_map) > 1){ //for non deterministic
                for(auto itt = state_map.find(l_map); itt != state_map.end(); itt++){
                    if(itt->first == l_map) {

                        print_tabs(tabs);
                        cout << itt->first << " -> " << itt->second << endl;

                        tmp_tape = tape;
                        tmp_tape_ptr = tape_ptr;
                        tmp_r_transition = itt->second;
                        r_tr_len = tmp_r_transition.length();
                        tmp_state = tmp_r_transition.substr(0, tmp_r_transition.length() - 2);

                        //changing value in tape according to state
                        tmp_tape[tmp_tape_ptr] = tmp_r_transition[r_tr_len - 2];

                        //moving to next transition
                        if (tmp_r_transition[r_tr_len - 1] == 'R') {
                            tmp_tape_ptr++;
                        } else {
                            tmp_tape_ptr--;
                        }
                        if (tmp_tape_ptr == tmp_tape.length() - 1) {
                            tmp_tape = tmp_tape + 'B';
                        } else if (tape_ptr == 0) {
                            tmp_tape = 'B' + tmp_tape;
                        }
                        proceed(tmp_tape_ptr, tmp_state, state_map, tmp_tape, tabs + 1);

                        //backtracking
                        print_tabs(tabs);
                        cout << "    <<<<Backtracking<<<<" << endl;
                    }
                }
                done = true;
            }
        }else{
            final = true;
            done = true;
        }
    }

//    print_tabs(tabs);
//    cout<<"ExiTing..."<<endl;
    if(final){
        print_tabs(tabs);
        cout<<tape<<endl;

        print_tabs(tabs);
        if(final_states.find(state) != final_states.end()){
            cout<<"Accepted"<<endl;
        }else{
            cout<<"Rejected"<<endl;
        }
    }
}

int main() {
    cout << "Turing Machine Simulation!!!" << endl;
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
    int tape_ptr = 1;
    int tabs = 0;
    string initial_state = "q0";
    proceed(tape_ptr,initial_state,state_map,tape,tabs);
    return 0;
}