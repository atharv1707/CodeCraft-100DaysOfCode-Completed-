

//Approach 0 : Time limit exceeded.
class LRUCache {

private:
    int cap;
    unordered_map<int, int> cache;
    vector<int> keys;

public:
    LRUCache(int capacity) {

        cap = capacity;
        
    }
    
    int get(int key) {

        //search if the key is in the hashmap or not.

        if (cache.find(key) != cache.end()){
            keys.erase(remove(keys.begin(), keys.end(), key));
            keys.push_back(key); //we are going such that the LSU are stored in the intial part of array and MRU is on right side of the array
            return cache.find(key)->second;
        }
        return -1;   
    }
    
    void put(int key, int value) {

        //check if it is in the map or not
        if (cache.find(key) != cache.end()){
            cache.find(key) -> second = value; //update the value of key if already present.
            keys.erase(remove(keys.begin(), keys.end(), key));
            keys.push_back(key);

        }
        else{
            //if key is not present
            if(cache.size() >= cap){
                //if full, we remove the LSU from the hashmap and we remove it from the vector
                int lruKey = keys[0];
                cache.erase(lruKey);
                keys.erase(keys.begin());
            }

            cache[key] = value;
            keys.push_back(key);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 
 
 
 //Approach 1 :  Linked_list and hashmap
 
 
 class LRUCache {
        list<pair<int,int>> cache; //each pair consists of key and value. Here we are storing the LRU ->  MRU. 
        unordered_map<int,list<pair<int,int>>::iterator> mymap; 
        //::iterator stores the address of the element, i.e <int, int> 
         //it has pair - > key and address in cacheb  
        
        void refreshPosition(int key,int value)
        {
            cache.erase(mymap[key]);
            cache.push_front(make_pair(key,value)); //this will be the most recently use.
            mymap[key] = cache.begin();     //Addr of new position stored in map, because we just changed the address of key.
        }
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mymap.find(key)!=mymap.end())
        {
            refreshPosition(key,(*mymap[key]).second);
            return (*mymap[key]).second;
            //mymap[key] -> gives the key in map
            //**mymap[key] -> dereferences it, and gives us pair
            //*mymap[key]).second- > gives us second value of the pair, which is value of key
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mymap.find(key)!=mymap.end())
            refreshPosition(key,value);
        else
        {
            //Add to cache
            cache.push_front(make_pair(key,value));
            mymap[key] = cache.begin();
            if(mymap.size()>capacity)
            {
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 