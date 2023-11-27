class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> store;
        vector<int> result;

        for(int i = 0 ; i < ast.size();i++){
            //pushing the right moving asteroids in the stack , and we wait for the left moving ones to decide the collisions
            if(store.empty() || ast[i] > 0){
                store.push(ast[i]);
            }
            else{
                while(true){
                    //what we will have here is a left moving or a negative asteroid
                    int top = store.top();
                    if(top < 0){
                        store.push(ast[i]);
                        break;
                    }
                    //checking if the colliding asteroids are equal
                    else if(top == abs(ast[i])){
                        store.pop();
                        //both are destroyed
                        break;
                    }
                    else if(top > abs(ast[i])){
                        break; //the right moving asteroid just crushed the left moving one
                    }
                    else{
                        //if we reach here, that means that it is a bigger asteroid
                        store.pop(); //it crushes the existing top
                        if(store.empty()){
                            store.push(ast[i]);
                            break;
                        }
                    }
                }
            }
        }

        while(!store.empty()){
            result.emplace_back(store.top());
            store.pop();
        }

        reverse(result.begin(), result.end()); //that is how stack is





        return result;
        
        
    }
};