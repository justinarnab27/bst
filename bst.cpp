#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
	int val;
	int lc = -1;
	int rc = -1;
};

void add(int val, vector<node>& bst){
	node x;
	x.val = val;

	if(bst.empty()){
		bst.push_back(x);
		return;
	}

	int it = 0;

	while(1){
		if(bst[it].val > val){
			if(bst[it].lc == -1){
				bst[it].lc = bst.size();
				bst.push_back(x);
				return;
			}
			else it = bst[it].lc;
		}
		else{
			if(bst[it].rc == -1){
				bst[it].rc = bst.size();
				bst.push_back(x);
				return;
			}
			else it = bst[it].rc;
		}
	}
}

void disp_aux(queue<int>& qu,int it,const vector<node>& bst){
	qu.pop();
	cout << bst[it].val << " ";

	if(bst[it].lc != -1) qu.push(bst[it].lc);
	if(bst[it].rc != -1) qu.push(bst[it].rc);

	if(!qu.empty()) disp_aux(qu,qu.front(),bst);
}

void disp(const vector<node>& bst){
	queue<int> qu;
	qu.push(0);
	disp_aux(qu,0,bst);
}

int search_aux(int val, int it, const vector<node>& bst){
	if(bst[it].val == val) return 1;
	else if(bst[it].val > val){
		if(bst[it].lc == -1) return 0;
		search_aux(val,bst[it].lc,bst);
	}
	else {
		if(bst[it].rc == -1) return 0;
		search_aux(val,bst[it].rc,bst);
	}
}

int search(int val,const vector<node>& bst){
	if(!bst.empty()) return search_aux(val,0,bst);
}

int maxval(const vector<node>& bst){
	int it = 0;

	while(1){
		if(bst[it].rc == -1) return bst[it].val;
		it = bst[it].rc;
	}
}

int minval(const vector<node>& bst){
	int it = 0;

	while(1){
		if(bst[it].lc == -1) return bst[it].val;
		it = bst[it].lc;
	}
}

void inorder_aux(int it,const vector<node>& bst){
	if(bst[it].lc!=-1) inorder_aux(bst[it].lc,bst);
	cout << bst[it].val << endl;
	if(bst[it].rc != -1) inorder_aux(bst[it].rc,bst);
	return;
}

void inorder(const vector<node>& bst){
	inorder_aux(0,bst);
}

int main(){
	vector<node> bst;
	add(5,bst);
	add(7,bst);
	add(1,bst);
	add(2,bst);
	add(9,bst);
	add(10,bst);
	add(0,bst);
	add(11,bst);
	add(4,bst);
	add(3,bst);
	add(-2,bst);

	cout << minval(bst) << endl;
	cout << maxval(bst) << endl;

	disp(bst);

	for(int i = 0;i!=bst.size();++i) cout << bst[i].val <<" " <<  bst[i].rc << " " << bst[i].lc << endl;

	inorder(bst);

	return 0;
}
