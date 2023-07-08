class DisjoinSet{

    private:
        vector<int> parent;
        vector<int> size;

    public:
        DisjoinSet(int memberSize){
            this->parent.reserve(memberSize);
            this->size.reserve(memberSize);
            for(int i=0 ; i<memberSize ; i++){
                this->parent[i] = i;
                this->size[i] = 1; 
            }
        }

        int find_parent(int member){
            if(this->parent[member] != member){
                member = find_parent(this->parent[member]);
            }
            return(member);
        }

        void Union(int memberA, int memberB){
            int pA = find_parent(memberA);
            int pB = find_parent(memberB);

            if(pA != pB){
                if(size[pA] > size[pB]){
                    this->parent[pB] = pA;
                }
                else
                    this->parent[pA] = pB;
            }
        }
};