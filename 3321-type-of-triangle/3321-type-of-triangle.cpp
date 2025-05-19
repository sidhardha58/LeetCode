class Solution {
public:
    string triangleType(vector<int>& n) {
        int cond;
        if (((n[0] + n[1]) > n[2]) && ((n[2] + n[1]) > n[0]) &&
            ((n[2] + n[0]) > n[1])) {
                //sort(n.begin(),n.end());
                //cond=distance(n.begin(),unique(n.begin(),n.end()));
                if(n[0]==n[1] && n[1]==n[2]) return "equilateral";
                else if(n[0]==n[1] || n[1]==n[2] ||n[0]==n[2])return "isosceles";
                else return "scalene";
        }
        else return "none";


    }
};