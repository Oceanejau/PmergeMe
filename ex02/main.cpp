#include "PmergeMe.hpp"

int     main(int ac, char **av)
{
    int nb;
    int nbr;
    int y = 0;
    int t;
    int s;
    int xx;
    std::vector<int> sorted;
    std::deque<int> desorted;
    std::vector<std::pair<int, int> > victor;
    std::list<std::pair<int, int> > lisi;
    std::deque<std::pair<int, int> > dereck;

    std::cout << std::endl;
    if (ac < 2)
    {
        std::cout << "Error: expecting ./PmergeMe nb nb nb" << std::endl;
        return (-1);
    }
    xx = 0;
    for (int x = 1; x < ac; x++)
    {
        xx++;
        for (int y = 1; y < ac; y++)
        {
            std::istringstream isisi(av[x]);
            std::istringstream isis(av[y]);
            isis >> t;
            isisi >> s;
            if (t == s && y != xx)
            {
                std::cout << "Error: Doubles" << std::endl;
                return (-1);
            }
        }
        std::istringstream isis(av[x]);
        if (isis >> nb)
        {
            if (!isis.eof())
            {
                std::cout << "Error: Numbers only" << std::endl;
                return (-1);
            }
            if (nb < 0)
            {
                std::cout << "Error: only positive numbers" << std::endl;
                return (-1);
            }
        }
        else
        {
            std::cout << "Error: extraction failed - not an int" << std::endl;
            return (-1);
        }
        if ((x % 2) == 0)
        {
            /*   vector    */
            victor.push_back(std::make_pair(nbr, nb));
            std::pair<int, int> myPair = victor[y];
            if (myPair.first > myPair.second)
            {
                myPair.first = nb;
                myPair.second = nbr;
                victor.pop_back();
                victor.push_back(myPair);
            }
            /*   deque    */
            dereck.push_back(std::make_pair(nbr, nb));
            std::pair<int, int>& myPari = dereck.back();
            if (myPari.first > myPari.second)
                std::swap(myPari.first, myPari.second);
            y++;
        }
        else
            nbr = nb;
    }
    /* ---------Timer Victor start here---------*/
    clock_t         start = clock();
    nesquik(victor, 0, victor.size() - 1);
    if ((ac - 1) % 2)
        sorted = insert_low_imp(victor, nbr);
    else
        sorted = insert_low(victor);
    clock_t         time_victor = clock();
    /* ---------Timer Victor end here---------*/
    std::cout << "Victor: ";
    show_vector(sorted);
    time_victor = time_victor - start;
    /* ---------Timer Dereck start here---------*/
    start = clock();
    desorted = insert_low(dereck);
    nesquik_deck(dereck, 0, dereck.size() - 1);
    if ((ac - 1) % 2)
        desorted = insert_low_imp(dereck, nb);
    else
        desorted = insert_low(dereck);
    clock_t         time_dereck = clock();
    /* ---------Timer Dereck end here---------*/
    time_dereck = time_dereck - start;
    std::cout << "Deque:   ";
    show_deque(desorted);
    /* ---------Final Print---------*/
    std::cout << "\nBefore:  ";
    for (int x = 1; x < ac; x++)
    {
        std::cout << av[x] << " ";
    }
    std::cout << std::endl;
    std::cout << "\nAfter:  ";
    show_vector(sorted);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::[" << "vector" << "]: " << time_victor << " us"<< std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::[" << "deque" << "]:  " << time_dereck << " us" << std::endl;
    return (0);
}