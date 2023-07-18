#include<bits/stdc++.h>
using namespace std;
int N,items,maxc,weight,value;
long long dynamicvalue[50010];



#define nega_infinity -200000//比最大重量还大


int main()
{
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>items>>maxc;
        memset(dynamicvalue,nega_infinity,sizeof(long long)*50010);
        int choose = 1;
        while(choose <= items){//选择哪个item
            choose++;
            cin>>weight>>value;
            if(weight > maxc)continue;
            int curcapacity = 1;
            while(curcapacity <= maxc){//当前背包容量
                curcapacity++;
                long long uppervalue = dynamicvalue[curcapacity];//上一个物品在当前容量下的价值
                //如果自身的重量是格子倍数
                if(curcapacity % weight == 0){
                    int index = curcapacity / weight;//求倍数
                    long long  sumvalue = index * value;//综合价值
                    if(sumvalue > uppervalue || dynamicvalue[curcapacity] <= 0){
                        //自己比以前的格子还大||这个格子从未被涉及
                        dynamicvalue[curcapacity] = sumvalue;
                        uppervalue = dynamicvalue[curcapacity];
                    }
                }
                int targetcapacity = curcapacity + weight;//在上一个物品的基础上，装上当前物品，将会达到什么体积
                long long uppertargetvalue = dynamicvalue[targetcapacity];
                long long iftakecuritem = uppervalue + value;
                if(targetcapacity <= maxc && uppervalue > 0){
                    //如果目前的背包还装的下这个体积 && 当前格子是被装过的，那么这个格子可以当跳板
                    if((iftakecuritem > uppertargetvalue && uppertargetvalue > 0)
                    ||uppertargetvalue < 0){
                        dynamicvalue[targetcapacity] = iftakecuritem;
                    }
                }
            }
        }
        //如果最终格不是0，就意味着可以装满，输出最终格，否则发no
        if(dynamicvalue[maxc] > 0)cout<<dynamicvalue[maxc]<<endl;
        else cout<<"NO"<<endl;
    }
} 
