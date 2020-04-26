/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

// #define LOCAL

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;

class LRUCache {
	int cap;
	unordered_map<int, list<pair<int, int>>::iterator> h;
	list<pair<int, int>> l;
public:
	LRUCache(int capacity) {
		this->cap = capacity;
	}

	int get(int key) {
		auto it = h.find(key);
		int res = -1;
		if (it != h.end()) {
			res = it->second->second;
			l.erase(it->second);
			l.push_front({key, res});
			h[key] = l.begin();
		}
		return res;
	}

	void put(int key, int value) {
		int n = l.size();
		auto it = h.find(key);

		if (it != h.end() ) {
			l.erase(it->second);
		} else if ( n == cap ) {
			h.erase(l.back().first);
			l.pop_back();
		}
		l.push_front({key, value});
		h[key] = l.begin();
	}
};


signed main() {
	cin.tie(nullptr);
	std::ios::sync_with_stdio(false);

	LRUCache cache( 2 /* capacity */ );

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << '\n';       // returns 1
	cache.put(3, 3);    // evicts key 2
	cout << cache.get(2) << '\n';       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	cout << cache.get(1) << '\n';       // returns -1 (not found)
	cout << cache.get(3) << '\n';       // returns 3
	cout << cache.get(4) << '\n';       // returns 4

	return 0;
}