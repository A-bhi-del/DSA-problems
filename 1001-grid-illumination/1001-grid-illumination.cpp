class Solution {
public:
    vector<int> op_r = {-1, 0, 1, 1, 1, 0, -1, -1};
    vector<int> op_c = {1, 1, 1, 0, -1, -1, -1, 0};
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                                 vector<vector<int>>& queries) {
        map<pair<int,int>,bool>mat;
        unordered_map<int, int> mp_i;
        unordered_map<int, int> mp_j;
        unordered_map<int, int> dia;
        unordered_map<int, int> o_dia;

        for (auto lamp : lamps) {
            int i = lamp[0];
            int j = lamp[1];
            int d = i - j;
            int od = i + j;

            if(mat[{i,j}] != true){
                mp_i[i]++;
                mp_j[j]++;
                dia[d]++;
                o_dia[od]++;
                mat[{i,j}] = true;
            }
        }

        int x = 0;
        vector<int> ans(queries.size(), 0);
        // auto display = [&]() {
        //     for (int i = 0; i < n; i++) {
        //         for (int j = 0; j < n; j++) {
        //             cout << mat[i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout<<endl;

        //     cout<<"mp_i"<<endl;
        //     for(auto it : mp_i){
        //         cout<<it.first<<" "<<it.second<<endl;
        //     }
        //     cout<<endl<<"mp_j"<<endl;
        //     for(auto it : mp_j){
        //         cout<<it.first<<" "<<it.second<<endl;
        //     }
        //     cout<<endl<<"dia"<<endl;
        //     for(auto it : dia){
        //         cout<<it.first<<" "<<it.second<<endl;
        //     }
        //     cout<<endl<<"o_dia"<<endl;
        //     for(auto it : o_dia){
        //         cout<<it.first<<" "<<it.second<<endl;
        //     }
        //     cout<<endl;
        // };

        // display();
        for (auto query : queries) {
            int i = query[0];
            int j = query[1];
            int d = i - j;
            int od = i + j;
            
            if (mp_i.count(i) > 0 || mp_j.count(j) > 0 || dia.count(d) > 0 ||
                o_dia.count(od) > 0) {
                ans[x] = 1;
            }

            if (mat[{i, j}] == true) {
                mp_i[i]--;
                if (mp_i[i] == 0) {
                    mp_i.erase(i);
                }

                mp_j[j]--;
                if (mp_j[j] == 0) {
                    mp_j.erase(j);
                }

                if (dia.count(d) > 0) {
                    dia[d]--;
                    if (dia[d] == 0) {
                        dia.erase(d);
                    }
                }

                if (o_dia.count(od) > 0) {
                    o_dia[od]--;
                    if (o_dia[od] == 0) {
                        o_dia.erase(od);
                    }
                }
                mat[{i,j}] = false;
            }

            for (int k = 0; k < 8; k++) {
                int ni = i + op_r[k];
                int nj = j + op_c[k];
                int nd = ni - nj;
                int nod = ni + nj;

                if (ni < 0 || ni >= n || nj < 0 || nj >= n) {
                    continue;
                }

                if (mat[{ni, nj}] == true) {
                    mp_i[ni]--;
                    if (mp_i[ni] == 0) {
                        mp_i.erase(ni);
                    }

                    mp_j[nj]--;
                    if (mp_j[nj] == 0) {
                        mp_j.erase(nj);
                    }

                    if (dia.count(nd) > 0) {
                        dia[nd]--;
                        if (dia[nd] == 0) {
                            dia.erase(nd);
                        }
                    }

                    if (o_dia.count(nod) > 0) {
                        o_dia[nod]--;
                        if (o_dia[nod] == 0) {
                            o_dia.erase(nod);
                        }
                    }

                    mat[{ni, nj}] = false;
                }
            }
            // display();
            x++;
        }


        return ans;
    }
};