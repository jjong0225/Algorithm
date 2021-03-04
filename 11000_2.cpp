    #include<iostream>
    #include<vector>
    #include<algorithm>
    #include<queue>

    using namespace std;

    bool my_operator(pair<int,int> lp, pair<int,int> rp)
    {
        if(lp.second != rp.second)
            return lp.second < rp.second;
        else
            return lp.first < rp.first;
    }

    struct op_class {
        bool operator()(pair<int,int> &lp, pair<int,int> &rp)
        {
            if(lp.first != rp.first)
                return lp.first < rp.first;
            else
                return lp.second < rp.second;
        }
    };

    vector<pair<int,int>> input_v;
    int main()
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            int a,b;
            cin >> a >> b;
            input_v.push_back(make_pair(a,b));
        }
        sort(input_v.begin(), input_v.end(), my_operator);
        priority_queue<pair<int,int>,vector<pair<int,int>>, op_class> pq;
        pq.push(input_v[n-1]);
        int output = 1;
        for(int i=n-2; i>=0; i--)
        {
            if(pq.top().first >= input_v[i].second)
            {
                pq.pop();
                pq.push(input_v[i]);
            }
            else
            {
                pq.push(input_v[i]);
                output++;
            }
        }
        cout << output;
    }
