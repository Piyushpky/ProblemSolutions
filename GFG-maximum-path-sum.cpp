/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
int mx=INT32_MIN;
int fun(Node * root){
    if(root==NULL) return 0;
    int x=fun(root->left);
    int y=fun(root->right);
    int res=x+y+root->data;
    if(res>mx){
        mx=res;
    }
    return max(x,y)+root->data;
}
int maxPathSum(struct Node *root)
{
//add code here.
mx=INT32_MIN;
    fun(root);
    return mx;
}