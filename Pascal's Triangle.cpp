//杨辉三角每行的基都为1，所需要做的就是对每行该改造的地方进行改造-->特别是从第三行开始
//如果不好理解，可以将每行手写完然后理解
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> row;
        for(int i=0;i<numRows;i++)
        {
            row.push_back(1);
            for(int j=i-1;j>0;j--)
            {
                row[j]=row[j-1]+row[j];
            }
            result.push_back(row);
        }
    return result;
    }
    
};
