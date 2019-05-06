// Source : https://oj.leetcode.com/problems/palindrome-number/
// Author : Tianming Cao
// Date   : 2018-02-11

/**********************************************************************************
 * 
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * 
 * You could also try reversing an integer. 
 * However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
 * How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 **********************************************************************************/
package pancakeSorting;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class PancakeSorting {
	public List<Integer> pancakeSort(int[] A) {
		List<Integer> ans = new ArrayList();
		int N = A.length;

		Integer[] B = new Integer[N];
		for (int i = 0; i < N; ++i)
			B[i] = i+1;
		Arrays.sort(B, (i, j) -> A[j-1] - A[i-1]);

		for (int i: B) {
			for (int f: ans)
				if (i <= f)
					i = f+1 - i;
			ans.add(i);
			ans.add(N--);
		}

		return ans;
	}
}
