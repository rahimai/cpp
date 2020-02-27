//Author: Lawan Rahim
//UNI: lr2965

#include <vector>
#include <list>
#include <map>
#include <random>
#include <chrono>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct Chunk{
    int arr[1000];
    int x;
} Chunk;

template <class Container1, class Container2>
void insert_remove(Container1 &randomset, Container2 &container)
{
    //Accepts a variable of type Container, inserts random values into the container in order and
    //removes these values in a given order
    auto it = container.begin();

    for (int x : randomset)
    {   
        Chunk rand_chunk;
        rand_chunk.x = x;

        if (container.empty())
        {
            container.insert(it, rand_chunk);
            continue;
        }

        for (it = container.begin(); it != container.end(); it++)
        {
            if (x < (*it).x)
            {
                break;
            }
        }
        container.insert(it, rand_chunk);
    }

    while (container.size() > 0)
    {
        int rdm = (rand() % (container.size()));
        auto it = container.begin();
        for (int i = 0; i < rdm + 1; i++)
        {
            if (i == rdm)
            {
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
    vector<int> TRIALS = {5, 10, 100, 1000, 10000, 100000}; 

    //Initialize array containing subarrays of the three runs with different seeds
    vector<vector<float>> all_runtimes_v;
    vector<vector<float>> all_runtimes_l;

    for (int i = 0; i < SEEDS.size(); i++)
    {
        generator.seed(SEEDS[i]);
        vector<float> runtimes_vec;
        vector<float> runtimes_lis;

        for (int j = 0; j < TRIALS.size(); j++)
        {   

            vector<Chunk> vect;
            list<Chunk> list;
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

            //Save runtimes
            runtimes_vec.push_back(chrono::duration_cast<chrono::nanoseconds>(end_v - start_v).count());
            runtimes_lis.push_back(chrono::duration_cast<chrono::nanoseconds>(end_l - start_l).count());
        }
        for (int i = 0; i < runtimes_vec.size(); i++)
        {

            cout << "Vec times"
                 << " " << runtimes_vec[i] << endl;
            cout << "List times"
                 << " " << runtimes_lis[i] << endl;
        }

        all_runtimes_v.push_back(runtimes_vec);
        all_runtimes_l.push_back(runtimes_lis);
    }
}
