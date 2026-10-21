class SnapshotArray {
    int snap_id = -1;
    unordered_map<int, int> toSet;
    vector<vector<pair<int, int>>> arr;
public:
    SnapshotArray(int length) {
        arr.resize(length);
        for (auto& i : arr) i.push_back({snap_id, 0});
    }
    
    void set(int index, int val) {
        toSet[index] = val;
    }
    
    int snap() {
        snap_id++;
        for (auto& p : toSet) {
            int index = p.first;
            int value = p.second;
            arr[index].push_back({snap_id, value});
        }
        toSet.clear();
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        auto& a = arr[index];
        auto it = lower_bound(a.begin(), a.end(), make_pair(snap_id, 1e9));
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
