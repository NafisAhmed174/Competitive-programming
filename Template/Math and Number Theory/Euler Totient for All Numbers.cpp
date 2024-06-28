const int N = 100000 + 5;
int phi[N + 1];

void computePhi(){
    for(int i=2; i<=N; i++)
        phi[i] = i;
    for(int i=2; i<=N; i++)
        if(phi[i]==i)
            for(int j=i; j<=N; j+=i)
                phi[j]-=phi[j]/i;
}