// return the inverse of strict if in boundary

template<class T> bool in_polygon(vector<T> &a, T p, bool strict = true) {
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (on_segment(a[i], a[j], p)) return !strict;
        ans ^= ((p.y < a[i].y) - (p.y < a[j].y)) * p.cross(a[i], a[j]) > 0;
    }
    return ans;
}

template<class T> T polygon_area(vector<pt<T>> &points){
    int tam = points.size();
    T ans = 0;
    pt<T> zero(0,0);
    
    for(int i = 0; i < tam; i++){
        ans += zero.cross(points[i], points[(i+1)%tam]);
    }
    return abs(ans)/2;
}

template<class T> vector<T> convex_hull(vector<T> a, bool ic) {
    if (a.size() <= 1) return a;
    sort(a.begin(), a.end());
    vector<T> ans((int)a.size() + 1);
    int s = 0, t = 0, it = 2;
    for (; it--; s = --t, reverse(a.begin(), a.end())) {
        for (T p : a) {
            while (t - 2 >= s && ans[t - 2].ori(ans[t - 1], p) + ic <= 0) t--;
            ans[t++] = p;
        }
        if (ic && t == (int)a.size()) return a;
    }
    ans.resize(t - (t == 2 && ans[0] == ans[1]));
    return ans;
}
