#include<bits/stdc++.h>

#define endl "\n"
using namespace std;

int get_primary_diagonal_score(vector<vector<int> > &board,int i,int j){
    int score = 0;
    int x=i;
    int y=j;
    int n=board.size();
    int m=board[0].size();
    while(x<n and y>=0){
        score+=board[x][y];
        ++x;
        --y;
    }
    x=i;
    y=j;
    while(x>=0 and y<m){
        score+=board[x][y];
        --x;
        ++y;
    }
    return score-board[i][j];
}


int get_secondary_diagonal_score(vector<vector<int> > &board,int i,int j){
    int n=board.size();
    int m=board[0].size();
    int x=i;
    int y=j;
    int score=0;
    while(x>=0 and y>=0){
        score+=board[x][y];
        --x;
        --y;
    }
    x=i;
    y=j;
    while(x<n and y<m){
        score+=board[x][y];
        ++x;
        ++y;
    }
    return score-2*board[i][j];
}
int main() {
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > board(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>board[i][j];
            }
        }
        int max_score=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int primary_diagonal_score=get_primary_diagonal_score(board,i,j);
                int secondary_diagonal_score=get_secondary_diagonal_score(board,i,j);
                max_score=max(max_score,primary_diagonal_score+secondary_diagonal_score);
            }
        }
        cout<<max_score<<endl;
    }
}




