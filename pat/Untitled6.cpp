#include <iostream>

using namespace std;

typedef struct node
{
    char sex;
    int father;
    int mother;
} person;

bool fun(person *p, int x, int y, int count)
{
    // cout << x << " " << y << ", count = " << count << endl;
    if (count <= 0 || x < 0 || y < 0)
        return false;
    if (x == y)
        return true;
    return fun(p, p[x].father, p[y].father, count - 1) || fun(p, p[x].mother, p[y].mother, count - 1) || fun(p, p[x].father, p[y].mother, count - 1) || fun(p, p[x].mother, p[y].father, count - 1);
}

int main()
{
    int n, k;
    cin >> n;
    person p[100000];
    for (int i = 0; i < 100000; i++)
    {
        p[i].father = p[i].mother = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int id, sex, father, mother;
        cin >> id;
        cin >> p[id].sex >> p[id].father >> p[id].mother;
    }
    cin >> k;
    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        if (p[x].sex == p[y].sex)
        {
            cout << "Never Mind" << endl;
            continue;
        }
        if (fun(p, x, y, 5))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
