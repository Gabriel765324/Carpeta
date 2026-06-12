#include "bits/stdc++.h"
using namespace std;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define forn(i, n) for(int i = n - 1; i > -1; i--)
#define forsn(i, s, n) for(int i = int(s); i > -1; i--)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define el "\n"
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, r, M_ximo = 0;
        cin>>n;
        r = n;
        vector<int> A(n), O(n);
        for(int i = 0; i < n; i++){
            cin>>A[i];
            O[i] = A[i];
            M_ximo = __gcd(A[i], M_ximo);
        }
        if(M_ximo == 1){
            cout<<"0\n";
            continue;
        }
        forn(a, n){
            //cerr<<n - a<<" "<<r<<".\n";
            if(n - a >= r) break;
            M_ximo = 0;
            forn(I, n){
                if(I == a) A[I] = __gcd(A[I], I + 1);
                M_ximo = __gcd(M_ximo, A[I]);
                A[I] = O[I];
            }
            if(M_ximo == 1) r = min(r, n - a);
        }
        //cerr<<r<<" r\n";
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                M_ximo = 0;
                forn(I, n){
                    if(I == a) A[I] = __gcd(A[I], I + 1);
                    if(I == b) A[I] = __gcd(A[I], I + 1);
                    M_ximo = __gcd(M_ximo, A[I]);
                    A[I] = O[I];
                }
                if(M_ximo == 1) r = min(r, 2 * n - a - b);
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    M_ximo = 0;
                    forn(I, n){
                        if(I == a) A[I] = __gcd(A[I], I + 1);
                        if(I == b) A[I] = __gcd(A[I], I + 1);
                        if(I == c) A[I] = __gcd(A[I], I + 1);
                        M_ximo = __gcd(M_ximo, A[I]);
                        A[I] = O[I];
                    }
                    if(M_ximo == 1) r = min(r, 3 * n - a - b - c);
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        M_ximo = 0;
                        forn(I, n){
                            if(I == a) A[I] = __gcd(A[I], I + 1);
                            if(I == b) A[I] = __gcd(A[I], I + 1);
                            if(I == c) A[I] = __gcd(A[I], I + 1);
                            if(I == d) A[I] = __gcd(A[I], I + 1);
                            M_ximo = __gcd(M_ximo, A[I]);
                            A[I] = O[I];
                        }
                        if(M_ximo == 1) r = min(r, 4 * n - a - b - c - d);
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            M_ximo = 0;
                            forn(I, n){
                                if(I == a) A[I] = __gcd(A[I], I + 1);
                                if(I == b) A[I] = __gcd(A[I], I + 1);
                                if(I == c) A[I] = __gcd(A[I], I + 1);
                                if(I == d) A[I] = __gcd(A[I], I + 1);
                                if(I == e) A[I] = __gcd(A[I], I + 1);
                                M_ximo = __gcd(M_ximo, A[I]);
                                A[I] = O[I];
                            }
                            if(M_ximo == 1) r = min(r, 5 * n - a - b - c - d - e);
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                M_ximo = 0;
                                forn(I, n){
                                    if(I == a) A[I] = __gcd(A[I], I + 1);
                                    if(I == b) A[I] = __gcd(A[I], I + 1);
                                    if(I == c) A[I] = __gcd(A[I], I + 1);
                                    if(I == d) A[I] = __gcd(A[I], I + 1);
                                    if(I == e) A[I] = __gcd(A[I], I + 1);
                                    if(I == f) A[I] = __gcd(A[I], I + 1);
                                    M_ximo = __gcd(M_ximo, A[I]);
                                    A[I] = O[I];
                                }
                                if(M_ximo == 1) r = min(r, 6 * n - a - b - c - d - e - f);
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    M_ximo = 0;
                                    forn(I, n){
                                        if(I == a) A[I] = __gcd(A[I], I + 1);
                                        if(I == b) A[I] = __gcd(A[I], I + 1);
                                        if(I == c) A[I] = __gcd(A[I], I + 1);
                                        if(I == d) A[I] = __gcd(A[I], I + 1);
                                        if(I == e) A[I] = __gcd(A[I], I + 1);
                                        if(I == f) A[I] = __gcd(A[I], I + 1);
                                        if(I == g) A[I] = __gcd(A[I], I + 1);
                                        M_ximo = __gcd(M_ximo, A[I]);
                                        A[I] = O[I];
                                    }
                                    if(M_ximo == 1) r = min(r, 7 * n - a - b - c - d - e - f - g);
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        M_ximo = 0;
                                        forn(I, n){
                                            if(I == a) A[I] = __gcd(A[I], I + 1);
                                            if(I == b) A[I] = __gcd(A[I], I + 1);
                                            if(I == c) A[I] = __gcd(A[I], I + 1);
                                            if(I == d) A[I] = __gcd(A[I], I + 1);
                                            if(I == e) A[I] = __gcd(A[I], I + 1);
                                            if(I == f) A[I] = __gcd(A[I], I + 1);
                                            if(I == g) A[I] = __gcd(A[I], I + 1);
                                            if(I == h) A[I] = __gcd(A[I], I + 1);
                                            M_ximo = __gcd(M_ximo, A[I]);
                                            A[I] = O[I];
                                        }
                                        if(M_ximo == 1) r = min(r, 8 * n - a - b - c - d - e - f - g - h);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            M_ximo = 0;
                                            forn(I, n){
                                                if(I == a) A[I] = __gcd(A[I], I + 1);
                                                if(I == b) A[I] = __gcd(A[I], I + 1);
                                                if(I == c) A[I] = __gcd(A[I], I + 1);
                                                if(I == d) A[I] = __gcd(A[I], I + 1);
                                                if(I == e) A[I] = __gcd(A[I], I + 1);
                                                if(I == f) A[I] = __gcd(A[I], I + 1);
                                                if(I == g) A[I] = __gcd(A[I], I + 1);
                                                if(I == h) A[I] = __gcd(A[I], I + 1);
                                                if(I == i) A[I] = __gcd(A[I], I + 1);
                                                M_ximo = __gcd(M_ximo, A[I]);
                                                A[I] = O[I];
                                            }
                                            if(M_ximo == 1) r = min(r, 9 * n - a - b - c - d - e - f - g - h - i);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                M_ximo = 0;
                                                forn(I, n){
                                                    if(I == a) A[I] = __gcd(A[I], I + 1);
                                                    if(I == b) A[I] = __gcd(A[I], I + 1);
                                                    if(I == c) A[I] = __gcd(A[I], I + 1);
                                                    if(I == d) A[I] = __gcd(A[I], I + 1);
                                                    if(I == e) A[I] = __gcd(A[I], I + 1);
                                                    if(I == f) A[I] = __gcd(A[I], I + 1);
                                                    if(I == g) A[I] = __gcd(A[I], I + 1);
                                                    if(I == h) A[I] = __gcd(A[I], I + 1);
                                                    if(I == i) A[I] = __gcd(A[I], I + 1);
                                                    if(I == j) A[I] = __gcd(A[I], I + 1);
                                                    M_ximo = __gcd(M_ximo, A[I]);
                                                    A[I] = O[I];
                                                }
                                                if(M_ximo == 1) r = min(r, 10 * n - a - b - c - d - e - f - g - h - i - j);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    M_ximo = 0;
                                                    forn(I, n){
                                                        if(I == a) A[I] = __gcd(A[I], I + 1);
                                                        if(I == b) A[I] = __gcd(A[I], I + 1);
                                                        if(I == c) A[I] = __gcd(A[I], I + 1);
                                                        if(I == d) A[I] = __gcd(A[I], I + 1);
                                                        if(I == e) A[I] = __gcd(A[I], I + 1);
                                                        if(I == f) A[I] = __gcd(A[I], I + 1);
                                                        if(I == g) A[I] = __gcd(A[I], I + 1);
                                                        if(I == h) A[I] = __gcd(A[I], I + 1);
                                                        if(I == i) A[I] = __gcd(A[I], I + 1);
                                                        if(I == j) A[I] = __gcd(A[I], I + 1);
                                                        if(I == k) A[I] = __gcd(A[I], I + 1);
                                                        M_ximo = __gcd(M_ximo, A[I]);
                                                        A[I] = O[I];
                                                    }
                                                    if(M_ximo == 1) r = min(r, 11 * n - a - b - c - d - e - f - g - h - i - j - k);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        M_ximo = 0;
                                                        forn(I, n){
                                                            if(I == a) A[I] = __gcd(A[I], I + 1);
                                                            if(I == b) A[I] = __gcd(A[I], I + 1);
                                                            if(I == c) A[I] = __gcd(A[I], I + 1);
                                                            if(I == d) A[I] = __gcd(A[I], I + 1);
                                                            if(I == e) A[I] = __gcd(A[I], I + 1);
                                                            if(I == f) A[I] = __gcd(A[I], I + 1);
                                                            if(I == g) A[I] = __gcd(A[I], I + 1);
                                                            if(I == h) A[I] = __gcd(A[I], I + 1);
                                                            if(I == i) A[I] = __gcd(A[I], I + 1);
                                                            if(I == j) A[I] = __gcd(A[I], I + 1);
                                                            if(I == k) A[I] = __gcd(A[I], I + 1);
                                                            if(I == l) A[I] = __gcd(A[I], I + 1);
                                                            M_ximo = __gcd(M_ximo, A[I]);
                                                            A[I] = O[I];
                                                        }
                                                        if(M_ximo == 1) r = min(r, 12 * n - a - b - c - d - e - f - g - h - i - j - k - l);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        forsn(m, l, n){
                                                            if(13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m >= r) break;
                                                            M_ximo = 0;
                                                            forn(I, n){
                                                                if(I == a) A[I] = __gcd(A[I], I + 1);
                                                                if(I == b) A[I] = __gcd(A[I], I + 1);
                                                                if(I == c) A[I] = __gcd(A[I], I + 1);
                                                                if(I == d) A[I] = __gcd(A[I], I + 1);
                                                                if(I == e) A[I] = __gcd(A[I], I + 1);
                                                                if(I == f) A[I] = __gcd(A[I], I + 1);
                                                                if(I == g) A[I] = __gcd(A[I], I + 1);
                                                                if(I == h) A[I] = __gcd(A[I], I + 1);
                                                                if(I == i) A[I] = __gcd(A[I], I + 1);
                                                                if(I == j) A[I] = __gcd(A[I], I + 1);
                                                                if(I == k) A[I] = __gcd(A[I], I + 1);
                                                                if(I == l) A[I] = __gcd(A[I], I + 1);
                                                                if(I == m) A[I] = __gcd(A[I], I + 1);
                                                                M_ximo = __gcd(M_ximo, A[I]);
                                                                A[I] = O[I];
                                                            }
                                                            if(M_ximo == 1) r = min(r, 13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        forsn(m, l, n){
                                                            if(13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m >= r) break;
                                                            forsn(o, m, n){
                                                                if(14 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o >= r) break;
                                                                M_ximo = 0;
                                                                forn(I, n){
                                                                    if(I == a) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == b) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == c) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == d) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == e) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == f) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == g) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == h) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == i) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == j) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == k) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == l) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == m) A[I] = __gcd(A[I], I + 1);
                                                                    if(I == o) A[I] = __gcd(A[I], I + 1);
                                                                    M_ximo = __gcd(M_ximo, A[I]);
                                                                    A[I] = O[I];
                                                                }
                                                                if(M_ximo == 1) r = min(r, 14 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        forsn(m, l, n){
                                                            if(13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m >= r) break;
                                                            forsn(o, m, n){
                                                                if(14 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o >= r) break;
                                                                forsn(p, o, n){
                                                                    if(15 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p >= r) break;
                                                                    M_ximo = 0;
                                                                    forn(I, n){
                                                                        if(I == a) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == b) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == c) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == d) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == e) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == f) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == g) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == h) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == i) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == j) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == k) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == l) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == m) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == o) A[I] = __gcd(A[I], I + 1);
                                                                        if(I == p) A[I] = __gcd(A[I], I + 1);
                                                                        M_ximo = __gcd(M_ximo, A[I]);
                                                                        A[I] = O[I];
                                                                    }
                                                                    if(M_ximo == 1) r = min(r, 15 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        forsn(m, l, n){
                                                            if(13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m >= r) break;
                                                            forsn(o, m, n){
                                                                if(14 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o >= r) break;
                                                                forsn(p, o, n){
                                                                    if(15 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p >= r) break;
                                                                    forsn(q, p, n){
                                                                        if(16 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q >= r) break;
                                                                        M_ximo = 0;
                                                                        forn(I, n){
                                                                            if(I == a) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == b) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == c) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == d) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == e) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == f) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == g) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == h) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == i) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == j) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == k) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == l) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == m) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == o) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == p) A[I] = __gcd(A[I], I + 1);
                                                                            if(I == q) A[I] = __gcd(A[I], I + 1);
                                                                            M_ximo = __gcd(M_ximo, A[I]);
                                                                            A[I] = O[I];
                                                                        }
                                                                        if(M_ximo == 1) r = min(r, 16 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        forsn(m, l, n){
                                                            if(13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m >= r) break;
                                                            forsn(o, m, n){
                                                                if(14 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o >= r) break;
                                                                forsn(p, o, n){
                                                                    if(15 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p >= r) break;
                                                                    forsn(q, p, n){
                                                                        if(16 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q >= r) break;
                                                                        forsn(s, q, n){
                                                                            if(17 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q >= r) break;
                                                                            M_ximo = 0;
                                                                            forn(I, n){
                                                                                if(I == a) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == b) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == c) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == d) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == e) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == f) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == g) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == h) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == i) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == j) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == k) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == l) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == m) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == o) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == p) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == q) A[I] = __gcd(A[I], I + 1);
                                                                                if(I == s) A[I] = __gcd(A[I], I + 1);
                                                                                M_ximo = __gcd(M_ximo, A[I]);
                                                                                A[I] = O[I];
                                                                            }
                                                                            if(M_ximo == 1) r = min(r, 17 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q - s);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        forsn(m, l, n){
                                                            if(13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m >= r) break;
                                                            forsn(o, m, n){
                                                                if(14 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o >= r) break;
                                                                forsn(p, o, n){
                                                                    if(15 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p >= r) break;
                                                                    forsn(q, p, n){
                                                                        if(16 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q >= r) break;
                                                                        forsn(s, q, n){
                                                                            if(17 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q >= r) break;
                                                                            forsn(t, s, n){
                                                                                if(18 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q - t >= r) break;
                                                                                M_ximo = 0;
                                                                                forn(I, n){
                                                                                    if(I == a) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == b) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == c) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == d) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == e) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == f) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == g) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == h) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == i) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == j) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == k) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == l) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == m) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == o) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == p) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == q) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == s) A[I] = __gcd(A[I], I + 1);
                                                                                    if(I == t) A[I] = __gcd(A[I], I + 1);
                                                                                    M_ximo = __gcd(M_ximo, A[I]);
                                                                                    A[I] = O[I];
                                                                                }
                                                                                if(M_ximo == 1) r = min(r, 18 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q - s - t);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        forn(a, n){
            if(n - a >= r) break;
            forsn(b, a, n){
                if(2 * n - a - b >= r) break;
                forsn(c, b, n){
                    if(3 * n - a - b - c >= r) break;
                    forsn(d, c, n){
                        if(4 * n - a - b - c - d >= r) break;
                        forsn(e, d, n){
                            if(5 * n - a - b - c - d - e >= r) break;
                            forsn(f, e, n){
                                if(6 * n - a - b - c - d - e - f >= r) break;
                                forsn(g, f, n){
                                    if(7 * n - a - b - c - d - e - f - g >= r) break;
                                    forsn(h, g, n){
                                        if(8 * n - a - b - c - d - e - f - g - h >= r) break;
                                        forsn(i, h, n){
                                            if(9 * n - a - b - c - d - e - f - g - h - i >= r) break;
                                            forsn(j, i, n){
                                                if(10 * n - a - b - c - d - e - f - g - h - i - j >= r) break;
                                                forsn(k, j, n){
                                                    if(11 * n - a - b - c - d - e - f - g - h - i - j - k >= r) break;
                                                    forsn(l, k, n){
                                                        if(12 * n - a - b - c - d - e - f - g - h - i - j - k - l >= r) break;
                                                        forsn(m, l, n){
                                                            if(13 * n - a - b - c - d - e - f - g - h - i - j - k - l - m >= r) break;
                                                            forsn(o, m, n){
                                                                if(14 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o >= r) break;
                                                                forsn(p, o, n){
                                                                    if(15 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p >= r) break;
                                                                    forsn(q, p, n){
                                                                        if(16 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q >= r) break;
                                                                        forsn(s, q, n){
                                                                            if(17 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q >= r) break;
                                                                            forsn(t, s, n){
                                                                                if(18 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q - t >= r) break;
                                                                                forsn(u, t, n){
                                                                                    if(19 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q - t - u >= r) break;
                                                                                    M_ximo = 0;
                                                                                    forn(I, n){
                                                                                        if(I == a) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == b) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == c) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == d) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == e) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == f) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == g) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == h) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == i) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == j) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == k) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == l) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == m) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == o) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == p) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == q) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == s) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == t) A[I] = __gcd(A[I], I + 1);
                                                                                        if(I == u) A[I] = __gcd(A[I], I + 1);
                                                                                        M_ximo = __gcd(M_ximo, A[I]);
                                                                                        A[I] = O[I];
                                                                                    }
                                                                                    if(M_ximo == 1) r = min(r, 19 * n - a - b - c - d - e - f - g - h - i - j - k - l - m - o - p - q - s - t - u);
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        cout<<r<<el;
    }
    return 0;
}