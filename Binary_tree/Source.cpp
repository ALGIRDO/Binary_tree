#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <hash_map>
#include <map>
using namespace std;

const int max_pav_ilgis = 26;
string failas = "20000.bin";
int kiekis = 20000;


char* getElemnt(int index, char *key)			// O(1)
{
	ifstream read(failas, ios::binary );		// 1
	read.seekg((index-1)*max_pav_ilgis);		// 1
	//cout << sizeof(key) << endl;
	for (int i = 0; i < max_pav_ilgis; i++)		// max_pav_ilgis + 1 = 27
	{
		read.get(key[i]);						// 26
		//cout << key[i] << endl;
	}
	read.close();								// 1
	return key;									// 1
}
/*void setElement(int index, char key[])
{
	ofstream a("binary.bin", ios::binary );
	a.seekp((index-1)*4);
	a.write( reinterpret_cast <const char*> (&key), sizeof( key ) );
	a.close();
}*/
void charPrint(char cha[])
{
	cout << "|>";
	for (int i = 0; i < max_pav_ilgis; i++)
	{
		cout << cha[i];
	}
	cout << "<|" << endl;
}
string charString(char cha[]){				// O(1)
	string s;								// 1
	for(int i=0; i< max_pav_ilgis; i++){	// max_pav_ilgis + 1 = 27
		s +=cha[i];							// 26
	}
	return s;								// 1
}
string getString(int index) {   // O(1)
	char zodis[max_pav_ilgis] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; // 1
	getElemnt(index, zodis);	// O(1)
	return charString(zodis);	// O(1)
}
struct node
{
  int key_value;
  int sk;
  node *top;
  node *left;
  node *right;

