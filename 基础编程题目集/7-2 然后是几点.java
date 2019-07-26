import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int temp = sca.nextInt();
		int time = sca.nextInt();
		sca.close();
		int hh = temp / 100;
		int mm = temp % 100;
		temp = hh * 60 + mm + time;
		hh = (temp / 60);
		mm = (temp % 60);
		System.out.printf("%d%02d\n", hh, mm);
	}

}