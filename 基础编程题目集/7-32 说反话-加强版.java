import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException {
		Scanner sca = new Scanner(System.in);
		BufferedReader read = null;
		read = new BufferedReader(new InputStreamReader(System.in));
		String strs = read.readLine();
		sca.close();
		strs = strs.trim();
		String str[] = strs.split("\\s+");
		if(str.length != 0) {
			for(int i = str.length - 1; i > 0; i--) {
				System.out.print(str[i] + " ");
			}
			System.out.println(str[0]);			
		}
	}
}


/*
 * 测试点4运行超时
 */
