import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int num = sca.nextInt();
		boolean flag = false;
		sca.close();
		for(int i = 0; i <= Math.sqrt(num); i++) {
			int a = i * i;
			for(int j = i + 1; j < Math.sqrt(num); j++) {
				int b = j * j;
				if(a + b == num) {		// 符合
					flag = true;
					System.out.println(i + " " + j);
					break;
				} else if(a + b > num) {
					break;
				}
			}
		}
		if(flag == false) {
			System.out.println("No Solution");
		}
	}

}