class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {{1}};

        if(numRows >= 2) {
            vector<int> second = {1, 1};
            result.push_back(second);
        }


        for(int i=0; i<numRows-2; i++) {
            // cout<<endl;
            // for(auto r: result) {
            //     for(auto e: r) {
            //         cout<<e<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<"----------"<<endl;

            vector<int> row;
            row.push_back(1);
            int n = result.size()-1;
            // cout<<"n"<<n;
            for(int i=0; i<n; i++) {
                row.push_back(result[n][i] + result[n][i+1]);
            }
            row.push_back(1);
            result.push_back(row);
        }

        return result;
    }
};