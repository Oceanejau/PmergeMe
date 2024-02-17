#include "PmergeMe.hpp"

/* ---------Fonctions Victor start here---------*/

void    show_vector(std::vector<int>& victor)
{
    for (std::vector<int>::iterator it = victor.begin(); it != victor.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
}

void    show_vector(std::vector<std::pair<int, int> >& victor)
{
    for (std::vector<std::pair<int, int> >::iterator it = victor.begin(); it != victor.end(); it++)
        std::cout << (*it).first << " " << (*it).second << std::endl;
}

int     musique(std::vector<std::pair<int, int> >& victor, int low, int pivot)
{
    int     val_pivot = victor[pivot].second;
    int     i;

    i = low - 1;
    for (int j  = low; j <= pivot - 1; j++)
    {
        if (victor[j].second < val_pivot && i != j)
        {
            i++;
            std::swap(victor[i], victor[j]);
        }
    }
    std::swap(victor[i + 1], victor[pivot]);
    return (i + 1);
}

void    nesquik(std::vector<std::pair<int, int> >& victor, int low, int pivot)
{
    if (low < pivot)
    {
        int i = musique(victor, low, pivot);
        nesquik(victor, low, i - 1);
        nesquik(victor, i, pivot);
    }
}

std::vector<int> insert_low(std::vector<std::pair<int, int> > victor)
{
    std::vector<int> lower;
    std::vector<int> bigger;
    int                 count;

    for (std::vector<std::pair<int, int> >::iterator it = victor.begin(); it != victor.end(); it++)
    {
        lower.push_back(it->first);
        bigger.push_back(it->second);
    }
    count = 0;
    for (std::vector<int>::iterator it_low = lower.begin(); it_low != lower.end(); it_low++)
    {
        count = *it_low;
        std::vector<int>::iterator it_bigger = bigger.begin();
        while (it_bigger != bigger.end() && count > *it_bigger)
            ++it_bigger;
        bigger.insert(it_bigger, count);
    }
    return (bigger);
}

std::vector<int> insert_low_imp(std::vector<std::pair<int, int> > victor, int nb)
{
    std::vector<int> lower;
    std::vector<int> bigger;
    int                 count;

    for (std::vector<std::pair<int, int> >::iterator it = victor.begin(); it != victor.end(); it++)
    {
        lower.push_back(it->first);
        bigger.push_back(it->second);
    }
    lower.push_back(nb);
    count = 0;
    for (std::vector<int>::iterator it_low = lower.begin(); it_low != lower.end(); it_low++)
    {
        count = *it_low;
        std::vector<int>::iterator it_bigger = bigger.begin();
        while (it_bigger != bigger.end() && count > *it_bigger)
            ++it_bigger;
        bigger.insert(it_bigger, count);
    }
    return (bigger);
}

/* ---------Fonctions Dereck start here---------*/

void show_deque(std::deque<int>& deq)
{
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void show_deque(std::deque<std::pair<int, int> >& deq)
{
    std::cout << "Deque of pairs:" << std::endl;
    for (std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << it->first << " " << it->second << std::endl;
}

int musique_deck(std::deque<std::pair<int, int> >& deq, int low, int pivot)
{
    int val_pivot = deq[pivot].second;
    int i = low - 1;
    for (int j = low; j <= pivot - 1; ++j)
    {
        if (deq[j].second < val_pivot)
        {
            ++i;
            std::swap(deq[i], deq[j]);
        }
    }
    std::swap(deq[i + 1], deq[pivot]);
    return i + 1;
}

void nesquik_deck(std::deque<std::pair<int, int> >& deq, int low, int pivot)
{
    if (low < pivot)
    {
        int i = musique_deck(deq, low, pivot);
        nesquik_deck(deq, low, i - 1);
        nesquik_deck(deq, i + 1, pivot);
    }
}

std::deque<int> insert_low(std::deque<std::pair<int, int> >& deq)
{
    std::deque<int> lower;
    std::deque<int> bigger;

    for (std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        lower.push_back(it->first);
        bigger.push_back(it->second);
    }
    int count = 0;
    for (std::deque<int>::iterator it_low = lower.begin(); it_low != lower.end(); ++it_low)
    {
        count = *it_low;
        std::deque<int>::iterator it_bigger = bigger.begin();
        while (it_bigger != bigger.end() && count > *it_bigger)
            ++it_bigger;
        bigger.insert(it_bigger, count);
    }
    return bigger;
}

std::deque<int> insert_low_imp(std::deque<std::pair<int, int> >& deq, int nb)
{
    std::deque<int> lower;
    std::deque<int> bigger;

    for (std::deque<std::pair<int, int> >::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        lower.push_back(it->first);
        bigger.push_back(it->second);
    }
    lower.push_back(nb);
    int count = 0;
    for (std::deque<int>::iterator it_low = lower.begin(); it_low != lower.end(); ++it_low) 
    {
        count = *it_low;
        std::deque<int>::iterator it_bigger = bigger.begin();
        while (it_bigger != bigger.end() && count > *it_bigger)
            ++it_bigger;
        bigger.insert(it_bigger, count);
    }
    return bigger;
}






























   /* std::list<std::pair<int, int> >::iterator it;
    std::pair<int, int> myPair = *(lisi.end());
    int val_pivot = myPair.second;
    int i = -1;
    int j = low;
    it = lisi.begin();
    while (j <= pivot)
    {
        if (it->second < val_pivot)
        {
            i++;
            if (i != j)
            {
                std::list<std::pair<int, int> >::iterator it2 = lisi.begin();
                std::advance(it2, i);
                std::iter_swap(it, it2);
          //      std::cout << "swap " << i << "  " << j << " "<< it->second << " i <- j->" << it2->second << std::endl;
            }
        }
        ++it;
        ++j;
    }

    std::cout << "LIST == trie" << std::endl;
    for (it = lisi.begin(); it != lisi.end(); ++it)
    {
        std::pair<int, int> myPair = *it;
        std::cout << myPair.first << " " << myPair.second << " PIVOT " <<     val_pivot<< std::endl;
    }
    it = lisi.begin();
    std::advance(it, i + 1);

    std::list<std::pair<int, int> >::iterator it2 = lisi.begin();
    std::advance(it2, pivot);
    std::iter_swap(it, it2);*/


    // std::cout << "LIST == trie" << std::endl;
    // for (it = lisi.begin(); it != lisi.end(); ++it)
    // {
    //     std::pair<int, int> myPair = *it;
    //     std::cout << myPair.first << " " << myPair.second << std::endl;
    // }
    // return (i + 1);

/*
void    nesquik_l(std::list<std::pair<int, int> >& lisi, int low, int pivot)
{
    if (low < pivot)
    {
        int i = musique_l(lisi, low, pivot);
            //    std::cout << "i = l "<< i << std::endl;

        nesquik_l(lisi, low, i - 1);
        nesquik_l(lisi, i + 1, pivot);
    }
}*/


/*void nesquik_l(std::list<std::pair<int, int> >& lisi, int low, int pivot)
{
    //gpt
    if (low < pivot)
    {
        int i = musique_l(lisi, low, pivot);
                        std::cout << "i = l "<< i << std::endl;

       // show_list(lisi);
        nesquik_l(lisi, low, i - 1);
        nesquik_l(lisi, i, pivot);
        //show_list(lisi);
    }
}*/

