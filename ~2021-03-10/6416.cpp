#include<iostream>
#include<map>

using namespace std;

int main ()
{
    int counter = 1;
    while(1)
    {
        bool break_flag = 0;
        int tree_flag = 1;
        int edge_count = 0;
        map<int,int> root_map;
        
        while(1)
        {
            int a, b = 0;
            cin >> a >> b;
            if(a == 0 && b == 0)
                break;
            else if (a < 0 && b < 0)
            {
                break_flag = 1;
                break;
            }
            edge_count++;
            if(tree_flag == -1)
            {
                continue;
            }

            int a_root,b_root = 0;

            try{
                a_root = root_map.at(a);
            }
            catch(out_of_range)
            {
                a_root = -1;
            }

            try{
                b_root = root_map.at(b);
            }
            catch(out_of_range)
            {
                b_root = -1;
            }

            // 이중 travle, v_2는 반드시 root여야 한다(그렇지 않으면 두개의 parent를 갖는다)
            if(b_root != -1 && b_root != b) 
            {
                tree_flag = -1;
            }

            // 순환 구조 형성
            if( (b_root != -1 && a_root != -1)&&(a_root == b_root) )
            {
                tree_flag = -1;
            }

            // 새 node의 추가
            if(a_root == -1)
            {
                root_map.insert(pair<int,int>(a,a));
                a_root = a;
            }
            if(b_root == -1)
            {
                root_map.insert(pair<int,int>(b,a_root));
                continue;
            }

            // 다른 tree의 합병
            // find all value=b and replace it with a_root
            for(map<int,int>::iterator tree_iterator=root_map.begin();  tree_iterator!=root_map.end(); ++tree_iterator)
            {
                if(tree_iterator->second == b_root)
                    tree_iterator->second = a_root;
            }
        }
        if(break_flag == 1)
            break;


        map<int,int>::iterator tree_iterator=root_map.begin();
        int main_root = tree_iterator->second;
        for(;tree_iterator!=root_map.end(); ++tree_iterator)
        {
            if(main_root != tree_iterator->second)
            {
                tree_flag = -1;
            }
        }
        if(root_map.size() != edge_count + 1)
            tree_flag = -1;

        // tree 판별 코드
        if((tree_flag == 1 && edge_count > 0) || root_map.size()==0)
        {
            cout << "Case " << counter << " is a tree.\n";
        }
        else
        {
            cout << "Case " << counter << " is not a tree.\n";
        }
        counter++;
    }
}