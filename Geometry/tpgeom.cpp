/// sort counter clockwise in (0,0) -> if change the center subtract from coordinates
struct Point{
    ll x, y;
    Point(){}
    Point(ll x, ll y): x(x), y(y){}
};

ll operator%(const Point &a, const Point &b){//z-coordinate of cross product
    return a.x * b.y - a.y * b.x;
}
ll operator*(const Point &a, const Point &b){//dot product
    return a.x * b.x + a.y * b.y;
const Point u(0, 1); /// Point that the line will begin
bool A(const Point &p){
    return u % p > 0 || (u % p == 0 && u * p > 0);
}
bool operator<(const Point &a, const Point &b){
    return (A(a) == A(b) && a % b > 0) || (A(a) && !A(b));
}

// case when points a and b are on the same line from the center, 
// can be used to solve this edge case in sort
// check which point is closer to the center
// int d1 = (a.x - center.x) * (a.x - center.x) + (a.y - center.y) * (a.y - center.y);
// int d2 = (b.x - center.x) * (b.x - center.x) + (b.y - center.y) * (b.y - center.y);
// return d1 > d2;