  void padidinti(){sk++;}
};
class btree
{
	hash_map<string, int> map;
	hash_map<string, int> map2;
    public:
		btree(){ root = NULL; }
        ~btree(){ destroy_tree(); }
		void insert(int key)
		{
			if(root!=NULL)
				insert(key, root);
			else
			{
				root=new node;
				root->key_value=key;
				root->sk = 1;
				root->top=NULL;
				root->left=NULL;
				root->right=NULL;
			}
		}
        node *Tree_Search(int key)
		{
			return Tree_Search(key, root);
		}
		node *Iterative_Tree_Search(int key)
		{
			return Iterative_Tree_Search(key, root);
		}
        void destroy_tree()
		{
			destroy_tree(root);
		}
/**/	void Inorder_Tree_Walk()
		{
			Inorder_Tree_Walk(root);
		}
		node *Tree_Minimum()
		{
			return Tree_Minimum(root);
		}
		node *Tree_Maximum()
		{
			return Tree_Maximum(root);
		}
		node *Tree_Successor(node *leaf)
		{
			if ( leaf->right != NULL)
				return Tree_Minimum(leaf->right);
			node *Successor = leaf->top;
			while ( Successor != NULL && leaf == Successor->right ){
				leaf = Successor;
				Successor = Successor->top; }
			return Successor;
		}
		node *Tree_Predecessor(node *leaf)
		{
			if ( leaf->left != NULL)
				return Tree_Maximum(leaf->left);
			node *Predecessor = leaf->top;
			while ( Predecessor != NULL && leaf == Predecessor->left ){
				leaf = Predecessor;
				Predecessor = Predecessor->top; }
			return Predecessor;
		}
		node *Tree_Delete(node *leaf)
		{
			node *y, *x;
			if ( leaf->left == NULL || leaf->right == NULL){
				y = leaf;
			} else { y = Tree_Successor(leaf); }
			if ( y->left != NULL ) {
				x = y->left;
			} else { x = y->right; }
			if ( x != NULL )
				x->top = y->top;
			if ( y->top == NULL ) {
				root->top = x;
			} else { if ( y == y->top->left ){
						y->top->left = x;
					} else { y->top->right = x; } }
			if ( y != leaf)
				leaf->key_value = y->key_value;
				//
			return y;
		}
/**/	void Tree_Insert(int key)
		{
			node *ideti;
			ideti = new node;
			ideti->key_value=key;
			ideti->left = NULL;
			ideti->right = NULL;
			ideti->top = NULL;
			ideti->sk = 0;
			Tree_Insert(ideti);
		}
		void Show_Tree()
		{
			Show_Tree(root);
		}
		int Tree_Size()
		{
			return Tree_Size(root, 0);
		}
/**/	void Pasikartojantys()
		{
			Pasikartojantys(root);
		}
/**/	void PasikartojaciuIsrinkimas(){
			PasikartojaciuIsrinkimas(root);
		}
/**/	void PasikartojanciuSpausdinimas(){
			for(hash_map<string,int>::iterator i = map.begin(); i != map.end(); i++)
			{
				cout << setw(2) << i->second << " : " << i->first << endl;
			}
			cout<< "Pasikartojaciu pavardziu skaicius: " <<map.size() << endl;
		}
/**/	void IskotiPasikartojanciuPavardiu()
		{
			IskotiPasikartojanciuPavardiu(root);
		}
		clock_t simpleSearch() {
			simpleSearch(root);
			clock_t t = clock();
			int pas = 0;
			int ne = 0;
			int pas_sk = 0;
			for(hash_map<string,int>::iterator i = map2.begin(); i != map2.end(); i++)
			{
				if( i->second > 1 ){
					cout << setw(2) << i->second << " : " << i->first << endl;
					pas++;
					pas_sk += i->second;
				} else {
					ne++;
				}
			}
			cout<< "Unikaliu pavardziu skaicius: " <<map2.size() << endl;
			cout<< "Pasikartojaciu pavardziu skaicius: " <<pas <<"   "<<ne<< "   " << pas_sk << endl;
			return t;
		}
/**/	int height(){
			return height(root);
		}
    private:
		node *root;
		void destroy_tree(node *leaf){
			if(leaf!=NULL)
			{
				destroy_tree(leaf->left);
				destroy_tree(leaf->right);
				delete leaf;
			}
		}
		void insert(int key, node *leaf){
			if(key < leaf->key_value)
			{
				if(leaf->left != NULL)
					insert(key, leaf->left);
				else
				{
					leaf->left=new node;
					leaf->left->key_value=key;
					leaf->left->sk = 1;
					leaf->left->top = leaf;
					leaf->left->left=NULL;    //Sets the left child of the child node to null
					leaf->left->right=NULL;   //Sets the right child of the child node to null
				}  
			}
			else if(key > leaf->key_value)
			{
				if(leaf->right != NULL)
					insert(key, leaf->right);
				else
				{
					leaf->right=new node;
					leaf->right->key_value=key;
					leaf->right->top = leaf;
					leaf->right->sk = 1;
					leaf->right->left=NULL;  //Sets the left child of the child node to null
					leaf->right->right=NULL; //Sets the right child of the child node to null
				}
			} else if(key == leaf->key_value){
				leaf->sk++;
			}
		}
        node *Tree_Search(int key, node *leaf)
		{
			if ( leaf == NULL || key == leaf->key_value ) {
				return leaf; }
			if ( key < leaf->key_value ){ 
				return Tree_Search( key, leaf->left );
			} else { return Tree_Search( key, leaf->right ); }
		}
		node *Iterative_Tree_Search(int key, node *leaf)
		{
			while ( leaf != NULL && key != leaf->key_value){
				if ( key < leaf->key_value ){
					leaf = leaf->left;
				} else { leaf = leaf->right; }
			}
			return leaf;
		}
/**/	void Inorder_Tree_Walk(node *leaf)
		{
			if ( leaf != NULL){
				Inorder_Tree_Walk( leaf->left );
				cout << "--> " << getString(leaf->key_value) << " <--" << leaf->sk << endl;
				Inorder_Tree_Walk( leaf->right );
			}
		}
		node *Tree_Minimum(node *leaf)
		{
			while ( leaf->left != NULL ){
				leaf = leaf->left; }
			return leaf;
		}
		node *Tree_Maximum(node *leaf)
		{
			while ( leaf->right != NULL ){
				leaf = leaf->right; }
			return leaf;
		}
/**/	void Tree_Insert(node *leaf) 
		{
			node *y = NULL;
			node *x = root;
			while ( x != NULL ){
				y =x;
				if ( getString(leaf->key_value).compare(getString(x->key_value)) == -1 ) {
					x = x->left;
				} else { 
					x = x->right; 
				} 
			}
			leaf->top = y;
			if ( y == NULL ){
				root = leaf;
			} else { if ( getString(leaf->key_value).compare(getString(y->key_value)) == -1 ){
						y->left = leaf;
					} else { y->right = leaf; } }

		}
		void Show_Tree(node *leaf)
		{

			if ( leaf != NULL){
				Show_Tree( leaf->left );
								//if (leaf->top != NULL)
				//	cout << "   " << leaf->top->key_value << endl;
				if ( leaf->left != NULL)
					cout << leaf->left->key_value;
				cout << " <-- " << leaf->key_value << " --> ";
				if ( leaf->right != NULL)
					cout << leaf->right->key_value;
				cout << endl;
				Show_Tree( leaf->right );
			}

		}
		int Tree_Size(node *leaf, int dydis)
		{
			if ( leaf != NULL){
				dydis++;
				dydis = Tree_Size( leaf->left , dydis);
				dydis = Tree_Size( leaf->right , dydis);
			}
			return dydis;
		}
/**/	void Pasikartojantys(node *leaf)
		{
			if ( leaf != NULL){
				Pasikartojantys( leaf->left);
				if (leaf->sk > 1)
					cout << getString(leaf->key_value) << " pasikartoja " << leaf->sk << " kartus" << endl;
				Pasikartojantys( leaf->right);
			}
		}
/**/	void IskotiPasikartojanciosPavardes(node *leaf, int key)				// T1(n)
		{
			if ( leaf == NULL ) {												// 1
				return;
			}
			if ( getString(key).compare(getString(leaf->key_value)) == 0 )		// O(1)
				leaf->sk++;														// 1
			if ( getString(key).compare(getString(leaf->key_value )) == -1 ) {	// O(1)
				IskotiPasikartojanciosPavardes( leaf->left, key );				// T1(n/2)
			} else { 
				IskotiPasikartojanciosPavardes( leaf->right, key );				// T1(n/2)
			}
		}
/**/	void IskotiPasikartojanciuPavardiu(node *leaf)					// T(n)
		{
			if ( leaf != NULL){											// 1
				IskotiPasikartojanciosPavardes(root, leaf->key_value);	// T1(n)
				IskotiPasikartojanciuPavardiu( leaf->left);				// T(n/2)
				IskotiPasikartojanciuPavardiu( leaf->right);			// T(n/2)
			}
		}
/**/	void PasikartojaciuIsrinkimas(node *leaf){
			if ( leaf != NULL){
				if (leaf->sk > 1) //cout << getString(leaf->key_value) << endl;
					map[getString(leaf->key_value)]=leaf->sk;
				PasikartojaciuIsrinkimas( leaf->left );
				
				PasikartojaciuIsrinkimas( leaf->right );
			}
		}
		void simpleSearch(node *leaf){
			if (leaf != NULL){
					map2[getString(leaf->key_value)]++;
				simpleSearch(leaf->left);
				simpleSearch(leaf->right);
			}
		}
/**/	int height(node *leaf){
		   if(leaf == NULL )
			   return 0;
		   return 1 + max( height(leaf->left), height(leaf->right) );
		}
};

