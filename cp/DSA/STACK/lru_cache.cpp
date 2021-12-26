// LRU CACHE IMPLEMENTATION
// VERY IMP. QUESTION

#define ll long long int

unordered_map<ll, ll> mp ;
unordered_map<ll, list<ll> :: iterator> idx ;
list<ll> dq ;
int capacity=0 ;

LRUCache::LRUCache(int cap) {
    capacity = cap ;
    dq.clear() ;
    idx.clear() ;
    mp.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key) == mp.end())
        return -1 ;
    dq.erase(idx[key]) ;
    dq.push_front(key) ;
    idx[key] = dq.begin() ;
    return mp[key] ;
}

void LRUCache::set(int key, int value) {
    if(mp.find(key) != mp.end()){
        mp.erase(key) ;
        dq.erase(idx[key]) ;
    }
        
    if(mp.size() >= capacity) // here we have to delete the LRU element
        if(dq.back() != key){
            mp.erase(dq.back()) ;
            dq.pop_back() ;
        }
    
    
    dq.push_front(key) ;
    idx[key] = dq.begin() ;
    mp[key] = value;
    
    return ;
}
