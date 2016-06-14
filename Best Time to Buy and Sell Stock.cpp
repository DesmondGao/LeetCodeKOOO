//动态规划解决单支股票买入卖出问题
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(0==prices.size())
        {
            return 0;
        }
       int currMin=prices[0];
       int maxProfit=0;
       for(int i=1;i<prices.size();i++)
       {
           currMin=min(currMin,prices[i]);//当前的买入价格---》动态选择当前最小买入价格
           maxProfit=max(maxProfit,prices[i]-currMin);//当前卖出的最大利润---->动态选择当前计算的利润和前面计算出来的利润比较
       }
    return maxProfit;
    }
};
