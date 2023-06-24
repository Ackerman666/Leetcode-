class Solution {

/**
 * @param Integer[] $values
 * @return Integer
 */
function maxScoreSightseeingPair($values) {
    $sum = [];                      // values[i] + i
    $diff = [];                     // values[j] - j
    $len = count($values);
    $max = PHP_INT_MIN;             // 當前紀錄到最大的 values[j] - j;
    $ans = 0;

    for($i=0 ; $i<$len ; $i++){
        $sum[$i] = $values[$i] + $i;
        $diff[$i] = $values[$i] - $i;
    }

    for($i=$len-2 ; $i>=0 ; $i--){
        $max = max($max, $diff[$i+1]);
        $ans = max($ans, $sum[$i]+$max);
    }

    return($ans);




}
}