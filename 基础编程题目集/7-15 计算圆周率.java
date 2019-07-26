import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		double a = 1, step1 = 1, b = 3, step2 = 3, ans = 1, pi = 1;
		double x = sca.nextDouble();
		sca.close();
		while(ans > x) {
			ans = a / b;
			pi += ans;
			step1++;
			step2 += 2;
			a *= step1;
			b *= step2;
		}
		System.out.printf("%6f", pi * 2);
	}

}