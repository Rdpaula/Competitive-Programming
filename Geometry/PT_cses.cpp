// https://github.com/kth-competitive-programming/kactl/tree/main/content/geometry
// https://victorlecomte.com/cp-geo.pdf

template<class T> struct pt {
    T x, y;
    pt(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    bool operator < (pt p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator == (pt p) const { return tie(x, y) == tie(p.x, p.y); }
    pt operator + (pt p) const { return pt(x + p.x, y + p.y); }
    pt operator - (pt p) const { return pt(x - p.x, y - p.y); }
    pt operator * (T f) const { return pt(x * f, y * f); }
    pt operator / (T f) const { return pt(x / f, y / f); }
    T dot(pt p) const { return x * p.x + y * p.y; }
    T cross(pt p) const { return x * p.y - y * p.x; }
    T cross(pt a, pt b) const { return (a - *this).cross(b - *this); }
    T ori(pt a, pt b) const { T f = cross(a, b); return (f < 0 ? -1 : (f > 0 ? 1 : 0)); }
    T dist() const { return x * x + y * y; }
    double distsq() const { return sqrt(double(dist())); }
    pt rotate(double a) const { return pt(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a)); }
    friend ostream& operator << (ostream &os, pt p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
    friend istream& operator >> (istream &is, pt &p) {
        return is >> p.x >> p.y;
    }
};

template<typename U, typename T>
U& operator >> (U& is, pt<T> &p) {
    T x, y; is >> x >> y;
    p = pt(x, y);
    return is;
}

template<class T> int sgn(T x) { return (x > 0) - (x < 0); }

template<class T> bool on_segment(T a, T b, T p) {
    return p.cross(a, b) == 0 && (a - p).dot(b - p) <= 0;
}

template<class T> int segment_points(T a, T b, int isPolygon = 0){
    return __gcd(abs(b.y - a.y), abs(b.x - a.x)) + (1 - isPolygon);
}

template<class T> vector<T> seg_int(T a, T b, T c, T d) {
    auto oa = c.cross(d, a), ob = c.cross(d, b),
         oc = a.cross(b, c), od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};
    set<T> s;
    if (on_segment(c, d, a)) s.insert(a);
    if (on_segment(c, d, b)) s.insert(b);
    if (on_segment(a, b, c)) s.insert(c);
    if (on_segment(a, b, d)) s.insert(d);
    return {s.begin(), s.end()};
}

template<class T> T closest_pair(vector<pt<T>> &vet){
    sort(all(vet));
    set<pt<ll>> st;
    ll menorDist = 9e18;
    int j = 0;
    rep(i,0,sz(vet)){
       ll d = ceil(sqrt(menorDist));
       while(j < i && d <= vet[i].x - vet[j].x){
           st.erase(pt<ll>(vet[j].y, vet[j].x));
           j++;
       }
       auto ini = st.lower_bound(pt<ll>(vet[i].y - d, vet[i].x));
       auto fim = st.upper_bound(pt<ll>(vet[i].y + d, vet[i].x));
       for(;ini != fim; ini++){
           pt<ll> act = *ini;
           menorDist = min(menorDist, pt<ll>(vet[i].x - act.y, vet[i].y - act.x).dist());
       }
       st.insert(pt<ll>(vet[i].y, vet[i].x));
    }
    return menorDist;
}
