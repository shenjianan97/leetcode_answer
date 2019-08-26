#include <iostream>
#define MAX 100
typedef int WeiType;
using namespace std;

struct Edge
{
    int no; //边的序号
    int x; //端点1序号
    int y; // 端点2序号
    WeiType weight; //权值
    bool selected; //是否被选择
};

//边集和
Edge edge[MAX];

//已找到的最小生成树其中一部分的秩  这个是用来优化并查集的
int rankk[MAX];

//已找到的最小生成树其中一部分的头结点
//用来判断一条边的2个端点是否在一个集合中，即加上这条边是否会形成回路

int parent[MAX];

//找出每一集合的头结点   //将层次变为2
int find_set(int x)
{
    if (x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}

//合并集合
void union_set(int x, int y, WeiType w, WeiType &sum)
{
    if (x == y)
        return;
    if (rankk[x] > rankk[y])
        parent[y] = x;
    else
    {
        if (rankk[x] == rankk[y])
            rankk[y]++;
        parent[x] = y;
    }
    sum += w;
}

//依据边的权值升序快速排序
void fast_sort(Edge *edge, int begin, int end)
{
    if (begin < end)
    {
        int i = begin - 1, j = begin;
        edge[0] = edge[end];
        while (j < end)
        {
            if (edge[j].weight < edge[0].weight)
            {
                i++;
                Edge temp1 = edge[i];
                edge[i] = edge[j];
                edge[j] = temp1;
            }
            j++;
        }
        Edge temp2 = edge[end];
        edge[end] = edge[i + 1];
        edge[i + 1] = temp2;
        fast_sort(edge, begin, i);
        fast_sort(edge, i + 2, end);
    }
}

int main()
{
    int cases;
    cout << "请输入案例的个数：";
    cin >> cases;
    while (cases--)
    {
        int n;
        //最小生成树的权值总和
        WeiType sum = 0;
        cout << "请输入边的个数：";
        cin >> n;
        int i;

        //初始化
        char chx, chy;
        WeiType weight;
        for (i = 1; i <= n; i++)
        {
            edge[i].no = i;
            cout << "请输入第" << i << "条边的二个端点的名称(小写字符)：";
            cin >> chx >> chy;
            edge[i].x = chx - 'a' + 1;
            edge[i].y = chy - 'a' + 1;
            cout << "这条边的权值为：";
            cin >> weight;
            edge[i].weight = weight;
            edge[i].selected = false;
            parent[edge[i].x] = edge[i].x;
            parent[edge[i].y] = edge[i].y;
            rankk[edge[i].x] = 0;
            rankk[edge[i].y] = 0;
        }

        //快排
        fast_sort(edge, 1, n);
        for (i = 1; i <= n; i++)
        {
            int x, y;
            x = find_set(edge[i].x);
            y = find_set(edge[i].y);
            //判断即加上这条边是否会形成回路
            if (x != y)
            {
                //选择这条边
                edge[i].selected = true;
                //合并不会形成回路的二个集合
                union_set(x, y, edge[i].weight, sum);
            }
        }

        cout << "最小生成树的边集为：" << endl;
        for (i = 1; i <= n; i++)
        {
            if (edge[i].selected)
            {
                cout << "序号：" << edge[i].no << "  "
                     << "端点1：" << (char)(edge[i].x + 'a' - 1) << ",端点2：" << (char)(edge[i].y + 'a' - 1) << endl;
            }
        }
        cout << "最小生成树的权值为：" << sum << endl;
    }

    return 0;
}