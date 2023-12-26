#include <vector>
#include <iostream>
std::vector<float> merge_sort(std::vector<float> v){
    if (v.size() <=1){
        return v;
    }
    int n = v.size()/2;
    std::vector<float> L;
    std::vector<float> R;
    std::vector<float> ans;


    for (int i =0; i < n; ++i){
        L.push_back(v[i]);
    }
    for (size_t i = n; i < v.size(); ++i){
        R.push_back(v[i]);
    }

    L = merge_sort(L);
    R = merge_sort(R);

    uint8_t p = 0,q = 0;

    while (q < L.size() && p < R.size()) {
        if( L[q] <= R[p]){
            ans.push_back(L[q]);
            q++;
        }
        else{
            ans.push_back(R[p]);
            p++;
        }
    }
    while (q < L.size()){
        ans.push_back(L[q]);
        q++;
    }
    while (p < R.size()){
        ans.push_back(R[p]);
        p++;
    }

    return ans;
}

int main(){

    std::vector<float> a = {-1.2,6.3,-322.2,0.68,1.3,9.1,-315.25};
    a = merge_sort(a);
    for (float s: a){
        std::cout << s << std::endl;
    }
}