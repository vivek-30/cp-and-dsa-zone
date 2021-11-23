import java.io.*;
import java.util.ArrayList;

public class Main {

  private static boolean isPalindromic(int num) {
    if(num == 1) return true;

    String s = Integer.toBinaryString(num);

    int i = 0, j = s.length() - 1;
    while(i <= j) {
      if(s.charAt(i) != s.charAt(j)) return false;
      i++;
      j--;
    }

    return true;
  }

  public static void main(String args[]) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int t = Integer.parseInt(br.readLine());

    while(t-->0) {
      int n = Integer.parseInt(br.readLine());

      ArrayList<Integer> res = new ArrayList<>();
      int curr = n;
      boolean flag = false;
    
      for(int i = 100000; i >= 1; i--) {
        while(curr - i >= 0 && isPalindromic(i)) {
          if(curr == 0) {
            flag = true;
            break;
          }
          curr -= i;
          res.add(i);
        }

        if(flag) break;
      }

      System.out.println(res.size());
      for(Integer i: res) System.out.print(i + " ");

      System.out.println();
    }
  }
}
