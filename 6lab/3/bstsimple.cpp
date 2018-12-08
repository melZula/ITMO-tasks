#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
 
struct leaf{
    long long value;
    leaf *parent;
    leaf *lchild;
    leaf *rchild;
};
 
leaf *insert(leaf *curr,long long key){
    if (curr->value == -1000000001){            //insert first node
        curr->value = key;
        return curr;
    }else{
        if (curr->value < key){                         //write right
            if (curr->rchild != NULL){
                return insert(curr->rchild, key);
                }
            else{
                leaf *node = new(leaf);
                curr->rchild = node;
                node->parent = curr;
                node->lchild = NULL;
                node->rchild = NULL;
                node->value = key;
                return node;
            }
        }
        else{
            if (curr->value > key){//write left
				if (curr->lchild != NULL){
				    return insert(curr->lchild, key);
				} else{
				    leaf *node = new(leaf);
				    curr->lchild = node;
				    node->parent = curr;
				    node->lchild = NULL;
				    node->rchild = NULL;
				    node->value = key;
				    return node;
					}
			} else
				return NULL;
        }
    }
}
 
leaf *search(leaf *root, long long key){        //printf("SEaRCH %p\n", root);  //printf("search %lld (%lld)\n", root->value, key);
    if ((root == NULL)||(root->value == key)){  //printf("YES (%p %lld) \n", root, root->value);
        return root;                          
    }else{                                      //printf ("%lld ", root->value);
        if (key > root->value)
            return search(root->rchild, key);      
        else{
            return search(root->lchild, key);
        }
    }
}
 
leaf *next(leaf *root, long long key){
    leaf *current = root;
    leaf *successor = NULL;          
    while (current != NULL){    //printf("next %lld\n", current->value);
        if (current->value > key){
            successor = current;
            current = current->lchild;
        }else
            current = current->rchild;
    }
   return successor;
}
 
leaf *prev(leaf *root, long long key){          //printf ("PREV\n");
    leaf *current = root;
    leaf *successor = NULL;          
    while (current != NULL){
        if (current->value < key){
            successor = current;
            current = current->rchild;
        }else
            current = current->lchild;
    }
   return successor;
}
 
void del(leaf *curr,long long key){             //printf ("ST DEL\n");
    leaf *delleaf = search(curr, key);      //printf("delleaf (%p %lld) par (%p %lld)\n", delleaf, delleaf->value);
    if (delleaf != NULL){
        if ((delleaf->lchild == NULL)&&(delleaf->rchild == NULL)){  //printf(" child=0 "); printf("delleaf (%p, %lld) delleaf.par (%p %lld) del.par.ch (%p %lld) \n", delleaf,delleaf->value, delleaf->parent,delleaf->parent->value , delleaf->parent->rchild, delleaf->parent->rchild->value);    // simple case 0 child
            if (delleaf->parent->rchild == delleaf){
                delleaf->parent->rchild = NULL;                 //printf("del zeroch R ");
                delleaf->parent = NULL;
            }else{ if (delleaf->parent->lchild == delleaf){
                delleaf->parent->lchild = NULL;                 //printf("del zeroonech L ");
                delleaf->parent = NULL;
                }
            }
            free (delleaf);
        } else { //printf("HARD ");
            if (next(curr, key) != NULL){                   //printf("find next for del \n");
                leaf *change = next(curr, key);
                delleaf->value = change->value;
                del(change, change->value);
            } else if (prev(curr, key) != NULL){                            // hard case
                leaf *change = prev(curr, key);                 //printf("find prev for del (%p %lld)\n", change, change->value);
                delleaf->value = change->value;
                del(change, change->value);
            }
        }
    }
    //printf("END DEL\n");
}
 
 
 
 
int main() {
    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");
    string cmd;
    long long now;
   
    leaf *root = new(leaf); //first leaf
    root->value = -1000000001;
    root->parent = NULL;
    root->lchild = NULL;
    root->rchild = NULL;
   
    while (fin >> cmd){ //printf ("%d\n", n++);
        fin >> now;
        if (cmd == "insert")
            insert(root, now);
        else if (cmd == "delete"){
            del(root, now);
        }else if (cmd == "prev"){
            leaf *answ = prev(root, now);
            if (answ == NULL)
                fout << "none" << endl;
            else fout << answ->value << endl;
        } else if (cmd == "next"){
            leaf *answ = next(root, now);
            if (answ == NULL)
                fout << "none" << endl;
            else fout << answ->value << endl;
        } else if (cmd == "exists"){
            leaf *answ = search(root, now);
            fout << ((answ == NULL) ? "false" : "true") << endl;
        }
        //printf("--------\n");
    }
    //printf("root (%p %lld)\n", root, root->value);
    //printf("1: %lld \n 2: %lld \n\n", root->value, root->lchild->value);
    return 0;
}
