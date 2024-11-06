/*
* Nombre: Andr�s Ignacio Zegales Taborga
* Fecha: 24/10/2024
* Tema: Sum In Binary Tree 1843C - Codeforces
*/

#include <string>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;

template <class T> class BST;

template <class T>
class TreeNode {
private:
	T value;
	TreeNode *left, *right;
	TreeNode<T>* succesor();

public:
	TreeNode(T);
	TreeNode(T, TreeNode<T>*, TreeNode<T>*);
	void add(T);
	bool find(T);
	long long sumTot(T);
	void removeChilds();
	friend class BST<T>;
};
// Constructor por default
template <class T>
TreeNode<T>::TreeNode(T val) : value(val), left(0), right(0) {}
// Constructor por par�metros
template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri)
	: value(val), left(le), right(ri) {}
/*
* add(T val)
*
* Crea una nuevo nodo y lo agrega al arbol en el primer espacio
* libre usando un BFS
*
* param T val
* @return
*/
template <class T>
void TreeNode<T>::add(T val) {
    std::queue<TreeNode<T>*> q;
    q.push(this);
    while (!q.empty()) {
        TreeNode<T>* p = q.front();
        q.pop();
        if (p->left == nullptr) {
            p->left = new TreeNode<T>(val);
            return;
        } else {
            q.push(p->left);
        }
        if (p->right == nullptr) {
            p->right = new TreeNode<T>(val);
            return;
        } else {
            q.push(p->right);
        }
    }
}

/*
* find(T val)
*
* Busca dentro del arbol y revisa la ubicacion donde est� ese nodo
*
* param T val
* return true o false
*/
template <class T>
bool TreeNode<T>::find(T val) {
    if (val == value) {
        return true;
    }
    if (left && left->find(val)) {
        return true;
    }
    if (right && right->find(val)) {
        return true;
    }
    return false;
}
/*
* sumTot(T num)
*
* Realiza de manera recursiva la suma acumulada
* dentro del �rbol
*
* param T val
* return suma acumulada
*/
template <class T>
long long TreeNode<T>::sumTot(T num) {
    if (value == num) {
        return value;
    }
    if (left != nullptr && left->find(num)) {
        return value + left->sumTot(num);
    }
    if (right != nullptr && right->find(num)) {
        return value + right->sumTot(num);
    }
}
/*
* removeChilds()
*
* Vacia todo el arbol
*
* @param
* @return
*/
template <class T>
void TreeNode<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

template <class T>
class BST {
    private:
        TreeNode<T> *root;
    public:
        BST();
        bool empty() const;
        void add(T);
        bool find(T) const;
        long long sumTot(T) const;
        void removeAll();
    };
// Constructor por default
template <class T>
BST<T>::BST() : root(0) {}
/*
* empty() const
*
* Revisa si el arbol esta vacio
*
* @param
* return true o false
*/
template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}
/*
* add(T val)
*
* A�ade el valor en el lugar correspondiente
*
* param T val
* @return
*/
template<class T>
void BST<T>::add(T val) {
	if (root != 0) {
        root->add(val);
	} else {
		root = new TreeNode<T>(val);
	}
}
/*
* find(T val)
*
* Busca el valor corresponediente
*
* param T val
* return true o false
*/
template <class T>
bool BST<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}
/*
* sumTot(T val) const
*
* Devuelve la suma acumulada del nodo
*
* param T val
* return suma acumulada
*/
template <class T>
long long BST<T>::sumTot(T val) const {
    if (root != nullptr) {
        return root->sumTot(val);
    }
    return 0;
}
/*
* sumTot(T val) const
*
* Vacia el arbol
*
* @param
* @return
*/
template <class T>
void BST<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

int main(){
    BST<long long> bst;
    long long num, intentos;
    cin >> intentos;
    for (long long i = 1; i <= 15000; i++){
        bst.add(i);
    }
    for (int j = 0; j < intentos; j++){
        cin >> num;
        if (num > 15000){
            long long aux = 0;
            while (num > 0) {
                aux = aux + num;
                num = num / 2;
            }
            cout << aux << endl;
        }
        else {
            cout << bst.sumTot(num) << endl;
        }
    }
    bst.removeAll();
}
