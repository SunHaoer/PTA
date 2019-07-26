import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int v = sca.nextInt();
		sca.close();
		if(v <= 60) {
			System.out.println("Speed: " + v + " - OK");
		} else {
			System.out.println("Speed: " + v + " - Speeding");
		}
	}

}