for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==0 && j==0)continue;
        else if(i==0)mat[i][j] += mat[i][j-1];
        else if(j==0)mat[i][j] += mat[i-1][j];
        else mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
    }
}