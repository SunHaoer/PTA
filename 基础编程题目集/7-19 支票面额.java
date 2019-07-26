import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		sca.close();
		boolean flag = false;
		for(int y = 0; y < 100; y++) {
			for(int f = 0; f < 100; f++) {
				if(98 * f - 199 * y == n) {
					flag = true;
					System.out.println(y + "." + f);
				}
			}
		}
		if(flag == false) {
			System.out.println("No Solution");
		}
	}

}
