package pancakeSorting;

import org.junit.Assert;
import org.junit.Test;

import java.util.List;

/**
 * Test for 9. Palindrome Number
 */
public class TestPancakeSorting {
	@Test
	public void test() {
		PancakeSorting solution = new PancakeSorting();
		int[] stack = {19, 9, 35, 3};;
		List<Integer> flag1 = solution.pancakeSort(stack);
		for (int i : flag1) {
			System.out.println(flag1.get(i));
		}
	}
}
