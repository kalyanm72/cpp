string ner(string num)
{
    string s=num,res=s;
    reverse(res.begin(),res.end());
    int f=2;
        for(int i=0;i<s.length();i++){
            if(s[i]!='9'){
                f=0;
                break;
            }
        }
        if(f==2){
            res.clear();
            res+="1";
            for(ll i=0;i<s.length()-1;i++)
            res+="0";
            res+="1";
            return res;
        }
        if(res==s)
        return s;
        int n=s.length();
        f=0;
        for(int i=0;i<n/2;i++){
            if(s[i]<s[n-1-i]){
                f=-1;
            }
            else if(s[i]>s[n-1-i]){
                f=1;
            }
            s[n-1-i]=s[i];
        }
        int i;
        if(n%2==0){
            i=n/2-1;
        }
        else{
            i=n/2;
        }
        if(f!=1){
            while(s[i]=='9'){
                s[i]='0';
                s[n-1-i]='0';
                i--;
            }
            s[i]++;
            s[n-1-i]=s[i];
        }
        return s;
}
