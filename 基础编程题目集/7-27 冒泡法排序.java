import java.util.Scanner;

public class Main {
	
	public static int MAX = 110;

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		int k = sca.nextInt();
		int num[] = new int[MAX];
		for(int i = 0; i < n; i++) {
			num[i] = sca.nextInt();
		}
		for(int i = n - 1; i >= k; i--) {
			for(int j = i - 1; j >= 0; j--) {
				int temp;
				if(num[i] < num[j]) {
					temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				}
			}
		}
		for(int i = 0; i < n - 1; i++) {
			System.out.print(num[i] + " ");
		}
		System.out.println(num[n-1]);
	}

}