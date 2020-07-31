class Solution {
public:
    vector<pair<int,int>> pos;
    void find_zeros(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(!matrix[i][j])
                    pos.push_back(pair<int,int>(i,j));
            }
        }
    }
    
    bool e(int i,int j,vector<vector<bool>>& visited){
        if(!visited[i][j]&&i>=0&&i<visited.size()&&j>=0&&j<visited[i].size())
            return true;
        return false;
    }
    
    void bfs(vector<vector<int>>& matrix,int si,int sj){
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,1,0};
        queue<pair<pair<int,int>,int>> q;
        pair<pair<int,int>,int> cur;
        vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
        visited[si][sj]=true;
        matrix[si][sj]=0;
        q.push(pair<pair<int,int>,int>(pair<int,int>(si,sj),0));
        while(!q.empty()){
            cur=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                if(e(cur.first.first+dx[i],cur.first.second+dy[i],visited)){
                    visited[cur.first.first+dx[i]][cur.first.second+dy[i]]=true;
                    q.push(pair<pair<int,int>,int>(pair<int,int>(cur.first.first+dx[i],cur.first.second+dy[i]),cur.second+1));
                    matrix[cur.first.first+dx[i]][cur.first.second+dy[i]]=min(cur.second+1,matrix[cur.first.first+dx[i]][cur.first.second+dy[i]]);
                }
            }
        }
        
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        find_zeros(matrix);
        for(int i=0;i<matrix.size();i++){
            matrix[i].assign(matrix[i].size(),10000);
        }
        for(auto x:pos){
            bfs(matrix,x.first,x.second);
        }
        return matrix;
    }
};