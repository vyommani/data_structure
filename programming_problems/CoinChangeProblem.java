/*
 * Find the minimum number of coins needed to make change.
 * Input: An integer money and positive integers coin1,......coinn.
 * Output: The minimum number of coins with denominations coin1, coin2,...coinn
 * that change money.
 *
 * We have below coins 10,5,2,1 rupee coins.
 */


public class CoinChangeProblem {

    static int coins[] = {10, 5, 2, 1};

    static long arr[][];

    /*
     * Below is the greedy algo which is not optimal.Given the denominations
     * 1,5,10,20,25, and wish to make change for 40 cents,the greedy algorithm
     * would give us 25, 10, 5, but the best solution only requires 2 coins(20,20)
     * cent coins.
     */

    static int greedyChange(int money) {
        int minNumberOfcoins = 0;
        while (money > 0) {
            // use greedy approach and always choose the max value coin.
            if (money >= 10) {
                minNumberOfcoins++;
                money -= 10;
            } else if (money >= 5) {
                minNumberOfcoins++;
                money -= 5;
            } else if (money >= 2) {
                minNumberOfcoins++;
                money -= 2;
            } else {
                minNumberOfcoins++;
                money -= 1;
            }
        }
        return minNumberOfcoins;
    }

    /*
     * The minimum coin change problem is the problem of using the minimum numer
     * of coins to make change for a particular amount of cents n using the given
     * set of denaminations d1, d2,.....dm.
     *
     * Below Recursive formulation, which is optimal.
     * C(N, m) = min(C(N,m - 1), C(N - Sm, m) + 1)
     * C(N, m) = 0, N =0
     * C(N, m) = INT_MAX, N < 0
     * C(N, m) = INT_MAX, N >=1, m <=0
     *
     * if the result is <= 0 then it means it is impossible to make change for N
     * with the given coins.
     */

    static long minNumOfCoins(int money, int m) {
        if (money == 0)
            return 0;
        else if (money < 0)
            return Integer.MAX_VALUE; // you can not give change
        else if (money >= 1 && m < 0)
            return Integer.MAX_VALUE; // you can not give change
        else {
            if (arr[money][m] != -1)
                return arr[money][m];
            else {
                long mnc = Math.min(minNumOfCoins(money, m - 1), 1 + minNumOfCoins(money - coins[m], m));
                arr[money][m] = mnc;
                return mnc;
            }
        }
    }

    /*
     * This function will return the number of ways you can give the change. this problem is defined more precisely
     * as below:
     *
     * Given an integer N and set of integers S = { S1, S2,....,Sm}, how many ways can one express N as a linear
     * combination of S = {S1, S2,....Sm} with non-negative coefficients
     *
     * We are trying to count the number of distinct sets.
     * The set of solutions for this problem C(N,m) can be partitioned into two sets
     * there are thoes sets that do not contain any Sm and thoes sets that contains at least 1 Sm.
     *
     * C(N, m) = 1 N = 0 (one sol we have no money exactly one way to solve
     * C(N, m) = C(N, m-1) + C(N-Sm, m)
     * C(N, m) = 0 N < 0
     * C(N, m) = 0 N >= 1 && m <= 0
     */
    static long countNumOfWays(int money, int m) {
        if (money == 0)
            return 1;
        else if (money < 0)
            return 0;
        else if (money >= 1 && m <= 0)
            return 0;
        else {
            if (arr[money][m] != -1)
                return arr[money][m];
            else {
                long now = countNumOfWays(money, m - 1) + countNumOfWays(money - coins[m], m);
                arr[money][m] = now;
                return now;
            }
        }
    }

    public static void main(String[] args) {
        int money = 999;
        arr = new long[money + 1][11]; // 10 is the max number of coin
        resetArray(arr);
        System.out.println("Minimum number of coin needed is : " + minNumOfCoins(money, coins.length - 1));
        resetArray(arr);
        System.out.println("number of ways you can choose is : " + countNumOfWays(money, coins.length - 1));
    }

    private static void resetArray(long arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++)
                arr[i][j] = -1;
        }
    }
}
