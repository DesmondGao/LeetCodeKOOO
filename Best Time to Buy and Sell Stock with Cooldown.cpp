//再思考----->self方法没有AC-->主要是想通过增减性找到峰值点，然后其冷却一天不影响我的收益，。。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
        {
            return 0;
        }
        int maxProfit=0;
        prices[-1]=prices[0];
        for(int i=0;i<prices.size()-1;i++)
        {
            //注意是sell后有一天的冷却时间
            //还是采用贪心，不过后面如果是下降的趋势则需要买，因为冷却时间也不过是冷却的下降时间
            int down=prices[i+1]-prices[i];
            int up=prices[i]-prices[i-1];
            if(down<0&&up>=0)
            {
                int k=i;
                for(int j=0;j<k-1;j++)
                {
                int diff=prices[j+1]-prices[j];
                 maxProfit+=diff;
                }
                i++;
                continue;
            }
        }
        return maxProfit;
    }
};

//动态规划思想
class Solution {
public:
    int maxProfit(vector<int>& prices){
        //采用动态规划计算
        //主要是怎样设定动态方程-->股票的买与卖，即手头有股票和没有股票
        vector<int> profitNoBlock(prices.size(),0);//手头有股票最大利润
        vector<int> profitHasBlock(prices.size(),0);//手头没有股票最大利润
        if(prices.size()==0)
        return 0;
        //day0
        profitNoBlock[0]=0;
        profitHasBlock[0]=-prices[0];
        //day1
        profitNoBlock[1]=max(profitNoBlock[0],profitHasBlock[0]+prices[1]);
        profitHasBlock[1]=max(profitHasBlock[0],0-prices[1]);
        for(int i=2;i<prices.size();i++)
        {
            profitNoBlock[i]=max(profitNoBlock[i-1],profitHasBlock[i-1]+prices[i]);//把昨天的股票卖掉加上今天的价钱-->没股票了
            profitHasBlock[i]=max(profitHasBlock[i-1],profitNoBlock[i-2]-prices[i]);//前天卖出，只能今天买入，买入后需减去今天股价
        }
    return profitNoBlock[prices.size()-1];
    }
};
