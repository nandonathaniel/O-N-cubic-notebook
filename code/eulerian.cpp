void eulerian_path(int cur){
    stack<int> st;
    vector<int> ans;
    st.push(cur);
    //V is multiset
    while(!st.empty()){
        int cur = st.top();
        if(V[cur].size()){
            auto it = V[cur].begin();
            st.push(*it);
            V[cur].erase(it);
            //use this for bidirectional graph
            //if(V[*it].count(cur)){
            // V[*it].erase(V[*it].find(cur));
            //}
        }else{
            ans.pb(cur);
            st.pop();
        }
    }
}
