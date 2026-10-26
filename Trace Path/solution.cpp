class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        int nn = s.length();

        int max_w = 0;
        int min_w = 0;
        int max_h = 0;
        int min_h = 0;

        int width = 0;
        int height = 0;

        for(int i = 0; i < nn; i++){
            if(s[i] == 'L'){
                width++;
            }else if(s[i] == 'R'){
                width--;
            }else if(s[i] == 'U'){
                height++;
            }else if(s[i] == 'D'){
                height--;
            }

            max_w = max(max_w, width);
            min_w = min(min_w, width);
            max_h = max(max_h, height);
            min_h = min(min_h, height);
        }

        int total_w = max_w - min_w + 1;
        int total_h = max_h - min_h + 1;

        return (total_w <= m && total_h <= n);
    }
};