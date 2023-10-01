class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int sum=0;
        for(int i=0;i<energy.size();i++)
        {
            if(initialEnergy>energy[i])
                initialEnergy-=energy[i];
            else
            {
                sum+=(energy[i]+1-initialEnergy);
                initialEnergy = (energy[i]+1);
                initialEnergy-=energy[i];
            }
        }
        for(int i=0;i<experience.size();i++)
        {
            if(initialExperience>experience[i])
                initialExperience+=experience[i];
            else
            {
                sum+=(experience[i]-initialExperience+1);
                initialExperience=experience[i]+1;
                initialExperience+=experience[i];
            }
        }
        return sum;
    }
};