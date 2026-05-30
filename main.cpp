
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
#include <ctime>
const int BOARD_SIZE =8;
#include "othelo.h"





int main() {
	othelo o1;
	char player = '1';
	char ai = '0';
	int depth ;
	char choice;
	int choice_i;
	int choice_j;
	cout<<"First player ? : (0 for pc , 1 for user)"<<endl;
	cin>>choice;
	o1.set_player(choice);

	cout<<"Choose minimax's depth  : "<<endl;
	cin>>depth;

	while(true)
	{

		char current_player = o1.get_player();
		cout<<"----------"<<endl;
		cout<<"Board: " <<endl;
		cout<<o1;
		cout<<"player : "<< current_player << " is playing"<<endl;

		vector<pair<int,int>>  current_valid_moves = o1.get_all_valid_moves_for_player(current_player);
		if(current_valid_moves.empty())
		{
			o1.next_player();
			bool next_player_has_valid_moves=!o1.get_all_valid_moves_for_player(o1.get_player()).empty();
			o1.next_player();
			if(!next_player_has_valid_moves) {
				cout<<"Game is over";
				break;
			}
			cout << "Player: " << current_player << " has not valid move,so the turn is skipped. " << endl;
			o1.next_player();
			continue;
		}
		int row=-2;
		int column=-2;
		if(current_player=='0')
		{
			pair<int,int> best_move = o1.find_best_move(current_player,depth);
			int row = best_move.first;
			int column = best_move.second;
			if(row!=-1 && column != -1)
			{
				o1.play(row,column);
			}
			else
			{
				cout<<"No move found for pc"<<endl;
				o1.next_player();
			}
		}

		else
		{	bool valid_move=true;
			int row,column;
			cout<<"Give line , column : "<<endl;
			while(true)
			{
				if(!(cin>>row>>column))/*try to read 2 numbers,and save them at row,column*/
					/*The input stream acts as a boolean condition*/
					/*If the user enters something other than numbers, it returns false, so they must try again.*/
				{
					cout<<"Error, Please enter valid coordinates!"<<endl;
					cin.clear();/*reset the input stream*/
					cin.ignore(10000,'\n');/*discard invalid data*/
					continue;
				}
				if((row<0 || row>BOARD_SIZE-1) || (column<0 || column>BOARD_SIZE-1))
				{
					cout<<"Error, Please enter valid coordinates!"<<endl;
					cin.clear();
					cin.ignore(10000,'\n');
					continue;
				}


				if(o1.play(row,column))
				{
					cout<<"Valid move"<<endl;
					break;
				}
				else {
					cout << "Not valid move! Try again." << endl;

				}
			}
		}
		o1.next_player();
	}
	o1.count_checkers();
	return 0;
}



