while(mo_right < right) {
            mo_right++;
            add(arr[mo_right]);
        }
        while(mo_right > right) {
            remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            add(arr[mo_left]);
        }
        bool operator< (const structname &x ) const {
                if(l/BS != x.l/BS) return mp(l,r) < mp(x.l, x.r);
                return (l/BS & 1) ? (r < x.r) : (r > x.r);
            }
