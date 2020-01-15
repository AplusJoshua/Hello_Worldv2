#include <cstdio>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f

inline int read(){ //快读，cin替代
    int w=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        w=(w<<3)+(w<<1)+ch-48;
        ch=getchar();
    }
    return w*f;
}
int n,a[200010],ans;
bool vis[200010];
signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    //首先读入了这个n和原来的整个数列
    for(int i=30;i>=0;i--){  //logn 2^10=1024 1024^3=2^30>=1e9
        //告诉你现在我们在处理二进制串中的哪一位
        int cnt=0;  //来数目前还合法的数字中这位有几个1
        for(int j=1;j<=n;j++){
            if(vis[j]==true)continue;  //vis[j]==true说明aj被淘汰了
            if((a[j]>>i)&1)cnt++;  //这个步骤是用来统计该位有多少个1
        }
        if(cnt<2)continue;  //如果总共该位上是1的个数不足2个，那么可以跳过这位了
        for(int j=1;j<=n;j++){  //如果超过两个的话，哪些会被标为不合法
            if(vis[j]==true)continue;  //已经放弃掉的不用考虑
            if(((a[j]>>i)&1)==false)vis[j]=true;  //这位是0舍弃掉
        }
        ans+=1<<i;//统计答案
    }
    cout<<ans<<endl;
    return 0;
}

/*
2^3 c++ xor ^ 1<<3 1000 8

4
1 2 8 10

3210

0001 a1
0010 a2
1000 a3
1010 a4
vis[i]是true的话表示第i个数字在之前的选择中已经被淘汰掉了
首先考虑第3位，因为vis[]，除了a3,a4之外都把其他的vis标成true,ans+=2^3
考虑第2位，所以不用被考虑
考虑第1为，因为计数只有1个，所以不用被考虑
考虑第0位，
综上，只有第三位是选择的，所以答案也就是ans=2^3+(2^)+(2^)
1010
x>>y
x拆成一个二进制串，右移y位
和右移相对的是左移
x<<y
表示把x拆成一个二进制串，左移y位
比如10的二进制串是1010
10<<2也就是把这个二进制串左移两位得到了101000
大多数代码本身在存储数字的时候就是把数字转换成二进制串
所以大多数情况下不用考虑二进制串和数字之间的转换，直接用就行了
*/

