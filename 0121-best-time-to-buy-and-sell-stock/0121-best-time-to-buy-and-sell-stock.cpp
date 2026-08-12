class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprices=INT_MAX;
        int maxprice=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minprices){
                minprices=prices[i];
            }
            int profit=prices[i]-minprices;

            if(profit>maxprice){
                maxprice=profit;
            }

        }
        return maxprice;
    }
};