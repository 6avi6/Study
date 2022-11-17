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
        for (auto i = neighbor_node.begin(); i != neighbor_node.end(); ++i)
            cout << node_number << "->" << *i << endl;   
    }

    //Method returning number of this node
    int get_node_num() {
        return node_number;
    }
};


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
    string lol = "";
    while (file >> znak) //reading with out spaces
    {
        //if (znak != ' ' && znak !='-' && znak != '>' && znak != ',') {
            if((int)znak >= 48 && (int)znak <= 57){
            
            if (node_or_nb == true) {
                //cout << znak << " ";
                main_node.push_back(lol + znak);
           }
            else if (node_or_nb != true) {
                node_nb.push_back(lol + znak);
               // cout << znak << " ";
            }
           

        }
            if (znak == '-') {
                node_or_nb = false;
            }
            if (znak == ',') {
                node_or_nb = true;
               // cout << endl;
            }
    }
    //closeing file
    file.close();
   
}

int main()
{
    file_stuff();

    //testing functions
    
    {
        
        cout <<endl<< main_node[0]<<endl;
        cout <<  main_node[1]<<endl;
        cout <<  main_node[2]<<endl;
        cout <<  main_node[3]<<endl;
        
        create_node(stoi(main_node[0]));
        create_node(1);
        add_neighbor_to_node(stoi(main_node[0]), 11);
        add_neighbor_to_node(stoi(main_node[0]), 12);
        add_neighbor_to_node(1, 14);
        add_neighbor_to_node(1, 121);
        graph[0].cout_node_info();
        graph[1].cout_node_info();
    }
    
  
    



    std::cout << "Skompilowany";
    
    return 0;
}

