class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        int row[26] = {
            2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
            2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
            1, 3, 1, 3, 1, 3
        };

        vector<string> result;

        for(int i = 0; i < words.size(); i++)
        {
            int check = row[tolower(words[i][0]) - 'a'];

            for(int j = 1; j < words[i].length(); j++)
            {
                if(check != row[tolower(words[i][j]) - 'a'])
                {
                    check = -1;
                    break;
                }
            }

            if(check != -1)
            {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};