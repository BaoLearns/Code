#include <iostream>
using namespace std;
int main()
{
    string start, end, ans;
    while(cin>>start && start != "ENDOFINPUT")
    {
        
        while(true)
        {
            ans.clear();
            cin>>end;
        if( end != "END")
        {
            int len = end.length();
            for(int i = 0; i < len; ++i)
            {
                if(end[i] >= 'A' && end[i] <= 'Z')
                {
                    if(end[i] < 'F')
                        ans += (end[i] + 21);
                    else
                        ans += (end[i] - 5);
                }
                else
                    ans += end[i];
            }
            cout<<ans<<' ';
        }
        else 
            break;
        }
       cout<<endl; 
    }
    return 0;
}
