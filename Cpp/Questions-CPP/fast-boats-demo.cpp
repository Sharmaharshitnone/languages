#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/**
 * BOATS TO SAVE PEOPLE - COMPREHENSIVE DEMONSTRATION
 *
 * This program demonstrates both the simple and optimal approaches
 * with detailed step-by-step output to help understand the algorithms.
 */

// Simple approach implementation
int numRescueBoatsSimple(std::vector<int> people_weights, int weight_limit, bool show_steps = false)
{
    if (show_steps)
    {
        std::cout << "\n=== SIMPLE APPROACH (First-Fit Greedy) ===" << std::endl;
        std::cout << "People weights: [";
        for (int i = 0; i < people_weights.size(); i++)
        {
            std::cout << people_weights[i];
            if (i < people_weights.size() - 1)
                std::cout << ", ";
        }
        std::cout << "], limit: " << weight_limit << std::endl;
        std::cout << std::endl;
    }

    int total_people = people_weights.size();
    std::vector<bool> already_in_boat(total_people, false);
    int boats_needed = 0;

    for (int first_person = 0; first_person < total_people; ++first_person)
    {
        if (already_in_boat[first_person])
        {
            continue;
        }

        boats_needed++;
        already_in_boat[first_person] = true;

        if (show_steps)
        {
            std::cout << "Boat " << boats_needed << ": Person " << first_person
                      << " (weight " << people_weights[first_person] << ")";
        }

        // Try to find a partner
        for (int second_person = first_person + 1; second_person < total_people; ++second_person)
        {
            if (already_in_boat[second_person])
            {
                continue;
            }

            if (people_weights[first_person] + people_weights[second_person] <= weight_limit)
            {
                already_in_boat[second_person] = true;
                if (show_steps)
                {
                    std::cout << " + Person " << second_person
                              << " (weight " << people_weights[second_person] << ") "
                              << "= " << people_weights[first_person] + people_weights[second_person];
                }
                break;
            }
        }

        if (show_steps)
        {
            std::cout << std::endl;
        }
    }

    return boats_needed;
}

// Optimal approach implementation
int numRescueBoatsOptimal(std::vector<int> people_weights, int weight_limit, bool show_steps = false)
{
    if (show_steps)
    {
        std::cout << "\n=== OPTIMAL APPROACH (Two-Pointer Greedy) ===" << std::endl;
        std::cout << "Original: [";
        for (int i = 0; i < people_weights.size(); i++)
        {
            std::cout << people_weights[i];
            if (i < people_weights.size() - 1)
                std::cout << ", ";
        }
        std::cout << "], limit: " << weight_limit << std::endl;
    }

    std::sort(people_weights.begin(), people_weights.end());

    if (show_steps)
    {
        std::cout << "Sorted:   [";
        for (int i = 0; i < people_weights.size(); i++)
        {
            std::cout << people_weights[i];
            if (i < people_weights.size() - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
        std::cout << std::endl;
    }

    int boats_needed = 0;
    int lightest_person = 0;
    int heaviest_person = people_weights.size() - 1;

    while (lightest_person <= heaviest_person)
    {
        boats_needed++;

        if (show_steps)
        {
            std::cout << "Boat " << boats_needed << ": ";
            std::cout << "Heaviest person (weight " << people_weights[heaviest_person] << ")";
        }

        if (people_weights[lightest_person] + people_weights[heaviest_person] <= weight_limit)
        {
            if (show_steps)
            {
                std::cout << " + Lightest person (weight " << people_weights[lightest_person] << ") ";
                std::cout << "= " << people_weights[lightest_person] + people_weights[heaviest_person];
            }
            lightest_person++;
        }
        else
        {
            if (show_steps)
            {
                std::cout << " (goes alone, " << people_weights[lightest_person]
                          << " + " << people_weights[heaviest_person] << " = "
                          << people_weights[lightest_person] + people_weights[heaviest_person]
                          << " > " << weight_limit << ")";
            }
        }

        if (show_steps)
        {
            std::cout << std::endl;
        }

        heaviest_person--;
    }

    return boats_needed;
}

// Function to run comparison tests
void runComparison()
{
    std::vector<std::vector<int>> test_cases = {
        {1, 2},
        {3, 2, 2, 1},
        {1, 2, 2, 3, 4, 5},
        {5, 5, 5, 5},
        {1, 1, 1, 1, 1, 1}};

    std::vector<int> limits = {3, 3, 5, 5, 3};

    std::cout << "BOATS TO SAVE PEOPLE - ALGORITHM COMPARISON" << std::endl;
    std::cout << "===========================================" << std::endl;

    for (int i = 0; i < test_cases.size(); i++)
    {
        std::cout << "\n"
                  << std::string(50, '=') << std::endl;
        std::cout << "TEST CASE " << (i + 1) << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        std::vector<int> people = test_cases[i];
        int limit = limits[i];

        int result_simple = numRescueBoatsSimple(people, limit, true);
        int result_optimal = numRescueBoatsOptimal(people, limit, true);

        std::cout << "\nRESULTS:" << std::endl;
        std::cout << "Simple approach:  " << result_simple << " boats" << std::endl;
        std::cout << "Optimal approach: " << result_optimal << " boats" << std::endl;

        if (result_simple == result_optimal)
        {
            std::cout << "✅ Both approaches agree!" << std::endl;
        }
        else
        {
            std::cout << "❌ Approaches disagree - check implementation!" << std::endl;
        }
    }
}

int main()
{
    // Run comprehensive demonstration
    runComparison();

    std::cout << "\n"
              << std::string(60, '=') << std::endl;
    std::cout << "COMPLEXITY COMPARISON" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "Simple Approach:  Time O(n²), Space O(n)" << std::endl;
    std::cout << "Optimal Approach: Time O(n log n), Space O(1)" << std::endl;
    std::cout << std::endl;
    std::cout << "For large inputs, optimal approach is significantly faster!" << std::endl;
    std::cout << "Example: 1000 people → Simple: ~1M operations, Optimal: ~10K operations" << std::endl;

    return 0;
}

/**
 * PROGRAM OUTPUT EXPLANATION:
 *
 * This demonstration shows:
 * 1. How both algorithms process the same input
 * 2. Step-by-step decisions made by each approach
 * 3. Final results comparison
 * 4. Performance characteristics
 *
 * Key observations:
 * - Simple approach: First-fit strategy, may not be optimal pairing
 * - Optimal approach: Always tries best possible pairing
 * - Both give same result but optimal is much faster for large inputs
 * - Optimal approach's sorting step enables better decision making
 *
 * Educational value:
 * - Shows how sorting can transform a hard problem into an easy one
 * - Demonstrates greedy algorithm design and proof techniques
 * - Illustrates the importance of choosing the right data structure/approach
 */
