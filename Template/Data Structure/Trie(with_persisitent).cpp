class Trie {

public:
    //N is number of possible characters in a string
    const static int N = 26;
    
    //baseChar defines the base character for possible characters
    //like '0' for '0','1','2'... as possible characters in string 
    const static char baseChar = 'a';
    
    struct TrieNode
    {
        int next[N];
        //if isEnd is set to true , a string ended here
        bool isEnd;
        //freq is how many times this prefix occurs
        int freq;
    
        TrieNode()
        {
            for(int i=0;i<N;i++)
                next[i] = -1;
            isEnd = false;
            freq = 0;
        }
    };
    
    //the implementation is via vector and each position in this vector
    //is similar as new pointer in pointer type implementation
    vector <TrieNode> tree;
    
    //Base Constructor
    Trie ()
    {
        tree.push_back(TrieNode());
    }
    
    //inserting a string in trie
    void insert(const string &s)
    {
        int p = 0;
        tree[p].freq++;
        for(int i=0;i<s.size();i++)
        {
            // tree[]
            if(tree[p].next[s[i]-baseChar] == -1)
            {
                tree.push_back(TrieNode());
                tree[p].next[s[i]-baseChar] = tree.size()-1;
            }

            p = tree[p].next[s[i]-baseChar];
            tree[p].freq++;
        }
        tree[p].isEnd = true;
    }
    
    //check if a string exists as prefix
    bool checkPrefix(const string &s)
    {
        int p = 0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;
    
            p = tree[p].next[s[i]-baseChar];
        }
        return true;
    }
    
    //check is string exists
    bool checkString(const string &s)
    {
        int p = 0;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }
    
        return tree[p].isEnd;
    }
    
    //persistent insert
    //returns location of new head
    int persistentInsert(int head , const string &s)
    {
        int old = head;
    
        tree.push_back(TrieNode());
        int now = tree.size()-1;
        int newHead = now;
    
        int i,j;
    
        for(i=0;i<s.size();i++)
        {
            if(old == -1)
            {
                tree.push_back(TrieNode());
                tree[now].next[s[i]-baseChar] = tree.size() - 1;
                tree[now].freq++;
                now = tree[now].next[s[i]-baseChar];
                continue;
            }
            for(j=0;j<N;j++)
                tree[now].next[j] = tree[old].next[j];
            tree[now].freq = tree[old].freq;
            tree[now].isEnd = tree[old].isEnd;
    
            tree[now].freq++;
                
            tree.push_back(TrieNode());
            tree[now].next[s[i]-baseChar] = tree.size()-1;
    
            old = tree[old].next[s[i]-baseChar];
            now = tree[now].next[s[i]-baseChar];
        }
    
        tree[now].freq++;
        tree[now].isEnd = true;

        return newHead;
    }
    
    //persistent check prefix
    bool persistentCheckPrefix(int head, const string &s)
    {
        int p = head;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;
    
            p = tree[p].next[s[i]-baseChar];
        }
        return true;
    }
    
    //persistent check string
    bool persistentCheckString(int head, const string &s)
    {
        int p = head;
        for(int i=0;i<s.size();i++)
        {
            if(tree[p].next[s[i]-baseChar] == -1)
                return false;

            p = tree[p].next[s[i]-baseChar];
        }
        return tree[p].isEnd;
    }
};