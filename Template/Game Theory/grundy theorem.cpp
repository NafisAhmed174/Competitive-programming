
/* Game Description-
"A game is played between two players and there are N piles
of stones such that each pile has certain number of stones.
On his/her turn, a player selects a pile and can take any
non-zero number of stones upto 3 (i.e- 1,2,3)
The player who cannot move is considered to lose the game
(i.e., one who take the last stone is the winner).
Can you find which player wins the game if both players play
optimally (they don't make any mistake)? "

A Dynamic Programming approach to calculate Grundy Number
and Mex and find the Winner using Sprague - Grundy Theorem. */


/* piles[] -> Array having the initial count of stones/coins
in each piles before the game has started.
n-> Number of piles

Grundy[] -> Array having the Grundy Number corresponding to
the initial position of each piles in the game

The piles[] and Grundy[] are having 0-based indexing*/

ll dp[N];

// A Function to calculate Mex of all the values in that set
ll calculateMex(unordered_set<ll> Set){
    ll Mex = 0;
    while (Set.find(Mex) != Set.end()) Mex++;
    return Mex;
}

// A function to Compute Grundy Number of 'n'
ll calculateGrundy(ll n){
    if(n<=3) return dp[n]=n;
    ll &ret=dp[n];
    if(ret!=-1) return ret;
    unordered_set<ll> Set; // A Hash Table

    for (ll i=1; i<=3; i++) Set.insert (calculateGrundy (n-i));
    // Store the result
    return ret = calculateMex (Set);
}

// A function to declare the winner of the game
bool declareWinner(vl &piles, ll n){
    ll xorValue = dp[piles[0]];
    for(int i=1; i<=n-1; i++) xorValue = xorValue ^ dp[piles[i]];
    return (xorValue!=0);
}