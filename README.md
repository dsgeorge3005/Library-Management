# AVL Tree Library Management
Collaborators: Mohamed Afraz, Aatreya Mohana Sundaram Dave Shejo George

## 📚 Overview

The **AVL Tree Library Management** project is designed to manage library operations efficiently using the AVL Tree data structure. It provides functionalities to add, remove, and search for books swiftly while maintaining a balanced tree structure.

## 🎯 Features
- **Fast Operations**: Add, remove, and search for books with logarithmic time complexity.
- **Self-Balancing**: Automatically balances the tree after operations to ensure performance.
- **User-Friendly Interface**: Simple and intuitive interaction to manage library data easily.

## ⚙️ Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/dsgeorge3005/Library-Management.git
   ```
2. Navigate into the project directory:
   ```bash
   cd Library-Management
   ```
3. Install dependencies (if any):
   ```bash
   npm install
   ```

## 🔧 Usage

To use the AVL Tree Library Management system:
1. Import the library:
   ```python
   from avl_tree import AVLTree
   ```
2. Create an AVL tree instance:
   ```python
   library = AVLTree()
   ```
3. Add books, remove books, or search for them.

---

## 📖 Technical Documentation

### Choosing of Method

#### 1. Guaranteed Performance (O(log n))
When you add books to a standard Binary Search Tree (BST) in sorted order (like ISBN 101, 102, 103), the tree gets "skewed" and starts to look like a linked list.

**The Problem:** Searching for a book in a skewed tree takes O(n) time, which is too long for big collections.

**The AVL Answer:** An AVL tree balances itself. It checks the balance on its own after every insertion and does rotations to keep the tree "short" and "flat." This makes sure that search, insert, and delete operations always take O(log n) time, even in the worst case.

#### 2. Efficiency Over Alternatives
Your project documentation correctly identifies why other structures fail for a dynamic library:

- **Arrays:** While they are easy to access, inserting or deleting a book is "costly" because you have to shift every other element to maintain order.
- **Linked Lists:** These make insertion easy, but searching is "slow" because you have to check records one by one.
- **B-Trees:** These are great for massive disk-based systems but are "more complex than needed" for this specific project.
- **AVL Tree:** It provides the "best choice" because it balances simplicity with high performance for dynamic applications.

#### 3. Memory and Space Management
- **Space Complexity:** The tree uses O(n) space because it stores exactly one node for every book record.
- **Recursive Efficiency:** Because the tree is always balanced, the "height" is limited. This means if you use recursion for your functions, the extra memory used by the "function call stack" is very small—only O(log n).

### Time Complexity

| Operation | Complexity | Explanation |
|-----------|-----------|-------------|
| Search | O(log n) | The tree height is kept at log n, so finding a specific ISBN takes very few steps. |
| Insert | O(log n) | Includes searching for the spot and performing rotations to rebalance. |
| Delete | O(log n) | Includes finding the node, removing it, and rebalancing the tree. |
| Display (Inorder) | O(n) | To print every book in sorted order, the system must visit every single node once. |

### Space Complexity

The space complexity is divided into the actual storage and the temporary memory used during operations.

- **Total Storage (O(n)):** The tree requires one node for every book record stored. Each node contains the ISBN, Title, Author, height, and two child pointers.
- **Auxiliary Space (O(log n)):** When using recursion for insertion, deletion, or searching, the system uses the function call stack. Because the AVL tree is balanced, the maximum depth of these recursive calls is limited to the height of the tree, which is O(log n).

### Algorithm

1. **Start:** Initialize an empty AVL tree.
2. **Input:** Take book details (ISBN, Title, Author) from the user.
3. **Search/Insert:** Compare the new ISBN with the Root.
   - If smaller, move to the Left child; if larger, move to the Right.
   - Repeat until an empty spot (NULL) is found and insert the new Book node.
4. **Update Height:** After insertion, travel back up the tree to update the height of every ancestor node.
5. **Check Balance:** Calculate the Balance Factor for these nodes.
6. **Rebalance (Rotations):** If the Balance Factor is not between -1 and 1, perform one of the four rotations to restore order:
   - **Left Rotation:** Used when the right side is too heavy.
   - **Right Rotation:** Used when the left side is too heavy.
   - **Left-Right / Right-Left Rotations:** Used for "zigzag" imbalances.
7. **Delete:** To remove a book, locate the node, remove it, and perform the same height update and rebalancing steps.
8. **Display:** Use Inorder Traversal (Left → Root → Right) to print all books in perfectly sorted order.

### Step-by-Step Example: Inserting ISBNs 10, 20, and 30

#### Step 1: Insert ISBN 10
The tree is empty, so 10 becomes the root.
- **Balance Factor:** 0
- **Status:** Perfectly balanced.

#### Step 2: Insert ISBN 20
Since 20 is greater than 10, it goes to the right.
- **Height of 10:** 2
- **Balance Factor of 10:** (Height Left: 0) - (Height Right: 1) = -1
- **Status:** Still balanced (within the -1 to 1 range).

#### Step 3: Insert ISBN 30 (The Imbalance)
Since 30 is greater than 10 and 20, it goes to the right of 20.
- **Balance Factor of 10:** (Left: 0) - (Right: 2) = -2
- **Status:** UNBALANCED.

Because the balance factor is -2 and the new ISBN (30) was inserted into the right child's right subtree, your code identifies this as a Right-Right (RR) Case.

#### Step 4: The Rotation (The Fix)
Your code triggers `leftRotate(node)` on the root (10):
- 20 moves up to become the new root.
- 10 moves down to become the left child of 20.
- 30 remains the right child of 20.

**The Result:** The tree is now a "V" shape instead of a straight line. The height has been reduced from 3 levels to 2 levels.

### Visual Diagrams

![Tree Rotation Example](https://github.com/user-attachments/assets/91256dfd-1670-4f83-854b-2aa30e103f49)

![AVL Tree Step 1](https://github.com/user-attachments/assets/b8ca09d3-f0a9-4a58-a0a0-db763e8d2e40)

![AVL Tree Step 2](https://github.com/user-attachments/assets/a149da48-1a9b-484f-bf17-e9a4daa5d9d3)

![AVL Tree Step 3](https://github.com/user-attachments/assets/c31ff53c-4509-4443-b491-dff553fc5778)

![AVL Tree Step 4](https://github.com/user-attachments/assets/d7e5fcf1-dca1-4909-83a2-44d70a2255e6)

---

## 📞 Contact
For any queries or support, reach out to **dsgeorge3005** via the following:
- [GitHub Profile](https://github.com/dsgeorge3005)
- Email: dsgeorge3005@example.com

## 🌟 Contributions
We welcome contributions! Please follow the guidelines in our CONTRIBUTING.md.

## 📅 Last Updated 
**2026-04-11**

Thank you for using the AVL Tree Library Management project!
