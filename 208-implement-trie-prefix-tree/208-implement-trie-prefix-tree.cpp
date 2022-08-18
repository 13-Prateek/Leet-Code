struct Node{
    Node* links[26];
    bool flag;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch, Node *node){
        links[ch-'a']=node;
    }
    Node* getch(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->getch(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->getch(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->getch(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */