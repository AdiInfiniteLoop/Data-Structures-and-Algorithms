void sort(stack<int> &s){
    //Base Case
    if(s.empty()){
        return;
    }
    int top = s.top();
    s.pop();
    sort(s);
    insertattarget(s,top);
    
}