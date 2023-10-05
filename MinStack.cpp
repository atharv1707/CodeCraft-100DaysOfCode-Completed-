//the key thing we need to do is OPTIMISE THE GETMIN() !!!! not insert, retreive the minimum shit! to do so , we maintain two stacks, normal and one where the min ones go. and by making the min stack , and making sure that the least element of all is at the top, we execute the getMin() in constant time, because we kept a record of min element by comparing and made sure only the minimum one stays at top be retrieved. Clever. Clever. Very clever! There you go!

//keyword : focus on getmin() and somehow keep track of min



class MinStack {
private:
    stack<int> normalStack; //this is our main stack where we store our all elements
    stack<int> minStack; //here we store the min elements.
public:
    MinStack() {
        //constructor
        
    }
    
    void push(int val) {
        normalStack.push(val);

        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {

        if(normalStack.top() == minStack.top()){
            minStack.pop();
        }

        normalStack.pop();
        
    }
    
    int top() {

        return normalStack.top();
        
    }
    
    int getMin() {

        return minStack.top(); 
        //because min element is at the top afterall.
        
    }
};


