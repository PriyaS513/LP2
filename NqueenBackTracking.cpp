/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/

#include<iostream>
#include<queue>
using namespace std;

bool isSafe(int row,int col,int &n,vector<string> &board){
        int i = row;
        int j = col;
        //left row check
        while(j>=0){
            if(board[i][j] == 'Q') return false;
            j--;
        }

        //upper left
        i = row;
        j = col;
        while(j>=0 && i>=0){
            if(board[i][j] == 'Q') return false;
            j--;
            i--;
        }

        //down left
        i = row;
        j = col;
        while(j>=0 && i<n){
            if(board[i][j] == 'Q') return false;
            j--;
            i++;
        }
        return true;
    }

void solve(int col,int &n,vector<string> &board,vector<vector<string> > &ans){
        //base case
        if(col >= n){
            ans.push_back(board);
            return;
        }
        //1 case solve
        
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,board)){
                board[row][col] = 'Q';
                //call
                solve(col+1,n,board,ans);
                board[row][col] = '.';
            }
        }
    }

vector<string> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board(n); 
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,n,board,ans);
			for(int j=0;j<ans[0].size();j++){
				cout << ans[0][j] <<  endl;
			}cout << endl;
        return board;
}
int main(){
	int n;
	cout <<"Enter the number of matrix : " << endl;
	cin >> n;
	 vector<string> ans(n);
	 ans = solveNQueens(n);
	return 0;
}


/*

Enter the number of matrix : 
5
Q....
...Q.
.Q...
....Q
..Q..


Enter the number of matrix : 
6
...Q..
Q.....
....Q.
.Q....
.....Q
..Q...
*/