class TextEditor {
public:
    stack<char> left,right;
    TextEditor() {
        while(!left.empty()) left.pop();
        while(!right.empty()) right.pop();
    }
    
    void addText(string text) {
        for(auto it:text) {
            left.push(it);
        }
    }
    
    int deleteText(int k) {
        int count = 0;
        while(k-- && !left.empty()) {
            count++;
            left.pop();
        }
        return count;
    }
    
    string getPrev10Char() {
        int count = min(10,(int)left.size());
        string ans = "";
        while(count--) {
            ans += left.top();
            left.pop();
        }
        reverse(ans.begin(),ans.end());
        for(auto it:ans) left.push(it);
        return ans;
    }
    
    string cursorLeft(int k) {
        
        while(k-- && !left.empty()) {
            right.push(left.top());
            left.pop();
        }
        
        return getPrev10Char();
    }
    
    string cursorRight(int k) {
        while(k-- && !right.empty()) {
            left.push(right.top());
            right.pop();
        }
        
        return getPrev10Char();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */