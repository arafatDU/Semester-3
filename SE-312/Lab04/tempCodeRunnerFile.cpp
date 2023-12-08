
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
                    cout<<s;