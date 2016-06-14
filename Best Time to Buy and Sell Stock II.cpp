class Solution {
public:
    int maxProfit(vector<int>& prices) {
       //本题是可以买多少股票然后每部分最大实现总体利益最大，无形中复杂化了问题
       //因为需要算出应该有多少trasaction,其实题意是交易次数不限，这样就不管次数问题了，只需要
       //用贪心算出总体最大就可以-->上坡就可以,抽象成一个一维离散函数问题
       if(prices.size()==0)
       {
           return 0;
       }
       int maxProfit=0;
       for(int i=0;i<prices.size()-1;i++)
       {
           int diff=prices[i+1]-prices[i];
           if(diff>=0)
           {
               maxProfit+=diff;
           }
       }
       return maxProfit;
    }
};
