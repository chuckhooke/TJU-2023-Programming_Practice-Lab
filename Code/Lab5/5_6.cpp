#include<bits/stdc++.h>
using namespace std; 
#define inf 10000 //定义一个无穷大的值


int n, k, m, s, t; 
int we[105];  //we数组表示每个国家的文化
int g[105][105];  //g数组表示各个文化之间是否互相排斥
int e[105][105];  //e数组a表示各个国家之间的距离
bool v[105]; 
int d[105];  //d数组表示源点s到各个点的最短距离

void dijkstra()
{
    set <int> setset; 
    int i, j; 
    memset(v, 0, sizeof(v));  //v数组表示某个点是否已被访问过，初始化为0
    // v[s] = 1;  //源点s标记为已访问
    // setset.insert(s); 
    
    for(i = 1; i <= n; i++) d[i] = inf;  //初始化d数组为源点s到各个点的距离
    d[s]  =  0; 
    while(1)
    {
        int k = -1; 
        int mm = inf; 
        setset.clear(); 
        for(i = 1; i <= n; i++)
        {
            if(!v[i]&&d[i]<mm) //如果i未被访问且i到源点s的距离比mm更小
            {
                k = i;  //记录距离s最近的未访问点
                mm = d[i];  //更新最小距离
            }
        }
        // cout << "DFDF"; 
        if(k == -1) break;  //如果所有点都已被访问，则结束
        v[k] = 1;  //标记k已被访问
        setset.insert(k); 
        for(i = 1; i <= n; i++)
        {
            bool flag1  =  false; 
            bool flag2  =  false; 
            set<int>::iterator it; 
            for(it = setset.begin();  it!= setset.end(); it++){
                flag1  =  flag1 || g[i][*it]; 
                //cout << flag << endl; 
            }
            set<int>::iterator itt; 
            for(itt = setset.begin();  itt!= setset.end(); itt++){
                if (we[i]  ==  we[*itt]) flag2  =  true; 
            }
                
            if(!flag2&&!flag1&&d[i]>d[k]+e[k][i])
            //如果k和i的文化不同、k和i的文化之间不互相排斥、从源点s到i的距离比从源点s到k再到i的距离更短
            { 
                //cout << "DFDF"; 
                d[i] = d[k]+e[k][i];  //更新从源点s到i的最短距离
                // cout << i << " " << d[i] << endl; 
            }



        }
    }
}

int main()
{
    cin>>n>>k>>m>>s>>t; 
    int i, j; 
    for(i = 1; i<= n; i++)
        for(j = 1; j<= n; j++)
        {
            if(i == j) e[i][j] = 0;  //如果i和j相等，表示这是同一个点，距离为0
            else e[i][j] = inf;  //否则初始化为无穷大
        }
    for(i = 1; i<= n; i++) cin>>we[i];  //输入每个国家的文化
    for(i = 1; i<= k; i++)
    {
        for(j = 1; j<= k; j++)
        {
            cin>>g[i][j];  //输入文化之间的排斥情况
        }
    }
    for(i = 1; i<= k; i++)
    {
        for(j = 1; j<= k; j++)
        {
            if(i  ==  j) g[i][j]  =  1; 
        }
    }
    for(i = 1; i<= m; i++)
    {
        int x, y, z; 
        cin>>x>>y>>z; 
        if(e[x][y]>z)
        {
            e[x][y] = z; 
            e[y][x] = z;  
        }
    }
    dijkstra(); 
    int ooo =  -1; 
    if(d[t] == inf)
    cout<<ooo; 
    else
    cout<<d[t]; 
    return 0; 
}