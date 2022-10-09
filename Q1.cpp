#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct trieNode{
    ll nums[2];
    trieNode *arr[2];
};

trieNode *newNode(){
	// cout<<"JGVJVJHV";
    trieNode *temp = new trieNode;
    temp->nums[0] = temp->nums[1] = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert(trieNode *root, ll x, ll len){
    trieNode *temp = root;
    ll i = 1<<(len), b;
    
    while(i != 0){
    	i = i >> 1;
    	if((x & i) == 0)
    		b = 0;
    	else
    		b = 1;
    	temp->nums[b]++;
        if(temp->arr[b] == NULL){
            temp->arr[b] = newNode();
        }
        temp = temp->arr[b];
    }
}

ll find(trieNode *root, ll x, ll k, ll len){
    trieNode *temp = root;
    ll i = 1<<len, ans = 0, b;
    // cout<<i<<" ";
    while(i != 1){
    	// cout<<ans<<" ";
    	ans = ans << 1;
    	i = i >> 1;
    	if((x & i) == 0)
    		b = 0;
    	else
    		b = 1;
    	if(temp->arr[b] != NULL){
    		if(temp->nums[b] >= k)
    			temp = temp->arr[b];
    		else{
    			k -= temp->nums[b];
    			temp = temp->arr[1 - b];
    			ans += 1;
    		}
    	} else{
    		temp = temp->arr[1 - b];
    		ans += 1;
    	}
    }
    return ans;
}

ll findLen(ll x){
	ll len = 0;
    while(x != 0){
    	len++;
    	x = x >> 1;
    }
    return len;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> nums;
    ll n, q, x, k, a, maxN = 0;
    cin>>n;
    while(n--){
    	cin>>a;
    	nums.emplace_back(a);
    	if(a > maxN)
    		maxN = a;
    }
    ll len = findLen(maxN);
    // cout<<len<<" ";
    trieNode *root = newNode();
    for(auto &i: nums){
    	insert(root, i, len);
    }
    
    cin>>q;
    while(q--){
    	cin>>x>>k;
    	ll extended = x >> len;
    	extended = extended << len;
    	cout<<(extended + find(root, x, k, len))<<"\n";
    }
    return 0;
}