#include <iostream>
#include <vector>
#include <algorithm>

/**
 * BOATS TO SAVE PEOPLE - OPTIMAL SOLUTION
 *
 * Building up from the simple approach, here's the key insight:
 * If we sort people by weight, we can use a greedy strategy:
 * - Always try to pair the lightest person with the heaviest person
 * - If they can't fit together, the heaviest person must go alone
 * - This guarantees we use the minimum number of boats
 *
 * Why this works: If the lightest person can't pair with the heaviest,
 * they can't pair with anyone heavier either. So the heaviest goes alone.
 */

int numRescueBoatsOptimal(std::vector<int> &people_weights, int weight_limit)
{
    // Step 1: Sort people by weight (lightest to heaviest)
    std::sort(people_weights.begin(), people_weights.end());

    int boats_needed = 0;
    int lightest_person = 0;                         // Points to lightest remaining person
    int heaviest_person = people_weights.size() - 1; // Points to heaviest remaining person

    // Step 2: Use two pointers to pair people optimally
    while (lightest_person <= heaviest_person)
    {
        // Step 2a: We definitely need a boat for the heaviest person
        boats_needed++;

        // Step 2b: Check if lightest person can also fit in this boat
        if (people_weights[lightest_person] + people_weights[heaviest_person] <= weight_limit)
        {
            // Yes! Both can share the boat
            lightest_person++; // Lightest person is now in a boat
        }
        // If not, heaviest person goes alone (lightest_person stays the same)

        // Step 2c: Heaviest person is now in a boat, move to next heaviest
        heaviest_person--;
    }

    return boats_needed;
}

int main()
{
    int number_of_people, weight_limit;

    // Step 3: Read input
    std::cin >> number_of_people >> weight_limit;

    std::vector<int> people_weights(number_of_people);
    for (int i = 0; i < number_of_people; ++i)
    {
        std::cin >> people_weights[i];
    }

    // Step 4: Calculate minimum boats needed
    int minimum_boats = numRescueBoatsOptimal(people_weights, weight_limit);

    // Step 5: Output result
    std::cout << minimum_boats << std::endl;

    return 0;
}

/**
 * OPTIMAL ALGORITHM EXPLANATION:
 *
 * Visual example for people = [3,2,2,1], limit = 3:
 *
 * Step 1: Sort the array
 * Original:  [3, 2, 2, 1]
 * Sorted:    [1, 2, 2, 3]
 * Positions:  0  1  2  3
 *
 * Step 2: Two-pointer approach
 *
 * Initial state:
 * lightest_person = 0 (weight 1)
 * heaviest_person = 3 (weight 3)
 * boats_needed = 0
 *
 * Iteration 1:
 * - Check: can person 0 (weight 1) + person 3 (weight 3) fit? 1+3=4 > 3 ❌
 * - Person 3 goes alone in boat 1
 * - boats_needed = 1, heaviest_person = 2
 * - lightest_person stays 0
 *
 * Iteration 2:
 * - Check: can person 0 (weight 1) + person 2 (weight 2) fit? 1+2=3 ≤ 3 ✓
 * - Both go together in boat 2
 * - boats_needed = 2, lightest_person = 1, heaviest_person = 1
 *
 * Iteration 3:
 * - lightest_person = heaviest_person = 1 (same person, weight 2)
 * - This person goes alone in boat 3
 * - boats_needed = 3, lightest_person = 2, heaviest_person = 0
 *
 * Loop ends: lightest_person > heaviest_person
 *
 * Result: 3 boats
 *
 * WHY THIS GREEDY APPROACH WORKS:
 *
 * Key insight: If the lightest person can't pair with the heaviest person,
 * they can't pair with ANYONE heavier. So the heaviest person must go alone.
 *
 * Proof by contradiction:
 * - Suppose lightest (L) can't pair with heaviest (H): L + H > limit
 * - But L can pair with someone heavier than H: L + H' ≤ limit where H' > H
 * - This means L + H' ≤ limit < L + H, so H' < H
 * - Contradiction! H' can't be both > H and < H
 * - Therefore, if L can't pair with H, H must go alone
 *
 * TIME COMPLEXITY: O(n log n)
 * - Sorting takes O(n log n) time
 * - Two-pointer traversal takes O(n) time
 * - Total: O(n log n) + O(n) = O(n log n)
 * - Real-world analogy: Like organizing people by height first, then pairing
 *   shortest with tallest. The organizing (sorting) takes most of the time.
 * - With 10× more people, this takes about 33× longer (n log n growth)
 *
 * SPACE COMPLEXITY: O(1)
 * - Only using a few variables (pointers, counters)
 * - Sorting is done in-place
 * - Much better than the O(n) space in simple approach
 *
 * COMPARISON WITH SIMPLE APPROACH:
 * - Simple: O(n²) time, O(n) space
 * - Optimal: O(n log n) time, O(1) space
 * - For large inputs, optimal is much faster!
 *
 * EDGE CASES HANDLED:
 * - All people same weight: pairs them optimally
 * - Single person: gets one boat
 * - Everyone too heavy to pair: each gets own boat
 * - Perfect pairing possible: uses exactly n/2 boats
 */
