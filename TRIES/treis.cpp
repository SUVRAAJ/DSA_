#include<unordered_map>
#include<string>
#include <iostream>
using namespace std;

class trie_node{
    public:
        char c;
        unordered_map <char,trie_node*> m;
        bool is_terminal;

        trie_node(char data)
        {
            c=data;
            is_terminal=false;
        }
};

class trie{
    public:
    trie_node* root;
    trie()
    {
        root= new trie_node('\0');
    }

    void insert(string word)
    {
        trie_node *temp= root;
        for(char a:word)
        {      
            if(temp->m.count(a)==0)
            {
                trie_node* n= new trie_node(a);
                temp->m[a]=n;
            }
            temp=temp->m[a];
        }

        temp->is_terminal=true;
    }

    bool search(string word)
    {
        trie_node* temp= root;
        for(char ch:word)
        {
            if(temp->m.count(ch)==0)
            {
                return false;
            }
            temp=temp->m[ch];
        }

        return temp->is_terminal;
    }
};

int main()
{
    trie t;
    
    // List of words to insert
    string words[] = {"apple", "app", "ape", "bat", "batman", "banana"};

    cout << "Inserting words..." << endl;
    for(const string& word : words) {
        t.insert(word);
        cout << "Inserted: " << word << endl;
    }

    cout << "\n--- Running Searches ---" << endl;
    
    // Use boolalpha to print "true" or "false" instead of 1 or 0
    cout << boolalpha; 

    // --- Test Case 1: Search for all inserted words (Should all be true) ---
    cout << "\nSearching for existing words:" << endl;
    cout << "Search 'apple': " << t.search("apple") << endl;     // Expected: true
    cout << "Search 'app': " << t.search("app") << endl;         // Expected: true
    cout << "Search 'ape': " << t.search("ape") << endl;         // Expected: true
    cout << "Search 'bat': " << t.search("bat") << endl;         // Expected: true
    cout << "Search 'batman': " << t.search("batman") << endl;   // Expected: true
    cout << "Search 'banana': " << t.search("banana") << endl;   // Expected: true

    // --- Test Case 2: Search for prefixes that are NOT terminal words (Should all be false) ---
    cout << "\nSearching for prefixes (not marked as words):" << endl;
    cout << "Search 'a': " << t.search("a") << endl;           // Expected: false
    cout << "Search 'ap': " << t.search("ap") << endl;          // Expected: false
    cout << "Search 'appl': " << t.search("appl") << endl;      // Expected: false
    cout << "Search 'b': " << t.search("b") << endl;            // Expected: false
    cout << "Search 'ba': " << t.search("ba") << endl;          // Expected: false

    // --- Test Case 3: Search for words that don't exist in the trie (Should all be false) ---
    cout << "\nSearching for non-existent words:" << endl;
    cout << "Search 'apply': " << t.search("apply") << endl;    // Expected: false
    cout << "Search 'zebra': " << t.search("zebra") << endl;    // Expected: false
    cout << "Search 'ball': " << t.search("ball") << endl;      // Expected: false

    // --- Test Case 4: Search for an empty string (Should be false unless explicitly inserted) ---
    cout << "\nSearching for empty string:" << endl;
    cout << "Search '': " << t.search("") << endl;              // Expected: false

    // Now insert an empty string
    cout << "Inserting empty string..." << endl;
    t.insert("");
    cout << "Search '': " << t.search("") << endl;              // Expected: true

    return 0;
}