const int N=2e5+5;
int n,q,s[N],T[N][22],Log[N];
int merge(int a,int b) {
    return __gcd(a,b);
}
void bulid() {
    for(int i=0;i<n;i++) {
        T[i][0]=s[i];
    }
    for(int pw=1;(1<<pw)<=n;pw++) {
        for(int i=0;i+(1<<pw)<=n;i++) {
            T[i][pw]=merge(T[i][pw-1],T[i+(1<<(pw-1))][pw-1]);
        }
    }
}
int query(int l,int r) {
    int sz=r-l+1;
    int pw=Log[sz];
    return merge(T[l][pw],T[r-(1<<pw)+1][pw]);
}
void preCount() {
    Log[1]=0;
    for(int i=2;i<N;i++) {
        Log[i]=Log[i>>1]+1;
    }
}
