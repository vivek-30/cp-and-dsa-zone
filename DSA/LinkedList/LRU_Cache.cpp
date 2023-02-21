#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;

// ============= Not Working ==============
class Node
{

public:
  pair<int, int> data;
  Node *next;

  Node(int key, int value)
  {
    data.first = key;
    data.second = value;
    next = NULL;
  }
};

class LRUCache
{

private:
  int maxCapacity, currentCapacity;
  Node *recent, *old;

public:
  LRUCache(int capacity = 1)
  {
    maxCapacity = capacity;
    recent = old = NULL;
    currentCapacity = 0;
  }

  int get(int key)
  {

    if (currentCapacity == 0 or maxCapacity == 0)
      return -1;

    Node *temp = old;

    if (temp->data.first == key)
    {
      old = old->next;
      recent->next = temp;
      recent = temp;
      temp->next = NULL;
      return temp->data.second;
    }

    while (temp->next)
    {
      if (temp->next->data.first == key)
      {
        Node *fresh = temp->next;
        if (fresh != recent)
        {
          temp->next = fresh->next;
          recent->next = fresh;
          recent = fresh;
          fresh->next = NULL;
        }
        return fresh->data.second;
      }
      temp = temp->next;
    }

    return -1;
  }

  void put(int key, int value)
  {

    if (maxCapacity <= 0)
      return;

    Node *temp = old;
    while (temp)
    {
      if (temp->data.first == key)
      {
        temp->data.second = value;
        return;
      }
      temp = temp->next;
    }

    Node *newNode = new Node(key, value);

    if (!recent)
    {
      recent = old = newNode;
      currentCapacity++;
      return;
    }

    if (currentCapacity == maxCapacity)
    {
      Node *temp = old;
      old = old->next;
      delete temp;
    }
    else
      currentCapacity++;

    recent->next = newNode;
    recent = newNode;

    return;
  }
};

int main()
{

  int choice = 1, value, capacity, key;

  cout << "Enter capacity of cache\n";
  cin >> capacity;

  LRUCache *cache = new LRUCache(capacity);
  cout << "Enter your choice\n1.get\n2.put\n3.exit\n";
  cin >> choice;

  while (choice > 0)
  {
    switch (choice)
    {
    case 1:
      cout << "Enter key\n";
      cin >> key;
      cout << cache->get(key) << endl;
      break;

    case 2:
      cout << "Enter key and value\n";
      cin >> key >> value;
      cache->put(key, value);
      break;

    case 3:
      return 0;

    default:
      cout << "Enter valid choice\n";
      break;
    }

    cout << "Make your choice\n";
    cin >> choice;
  }

  return 0;
}

// ============= Working ==============

class LRUCache
{
public:
  int currentCapacity, maxCapacity;
  list<pair<int, int> > ll;
  unordered_map<int, list<pair<int, int> >::iterator> hash;

  void adjustNodes(int key, int value, list<pair<int, int> >::iterator it)
  {
    ll.erase(it);
    ll.push_front(make_pair(key, value));
    hash.erase(key);
    hash.insert(make_pair(key, ll.begin()));
  }

  LRUCache(int capacity = 1)
  {
    maxCapacity = capacity;
    currentCapacity = 0;
  }

  int get(int key)
  {

    if (not maxCapacity or not currentCapacity)
      return -1;

    auto res = hash.find(key);

    if (res != hash.end())
    {
      int value = (*(res->second)).second;
      adjustNodes(key, value, res->second);
      return value;
    }

    return -1;
  }

  void put(int key, int value)
  {

    if (maxCapacity <= 0)
      return;

    auto res = hash.find(key);

    if (res != hash.end())
    {
      adjustNodes(key, value, res->second);
      return;
    }

    if (ll.empty())
    {
      ll.push_front(make_pair(key, value));
      currentCapacity++;
    }
    else if (currentCapacity == maxCapacity)
    {
      list<pair<int, int> >::iterator it = ll.end();
      it--;
      hash.erase(it->first);
      ll.pop_back();
      ll.push_front(make_pair(key, value));
    }
    else
    {
      currentCapacity++;
      ll.push_front(make_pair(key, value));
    }

    hash.insert(make_pair(key, ll.begin()));
    return;
  }
};
