class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> hm;
        for(auto e: s) {
            if(hm.find(e) == hm.end()) hm[e] = 1;
            else hm[e]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto i = hm.begin(); i != hm.end(); i++) {
            pq.push(make_pair(i->second, i->first));
        }

        string res = "";
        while(!pq.empty()) {
            pair<int,char> top = pq.top();
            pq.pop();
            for(auto i=0; i<top.first; i++) res += top.second;
        }

        return res;
    }
};