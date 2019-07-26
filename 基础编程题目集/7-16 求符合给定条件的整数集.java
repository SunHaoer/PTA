import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		sca.close();
		int num[] = new int[24];
		int ans = 0;
		for(int i = n; i < n + 4; i++) {
			for(int j = n; j < n + 4; j++) {
				if(j == i) continue;
				for(int k = n; k < n + 4; k++) {
					if(k == i || k  == j) continue;
					num[ans++] = i * 100 + j * 10 + k;
				}
			}
		}
		Arrays.sort(num);
		for(int i = 0; i < num.length; i++) {
			System.out.print(num[i]);
			if((i + 1) % 6 != 0) System.out.print(" ");
			else System.out.println();
		}
	}
}