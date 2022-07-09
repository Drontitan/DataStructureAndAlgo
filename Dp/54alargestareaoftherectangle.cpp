#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// here the TC was also almost equal to the O(N)

// two pass solution 
int findlargestarea(int n ,vector<int>vec){
//  here we have used the formula like (right[i]-left[i]+1)*height[i]
    vector<int>left(n),right(n);
    stack<int>st;
    for(int i= 0;i <n;i++){
        // here we have find the smaller index than vec[i] the smallest index is pushed in to the vector   

        //  stack is for temporary holding the element measn if vec[i]< other element it will push 
        // but if some element will be smaller than it will pop up to that index and store the  index in
        // to that array 

        while(!st.empty() && vec[st.top()]>=vec[i])st.pop();
        if(st.empty())left[i]=0;
        else left[i]=st.top()+1;;
        st.push(i);
    }
    while(!st.empty())st.pop();
     for(int i= n-1;i>=0;i--){
        while(!st.empty() && vec[st.top()]>=vec[i])st.pop();
        if(st.empty())right[i]=n-1;
        else right[i]=st.top()-1;
        st.push(i);
    }
     while(!st.empty())st.pop();
     int maxa=0;
     for(int i=0 ;i <n; i++){
        maxa =max(maxa ,vec[i]*(right[i]-left[i]+1));
     }

    return maxa;
    
}

int main(){
    vector<int>height={2,1,5,6,2,3};
    int n=height.size();
    cout<<findlargestarea(n,height)<<endl;
    return 0;
}