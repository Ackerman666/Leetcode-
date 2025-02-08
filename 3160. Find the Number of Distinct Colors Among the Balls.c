/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct{
    int idx;
    int color;
    UT_hash_handle hh;
} BallColor;

typedef struct{
    int color;
    int appears;
    UT_hash_handle hh;
} ColorCount;


int* queryResults(int limit, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {  

    BallColor *ball_color = NULL, *ball_entry = NULL;
    ColorCount *color_count = NULL, *color_entry = NULL;

    int *result = (int*)malloc(queriesSize * sizeof(int));
    int diff_colors = 0;

    for(int i=0 ; i<queriesSize ; i++){

        int idx = queries[i][0], color = queries[i][1];

        HASH_FIND_INT(ball_color, &idx, ball_entry);
        if(ball_entry){
            HASH_FIND_INT(color_count, &ball_entry->color, color_entry);
            --color_entry->appears;
            diff_colors -= !(color_entry->appears);  
        }
        else{
            ball_entry = (BallColor*)malloc(sizeof(BallColor));
            ball_entry->idx = idx;
            HASH_ADD_INT(ball_color, idx, ball_entry);
        }
        ball_entry->color = color;
        HASH_FIND_INT(color_count, &ball_entry->color, color_entry);
        if(color_entry == NULL){
            color_entry = (ColorCount*)malloc(sizeof(ColorCount));
            color_entry->color = color;
            color_entry->appears = 0;
            HASH_ADD_INT(color_count, color, color_entry);
        }
        diff_colors += !(color_entry->appears);
        ++color_entry->appears;
        
        result[i] = diff_colors;
    }

    BallColor *ball_next;
    ColorCount *color_next;

    
    HASH_ITER(hh, ball_color, ball_entry, ball_next) {
        HASH_DEL(ball_color, ball_entry);
        free(ball_entry);
    }
    HASH_ITER(hh, color_count, color_entry, color_next) {
        HASH_DEL(color_count, color_entry);
        free(color_entry);
    }
    

    *returnSize = queriesSize;
    return result;

}
