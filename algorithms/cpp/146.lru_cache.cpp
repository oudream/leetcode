#include "global.h"

#include <unordered_map>

using namespace std;

struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL){}
};

class LRUCache{
public:
    LRUCache(int capacity) :cp(capacity), cur(0), head(NULL), tail(NULL){ }

    int get(int key) {
        unordered_map<int, Node*>::const_iterator it = map.find(key);
        if(it != map.end()) {
            Node* node = it->second;
            moveNodeToHead(node);
            return node->value;
        }
        return -1;
    }

    void moveNodeToHead(Node* node) {
        if(node == head) {
            return;
        }

        if(node == tail) {
            tail = node->prev;
            node->prev->next = NULL;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = head;
        head->prev = node;
        node->prev = NULL;
        head = node;
    }

    void set(int key, int value) {
        unordered_map<int, Node*>::const_iterator it = map.find(key);
        if(it != map.end()) {
            Node* node = it->second;
            node->value = value;
            moveNodeToHead(node);
        } else {
            if(cur >= cp) {
                Node* tmp = tail;
                map.erase(tmp->key);
                if(tail->prev != NULL) {
                    tail = tail->prev;
                    tail->next = NULL;
                }
                delete tmp;
            } else {
                cur++;
            }

            Node* node = new Node(key, value);
            node->next = head;
            if(head != NULL) {
                head->prev = node;
            }
            head = node;
            if(cur == 1) {
                tail = node;
            }
            map[key] = node;
        }
    }

private:
    Node* head;
    Node* tail;
    int cp;
    int cur;
    unordered_map<int, Node*> map;

};

int test_lruCache1(int argc, const char *argv[])
{
    LRUCache lc(512);

    const int iCp = 1024;
    int a[iCp];
    srand(time(0));
    for (int i = 0; i < iCp; ++i)
    {
        int key = rand();
        lc.set(key,rand());
        a[i] = key;
    }

    for (int j = 0; j < iCp; ++j)
    {
        cout << a[j] << " - " << lc.get(a[j]) << endl;
    }
    return TRUE;
}
int fn_test_lruCache1 = fn_add_case("lruCache1", test_lruCache1);
