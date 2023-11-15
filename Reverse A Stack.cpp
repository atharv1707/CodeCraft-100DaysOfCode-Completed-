class Solution{
public:
    void insert_at_bottom(stack<int> &St, int x){
        
        if(St.empty()){
            St.push(x);
        }
        else{
            
            int a = St.top();
            St.pop();
            insert_at_bottom(St, x);
            St.push(a);
            
        }
    }
    void Reverse(stack<int> &St){
        //we first empty the stack using recursion also storing the top element in each respective state.
        
        if(St.size() >0){
            int x = St.top();
            St.pop();
            Reverse(St);
            insert_at_bottom(St, x);
            
        }
        return; 
        
        
    }
};