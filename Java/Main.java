import java.util.*;
import java.lang.*;
public class Main
{
    public static class Date
    {
        private final int month, day, year;
        Date(int m, int d, int y)
        {
            this.month = m;
            this.day = d;
            this.year = y;
        }
        public String toString()
        {
            String st = month + "/" + day + "/" + year;
            //String st = "Hello";
            return st;
        }
    
    }
    public static void main(String[] args)
    {
        int m, d, y;
        Scanner in = new Scanner(System.in);
        m = in.nextInt();
        d = in.nextInt();
        y = in.nextInt();
        Date date = new Date(m, d, y);
        System.out.println(date);
    }
}
