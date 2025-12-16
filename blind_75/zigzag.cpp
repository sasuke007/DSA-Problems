class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1) {
                return s;
            }
            int n = s.size();
            int sections = ceil(n / (2 * numRows - 2.0));
            int totalCols = sections * (numRows - 1);
            cout<<totalCols<<endl;
            vector<vector<char>> zigzag(numRows,vector<char>(totalCols,' '));
            int curr= 0;
            int currCol = 0;
            while(curr<n){
                int currRow = 0;
                //iterate down
                while(currRow<numRows and curr<n){
                    cout<<"firstLoop"<<" "<<currRow<<" "<<currCol<<" "<<curr<<endl;
                    zigzag[currRow][currCol]=s[curr];
                    ++currRow;
                    ++curr;
                }
                ++currCol;
    
                //iterate in zigzag manner
                currRow = numRows-2;
                while(currRow>0 and curr<n){
                    cout<<"secondLoop"<<currRow<<" "<<currCol<<" "<<curr<<endl;
                    zigzag[currRow][currCol] = s[curr];
                    --currRow;
                    ++currCol;
                    ++curr;
                }
            }
            string answer;
            for(int i=0;i<numRows;++i){
                for(int j=0;j<totalCols;++j){
                    //cout<<zigzag[i][j]<<" ";
                    if(zigzag[i][j]!=' '){
                        answer+=zigzag[i][j];
                    }
                }
                //cout<<endl;
            }
            return answer;
        }
};

