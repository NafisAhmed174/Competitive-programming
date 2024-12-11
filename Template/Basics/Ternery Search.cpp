double func(double mid){
    
}

double ts(double l, double r){
    double eps=1e-9;             //set the error limit here
    while (r-l>eps){
        double mid1=l+(r-l)/3;
        double mid2=r-(r-l)/3;
        double f1=func(mid1);      //evaluates the function at mid1
        double f2=func(mid2);      //evaluates the function at mid2
        if (f1<f2) l = mid1;       //change f1>f2 if needed minimum
        else r=mid2;
    }
    return func(l);              //return the maximum of func(x) in [l, r]
}