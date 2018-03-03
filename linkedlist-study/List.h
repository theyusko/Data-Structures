#include <string>
using namespace std;


    struct ListNode{
        string first;
        string last;
        string role;
        ListNode* next;
    };

class List{
public:
    List();
    List(const List& aList);
    ~List();

    bool isEmpty() const;
     int getLength() const;
    bool insert(string first, string last, string role);
    bool remove(string first, string last);
    void display();
    ListNode* find(string first, string last);

private:
    void lowercase(string str);
    int size;
    ListNode* head;
};

