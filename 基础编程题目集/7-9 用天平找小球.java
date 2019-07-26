import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int a = sca.nextInt();
		int b = sca.nextInt();
		int c = sca.nextInt();
		sca.close();
		if(a != b && a != c) {
			System.out.println("A");
		} else if(b != a && b != c) {
			System.out.println("B");
		} else {
			System.out.println("C");
		}
	}

}