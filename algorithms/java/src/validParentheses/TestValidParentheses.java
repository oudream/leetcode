package validParentheses;

import org.junit.Assert;
import org.junit.Test;
/**
 * Test for 125. Valid Parentheses
 */
public class TestValidParentheses {
	@Test
	public void test() {
		ValidParentheses solution = new ValidParentheses();
		String str1 = "((({(([]()))})))";
		Assert.assertTrue(solution.isValid(str1));
		String str2 = "()()()()";
		Assert.assertTrue(solution.isValid(str2));
		String str3 = "(((((((()";
		Assert.assertTrue(!solution.isValid(str3));
		String str4 = "((()[()]))";
		Assert.assertTrue(solution.isValid(str4));
	}
}
