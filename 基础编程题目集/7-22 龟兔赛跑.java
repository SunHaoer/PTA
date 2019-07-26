import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		int time = sca.nextInt();
		sca.close();
		int x1 = 0, x2 = 0;
		x1 = time * 3;
		x2 = time / 90 * 270;
		time = time % 90;
		if(time >= 0 && time < 10) {
			x2 += (time * 9);
		} else if(time >= 10 && time < 40) {
			x2 += 90;
		} else if(time >= 40 && time < 50) {
			x2 = x2 + (time - 40) * 9 + 90;
		} else if(time >= 50 && time < 80) {
			x2 += 180;
		} else if(time >= 80 && time < 90) {
			x2 = x2 + (time - 80) * 9 +180;
			
		}
		if(x1 > x2) {
			System.out.println("@_@ " + x1);
		} else if(x1 == x2) {
			System.out.println("-_- " + x1);
			
		} else if(x1 < x2) {
			System.out.println("^_^ " + x2);
		}
	}

}




