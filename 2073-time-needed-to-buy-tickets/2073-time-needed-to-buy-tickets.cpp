class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int c=0;
        int i=0;
        while(tickets[k]>0)
        {
            if(tickets[i]>0)
            {
                c++;
                tickets[i]--;
                i++;
                if(i==tickets.size())
                    i=0;
            }
            if(tickets[i]==0)
            {
                i++;
                if(i==tickets.size())
                    i=0;
            }
            if(i>=tickets.size())
                i=0;
        }
        return c;
    }
};