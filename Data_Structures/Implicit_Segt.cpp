struct Vertex {
    ll left, right;
    ll sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(ll lb, ll rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left < right) {
            ll t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t + 1, right);
        }
    }

    void add(ll k, ll x) {
        extend();
        sum += x;
        if (left_child) {
            if (k <= left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    ll get_sum(ll lq, ll rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) > min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};
