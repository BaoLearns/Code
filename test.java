public class test
{
    public static void main(String args[])
    {
        int m = 0;
        for(int i = 50; i <= 100; ++i) //枚举50到100
        {
            int t = sqrt(i);
            for(int j = 2; j < t; ++j) //每个i，若有j属于[2, sqrt(i)]能被i除尽，则不是
            {
                if(i % j == 0) 
                    break;
            }
            if(j >= t) m++; //是的情况
        }
        System.out.println(m);
    }
}