int main()
{
	setlocale(LC_ALL, "Lithuanian");

	btree b;
	clock_t t1,t2,t3,t4,t5,t6,t7, t8;

	t1 = clock();
	cout << "---Duomenys ikeliami i medi---" << endl;
	for(int i = 1; i <= kiekis; i++){
		b.Tree_Insert(i);
	}
	t2 = clock();
	//b.Show_Tree();
	//cout << "---perziura---" << endl; b.Inorder_Tree_Walk();
	t3 = clock();
	cout << "---Skaiciujamos pasikartojacios pavardes---" << endl; b.IskotiPasikartojanciuPavardiu();
	t4 = clock();
	//cout << "---Pasikartojacios pavardes isrenkamos---" << endl; b.Pasikartojantys();
	//b.PasikartojaciuIsrinkimas();
	t5 = clock();
	//cout << "---Pasikartojancios pavardes spausdinamos---" << endl; b.PasikartojanciuSpausdinimas();
	t6 = clock();
	cout << "---simleSearch---" << endl; t7 = b.simpleSearch();
	t8 = clock();


	//cout << "(t2 - t1) duomenu ikelimas: " << (t2 - t1)/(double) CLOCKS_PER_SEC << endl;
	//cout << "(t3 - t2) in order tree walk: " << (t3 - t2)/(double) CLOCKS_PER_SEC << endl;
	cout << "(t4 - t3) uztruko: " << (t4 - t3)/(double) CLOCKS_PER_SEC << endl;
	//cout << "(t5 - t4) uztruko: " << (t5 - t4)/(double) CLOCKS_PER_SEC << endl;
	//cout << "(t6 - t5) uztruko: " << (t6 - t5)/(double) CLOCKS_PER_SEC << endl;
	//cout << "(t6 - t3) uztruko: " << (t6 - t3)/(double) CLOCKS_PER_SEC << "  oldSearch" << endl;
	cout << "(t7 - t6) simpleSearch: " << (t7 - t6)/(double) CLOCKS_PER_SEC <<endl;
	//cout << "(t8 - t7) simpleSearch_toString: " << (t8 - t7)/(double) CLOCKS_PER_SEC <<endl;
	//cout << "is viso: " << (t7-t1)/(double) CLOCKS_PER_SEC << endl;

	cout << b.height() << endl;

	system("pause");
}