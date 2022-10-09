#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class num {
	public:
	ll high, low;
	num (ll h, ll l){
		high = h;
		low = l;				
	}
	bool operator<(const num &n2){
    	return high > n2.high;
	}
};

void switcher(ll &neg, ll &pos, ll K){
	if(neg < K){
		pos = neg + pos;
		neg = K - neg;
		pos = pos - neg;
	} else {
		neg = neg - K;
		pos = pos + K;
	}
}

int main() {
	int test;
	ll K, N, X, a, divisor, highs, lows, recentLows, recentHighs, pastLows, pastHighs, maxHigh;
	vector<ll> money;
	vector<num> bank;
	scanf("%d", &test);
	while(test--){

		highs = 0;
		lows = 0;
		maxHigh = 0;
		money.clear();

		scanf("%lld", &N);
		for(ll i = 0; i < N; i++){
			scanf("%lld", &a);
			money.emplace_back(a);
		}
		scanf("%lld", &K);
		scanf("%lld", &X);
		
		if(X == 0){
			printf("%d\n", accumulate(money.begin(), money.end(), 0));
			continue;
		}
		
		a = (int)log2(X);
		divisor = (int)pow(2, a);
		
		for(auto i =money.begin(); i != money.end(); i++){
			if((*i/divisor)%2 == 0){
				lows++;
				bank.emplace_back(num(*i^X, *i));
			} else {
				highs++;
				bank.emplace_back(num(*i, *i^X));
			}
		}


		pastLows = lows;
		pastHighs = highs;
		recentLows = lows;
		recentHighs = highs;
		while(true){
			switcher(lows, highs, K);
			if(lows == recentLows){
				switcher(highs, lows, K);
				if(lows == recentLows || lows == pastLows)
					break;
			} else if(lows == pastLows){
				lows = recentLows;
				highs = recentHighs;
				switcher(highs, lows, K);
				if(lows == recentLows || lows == pastLows)
					break;
			}
			if(maxHigh < highs)
				maxHigh = highs;
			pastLows = recentLows;
			recentLows = lows;
			pastHighs = recentHighs;
			recentHighs = highs;
			//cout<<lows<<" "<<highs<<endl;
		}

		sort(bank.begin(), bank.end());

		// for(auto i = bank.begin(); i!=bank.end(); i++){
		// 	printf("%lld - %lld\n", i->high, i->low);
		// }
		cout<<maxHigh;	

	}
	return 0;
}