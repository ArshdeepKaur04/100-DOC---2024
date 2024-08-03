/*
Question "Buddy NIM" on CodeChef
Alice, Bob and Charlie are playing a new game called Buddy NIM. The game is played at two tables; on the first 
table, there are N heaps containing A1, A2, ..., AN stones and on the second table, there are M heaps containing B1,
B2, ..., BM stones respectively.

Initially, Alice is playing at the first table and Bob is playing at the second table. The players take their turns
in this order: Charlie, Alice, Bob, Charlie, etc. 

Alice and Bob follow the rules for classical NIM - on Alice's turn, Alice must remove a positive number of stones
from one of the piles at her current table and on Bob's turn, Bob must remove a positive number of stones from one
of the piles at his current table. Whoever cannot remove any stone from a pile loses.

Charlie does not play at any table. Instead, on his turn, he decides if Alice and Bob should keep playing at their
respective tables or swap places.

Alice and Charlie are buddies and they cooperate, playing in the optimal way that results in Alice's victory
(if possible).

It is clear that either Alice or Bob wins the game eventually. You must find out who the winner will be. Print a 
single line containing the string "Alice" if Alice wins or "Bob" if Bob wins.
*/

#include <stdio.h>
#include <stdlib.h>

#define ll long long int

int cmp(const void *a, const void *b) {
    return (*(ll*)b - *(ll*)a);
}

int main(void) {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n, m, sum_1 = 0, sum_2 = 0, val;
        scanf("%lld %lld", &n, &m);
        ll cnt1 = n, cnt2 = m;
        ll a[n], b[m];
        
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            sum_1 += a[i];
            if(a[i] == 0)
                cnt1--;
        }
        
        for(int j = 0; j < m; j++) {
            scanf("%lld", &b[j]);
            sum_2 += b[j];
            if(b[j] == 0)
                cnt2--;
        }
        
        qsort(a, n, sizeof(ll), cmp);
        qsort(b, m, sizeof(ll), cmp);
        
        n = cnt1;
        m = cnt2;
        
        if(n != m) {
            if(sum_1 == sum_2 && sum_1 == 0) {
                printf("Bob\n");
            } else {
                printf("Alice\n");
            }
        } else {
            if(sum_1 == sum_2) {
                int fl = 0;
                for(int i = 0; i < n; i++) {
                    if(a[i] != b[i]) {
                        fl = 1;
                        break;
                    }
                }
                if(fl)
                    printf("Alice\n");
                else
                    printf("Bob\n");
            } else {
                printf("Alice\n");
            }
        }
    }
    return 0;
}