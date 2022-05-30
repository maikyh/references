struct TrieNode
{
    map< char, TrieNode* > dictionary;
    lli howMuch = 0;
    bool isWord=false;
};

struct Trie
{
    TrieNode *root = new TrieNode;
    
    void insert(const string &s)
    {
        TrieNode *curr = root;
        int index = 0;
        for(auto c: s)
        {
            if(curr->dictionary.find(c) == curr->dictionary.end())
                curr->dictionary[c] = new TrieNode();
            curr = curr->dictionary[c];
            curr->howMuch++;
        }
        curr->isWord = true;
    }

    lli search(const string &word)
    {
        TrieNode *curr = root;
        lli ans = -1;
        for(auto c: word)
        {
            if(curr->dictionary.find(c) == curr->dictionary.end())
            {
                return 0;
            }
            curr = curr->dictionary[c];
            ans = curr->howMuch;
        }
        return ans;
    }

    void Rec(TrieNode *root, const string &s)
    {
        for(auto c: root->dictionary)
        {
            string aux = s;
            aux.push_back(c.first);
            Rec(c.second, aux);
        }
        if(root->isWord)
            cout << s << endl;
    }

    void printWords()
    {
        string aux;
        Rec(root, aux);
    }
};
