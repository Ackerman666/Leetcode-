class Solution {

    /**
     * @param Integer[][] $matches
     * @return Integer[][]
     */
    function findWinners($matches) {
        $lose_times = [];
        $player_join = [];

        foreach($matches as $i => $match){
            $lose_times[$match[1]] += 1;
            $player_join[$match[0]] = true;
            $player_join[$match[1]] = true;
        }
        ksort($player_join);

        $ans = [[], []];
        foreach($player_join as $player => $val){
            if(!isset($lose_times[$player]))
                array_push($ans[0], $player);
            elseif($lose_times[$player] == 1)
                array_push($ans[1], $player);
        }
        return $ans;
    }
}
