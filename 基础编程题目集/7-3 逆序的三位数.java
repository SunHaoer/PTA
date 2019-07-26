import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int num = sca.nextInt();
		sca.close();
		boolean flag = false;
		while(num != 0) {
			if(num % 10 != 0 || flag != false) {
				System.out.print(num % 10);
				flag = true;
			}
			num /= 10;
		}
	}

}