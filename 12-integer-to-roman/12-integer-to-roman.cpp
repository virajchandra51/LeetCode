class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string,int>> v;
        v.push_back({"M",1000});
        v.push_back({"CM",900});
        v.push_back({"D",500});
        v.push_back({"CD",400});
        v.push_back({"C",100});
        v.push_back({"XC",90});
        v.push_back({"L",50});
        v.push_back({"XL",40});
        v.push_back({"X",10});
        v.push_back({"IX",9});
        v.push_back({"V",5});
        v.push_back({"IV",4});
        v.push_back({"I",1});
        int i=0; string s ="";
        while(num>0)
        {
            if(num-v[i].second>=0)
            {
                s+=v[i].first;
                num-=v[i].second;
            }
            else
                i++;
        }
        return s;
    }
};