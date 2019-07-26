import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sca = new Scanner(System.in);
		String str = sca.next();
		String flag = "AM";
		sca.close();
		int hh = 0, mm = 0;
		int i = 0;
		for(i = 0; i < str.length(); i++) {
			if(str.charAt(i) == ':') break;
			hh = hh * 10 + (str.charAt(i) - '0');
		}
		for(i = i + 1; i < str.length(); i++) {
			mm = mm * 10 + (str.charAt(i) - '0');
		}
		if(hh > 12 && hh < 24) {
			hh -= 12;
			flag = "PM";
		} else if(hh == 12) {
			flag = "PM";
		}
		System.out.println(hh + ":" + mm + " " + flag);
	}

}