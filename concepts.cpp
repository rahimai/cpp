// Author: Lawan Rahim
// UNI: lr2965
/*
    This script illustrates the benefits of concepts by wrapping the functions find(), find_if() and sort()
*/

#include <iostream>
#include <ranges>
#include <concepts>
#include <string>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

// Predicates for test purposes
bool search_for(string c ) {
    return c == "Java";
}

bool IsOdd (int i) {
  return ((i%2)==1);
}

bool int_compare (int i,int j) { 
    return (i<j); 
}

bool string_compare (string i, string j) { 
    return (i<j); 
}



//find() with Iterators as input
template< input_iterator InputIt, class Val >
    requires equality_comparable_with <iter_value_t<InputIt>, Val> 
InputIt find_with_concepts(InputIt first, InputIt last, Val value)
{
    auto it = find(first, last, value);
    return it;
};

//find() with range as input
template< ranges::input_range Range, class Val >
    requires equality_comparable_with < ranges::range_value_t<Range> , Val > 
ranges::iterator_t<Range> find_with_concepts(Range&& R , Val value)
{
    auto it = find(R.begin(), R.end(), value);
    return it;
};




//find_if() with Iterators as input
template< input_iterator InputIt, indirect_unary_predicate<InputIt> Pred >
InputIt find_if_with_concepts(InputIt first, InputIt last, Pred p)
{
    auto it = find_if(first, last, p);
    return it;
}



//find_if() with range as input
template< ranges::input_range Range , indirect_unary_predicate< ranges::iterator_t<Range> > Pred > 
ranges::iterator_t<Range> find_if_with_concepts(Range&& R, Pred p)
{
    auto it = find_if(R.begin(), R.end(), p);
    return it;
}



//NOTE: For sort(), I have followed the design principle to trust programmers. That is, I have left 
//policy and comp intentionally out after talking to Prof. Stroustrup


//sort() with Iterators as input
template < random_access_iterator RandIt >
void sort_with_concepts(RandIt first, RandIt last){

    sort(first, last);

}


//sort() with range as input 
template<typename R>
concept Sortable_range = ranges::random_access_range<R> && sortable<ranges::iterator_t<R>>;
template <Sortable_range Range>
void sort_with_concepts(Range R){
    
    sort(R.begin(), R.end());

}







int main(void){

    //Initialize two containers for testing
    vector<string> string_vector = {"C", "CPP", "Java", "Python"};
    list<int> list_ints = {100, 242, 42, 45, 56, 98, 23, 45, 50};
    //int num = 1;
    
    
    
    

    //Call find_with_concepts() on both data structures with containers
    find_with_concepts(string_vector, "Java");
    find_with_concepts(list_ints, 23);

    //Call find_with_concepts() on both data structures with iterators
    find_with_concepts(string_vector.begin(), string_vector.end(), "Java");
    find_with_concepts(list_ints.begin(), list_ints.end(), 23);
    
    //Bad example for find(), yields compile-time error if uncommented and int num is also uncommented
    //find_with_concepts(num, "Java");

    




    //Call find_if_with_concepts() on both data structures with containers
    find_if_with_concepts(string_vector, search_for);
    find_if_with_concepts(list_ints, IsOdd);

    //Call find_if_with_concepts() on both data structures with iterators
    auto it1 = find_if_with_concepts(string_vector.begin(), string_vector.end(), search_for);
    auto it2 = find_if_with_concepts(list_ints.begin(), list_ints.end(), IsOdd);
    
    cout << "The first string that matched \"Java\" is " << *it1 << endl;
    cout << "The first odd number in the container is " << *it2 << endl;
    
    //Bad example for find_if(), yields compile-time error if uncommented and int num is also uncommented
    //find_if_with_concepts(list_ints, num);
    
    
    

 

    //Call sort_with_concepts() on vector with container
    sort_with_concepts(string_vector);
    
    
    //Call sort_with_concepts() on vector with iterators
    sort_with_concepts(string_vector.begin(), string_vector.end());
    
    //Bad example would give error because of missing RandIt
    //sort_with_concepts(list_ints.begin(), list_ints.end());
    
    
   
    
}