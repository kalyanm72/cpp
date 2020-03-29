/* executing first 3 digits */
        double x=k*(log10(n));
        x=x-(int)x;              // taking fraction value only
        double ans=pow(10, x);
        ans=ans*100;
        cout<<(int)ans<<"...";
