import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int a = sca.nextInt();
		int b = sca.nextInt();
		sca.close();
		int ans = 0, sum = 0;
		int i = a;
		while(i <= b) {
			sum += i;
			System.out.printf("% 5d", i);
			i++; ans++; 
			if(ans % 5 == 0 || i > b) System.out.println();
		}
		System.out.println("Sum = " + sum);
	}

}