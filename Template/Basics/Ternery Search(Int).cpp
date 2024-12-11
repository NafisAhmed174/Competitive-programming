long double func(ll pos){

}

ll ts(ll low,ll high){
    ll mid;
    while(high-low>=2){
        mid=(high+low)>>1;
        //cout<<mid<<" "<<func(mid)<<endl;
        if(func(mid)<func(mid+1)){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    if(func(high)<func(low)) return high;
    else return low;
}