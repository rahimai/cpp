#include <vector>
#include <list>
#include <map> 
#include <random>
#include <chrono>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

/*

template <class Container1, class Container2>
void insert_remove_map(Container1 &randomset, Container2 &container)
{
    //Accepts a variable of type Container, inserts random values into the container in order and
    //removes these values in a given order

    for (int x: randomset)
    {
        container.insert({0, x});

    }

    auto xter =  container.size();

    for (int r: randomset)
    {   int y = rand();
        int rdm = (y % (container.size()));
        auto it = container.begin();
        for(int i = 0; i < rdm + 1; i++){
            if (i == rdm){
                container.erase(it);
                break;
            }
            it++;
        }
        
    }
}

*/

template <class Container1, class Container2>
void insert_remove(Container1 &randomset, Container2 &container)
{
    //Accepts a variable of type Container, inserts random values into the container in order and
    //removes these values in a given order
    auto it = container.begin();

    for (int x: randomset)
    {

        if (container.empty())
        {
            container.insert(it, x);
            continue;
        }

        for (it = container.begin(); it != container.end(); it++)
        {
            if (x < *it)
            {
                break;
            }
            

        }
        container.insert(it, x);
    }

    for (int r: randomset)
    {  
        int rdm = (rand() % (container.size()));
        auto it = container.begin();
        for(int i = 0; i < rdm + 1; i++){
            if (i == rdm){
                container.erase(it);
                break;
            }
            it++;
        }
        
    }
}

int main(void)
{

    //Initialize random engine and define uniform integer distribution
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, 900000000000);

    //Create a vector of SEEDS
    vector<int> SEEDS = {42, 43, 44};

    //Initialize and assign values to a vector containing the different trial numbers
    //vector<int> TRIALS = {1, 5, 10, 100, 1000, 10000, 100000, 200000, 300000, 400000};
    vector<int> TRIALS = {1, 5, 100, 1000, 20000};

    //Initialize array containing subarrays of the three runs with different seeds
    vector<vector<float>> all_runtimes_v;
    vector<vector<float>> all_runtimes_l;
    vector<vector<float>> all_runtimes_m;


    for (int i = 0; i < SEEDS.size(); i++)
    {
        generator.seed(SEEDS[i]);
        vector<float> runtimes_vec;
        vector<float> runtimes_lis;
        //vector<float> runtimes_map;

        for (int j = 0; j < TRIALS.size(); j++)
        {
            vector<int> vect;
            list<int> list;
            //map<int, int> hashmap;
            unordered_set<int> random_set;

            while (random_set.size() < TRIALS[j])
            {
                random_set.insert(distribution(generator));
            }

            //Analyze runtime of vector
            auto start_v = chrono::steady_clock::now();

            insert_remove(random_set, vect);

            auto end_v = chrono::steady_clock::now();

            //Analyze runtime of list
            auto start_l = chrono::steady_clock::now();

            insert_remove(random_set, list);

            auto end_l = chrono::steady_clock::now();

            //Analyze runtime of map
            //auto start_m = chrono::steady_clock::now();

            //insert_remove_map(random_set, hashmap);

            //auto end_m = chrono::steady_clock::now();

            //Save runtimes
            runtimes_vec.push_back(chrono::duration_cast<chrono::microseconds>(end_v - start_v).count());
            runtimes_lis.push_back(chrono::duration_cast<chrono::microseconds>(end_l - start_l).count());
            //runtimes_lis.push_back(chrono::duration_cast<chrono::microseconds>(end_m - start_m).count());
        }
        for (int i = 0; i < runtimes_vec.size(); i++){

            cout << "Vec times" << " " << runtimes_vec[i]<< endl;
            cout << "List times" << " " << runtimes_lis[i]<<endl;
        }

        all_runtimes_v.push_back(runtimes_vec);
        all_runtimes_l.push_back(runtimes_lis);
    }
}
