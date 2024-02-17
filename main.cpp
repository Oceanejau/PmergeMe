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
            /*if (xx != y)
            {
          //  std::cout << av[xx] <<  "==" << av[y] << " && xx= " << xx << " y =" << y  << std::endl;
                if (av[xx] == av[y])
                {
                    std::cout << "FUCKING same" << std::endl;
                }
            }*/
           // std::cout << av[xx] <<  "xx - " << xx <<"same?" << av[y] << std::endl;
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
            


            dereck.push_back(std::make_pair(nbr, nb));
            std::pair<int, int>& myPari = dereck.back(); // Accéder à la dernière paire ajoutée
            if (myPari.first > myPari.second)
            {
                // Échanger les éléments de la paire si nécessaire
                std::swap(myPari.first, myPari.second);
            }
            //show_deque(dereck);

            y++;
        }
        else
        {
            nbr = nb;
        }
    }
  
   /*
   deque
   finde
        ici lancer timer
   */
    clock_t         start = clock();
    nesquik(victor, 0, victor.size() - 1);
    if ((ac - 1) % 2)
    {
        sorted = insert_low_imp(victor, nbr);
    }
    else
        sorted = insert_low(victor);
    std::cout << "Victor: ";
    show_vector(sorted);
   
    clock_t         time_victor = clock();
    time_victor = time_victor - start;
    start = clock();
    desorted = insert_low(dereck);
    nesquik_deck(dereck, 0, dereck.size() - 1);
    if ((ac - 1) % 2)
    {
        desorted = insert_low_imp(dereck, nb);
    }
    else
        desorted = insert_low(dereck);
    

    clock_t         time_dereck = clock();
    time_dereck = time_dereck - start;
    std::cout << "Deque:   ";
    show_deque(desorted);
/*
    fin timer + print affichage
*/


    //musique_l(lisi, 0, lisi.size() - 1);
   // nesquik_l(lisi, 0, lisi.size() - 1);
    //double elapsed_seconds = static_cast<double>(time_victor - start) / CLOCKS_PER_SEC; // Temps en secondes
   // double elapsed_microseconds = elapsed_seconds * 1e6;

    std::cout << "\nBefore: ";
    for (int x = 1; x < ac; x++)
    {
        std::cout << av[x] << " ";
    }
    std::cout << std::endl;
    std::cout << "\nAfter: ";
        show_vector(sorted);
    std::cout << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::[" << "vector" << "] : " << time_victor << " clock ticks /s" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::[" << "deque" << "] : " << time_dereck << " clock ticks /s" << std::endl;
    
    return (0);
}