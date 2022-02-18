
import java.util.*;

public class leet39 {

    public static void solution(ArrayList<Integer> list, int target, ArrayList<Integer> temp, int idx) {
        if (idx >= list.size()) {
            if (target == 0)
                System.out.println(temp);
            return;
        }
        if (target - list.get(idx) >= 0) {

            temp.add(list.get(idx));
            solution(list, target - list.get(idx), temp, idx);
            temp.remove(list.get(idx));
        }
        solution(list, target, temp, idx + 1);

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }
        int target = sc.nextInt();
        ArrayList<Integer> temp = new ArrayList<>();
        solution(list, target, temp, 0);
        System.out.println(temp);
        int dice  = Math.floor(Math.random()*6)+1;
        System.out.println(dice);
    }
}

/*
 * !leet code question 17 feb 2022
 * ?solve this using recursion
 * 
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 * 
 * It is guaranteed that the number of unique combinations that sum up to target
 * is less than 150 combinations for the given input.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: candidates = [2,3,6,7], target = 7
 * Output: [[2,2,3],[7]]
 * Explanation:
 * 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple
 * times.
 * 7 is a candidate, and 7 = 7.
 * These are the only two combinations.
 * Example 2:
 * 
 * Input: candidates = [2,3,5], target = 8
 * Output: [[2,2,2,2],[2,3,3],[3,5]]
 * Example 3:
 * 
 * Input: candidates = [2], target = 1
 * Output: []
 * 
 * 
 * Constraints:
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * All elements of candidates are distinct.
 * 1 <= target <= 500
 */
