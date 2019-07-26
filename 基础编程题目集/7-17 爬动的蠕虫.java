import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();		// 总深度
		int u = sca.nextInt();		// 一分钟路程
		int d = sca.nextInt();		// 下滑路程
		int ans = 0;
		sca.close();
		while (n > 0) {
			n -= u;
			ans ++;
			if(n <= 0) break;
			n += d;
			ans ++;
		}
		System.out.println(ans);
	}

}