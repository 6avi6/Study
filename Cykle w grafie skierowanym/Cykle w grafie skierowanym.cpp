#include <iostream>
//libary for reading and writng txt file
#include <fstream>
//libary for vectors
#include <vector>
//for stoi
#include <string>

using namespace std;



//struct of node
struct node {
	//Number of node 
	int node_number;
	//Table of neighboring node
	vector <int> neighbor_node;

	//Constructor writing node number
	node(int n) {
		node_number = n;
	}

	//Method adding neighbor node
	void set_neighbor_node(int i) {
		//neighbor_node.resize(1);
		neighbor_node.push_back(i);
	}

	//Method printing nodes neighbors
	void cout_node_info() {
		cout << node_number;
		for (auto i = neighbor_node.begin(); i != neighbor_node.end(); ++i) {
			cout << "->" << *i;
		}
		cout << endl;
	}

	//Method returning number of this node
	int get_node_num() {
		return node_number;
	}
};

#pragma region graph
vector <node> graph;


//Function creating node
void create_node(int node_num) {
	graph.push_back(node(node_num));
}



//Function adding node
void add_neighbor_to_node(int node, int nb_num) {

	for (int i = 0; i < graph.size(); i++) {


		if (graph[i].get_node_num() == node) {
			graph[i].set_neighbor_node(nb_num);
		}
	}

}
#pragma endregion    

//reading from file
vector<string> main_node;
vector<string> node_nb;
int file_stuff() {
	ifstream file;

	//opening file
	file.open("input_file.txt", ios::in);
	//checking if file exist
	if (file.good() == false) {
		return 0;
	}
	char znak;
	bool node_or_nb = true;
	int next_num = 0;
	string lol = "";
	while (file >> znak) //reading with out spaces
	{
		//if (znak != ' ' && znak !='-' && znak != '>' && znak != ',') {
		if ((int)znak >= 48 && (int)znak <= 57) {

			if (node_or_nb == true) {
				//cout << znak << " ";
				if (next_num == 0) {
					main_node.push_back(lol + znak);
				}
				else if (next_num == 1) {
					main_node[main_node.size() - 1] += lol + znak;
				}
				next_num = 1;
			}
			else if (node_or_nb != true) {


				// cout << znak << " ";
				if (next_num == 0) {
					node_nb.push_back(lol + znak);
				}
				else if (next_num == 1) {
					node_nb[node_nb.size() - 1] += lol + znak;
				}
				next_num = 1;
			}
		}


		else if (znak == '-') {
			node_or_nb = false;
			next_num = 0;
		}
		else if (znak == ',') {
			node_or_nb = true;
			next_num = 0;
			// cout << endl;


		}
	}
	//closeing file
	file.close();

}

//Function to check if node already exist returning bool
bool find_node(int find) {
	for (int i = 0; i < graph.size(); i++) {


		if (graph[i].get_node_num() == find) {
			return true;
		}
	}
	return false;
}



//Function creating graph 
void create_graph() {


	for (int i = 0; i < main_node.size(); i++) {

		//If node exist add neighbor
		if (find_node(stoi(main_node[i]))) {
			//cout << "yes" << endl;
			add_neighbor_to_node(stoi(main_node[i]), stoi(node_nb[i]));

		}
		//If node dosen't exist creat node and add neighbor
		else if (find_node(stoi(main_node[i])) == false) {
			// cout << "nah" << endl;

			create_node(stoi(main_node[i]));
			add_neighbor_to_node(stoi(main_node[i]), stoi(node_nb[i]));
		}

	}


}


//Printing graph nodes with neighbors
void print_graph() {
	for (int i = 0; i < graph.size(); i++) {
		graph[i].cout_node_info();

	}
}



int main()
{

	file_stuff();
	create_graph();
	print_graph();





	//testing functions



	/*
		create_node(stoi(main_node[0]));
		create_node(1);
		add_neighbor_to_node(stoi(main_node[0]), 11);
		add_neighbor_to_node(stoi(main_node[0]), 12);
		add_neighbor_to_node(1, 14);
		add_neighbor_to_node(1, 121);
		*/
		// graph[0].cout_node_info();
		 //graph[1].cout_node_info();







	std::cout << "Skompilowany";

	return 0;
}

