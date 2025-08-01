// ## How It Works 🤔
//
// The solution involves three main passes over the data structure:
//
//     Build a Trie: First, we convert the input paths into a Trie. Each node in the Trie represents a folder, and the path from the root to a node represents its absolute path.
//
//     Serialize and Mark Duplicates: This is the most critical step. We perform a post-order traversal (visiting children before the parent) on the Trie.
//
//         For each node (folder), we generate a serialized string that uniquely represents its entire sub-folder structure. This string is created by combining the names of its children and their own serialized structures, sorted alphabetically. For example, a folder a with subfolders x and y might have a signature like x()y().
//
//         We use a hash map to store these signatures and a list of all nodes that produce them.
//
//         After the traversal, we iterate through the map. If any signature is associated with more than one node, we know those nodes represent identical folders, and we mark all of them for deletion.
//
//     Collect Remaining Paths: Finally, we perform a pre-order traversal (visiting the parent before children) on the Trie. We collect the paths of all folders that have not been marked for deletion. When we encounter a deleted folder, we stop traversing that entire branch, effectively deleting it and all its subfolders.
//


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

// ===================================================================
// ## Step 1: Define the Data Structure (Trie)
// ===================================================================
// A Trie is a tree-like data structure perfect for representing a file system.
// Each node will represent a single folder.
struct TrieNode {
    // The name of the folder (e.g., "a", "x").
    std::string name;
    
    // Flag to mark this folder for deletion if it's a duplicate.
    bool is_deleted = false;
    
    // A map to store child folders. Using std::map is crucial because it
    // automatically keeps the children sorted by name (alphabetically).
    // This ensures that folder structures are serialized consistently.
    std::map<std::string, TrieNode*> children;
};


// ===================================================================
// ## Step 3: Helper function to Serialize Sub-tree Structures
// ===================================================================
// This function performs a post-order traversal (children first, then parent)
// to create a unique string signature for any given folder's sub-tree.
// It also populates the 'structures' map to group all folders that have
// the same signature.
std::string serialize(TrieNode* node, std::map<std::string, std::vector<TrieNode*>>& structures) {
    // Base Case: A folder with no subfolders has an empty structure.
    if (node->children.empty()) {
        return "";
    }

    // Recursively build the signature from the signatures of all children.
    std::string signature = "";
    // Because we use std::map for children, this loop processes them alphabetically.
    for (auto const& [name, child] : node->children) {
        // The signature includes the child's name and its own sub-tree structure.
        // e.g., "x(y())" means a folder 'x' containing a folder 'y'.
        signature += name + "(" + serialize(child, structures) + ")";
    }

    // We only care about duplicates of non-empty folders.
    // We add the current node to the list of nodes that share this signature.
    if (!signature.empty()) {
        structures[signature].push_back(node);
    }
    
    // Return the generated signature for the parent to use.
    return signature;
}


// ===================================================================
// ## Step 5: Helper function to Collect Remaining Paths
// ===================================================================
// This function performs a pre-order traversal (parent first, then children)
// to build the final list of paths that were not marked for deletion.
void collectPaths(TrieNode* node, std::vector<std::string>& current_path, std::vector<std::vector<std::string>>& ans) {
    // Add the current folder to the path we are building.
    current_path.push_back(node->name);
    
    // This path is valid, so add a copy of it to our final answer list.
    ans.push_back(current_path);

    // Recursively visit all children that have NOT been marked for deletion.
    for (auto const& [name, child] : node->children) {
        if (!child->is_deleted) {
            collectPaths(child, current_path, ans);
        }
    }
    
    // Backtrack: After visiting all children of this node, remove it from the
    // current path so we can correctly build paths for other branches.
    current_path.pop_back();
}


// ===================================================================
// ## Main Function to Orchestrate the Process
// ===================================================================
std::vector<std::vector<std::string>> deleteDuplicateFolders(std::vector<std::vector<std::string>>& paths) {
    // --- Pass 1: Build the Trie from the input paths ---
    TrieNode* root = new TrieNode(); // The root of our file system.
    for (const auto& path : paths) {
        TrieNode* current = root;
        for (const std::string& folderName : path) {
            // If a subfolder doesn't exist, create it.
            if (current->children.find(folderName) == current->children.end()) {
                current->children[folderName] = new TrieNode{folderName};
            }
            // Move down to the next node in the path.
            current = current->children[folderName];
        }
    }

    // --- Pass 2: Serialize all sub-trees and identify duplicates ---
    // This map will store structure signatures and all nodes that have them.
    std::map<std::string, std::vector<TrieNode*>> structures;
    serialize(root, structures); // This populates the 'structures' map.

    // --- Pass 3: Mark all nodes that belong to a duplicate structure ---
    for (auto const& [signature, nodes] : structures) {
        // If a signature is shared by more than one node, it's a duplicate.
        if (nodes.size() > 1) {
            for (TrieNode* node : nodes) {
                node->is_deleted = true;
            }
        }
    }

    // --- Pass 4: Collect the paths of all non-deleted folders ---
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> current_path;
    // Start the collection process from the children of the root.
    for (auto const& [name, child] : root->children) {
        if (!child->is_deleted) {
            collectPaths(child, current_path, ans);
        }
    }

    return ans;
}


// ===================================================================
// ## Main function for execution and demonstration
// ===================================================================
int main() {
    // Define an example input file system.
    std::vector<std::vector<std::string>> paths = {
        {"a"}, {"c"}, {"a", "x"}, {"c", "x"}, {"a", "x", "y"},
        {"c", "x", "y"}, {"b"}, {"b", "x"}, {"b", "x", "y"}, {"b", "z"}
    };

    // Call the main logic function.
    std::vector<std::vector<std::string>> result = deleteDuplicateFolders(paths);

    // Print the results in a readable format.
    std::cout << "Remaining folders after deletion:" << std::endl;
    for (const auto& path : result) {
        std::cout << "/";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << (i == path.size() - 1 ? "" : "/");
        }
        std::cout << std::endl;
    }

    return 0;
}
