//the idea is to use two seperate sets -> one to store all elements whatever comes, and based on the 'status' of first set,
//we implement the second set and that is how we get constant time complexity for it.

//size_t :  It is frequently used to represent sizes of arrays and memory blocks.. Any object can exist in it.  It is unsigned.



class RandomizedSet {
private:
    unordered_set<int> normalSet;
    unordered_set<int> optimSet;
public:
    RandomizedSet() {

        //constructor
        
    }
    
    bool insert(int val) {

        bool status = false;
        if(normalSet.find(val) == normalSet.end()){
            normalSet.insert(val);
            status =  true;
        }
        
        if(status == true){
            return true;
        }
        else{
            return false;
        }

        
    }
    
    bool remove(int val) {
        bool status  = false;
        if(normalSet.find(val) != normalSet.end()){
                normalSet.erase(val);
                status  = true;
        }

        if(status == true){
            return true;
        }
        else{
            return false;
        }
        
    }
    
    int getRandom() {
        //getting the random element

        random_device rd; //rd is instance of random class
        mt19937 gen(rd()); // random number generator
        uniform_int_distribution<size_t> distri(0,normalSet.size()-1); //this generates numbers within a specific range, which we want
        size_t random_index = distri(gen); //gen engine is used to generate random number, which is coupled with distri()

        auto it = normalSet.begin(); // it is initialised to beginning of the normalSet
        advance(it, random_index); //advance -> it moves forward the iterator forward by random_index positions. 

        return *it; //dereferencing the iterator and getting access to the element itself. Thus, it returns the actual element. 

        
    }
};

