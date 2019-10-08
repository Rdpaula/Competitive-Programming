struct pt{
    ll x;
    ll y;
};
pt u;
bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
ll operator%(const pt &a, const pt &b){//z-coordinate of cross product
    return a.x * b.y - a.y * b.x;
}
ll operator*(const pt &a, const pt &b){//dot product
    return a.x * b.x + a.y * b.y;
}
bool A(const pt &p){
    return u % p > 0 || (u % p == 0 && u * p > 0);
}
bool operator<(const pt &a, const pt &b){
    return (A(a) == A(b) && a % b > 0) || (A(a) && !A(b));
}