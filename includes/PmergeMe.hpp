#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cctype>
#include <ctime>
#include <vector>
#include <list>
#include <utility>
#include <sstream>
#include <string>
#include <deque>

int     musique(std::vector<std::pair<int, int> >& victor, int low, int pivot);
void    nesquik(std::vector<std::pair<int, int> >& victor, int low, int pivot);
void    show_vector(std::vector<std::pair<int, int> >& victor);
void    show_vector(std::vector<int>& victor);
std::vector<int> insert_low(std::vector<std::pair<int, int> > victor);
std::vector<int> insert_low_imp(std::vector<std::pair<int, int> > victor, int nb);


void    show_deque(std::deque<int>& deq);
void    show_deque(std::deque<std::pair<int, int> >& deq);
int     musique_deck(std::deque<std::pair<int, int> >& deq, int low, int pivot);
void    nesquik_deck(std::deque<std::pair<int, int> >& deq, int low, int pivot);
std::deque<int> insert_low(std::deque<std::pair<int, int> >& deq);
std::deque<int> insert_low_imp(std::deque<std::pair<int, int> >& deq, int nb);





#endif