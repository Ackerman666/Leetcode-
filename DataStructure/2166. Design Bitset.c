


typedef struct {
    unsigned int ones, size;
    unsigned char bit_string[];
} Bitset;


Bitset* bitsetCreate(int size) {
    int byte_size = (size + 7) / 8;
    Bitset *b_set = malloc(sizeof(Bitset) + byte_size);
    b_set->size = size;
    memset(b_set->bit_string, 0, byte_size);
    b_set->ones = 0;
    return b_set;
}

void bitsetFix(Bitset* obj, int idx) {
    unsigned int loc = idx>>3;
    unsigned char pre = obj->bit_string[loc];
    obj->bit_string[loc] |=   (1 << (7 - (idx & 7)));
    obj->ones += (pre == obj->bit_string[loc]) ? 0 : 1;
   
}

void bitsetUnfix(Bitset* obj, int idx) {
     unsigned int loc = idx>>3;
    unsigned char pre = obj->bit_string[loc];
    obj->bit_string[loc] &=   ~(1 << (7 - (idx & 7)));
    obj->ones -= (pre == obj->bit_string[loc]) ? 0 : 1;
}

void bitsetFlip(Bitset* obj) {


    for(int i=0 ; i< (obj->size+7)>>3 ; ++i){
        obj->bit_string[i] ^= 0xff;
    }

    obj->ones =  obj->size - obj->ones;
    
}

bool bitsetAll(Bitset* obj) {
    return obj->size == obj->ones;   
}


bool bitsetOne(Bitset* obj) {

    return obj->ones;
}

int bitsetCount(Bitset* obj) {
    return obj->ones;
}



char* bitsetToString(Bitset* obj) {
   
    char *str = malloc(obj->size+1);
    for(int i=0 ; i<obj->size; ++i){
        str[i] = (obj->bit_string[(i>>3)] & (1 << (7 - (i & 7)))) ? '1' : '0';
    }
    str[obj->size] = '\0';
    return str;
}

void bitsetFree(Bitset* obj) {
    free(obj);
}



/**
 * Your Bitset struct will be instantiated and called as such:
 * Bitset* obj = bitsetCreate(size);
 * bitsetFix(obj, idx);
 
 * bitsetUnfix(obj, idx);
 
 * bitsetFlip(obj);
 
 * bool param_4 = bitsetAll(obj);
 
 * bool param_5 = bitsetOne(obj);
 
 * int param_6 = bitsetCount(obj);
 
 * char* param_7 = bitsetToString(obj);
 
 * bitsetFree(obj);
*/
