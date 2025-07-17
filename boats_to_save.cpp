#include <iostream>
#include <vector>

using namespace std;

/*
array -> people
people[i] -> weight of ith person
infinte number of boats
maximum weight -> limit.
each boat carries most 2 [sum < limit]
*/

int numRescueBoats(vector<int> &people, int limit)
{
    int boatCount = 0;
    for (int i = 0; i < people.size(); i++)
    {
        if (people[i] == limit)
        {
            boatCount++;
            continue;
        }
        for (int j = i + 1; j < people.size(); j++)
        {

            if (people[i] + people[j] == limit)
            {
                boatCount++;
                continue;
            }
            else if (people[j] == limit)
            {
                boatCount++;
                continue;
            }
            boatCount++;
        }
    }
    return boatCount;
}

int main()
{
    vector<int> people = {3, 5, 3, 4};
    cout << numRescueBoats(people, 5) << endl;
    return 0;
}