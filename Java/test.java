import java.util.*;
public class test
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        double a = 0;
        for(int i = 0; i < 4; ++i)
        {
            double e = in.nextInt();
            a += e;
        }
        System.out.println(a / 4);
    }
}
