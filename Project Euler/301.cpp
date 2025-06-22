#include "bits/stdc++.h"
using namespace std;
vector< vector< vector<long long> > > Memorizai_n;
long long Resolver(long long a, long long b, long long c){
    if(a == 0 and b == 0 and c == 0) return 0;
    vector<long long> Cos = {a, b, c};
    sort(Cos.begin(), Cos.end());
    a = Cos[0];
    b = Cos[1];
    c = Cos[2];
    if(Memorizai_n[a][b][c] != -2) return Memorizai_n[a][b][c];
    if(a == b or b == c){
        if(a == 0 or b == 0 or c == 0) return 0;
        else return 1;
    }
    long long Cero = 0;
    if(a == 0) Cero++;
    if(b == 0) Cero++;
    if(c == 0) Cero++;
    if(Cero == 1){
        if(a == 0 and b != c) return 1;
        if(b == 0 and a != c) return 1;
        if(c == 0 and a != b) return 1;
        return 0;
    }
    if(Cero == 2) return 1;
    for(long long i = 1; i <= a; i++){
        if(Resolver(a - i, b, c) == 0) return Memorizai_n[a][b][c] = 1;
    }
    for(long long i = 1; i <= b; i++){
        if(Resolver(a, b - i, c) == 0) return Memorizai_n[a][b][c] = 1;
    }
    for(long long i = 1; i <= c; i++){
        if(Resolver(a, b, c - i) == 0) return Memorizai_n[a][b][c] = 1;
    }
    return Memorizai_n[a][b][c] = 0;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    long long Mayor = 3 * 2222 + 22;
    Memorizai_n.assign(Mayor, vector< vector<long long> >(Mayor, vector<long long>(Mayor, -2)));
    for(long long i = 1; i < (Mayor - 22) / 3; i++){
        cout<<i<<" "<<((Resolver(i, i * 2, i * 3) == 0) ? "Pierdes.\n" : "Ganas.\n");
    }
    return 0;
}
/*
1 Pierdes.
2 Pierdes.
3 Ganas.
4 Pierdes.
5 Pierdes.
6 Ganas.
7 Ganas.
8 Pierdes.
9 Pierdes.
10 Pierdes.
11 Ganas.
12 Ganas.
13 Ganas.
14 Ganas.
15 Ganas.
16 Pierdes.
17 Pierdes.
18 Pierdes.
19 Ganas.
20 Pierdes.
21 Pierdes.
22 Ganas.
23 Ganas.
24 Ganas.
25 Ganas.
26 Ganas.
27 Ganas.
28 Ganas.
29 Ganas.
30 Ganas.
31 Ganas.
32 Pierdes.
33 Pierdes.
34 Pierdes.
35 Ganas.
36 Pierdes.
37 Pierdes.
38 Ganas.
39 Ganas.
40 Pierdes.
41 Pierdes.
42 Pierdes.
43 Ganas.
44 Ganas.
45 Ganas.
46 Ganas.
47 Ganas.
48 Ganas.
49 Ganas.
50 Ganas.
51 Ganas.
52 Ganas.
53 Ganas.
54 Ganas.
55 Ganas.
56 Ganas.
57 Ganas.
58 Ganas.
59 Ganas.
60 Ganas.
61 Ganas.
62 Ganas.
63 Ganas.
64 Pierdes.
65 Pierdes.
66 Pierdes.
67 Ganas.
68 Pierdes.
69 Pierdes.
70 Ganas.
71 Ganas.
72 Pierdes.
73 Pierdes.
74 Pierdes.
75 Ganas.
76 Ganas.
77 Ganas.
78 Ganas.
79 Ganas.
80 Pierdes.
81 Pierdes.
82 Pierdes.
83 Ganas.
84 Pierdes.
85 Pierdes.
86 Ganas.
87 Ganas.
88 Ganas.
89 Ganas.
90 Ganas.
91 Ganas.
92 Ganas.
93 Ganas.
94 Ganas.
95 Ganas.
96 Ganas.
97 Ganas.
98 Ganas.
99 Ganas.
100 Ganas.
101 Ganas.
102 Ganas.
103 Ganas.
104 Ganas.
105 Ganas.
106 Ganas.
107 Ganas.
108 Ganas.
109 Ganas.
110 Ganas.
111 Ganas.
112 Ganas.
113 Ganas.
114 Ganas.
115 Ganas.
116 Ganas.
117 Ganas.
118 Ganas.
119 Ganas.
120 Ganas.
121 Ganas.
122 Ganas.
123 Ganas.
124 Ganas.
125 Ganas.
126 Ganas.
127 Ganas.
128 Pierdes.
129 Pierdes.
130 Pierdes.
131 Ganas.
132 Pierdes.
133 Pierdes.
134 Ganas.
135 Ganas.
136 Pierdes.
137 Pierdes.
138 Pierdes.
139 Ganas.
140 Ganas.
141 Ganas.
142 Ganas.
143 Ganas.
144 Pierdes.
145 Pierdes.
146 Pierdes.
147 Ganas.
148 Pierdes.
149 Pierdes.
150 Ganas.
151 Ganas.
152 Ganas.
153 Ganas.
154 Ganas.
155 Ganas.
156 Ganas.
157 Ganas.
158 Ganas.
159 Ganas.
160 Pierdes.
161 Pierdes.
162 Pierdes.
163 Ganas.
164 Pierdes.
165 Pierdes.
166 Ganas.
167 Ganas.
168 Pierdes.
169 Pierdes.
170 Pierdes.
171 Ganas.
172 Ganas.
173 Ganas.
174 Ganas.
175 Ganas.
176 Ganas.
177 Ganas.
178 Ganas.
179 Ganas.
180 Ganas.
181 Ganas.
182 Ganas.
183 Ganas.
184 Ganas.
185 Ganas.
186 Ganas.
187 Ganas.
188 Ganas.
189 Ganas.
190 Ganas.
191 Ganas.
192 Ganas.
193 Ganas.
194 Ganas.
195 Ganas.
196 Ganas.
197 Ganas.
198 Ganas.
199 Ganas.
200 Ganas.
201 Ganas.
202 Ganas.
203 Ganas.
204 Ganas.
205 Ganas.
206 Ganas.
207 Ganas.
208 Ganas.
209 Ganas.
210 Ganas.
211 Ganas.
212 Ganas.
213 Ganas.
214 Ganas.
215 Ganas.
216 Ganas.
217 Ganas.
218 Ganas.
219 Ganas.
220 Ganas.
221 Ganas.
222 Ganas.
223 Ganas.
224 Ganas.
225 Ganas.
226 Ganas.
227 Ganas.
228 Ganas.
229 Ganas.
230 Ganas.
231 Ganas.
232 Ganas.
233 Ganas.
234 Ganas.
235 Ganas.
236 Ganas.
237 Ganas.
238 Ganas.
239 Ganas.
240 Ganas.
241 Ganas.
242 Ganas.
243 Ganas.
244 Ganas.
245 Ganas.
246 Ganas.
247 Ganas.
248 Ganas.
249 Ganas.
250 Ganas.
251 Ganas.
252 Ganas.
253 Ganas.
254 Ganas.
255 Ganas.
256 Pierdes.
257 Pierdes.
258 Pierdes.
259 Ganas.
260 Pierdes.
261 Pierdes.
*/