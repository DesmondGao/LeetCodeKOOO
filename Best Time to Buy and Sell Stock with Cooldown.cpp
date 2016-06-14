//再思考----->
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
