#include <iostream>
#include <vector>
#include <algorithm>

/**
 * BOATS TO SAVE PEOPLE - SIMPLE APPROACH
 * 
 * Problem in simple terms:
 * You have people with different weights and boats that can carry at most 2 people
 * with a weight limit. Find the minimum number of boats needed.
 * 
 * Examples:
 * 1. people = [1,2], limit = 3 → 1 boat (both people together: 1+2=3 ≤ 3)
 * 2. people = [3,2,2,1], limit = 3 → 3 boats 
 *    - Boat 1: person with weight 3 (alone)
 *    - Boat 2: people with weights 2+1=3 (together) 
 *    - Boat 3: person with weight 2 (alone)
 * 
 * Constraints:
 * - Each boat carries at most 2 people
 * - Total weight in boat ≤ limit
 * - All people have weight ≤ limit (so everyone can fit in at least one boat)
 */

int numRescueBoatsSimple(std::vector<int>& people_weights, int weight_limit) {
    int total_people = people_weights.size();
    std::vector<bool> already_in_boat(total_people, false);
    int boats_needed = 0;
    
    // Step 1: Try to pair each person with someone else
    for (int first_person = 0; first_person < total_people; ++first_person) {
        // Step 1a: Skip if this person already has a boat
        if (already_in_boat[first_person]) {
            continue;
        }
        
        // Step 1b: This person definitely needs a boat
        boats_needed++;
        already_in_boat[first_person] = true;
        
        // Step 1c: Try to find a partner for this person
        for (int second_person = first_person + 1; second_person < total_people; ++second_person) {
            // Skip if second person already has a boat
            if (already_in_boat[second_person]) {
                continue;
            }
            
            // Step 1d: Check if both people can fit in same boat
            if (people_weights[first_person] + people_weights[second_person] <= weight_limit) {
                // Found a partner! Put them in the same boat
                already_in_boat[second_person] = true;
                break;  // Each boat can only carry 2 people max
            }
        }
    }
    
    return boats_needed;
}

int main() {
    int number_of_people, weight_limit;
    
    // Step 2: Read input
    std::cin >> number_of_people >> weight_limit;
    
    std::vector<int> people_weights(number_of_people);
    for (int i = 0; i < number_of_people; ++i) {
        std::cin >> people_weights[i];
    }
    
    // Step 3: Calculate minimum boats needed
    int minimum_boats = numRescueBoatsSimple(people_weights, weight_limit);
    
    // Step 4: Output result
    std::cout << minimum_boats << std::endl;
    
    return 0;
}

/**
 * ALGORITHM EXPLANATION:
 * 
 * Visual example for people = [3,2,2,1], limit = 3:
 * 
 * Initial state:
 * People:     [3, 2, 2, 1]
 * Positions:   0  1  2  3
 * In boat:    [F, F, F, F]  (F = false, not in boat yet)
 * 
 * Step 1: Process person 0 (weight 3)
 * - boats_needed = 1, already_in_boat[0] = true
 * - Try to pair with person 1 (weight 2): 3+2=5 > 3 ❌
 * - Try to pair with person 2 (weight 2): 3+2=5 > 3 ❌  
 * - Try to pair with person 3 (weight 1): 3+1=4 > 3 ❌
 * - Person 0 goes alone in boat 1
 * 
 * Step 2: Process person 1 (weight 2)
 * - boats_needed = 2, already_in_boat[1] = true
 * - Try to pair with person 2 (weight 2): 2+2=4 > 3 ❌
 * - Try to pair with person 3 (weight 1): 2+1=3 ≤ 3 ✓
 * - Person 1 and 3 go together in boat 2
 * - already_in_boat[3] = true
 * 
 * Step 3: Process person 2 (weight 2)
 * - boats_needed = 3, already_in_boat[2] = true
 * - No more people to pair with
 * - Person 2 goes alone in boat 3
 * 
 * Step 4: Person 3 already has a boat, skip
 * 
 * Result: 3 boats
 * 
 * TIME COMPLEXITY: O(n²)
 * - For each person (n people), we check all remaining people (up to n people)
 * - This gives us n × n = n² operations in worst case
 * - Real-world analogy: Like organizing a party where you check every guest 
 *   against every other guest to see if they can share a table
 * - With 10× more people, this takes about 100× longer
 * 
 * SPACE COMPLEXITY: O(n)
 * - We use an array to track which people already have boats
 * - The array size grows linearly with number of people
 * 
 * WHY O(n²): In the worst case, we might need to check every person against 
 * every other person to find valid pairings. For n people, that's roughly
 * n×n/2 comparisons.
 * 
 * EDGE CASES HANDLED:
 * - Single person: gets their own boat
 * - Everyone too heavy to pair: each gets their own boat
 * - Everyone can pair perfectly: uses n/2 boats
 * - Mixed weights: optimal pairing based on first-fit strategy
 */
