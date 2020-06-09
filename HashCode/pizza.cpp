#include<iostream>
#include<deque>
#include<cstring>
#include<iostream>

using namespace std;

const int N = 100010;

int n, m;
int w[N];

int main(){
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    deque<int> resIdx, resVal, currIdx, currVal;
    int ans = 0;
    int maxv = 0;
    int st = n - 1;
    int sum = w[n - 1];
    currIdx.push_back(n - 1);
    currVal.push_back(w[n - 1]);
    while(!currIdx.empty()){
        st = st - 1;
        for(int i = st; i >= 0; i--){
            int temp = sum + w[i];
            if(temp == m){
                sum = temp;
                currIdx.push_back(i);
                currVal.push_back(w[i]);
                break;
            }else if(temp > m)
                continue;
            else if(temp < m){
                sum = temp;
                currIdx.push_back(i);
                currVal.push_back(w[i]);
            }
        }
        if(maxv < sum){
            maxv = sum;
            resIdx.clear(), resVal.clear();
            resIdx.assign(currIdx.begin(), currIdx.end());
            resVal.assign(currVal.begin(), currVal.end());
        }
        if(maxv == m) break;
        if(!currVal.empty()){
            int last = currVal.back();
            currVal.pop_back();
            sum -= last;
        }
        if(!currIdx.empty()){
            int last = currIdx.back();
            currIdx.pop_back();
            st = last;
        }
        
    }
    int resNum = resIdx.size();
    printf("%d\n", resNum);
    for(int i = resNum - 1; i >= 0; i--){
        ans+=w[resIdx[i]];
        printf("%d ", resIdx[i]);
    }
    cout << endl;
    cout << "final weight is: " << ans << endl;
    puts("");
    return 0;
}