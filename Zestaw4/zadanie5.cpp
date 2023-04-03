//
// Created by Arek on 27.03.2023.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "list"
using std::list;

#include "forward_list"
using std::forward_list;

#include <iterator>
using std::iterator_traits;
using std::forward_iterator_tag;
using std::random_access_iterator_tag;
using std::bidirectional_iterator_tag;

template <typename Iter>
int operacja_impl(Iter i, bidirectional_iterator_tag)
{
    cout << "Iterator dwukierunkowy.\n";
    return 1;
}

template <typename Iter>
int operacja_impl(Iter i, forward_iterator_tag)
{
    cout << "Iterator jednokierunkowy.\n";
    return 2;
}

template <typename Iter>
int operacja_impl(Iter i, random_access_iterator_tag)
{
    cout << "Iterator o swobodnym dostepie.\n";
    return 3;
}

template <typename Iter>
inline int operacja(Iter i)
{
    return operacja_impl(i,
                         typename iterator_traits<Iter>::iterator_category());
}


int main()
{
    forward_list<int> flista{1, 2, 3, 4, 5};
    operacja(flista.begin());

    list<int> lista{1, 2, 3, 4, 5};
    operacja(lista.begin());

    vector<int> v{1, 2, 3, 4, 5};
    operacja(v.begin());


    return 0;
}