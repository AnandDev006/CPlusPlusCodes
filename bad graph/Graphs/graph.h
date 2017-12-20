//
// Created by Anand on 21-08-2017.
//

#ifndef GRAPHS_BFS_H
#define GRAPHS_BFS_H

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

typedef std::map<std::string, std::list<std::string> > adjacency_list ;

void Initialize( std::map<std::string,std::list<std::string>> &Adj) ;

auto BreadthFirstSearch ( std::map<std::string,std::list<std::string>> Adj , std::string start );   // Change return type as needed

void PrintShortestPath( std::map<std::string, std::list<std::string> > Adj ) ;

void DFS_Visit( adjacency_list Adj , std::string s , std::unordered_map <std::string,std::string> &parent , std::vector<std::pair<std::string,int>> &timer) ;

auto DepthFirstSearch(std::map<std::string,std::list<std::string>> Adj ) ;

void topological_sort( std::map<std::string,std::list<std::string>> Adj ) ;

#endif //GRAPHS_BFS_H