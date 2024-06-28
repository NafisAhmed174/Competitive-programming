const int N = 2e5 + 10;
vector<int> divisors[N];

void divisor_store(){
    for(int i = 2; i < N; i++){
        for(int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }  
    }
}