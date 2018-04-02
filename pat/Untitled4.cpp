#include <iostream>

using namespace std;

int find(int *set, int n, int x)
{
    if (set[x] == x || set[x] == -1)
        return set[x];
    return find(set, n, set[x]);
}

int fun(int map[][500], int *set, int n)
{
    for (int i = 0; i < n; i++) //令每个结点的祖先指向i
        set[i] = i;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (map[i][j] == 1)
            {
                set[find(set, n, j)] = find(set, n, i);
            }
        }
    }

    // cout << "----" << endl;
    for (int i = 0; i < n; i++)
    {
        // cout << set[i] << " ";
        if (set[i] == i)
            count++;
    }
    // cout << "\n----" << endl;
    return count;
}

int main()
{
	
	//freopen("in.txt","r",stdin);
    int n, m, k;
    cin >> n >> m;
    int map[500][500]={0};
    int set[n];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }
    int count = fun(map, set, n);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < n; j++) //将与x结点相连的顶点清零
            map[x][j] = map[j][x] = 0;
        int newCount = fun(map, set, n);
        // printf("%d %d\n", count, newCount);

        if (newCount - 2 >= count)
            cout << "Red Alert: City " << x << " is lost!" << endl;
        else
            cout << "City " << x << " is lost." << endl;

        if (i >= n - 1)
            cout << "Game Over." << endl;
        count = newCount;
    }

    return 0;
}

