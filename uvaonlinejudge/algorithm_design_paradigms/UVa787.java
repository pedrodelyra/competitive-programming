import java.util.Scanner;
import java.math.BigInteger;

class UVa787 {
	private static final int INF = 999999;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int[] array = new int[128];
		while(s.hasNextInt()) {
			int n = s.nextInt(), k = 0;

			do {
				array[k++] = n;
			} while((n = s.nextInt()) != -INF);

			BigInteger max_product = new BigInteger("-99999999999999999");
			for(int i = 0; i < k; ++i) {
				BigInteger product = BigInteger.ONE;
				for(int j = i; j < k; ++j) {
					product = product.multiply(BigInteger.valueOf(array[j]));
					max_product = max_product.max(product);
				}
			}

			System.out.println(max_product);
		}
	}
}
