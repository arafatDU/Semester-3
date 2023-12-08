#include<bits/stdc++.h>
using namespace std;

int num_states, num_symbols, start_state, final_state, state, symbol, num_transition;
vector<int> states, symbols;
vector<vector<vector<int>>> transition_table;
set<set<int>> dfa_states;
vector<vector<set<int>>> dfa_transition_table;
vector<set<int>> finals;


bool is_visited(set<int> s);
int get_index(set<int> s);
bool is_final_state(set<int> s);
void construct_dfa_states();
void create_dfa_transition_table();



void get_final_states(set<set<int>> dfa_states)
{
    set<int> dfa_final_state;
    for(auto dfa_state: dfa_states)
    {
        for(auto s : dfa_state)
        {
            if(s == final_state)
            {
                dfa_final_state = dfa_state;
            }
        }
        finals.push_back(dfa_final_state);
    }
    
}

/*

 ->  1  {1,2}  {1}
     2    @    {3}
    *3    @     @
*/

/*
    states 0 1 
    1     12 1
    12    12 13
    13    12 1
*/

void printSetElement(set<int> state)
{
    cout<<"{";
    for(auto s : state)
    {
        cout<<s;
    }
    cout<<"}";
}


int main(){
    freopen("input.txt", "r", stdin);
    cin >> num_states;
    
    for(int i = 0; i < num_states; ++i){
        cin >> state;
        states.push_back(state);
    }

    for(int i = 0; i < num_states; ++i) cout << states[i] << " ";
    cout << endl;

    cin >> num_symbols;

    for(int i = 0; i < num_symbols; ++i){
        cin >> symbol;
        symbols.push_back(symbol);
    }

    for(int i = 0; i < num_symbols; ++i) cout << symbols[i] << " ";
    cout << endl;

    cin >> start_state >> final_state;
    cout << "Starting State: " << start_state << endl << "Final State: " << final_state << endl;

    transition_table.resize(num_states, vector<vector<int>>(num_symbols, vector<int> (num_states)));

    for(int i = 0; i < num_states; ++i){
        for(int j = 0; j < num_symbols; ++j){
            cin >> num_transition;
            for(int k = 0; k < num_transition; ++k){
                cin >> transition_table[i][j][k];
            }
        }
    }
    
    // displaying NFA transition table
    cout <<endl<< "--------------------" << endl;
    cout << "NFA Transition Table" << endl;
    cout << "--------------------" << endl<<endl;
    for(int i = 0; i < num_states; ++i){
        cout<< states[i] << "   ";
        for(int j = 0; j < num_symbols; ++j){
            cout << symbols[j] << "{";
            for(auto s : transition_table[i][j]){
                if(s == 0) {
                    cout<<"  ";
                    //continue;
                }else
                    cout<<s<<" ";
                //cout<<"   ";
            }  
            cout <<"}    "; 
        }
        cout << endl;
    }
    cout<<endl<<endl;

    
    construct_dfa_states();

    // Displaying DFA states
    cout<<"DFA States: "<<endl;
    for(auto set : dfa_states) {
        printSetElement(set);
        cout << endl;
    }
    cout<<endl;
    
    dfa_transition_table.resize(dfa_states.size(), vector<set<int>>(num_symbols + 1));

    create_dfa_transition_table();
    
    /* 0 + 'A'
      states   0    1 
        1   ds(idx) 1
        12    12   13
        13    12    1
    */

    get_final_states(dfa_states);

    cout << "------------------------" << endl;
    cout << "DFA Transition Table" << endl;
    cout << "------------------------" << endl<<endl;
    for(auto transi_states: dfa_transition_table)
    {
        for(auto transi_state: transi_states)
        {
            printSetElement(transi_state);
            cout<<"  ";
        }
        cout<<endl;
    }

    cout<<endl<<"Starting state: ";
    set<int> dfa_start_state = *dfa_states.begin();
    printSetElement(dfa_start_state);
    
    cout<<endl<<"Final states: ";
    for(auto state : finals)
    {
        if(state.empty()) continue;
        printSetElement(state);
    }

    return 0;
}


void create_dfa_transition_table(){
    for(auto ds : dfa_states){
        dfa_transition_table[get_index(ds)][0] = ds; 
        for(auto sym : symbols){
            cout<<"By "<<sym<<": ";
            set<int> new_state;
            for(auto s: ds){
                for(auto e : transition_table[s-1][sym]){
                    if(e != 0) {
                        new_state.insert(e);
                        cout<<e;
                    }               
                }
            }
            cout<<"   ";
            dfa_transition_table[get_index(ds)][sym+1] = new_state;
        }
        cout<<endl;
    }
}

void construct_dfa_states(){
    set<int> st;
    st.insert(start_state);
    dfa_states.insert(st); 

    for(int i = 0; i < dfa_states.size();++i){
        auto it = next(dfa_states.begin(), i);
        set<int> ds = *it; 
        for(auto sym : symbols){
            set<int> new_state;
            for(auto s : ds){ 
                for(auto e : transition_table[s-1][sym]){
                    if(e != 0) 
                        new_state.insert(e);
                }
                dfa_states.insert(new_state);
            }
        }
    }
}



int get_index(set<int> s){
    int i = 0;
    for(auto sets : dfa_states){
        if(sets == s) return i;
        i++;
    }
    return -1;
}

bool is_final_state(set<int> s){
    for(auto e : s){
        if(e == final_state) return true;
    }
    return false;
}



/*
    0 {1}
    1 {1,2}
    2 {1,3}
*/