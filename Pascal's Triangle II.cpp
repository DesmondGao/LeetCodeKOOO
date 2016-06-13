class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(0);
        for(int i=0;i<rowIndex+1;i++)
        {
            row.push_back(1);
            for(int j=i-1;j>0;j--)
            {
                row[j]=row[j-1]+row[j];
            }
        }
        return row;
    }
};
