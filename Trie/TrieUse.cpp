#include <iostream>
#include "Trie.h" 
int main() {
    Trie t;
    t.insertWord("are");
    t.insertWord("and");
    t.insertWord("dot");
    cout <<  t.searchWord("an") << endl;
    cout <<  t.searchWord("and") << endl;
    t.removeWord("and");
    cout << t.searchWord("and") << endl;
    return 0;
}