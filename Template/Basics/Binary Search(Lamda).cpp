auto func=[&](ll m){

};

auto bs=[&](ll lo,ll hi){

    ll mid=0;
    while(hi-lo>=2){
        mid=(lo+hi)>>1;
        if(func(mid)){
            
        }else{

        }
    }

    if(func(hi)) return hi;
    return lo;
};