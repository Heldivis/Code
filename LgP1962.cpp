// By https://www.luogu.com.cn/user/10420

#include <bits/stdc++.h>
#define mod 1000000007LL
using namespace std;

typedef long long LL;
typedef pair <LL, LL> pr;

LL n;
map <LL, LL> m;
map <LL, LL> :: iterator it;

LL F(LL i){
    LL res1, res2, res;
    if(i < 3) return 1LL; //F[1] = F[2] = 1
    it = m.find(i);
    if(it == m.end()){ //未算过
        if(i & 1){ //奇数使用公式②
            res1 = F(i >> 1);
            res2 = F(i + 1 >> 1);
            res = (res1 * res1 + res2 * res2) % mod;
        }else{ //偶数使用公式①
            res1 = F(i - 2 >> 1);
            res2 = F(i >> 1);
            res = ((res1 << 1) + res2) * res2 % mod; //注意移位的优先级比加减低
        }
        m.insert(pr(i, res)); //插入
        return res;
    }else
        return it -> second; //算过直接返回
}

int main(){
    scanf("%lld", &n);
    printf("%lld\n", F(n));
    return 0;
}
