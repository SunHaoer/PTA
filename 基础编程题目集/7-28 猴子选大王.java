import java.util.Scanner;

class Mon {
	public int index;
	public boolean flag;

	public Mon(int index, boolean flag) {
		this.index = index;
		this.flag = flag;
	}
}

public class Main {

	public static int MAX = 1010;

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		sca.close();
		Mon[] mon = new Mon[MAX];
		for (int i = 1; i <= n; i++) {
			mon[i] = new Mon(i, false);
		}
		int i = 1, ans = 1, out = 0;
		while (true) {
			if (i > n)
				i = 1;
			if (mon[i].flag == true) {
				i++;
				continue;
			}
			if (ans % 3 == 0) {
				mon[i].flag = true;
				out++;
			}
			if (out == n - 1) {
				break;
			}
			ans++;
			i++;
		}
		for (i = 1; i <= n; i++) {
			if (mon[i].flag == false) {
				System.out.println(mon[i].index);
			}
		}
	}

}