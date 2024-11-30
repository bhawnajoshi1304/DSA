class Binary_Tree_Representation{
public static void main(String[] args) {
    // Procedure to create new node
    Node root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    root.left.right = new Node(5);
    }
}

class Node{
    int data;
    Node left;
    Node right;
    public Node(int key){
        data=key;
    }
}

//        1
//      /   \
//     2      3
//    / \    / \
// null  5 null null