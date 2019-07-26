import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		sca.close();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= i; j++) {
				System.out.printf("%d*%d=%-4d", j, i, i * j);
			}
			System.out.println();
		}
	}

}