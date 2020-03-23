#include <chrono>
#include <vector>
#include <random>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int compare_reverse (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}


int compare_str(void const *a,void const *b){

    char const * const* aa=(char const **)a;
    char const * const * bb=(char const **)b;

    return strcmp(*aa, *bb);
}

int compare_str_reverse(void const *a,void const *b){

    char const * const* aa=(char const **)a;
    char const * const * bb=(char const **)b;

    return strcmp(*bb, *aa);
}


int main(){

    //Initialize random engine and define uniform integer distribution
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 900000000000);
    srand(time(NULL));
    uniform_int_distribution<int> distribution_str(0, 25);
    uniform_int_distribution<int> distribution_short(0, 7);
    uniform_int_distribution<int> distribution_long(8, 32);



    //Initialize vector for random integers 
    vector<int> random_ints_s1;
    vector<string> random_string1;
    vector<string> random_string2;
    vector<const char *> string1_pointers;
    vector<const char *> string2_pointers;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";




    while (random_ints_s1.size() < 1000000){

    random_ints_s1.push_back(distribution(generator));
    
    }


    int len1 = distribution_short(generator);
    int len2 = distribution_long(generator);

    string temp1;
    string temp2;

    while (random_string2.size() < 10){


        if (temp1.size() > len1){

            random_string1.push_back(temp1);
            temp1.clear();
            len1 = distribution_short(generator);

        }

        if (temp2.size() > len2){

            random_string2.push_back(temp2);
            temp2.clear();
            len2 = distribution_long(generator);

        }

        char rand = alphabet[distribution_str(generator)];
        temp1.push_back(rand);
        temp2.push_back(rand);

    }

    
    //Copy vector of random integers 
    vector<int> random_ints_s2 = random_ints_s1;
    vector<int> random_ints_q1 = random_ints_s1;
    vector<int> random_ints_q2 = random_ints_s1;

    //Test vectors 
    //vector<int> test_vector {4, 2, 3, 1, 7, 5, 9, 8, 6, 10};
    /*
    vector<string> test_vector {"ZGH", "DBE", "AAA", "ZZZ", "GEI", "POL"};
    vector<const char *> test_pointers;

    for (int i = 0; i < test_vector.size(); i++){

        test_pointers.push_back(test_vector[i].c_str());

    } 
    */

    //sort(test_vector.begin(), test_vector.end());
    //std::sort(test_vector.begin(), test_vector.end(), greater <> ());
    //qsort(test_pointers.data(), test_vector.size(), sizeof(const char *), compare_str);

    //sort(random_ints_s1.begin(), random_ints_s1.end());
    //sort(random_ints_s2.begin(), random_ints_s2.end(), greater <> ());

    //qsort(&random_ints_q1[0], random_ints_q1.size(), sizeof(int), compare);
    //qsort(&random_ints_q2[0], random_ints_q2.size(), sizeof(int), compare_reverse);


    //Sort with strings

    for (int i = 0; i < random_string1.size(); i++){

        string1_pointers.push_back(random_string1[i].c_str());
        string2_pointers.push_back(random_string2[i].c_str());
    }

    sort(random_string1.begin(), random_string1.end());
    sort(random_string1.begin(), random_string1.end(), greater <> ());

    //qsort(string1_pointers.data(), random_string1.size(), sizeof(const char *), compare_str);
    //qsort(string1_pointers.data(), random_string1.size(), sizeof(const char *), compare_str_reverse);
    //qsort(string2_pointers.data(), random_string2.size(), sizeof(const char *), compare_str);
    //qsort(string2_pointers.data(), random_string2.size(), sizeof(const char *), compare_str_reverse);

    /*
    for (auto x: random_string1){
        cout << x << " "<< endl;
    }
    */

   for (auto x: random_string1){
       cout << x << " " << endl;
   }
   
   for (auto x: string1_pointers){
        cout << x << " ";
    }



}