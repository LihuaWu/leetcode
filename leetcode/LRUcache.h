#include <list>
#include <unordered_map>

using namespace std;
class LRUCache {
public:	
	LRUCache(int capacity);
	int get(int key); 
	void set(int key, int value); 
private:	
	struct CacheNode {
		int key; 
		int value;
		CacheNode(int k, int v):key(k), value(v) {}
	};

	list<CacheNode> cacheList;
	unordered_map<int, list<CacheNode>::iterator> cacheMap; 
	int capacity;
};
