import java.util.Scanner;

public class Main{
  
  public static void main(String[] args) {
    Scanner sca = new Scanner(System.in);
    double foot, inch;
    double meter = sca.nextDouble() / 100;
    sca.close();
    double temp = meter / 0.3048 * 12;
    foot = temp / 12;
    inch = temp % 12;
    System.out.println((int)foot + " " + (int)inch);
  }
  
}