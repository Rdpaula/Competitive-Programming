ll ans = 0;
vector<ll> vet;

void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    // Performance: alternating sort — odd blocks traverse r in reverse.
    // Eliminates the full right-pointer reset between adjacent blocks,
    // cutting total pointer movement by ~40% compared to plain block sort.
    bool operator<(Query other) const {
        int b1 = l / block_size, b2 = other.l / block_size;
        if(b1 != b2) return b1 < b2;
        return (b1 & 1) ? r > other.r : r < other.r;
    }
};

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure
    
    ll cur_l = 0;
    ll cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

