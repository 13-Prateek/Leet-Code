class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
        }
        else if(left.size()>right.size()){
            if(num>left.top()){
                right.push(num);
            }
            else{
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        else if(left.size()==right.size()){
            if(num>left.top()){
                right.push(num);
            }
            else{
                left.push(num);
            }
        }
        else if(left.size()<right.size()){
            if(num<right.top()){
                left.push(num);
            }
            else{
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }
        
    }
    
    double findMedian() {
        double ans;
        if(left.size()>right.size()){
            ans=double(left.top());
        }
        else if(right.size()>left.size()){
            ans=double(right.top());
        }
        else{
            ans=(double(left.top())+double(right.top()))/2;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */