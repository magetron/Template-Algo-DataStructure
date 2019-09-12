class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int i = 0;
		int j = 0;
		int m = matrix.size();
		if (m == 0) return vector<int>();
        int n = matrix[0].size();
		if (n == 0) return vector<int>();
		int tot = m * n;
		vector<int> ans;
		while (n > 1 && m > 1) {
			for (int k = 0; k < n; k++) ans.push_back(matrix[i][j++]);
			j--; i++;
			for (int k = 0; k < m - 1; k++) ans.push_back(matrix[i++][j]);			
			i--; j--;
			for (int k = 0; k < n - 1; k++) ans.push_back(matrix[i][j--]);
			j++; i--;
			for (int k = 0; k < m - 2; k++) ans.push_back(matrix[i--][j]);
			i++; j++;
			m -= 2;
			n -= 2;
		}
        if (n == 1) for (int k = 0; k < m; k++) ans.push_back(matrix[i++][j]);
		else if (m == 1) for (int k = 0; k < n; k++) ans.push_back(matrix[i][j++]);
		return ans;
    }
};
