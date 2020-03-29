#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll inf=100000000000000000;
struct   AddPeriodic
{
    string add(string A, string B)
    {
         int i=0,j=0,num1=0,num2=0,num3=0,num4=0,n;
         // i j indices after .
         while(A[i]!='.')
         {
             num1*=10;
             num1+=A[i]-'0';
             i++;
         }
         j=0;
         while(B[j]!='.')
         {
             num2*=10;
             num2+=B[j]-'0';
             j++;
         }
         num1+=num2;

         string a,b,aa,bb,tes;
          //aa=recurring a= non recurr
         for(int it=i+1;it<A.length();it++)
         {
             if(A[it]=='('||A[it]==')'){
             aa+=A[it];
             continue;}
             if(aa!="")
             aa+=A[it];
             else
             a+=A[it];
         }
          //bb=recurring b= non recurr
         for(int it=j+1;it<B.length();it++)
         {
             if(B[it]=='('||B[it]==')'){
                 bb+=B[it];
             continue;}
             if(bb!="")
             bb+=B[it];
             else
             b+=B[it];
         }
         aa=aa.substr(1,aa.size()-2);
         bb=bb.substr(1,bb.size()-2);
         num3=a.size();num4=b.size();
         ll cnt=abs(num3-num4),cnt1=0,cnt2=0;
         num3=aa.size();num4=bb.size();
         //making equal size nr
         if(a.size()<b.size())
         {
               while(cnt--)
               {
                  a+=aa[cnt1];cnt1++;
                  cnt1%=num3;
               }
         }
         else
         {
             while(cnt--)
             {
                b+=bb[cnt2];cnt2++;
                cnt2%=num4;
             }
         }
         //maaking equal size r
         cnt=(num3*num4)/__gcd(num3,num4);
         // cnt--;
         cnt+=2;
         ll flg=0;
         while(cnt--)
         {
             a+=aa[cnt1];
             b+=bb[cnt2];
             if(aa[cnt]+bb[cnt2]-'0'-'0'>9)
             flg=1;
             cnt1++;cnt1%=num3;
             cnt2++;cnt2%=num4;
         }


         //aadding both
         cnt=a.size();
         // cout<<a<<endl;cout<<b<<endl;
         a=add1(a,b);
         if(flg)
         {
            a=add1(a,"1");
         }
         aa=to_string(num1);
         tes+=a[0];
         if(a.size()>cnt)
         aa=add1(aa,tes),a=a.substr(1,a.size()-1);
         aa+=".";
         num1=aa.size();
         tes.clear();
         tes.insert(tes.begin(),aa.begin(),aa.end());
         a=a.substr(0,a.size()-2);
         cnt=(num3*num4)/__gcd(num3,num4);
         if(a[a.size()-1]==a[a.size()-cnt-1])
         a=a.substr(0,a.size()-1);
         tes+=a;
         //adding recur bb=recur
         bb="";
         for(int i=tes.size()-cnt;i<tes.size();i++)
         {
             bb+=tes[i];
         }
         n=bb.size();

         //compress bb
         bb=compre(bb,n);
         tes=tes.substr(0,tes.size()-cnt);
         aa=tes.substr(num1,tes.size()-num1);
         tes=tes.substr(0,num1-1);

         //aa=nr part and copmress aa wrt bb
         aa=compre1(aa,bb);
         string tes1;
         //adjust compress
         if(bb.size()==1&&bb[0]=='9')
         {
             num3=aa.size();
             if(aa.size()){
             aa=add1(aa,"1");
             bb="0";
             if(aa.size()>num3)
             {
                 tes1+=aa[0];
                tes=add1(tes,tes1);
                aa=aa.substr(1,aa.size()-1);
            }}
            else
            {
                tes=add1(tes,"1");
                bb="0";
            }
         }
         bb.insert(bb.begin(),'(');
         bb+=")";
         tes+=".";
         tes+=aa;
         tes+=bb;
         return tes;
    }
    string compre1(string a,string b)
    {
        ll n1=a.size(),n2=b.size();
        if(a==b)
        a.clear();
        else if(n2==1)
        {
            for(int i=0;i<n1;i++)
            if(a[i]!=b[0]){
            return a;}
            return "";
        }
        return a;
    }
    string compre(string a,ll n)
    {
        string res,prev;int flg=0;
        for(int i=1;i<n;i++)
        {
            prev=a.substr(0,i);
            flg=0;
            for(int j=i;j<n;j+=i)
            {
               res=a.substr(j,i);
               if(res!=prev)
               flg=1;
            }
            if(!flg)
            {
                a=a.substr(0,i);
                break;
            }
        }
      return a;
    }
    string add1(string str1,string str2)
    {
        if (str1.length() > str2.length())
       swap(str1, str2);
        string str="";
        int n1 = str1.length(),n2=str2.length();
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int carry = 0,sum;
        for (int i=0; i<n1; i++)
        {
             sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
        for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
        if (carry)
            str.push_back(carry+'0');
            reverse(str.begin(), str.end());
            return str;
    }
};
// int main(){
// 	AddPeriodic ans;
//     auto v=ans.add(
//     		"4.0(7536822)", "2.(9596441)"
// );
//     cout<<v;
// // for(auto it:v)cout<<it<<" ";
// }
