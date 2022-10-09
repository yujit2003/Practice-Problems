#include<iostream>
#include<queue>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
            Node(int data) {
            this -> data = data;
            this ->left = NULL;
            this ->right = NULL;
        }
};


//we use recursion here
Node* insertInBST(Node* &root, int d) {
    //base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d > root ->data) {
        //insert into right part
        root -> right = insertInBST(root -> right, d);
    }
    if(d < root -> data) {
        //insert into left part
        root -> left = insertInBST(root ->left, d);
    }

    return root;
}

Node* minVal(Node* root) {
    Node* temp = root;
    while(temp -> left != NULL) {
        temp = temp -> left;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int x) {
    //base case
    if(root == NULL) {
        return root;
    }

    if(root -> data == x) {
    //0 child
        if(root ->left == NULL && root ->right == NULL) {
        // yani jo nhi upr ke node hai abb vo NULL ko point kregi
            return NULL;
        }
    //1 child
        //if it is left child
        if(root -> left == NULL && root-> right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //if it is right child
        if(root -> right == NULL && root-> left != NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

    //2 child
        int mini  = minVal(root ->right) -> data;
        root -> data = mini;
        root ->right = deleteFromBST(root -> right, mini);
        return root;

    }else if(root -> data > x) {
        root -> left = deleteFromBST(root ->left, x);
        return root;
    }else{
        root -> right = deleteFromBST(root ->right, x);
        return root;
    }
}

bool searchBST(Node* root, int d) {
    // iterative way on link(https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?leftPanelTab=1)
    //space complexity O(H) because of recursion
    if(root == NULL) {
        return false;
    }
    if(root ->data == d) {
        return true;
    }

    if(d > root ->data) {
        return searchBST(root -> right, d);
    }else{
        return searchBST(root -> left, d);
    }
}


void levelOrderTraversal(Node* root) {
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    // q == 1|NULL

    while(!q.empty()) {
        Node* temp = q.front();
            q.pop();

        if(temp == NULL) {
            // purana level pura traverse ho chuka hai
            // using seperator
            cout << endl;
            // q == NULL {poped}| 3 | 7
            if(!q.empty()) {
                // q still have some child nodes
                // and other level start krne se pehle NULL de diya
                
                q.push(NULL);
            // q == 3 | 7 |NULL
            }
        }else{
            // q == NULL|{1 is poped}
            cout << temp -> data << " ";
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
            // q == NULL | 3 | 7
        }

    }

}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1) {
        root = insertInBST(root, data);
        cin >> data;
    }

}

int main(){

    Node* root = NULL;
    // 10 8 21 7 27 5 4 3 -1
    cout << "Enter the data to form the BST" << endl;
    takeInput(root);

    deleteFromBST(root, 10);

    cout << "level order traversal is" << endl;
    levelOrderTraversal(root);

    cout << "enter number you want to search " << endl;
    int data;
    cin >> data;
    if(searchBST(root, data)){
        cout << "Present" << endl;
    }else {
        cout << "Not Present" << endl;
    }


    return 0;
}
