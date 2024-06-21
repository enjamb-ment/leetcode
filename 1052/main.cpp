/* 1052. Grumpy Bookstore Owner
There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.
*/


class Solution {
public:
    int useSecretTechnique(int minutes, vector<int> customers, vector<int> grumpy) {
        int notCustomer = 0;

        for (int i = 0; i < minutes; i++)
        {
            notCustomer += customers[i] * grumpy [i]; //oh sure, doesn't include not grumpy (0) items
        }

        int maxNotCustomer = notCustomer;

        for (int i = minutes; i < customers.size(); i++)
        {
            notCustomer += customers[i] * grumpy[i];
            notCustomer -= customers[i - minutes] * grumpy[i - minutes];

            maxNotCustomer = max(maxNotCustomer, notCustomer);  // pick whichever's higher
        }
        return maxNotCustomer;
    }

    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int allCustomer = 0;
        allCustomer = useSecretTechnique(minutes, customers, grumpy); //unnecessary... could've built the helper function into the main
        for (int i = 0; i < customers.size(); i++)
        {
            allCustomer += customers[i] * (1 - grumpy[i]);
        }

        return allCustomer;

    }
};


/* Psuedocode:
    for customers[] !grumpy[], find max(secretTechnique())
        sliding window to identify range(m) where customer[i to i+m] vs customer[i to i+m] grumpy[i to i+m] changes the most.

    sum all customers[] !grumpy[]


*/
