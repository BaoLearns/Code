public class test
{
    public static void main(String args[])
    {
        int m = 0;
        for(int i = 50; i <= 100; ++i) //ö��50��100
        {
            int t = sqrt(i);
            for(int j = 2; j < t; ++j) //ÿ��i������j����[2, sqrt(i)]�ܱ�i����������
            {
                if(i % j == 0) 
                    break;
            }
            if(j >= t) m++; //�ǵ����
        }
        System.out.println(m);
    }
}
