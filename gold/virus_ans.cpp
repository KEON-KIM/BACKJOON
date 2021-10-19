//@ nankisu0301 <https://www.acmicpc.net/source/10378849>

#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX 8

typedef struct _pos{
    int r;
    int c;
}Pos;

int R, C, B_len, Ans;
int Map[MAX][MAX];
Pos Birus[10];

int Rd, Wr;
Pos Queue[MAX * MAX ];
Pos Dir[] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
Pos Dir2[] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

int QueuePush(Pos p)
{
    if ((Wr + 1) % (MAX * MAX) == Rd)
        return -1;
    Queue[Wr++] = p;
    Wr %= MAX * MAX;
    return 0;
}

int QueuePop(Pos * p)
{
    if (Rd == Wr)
        return -1;
    *p = Queue[Rd++];
    Rd %= MAX * MAX;
    return 0;
}

void Input(void)
{
    int i, j;
    scanf("%d %d", &R, &C);
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%d", &Map[i][j]);
            if (Map[i][j] == 2)
                Birus[B_len++] = (Pos){i, j};
        }
    }
}

int GetSafe(void)
{
    register int i, j, safe;
    int map[MAX][MAX];
    Pos cur, next;

    memcpy(map, Map, sizeof(Map));

    for (i = 0; i < B_len; i++)
        QueuePush(Birus[i]);

    while (Rd != Wr)
    {
        QueuePop(&cur);
        for (i = 0; i < 4; i++)
        {
            next.r = cur.r + Dir[i].r;
            next.c = cur.c + Dir[i].c;
            if (next.r < 0 || next.r >= R || next.c < 0 || next.c >= C)
                continue;
            if (!map[next.r][next.c])
            {
                map[next.r][next.c] = 2;
                QueuePush(next);
            }
        }
    }

    safe = 0;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (map[i][j]) continue;
            safe++;
        }
    }

    return safe;
}

void GetAns(int r, int c, int cnt)
{
    int safe, i, r_t, c_t, flag;

    if (cnt == 3)
    {
        safe = GetSafe();
        if (Ans < safe)
            Ans = safe;
        return;
    }
    if (r == R)
        return;

    if (!Map[r][c])
    {
        flag = 0;
        for (i = 0; i < 8; i++)
        {
            r_t = r + Dir2[i].r;
            c_t = c + Dir2[i].c;
            if (r_t == -1 || r_t == R || c_t == -1 || c_t == C || Map[r_t][c_t])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            Map[r][c] = 1;
            if (c == C - 1)
                GetAns(r + 1, 0, cnt + 1);
            else
                GetAns(r, c + 1, cnt + 1);
            Map[r][c] = 0;
        }
    }
    if (c == C - 1)
        GetAns(r + 1, 0, cnt);
    else
        GetAns(r, c + 1, cnt);
}

int main(void)
{
    Input();
    GetAns(0, 0, 0);
    printf("%d", Ans);
    return 0;
}