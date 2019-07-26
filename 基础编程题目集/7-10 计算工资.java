import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int year = sca.nextInt();
		int hour = sca.nextInt();
		double ans = 0;
		sca.close();
		if(year >= 5) {
			//System.out.println("123");
			if(hour <= 40) {
				ans += hour * 50;
			} else {
				hour -= 40;
				ans += 2000 + hour * 50 * 1.5;
			}
		} else {
			if(hour <= 40) {
				ans += hour * 30;
			} else {
				hour -= 40;
				ans += 1200 + hour * 30 * 1.5;
			}
		}
		System.out.printf("%.2f", ans);
	}

}