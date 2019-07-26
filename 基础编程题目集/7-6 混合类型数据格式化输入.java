import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		double a = sca.nextDouble();
		int b = sca.nextInt();
		char c = sca.next().charAt(0);
		double d = sca.nextDouble();
		sca.close();
		System.out.printf("%c %d %.2f %.2f\n", c, b, a, d);
	}

}