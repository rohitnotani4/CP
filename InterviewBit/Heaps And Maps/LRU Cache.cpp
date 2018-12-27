/*
https://www.interviewbit.com/problems/lru-cache/
*/

#include <list>
int _capacity = 0;
list<int> dq;
unordered_map<int, pair<int, list<int>::iterator >> cache; 
    
void moveToFront(unordered_map<int, pair<int, list<int>::iterator >> :: iterator it)
{
    int key = it->first;
    dq.erase(it->second.second);
    dq.push_front(key);
    it->second.second = dq.begin();
}

LRUCache::LRUCache(int capacity) 
{
    _capacity = capacity;
    dq.clear();
    cache.clear();
}

int LRUCache::get(int key) 
{
    auto it = cache.find(key);
    if(it == cache.end())   
        return -1;
    
    moveToFront(it);
    return it->second.first;
}

void LRUCache::set(int key, int value) 
{
    auto it = cache.find(key);
    if (it != cache.end())
    {
        moveToFront(it);
    }
    else
    {
        if(cache.size() == _capacity)
        {
            int keyToBeRemoved = dq.back();
            dq.pop_back();
            cache.erase(keyToBeRemoved);
        }
        dq.push_front(key);
    }
    cache[key] = make_pair(value, dq.begin());
}
