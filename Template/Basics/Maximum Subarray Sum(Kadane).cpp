ll kadane(vl &vc,ll n){
    ll sum,currSum,i=0;
    sum=currSum=vc[0];
    Fo(i,1,n){
        currSum=max(currSum+vc[i],vc[i]);
        sum=max(sum,currSum);
        // currSum= (currSum<0? 0:currSum);
    }
    return sum;
}