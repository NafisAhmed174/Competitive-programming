using ll = long long;

ll func(ll pos){
    // define according to problem
}

ll binary_search(ll low, ll high){
    ll mid;
    while(high - low >= 2){
        mid = (high + low) >> 1;
        //cout<<mid<<" "<<func(mid)<<endl;
        if(func(mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    if(func(high)) return high;
    if(func(low)) return low;
    return -1; 
}