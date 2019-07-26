import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		double x = sca.nextDouble();
		sca.close();
		double y = 0;
		if(x <= 15) y = (4.0 * x) / 3;
		else y = 2.5 * x - 17.5;
		System.out.printf("%.2f", y);
	}

}