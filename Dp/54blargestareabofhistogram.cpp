#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// one pass solution 
//

//Tc:- O(N) SC:- O(N)

// int these we will traverse the array and parallely we are updating the stack

//  here first move element 1 index on the stack 
// then compare the next array element and compare with the stack top element 
// if the array element is found to be smaller the then for the stack top the array element will be 

// right smaller for it and the element below it in stack will be left smaller for it 

// else if greater then push it on to the stack till will found the greater stack top element

int main(){
      vector<int>height={2,1,5,6,2,3};
      stack<int>st;
      int n= height.size();
      int maxa =0; 
    for(int i= 0; i<=n ;i++){
     while(!st.empty() && (i==n || height[st.top()]>=height[i])){
        int heig = height[st.top()];
        st.pop();
        int weidth;
        if(st.empty())weidth=i;
        else weidth = i - st.top() -1;
        maxa = max(maxa, weidth *heig);
     }
     st.push(i);
    }

    cout<<maxa<<endl;
    return 0;
}