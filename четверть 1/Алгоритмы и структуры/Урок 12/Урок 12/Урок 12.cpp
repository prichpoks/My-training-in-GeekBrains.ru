// Алгоритмы и структуру данных
// Урок 12
// Корнилов Сергей

#include <iostream>
// Задание 1
struct Trees
{
    int data;
    Trees* lefttree;
    Trees* righttree;
};
Trees** CreateBinaryTrees(int trees, int knot)
{
    srand(time(0));
    Trees** arrtrees = new Trees*[trees];
    for (int i = 0; i < trees; i++)
    {
        arrtrees[i] = 0;
    }
    Trees* ptree;
    Trees* nexttree;
    for (int i = 0; i < trees; i++)
    {
        for (int j = 0; j < knot; j++)
        {
            if (j == 0)
            {
                ptree = new Trees;
                ptree->data = rand() % 10000;
                ptree->lefttree = NULL;
                ptree->righttree = NULL;
                arrtrees[i] = ptree;
            }
            else
            {
                ptree = new Trees;
                ptree->data = rand() % 10000;
                ptree->lefttree = NULL;
                ptree->righttree = NULL;
                nexttree = arrtrees[i];
                while (nexttree)
                {
                    if (ptree->data > nexttree->data)
                    {
                        if (nexttree->righttree == NULL)
                        {
                            nexttree->righttree = ptree;
                            break;
                        }
                        nexttree = nexttree->righttree;
                        
                    }
                    else
                    {
                        if (nexttree->lefttree == NULL)
                        {
                            nexttree->lefttree = ptree;
                            break;
                        }
                        nexttree = nexttree->lefttree;
                    }
                }

            }
        }
    }
    return arrtrees;
}
int height(Trees* tree)
{
    if (tree == NULL) 
        return 0;
    return 1 + height(tree->lefttree) + height(tree->righttree);
}
int BalancedTrees(Trees** arrtrees, int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        if (height(arrtrees[i]->lefttree) - height(arrtrees[i]->righttree) < 2 && height(arrtrees[i]->lefttree) - height(arrtrees[i]->righttree) > -2)
        {
            std::cout << "Tree " << i << " is balanced\n";
            res++;
        }
    }
    return res;
}
void printtree(Trees ** p, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Tree " << i << " left = " << height(p[i]->lefttree) << " right = " << height(p[i]->righttree) << "\n\n\n";
    }
}

// Задание 2
bool BinaySearch(Trees* p, int data)
{
    if (p == NULL)
        return 0;
    if (p->data == data)
        return 1;
    if (data > p->data)
        BinaySearch(p->righttree, data);
    else
        BinaySearch(p->lefttree, data);
}


int main()
{
    Trees** p = CreateBinaryTrees(50, 10000);
    printtree(p, 50);
    int res = BalancedTrees(p, 50);
    std::cout << "balced trees - " << res << "/50 - this " << res * 100 / 50 << std::endl;
    bool r = BinaySearch(p[0], 9999);
    if (r)
        std::cout << "Number found!\n";
    else
        std::cout << "Number not found!\n";
}
