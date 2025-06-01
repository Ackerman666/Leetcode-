class Solution {
public:

   struct status {
    int x, y, energy, unpick, step;
    status(int _x, int _y, int _energy, int _unpick, int _step)
        : x(_x), y(_y), energy(_energy), unpick(_unpick), step(_step) {}
    };

    
    int minMoves(vector<string>& classroom, int energy) {
        int i = classroom.size(), j = classroom[0].size();
        int litter = 0, s_x, s_y, litter_map[21][21];
        for(int x = 0; x < i; ++x){
            for(int y = 0; y < j; ++y){
                if(classroom[x][y] == 'S'){
                    s_x = x;
                    s_y = y;
                }
                else if(classroom[x][y] == 'L'){
                    ++litter;
                    litter_map[x][y] = litter;
                }
            }
        }

        // For example, if there are 5 pieces of litter, 
        // unpick = 0000011111 in binary, meaning all 5 are uncollected (1 = not picked)
        status ini_stat(s_x, s_y, energy, ((1 << litter) - 1), 0);

        /*
        record[i][j][unpick]: keeps track of the highest remaining energy 
        at position <i, j> given the current uncollected litter state.
        */
        int record[21][21][1024];
        int d_x[4] = {1, -1, 0, 0};
        int d_y[4] = {0, 0, 1, -1};

        std::fill(&record[0][0][0], &record[0][0][0] + 21 * 21 * 1024, -1);

        queue<status> q;

        q.push(ini_stat);

        while(q.size()){
            status s = q.front();
            q.pop();

            if(s.unpick == 0)
                return s.step;

            if(s.energy){
                // Move in four directions
                for(int d = 0 ; d < 4 ; ++d){
                    int next_x = s.x + d_x[d], next_y = s.y + d_y[d];
                    if(next_x >= 0 && next_x < i && next_y >= 0 && next_y < j && classroom[next_x][next_y] != 'X'){

                        status next_s = s;
                        next_s.x = next_x, next_s.y = next_y;

                        --next_s.energy;
                        ++next_s.step;
                        if(classroom[next_s.x][next_s.y] == 'R')
                            next_s.energy = energy;
                        else if(classroom[next_s.x][next_s.y] == 'L')
                            next_s.unpick &= (~(1 << (litter_map[next_s.x][next_s.y] - 1)));

                        // If the state <i, j, unpick> is the same but the energy is not better, skip this path
                        if(record[next_s.x][next_s.y][next_s.unpick] < next_s.energy){
                            record[next_s.x][next_s.y][next_s.unpick] = next_s.energy;
                            q.push(next_s);
                        }

                    }
                }
            }   
        }
        return -1;  
    }
};
