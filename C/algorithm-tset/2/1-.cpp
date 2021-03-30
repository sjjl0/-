#include <stdlib.h>
#include <cstring>
#include <iostream>
using namespace std;

#define M 100

char sa[1000];
char sb[1000];

typedef struct _Node{
    int s[100];//数字
    int l;//数字长度
    int c;//次幂
}Node,*pNode;

/**
 * 将n分解成两个n/2的数存储，并记录它的次幂
 * @param src 待分解的数节点
 * @param des 分解后得到的数字节点
 * @param st 从src中取数的开始位置
 * @param l 取数的长度
 */
void cp(pNode src, pNode des, int st, int l)
{
    int i, j;
    for(i=st, j=0; i<st+l; i++, j++)//从src节点数组中st位置开始
    {
        des->s[j] = src->s[i];//将这些数放入到des中
    }
    des->l = l;//长度等于取数的长度
    des->c = st + src->c; //des次幂等于从开始位置加上src次幂

}

/**
 * 合并函数
 * 分治法 大数乘法
        X = A*10^n + B
        Y = C*10^m + D
        X*Y = A*C*10^(n+m) + A*D*10^n + B*C*10^m + B*D
 * @param pa
 * @param pb
 * @param ans
 */
void add(pNode pa, pNode pb, pNode ans)
{
    int i,cc,k,palen,pblen,len;
    int ta, tb;//分别记录a，b相加时对应位上的数
    pNode temp;
    if((pa->c<pb->c))   //保证Pa的次幂大
    {
        temp = pa;
        pa = pb;
        pb = temp;
    }
    ans->c = pb->c;//结果的次幂为较小的一个的次幂
    cc = 0;//初始化进位为0
    palen=pa->l + pa->c;//a数加上次幂的总长度
    pblen=pb->l + pb->c;
    if(palen>pblen)
        len=palen;//取a b 总长度的最大值
    else
        len=pblen;
    k=pa->c - pb->c;//k为左侧补0的个数
    for(i=0; i<len-ans->c; i++) //结果的长度最长为pa，pb之中的最大长度减去最低次幂
    {
        if(i<k)
            ta = 0;
        else
            ta = pa->s[i-k];//次幂高的补0，大于低的长度后与0进行计算
        if(i<pb->l)
            tb = pb->s[i];
        else
            tb = 0;
        if(i>=pa->l+k)
            ta = 0;
        ans->s[i] = (ta + tb + cc)%10;
        cc = (ta + tb + cc)/10;
    }
    if(cc)
        ans->s[i++] = cc;
    ans->l = i;
}

void mul(pNode pa, pNode pb, pNode ans)
{
    int i, cc, w;
    int ma = pa->l>>1, mb = pb->l>>1; //长度除2
    Node ah, al, bh, bl;
    Node t1, t2, t3, t4, z;
    pNode temp;

    if(!ma || !mb) //如果其中个数为1
    {
        if(!ma)   //如果a串的长度为1，pa,pb交换，pa的长度大于等于pb的长度
        {
            temp = pa;
            pa = pb;
            pb = temp;
        }
        ans->c = pa->c + pb->c;
        w = pb->s[0];
        cc = 0;     //此时的进位为c
        for(i=0; i < pa->l; i++)
        {
            ans->s[i] = (w*pa->s[i] + cc)%10;
            cc= (w*pa->s[i] + cc)/10;
        }
        if(cc)
            ans->s[i++] = cc; //如果到最后还有进位，则存入结果
        ans->l = i;          //记录结果的长度
        return;
    }
    //分治的核心
    cp(pa, &ah, ma, pa->l-ma);  //先分成4部分al,ah,bl,bh
    cp(pa, &al, 0, ma);
    cp(pb, &bh, mb, pb->l-mb);
    cp(pb, &bl, 0, mb);

    mul(&ah, &bh, &t1);     //分成4部分相乘
    mul(&ah, &bl, &t2);
    mul(&al, &bh, &t3);
    mul(&al, &bl, &t4);

    add(&t3, &t4, ans);
    add(&t2, ans, &z);
    add(&t1, &z, ans);
}
int main() {
    Node ans,a,b;
    cout << "请输入大整数 a："<<endl;
    cin >> sa;
    cout << "请输入大整数 b：" << endl;
    cin >> sb;
    a.l = strlen(sa);//以字符串进行处理，计算长度
    b.l = strlen(sb);

    //倒向存储
    int z=0,i;
    for (int i = a.l-1; i >= 0; i--) {
        a.s[z++] = sa[i]-'0';
    }
    a.c=0;

    z=0;
    for (int i = b.l-1; i >= 0; i--) {
        b.s[z++] = sb[i] - '0';
    }
    b.c = 0;
    mul(&a, &b, &ans);
    cout << "最终结果为：";
    for (i = ans.l-1; i >= 0; i--) {
        cout<<ans.s[i];
    }
    cout << endl;
    system("pause");
}
