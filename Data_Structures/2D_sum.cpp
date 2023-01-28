ll mat[maxn][maxn]; // 1 - indexed

void build(){  
    for(int i=1;i<maxn;i++){
        for(int j=1;j<maxn;j++){
            if(i==1 && j==1)continue;
            else if(i==1)mat[i][j] += mat[i][j-1];
            else if(j==1)mat[i][j] += mat[i-1][j];
            else mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }
}

ll query(ll a,ll b, ll c, ll d){
    return mat[c][d] - (b > 1) * mat[c][b-1] - (a > 1) * (mat[a-1][d]) + (a > 1 && b > 1) * mat[a-1][b-1];
}

