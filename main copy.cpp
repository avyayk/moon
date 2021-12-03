
//Reddit Elimination Game

//The Objective of this Game is extremely simple: We will create a list of objects to be ranked

//In this simple case I will choose Buffy the Vampire Slayer Seasons 1-7
//But the algorithm can be used to rank anything up to 12 places
//We will go standard Mario Kart rules


/*
 So a vote for first place earns 15 points 
 2nd Place: 12 Points
 3rd Place: 10 Points
 4th Place: 9 Points
 5th Place: 8 Points
 And all ranks following receive one less point all the way to...
 
 12th Place: 1 Point
 */





#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

//vector <int> update_points ( vector <int> ranking_input ){
//    
//    vector <int> points;
//    
//    const map <int, int> rank_points = {{1, 15}, {2, 12}, {3, 10}, {4, 9}, {5, 8}, {6, 7}, {7, 6}, {8, 5}, {9, 4}, {10, 3}, {11, 2}, {12, 1} } ;
//    
//    for ( int i = 0 ; i < ranking_input.size() ; i++ ){
//        
//        points.push_back( rank_points[i])
//    }
//}

int main() {
    
    //Let's just create the point map here for now
    unordered_map <int, int> point_key = {{1, 15}, {2, 12}, {3, 10}, {4, 9}, {5, 8}, {6, 7}, {7, 6}, {8, 5}, {9, 4}, {10, 3}, {11, 2}, {12, 1} } ;
    
    map < int, string > item_key = { {1, "Season 1"}, {2, "Season 2"}, {3, "Season 3"}, {4, "Season 4"}, {5, "Season 5"}, {6, "Season 6"}, {7, "Season 7"} };
    
    // Just for ease of input in this example; if this were another ranking system that wasn't so numerical this is unnecessary
    
    
    //Unordered map to store item values
    map<string, int> standings = { {"Season 1", 0}, {"Season 2", 0}, {"Season 3", 0}, {"Season 4", 0}, {"Season 5", 0}, {"Season 6", 0}, {"Season 7", 0} };
    
    const int NUMBER_OF_ELEMENTS = 7;
    
    
    //General variables
    
    bool keepRunning = true; // keeps program running, until user explicitly exits
    
    int current_input = 0;
    int count = 0;
    
    vector <string> until_empty = { "Season 1", "Season 2", "Season 3", "Season 4", "Season 5", "Season 6", "Season 7" };
    
    
    while (keepRunning){
        
        while ( until_empty.size() > 1 ){
            
            for( int i = 0; i < until_empty.size(); i++ ){
                cout << until_empty[i] << endl;
            }
        
            cout << "What is your least favorite season? (Enter number 1 through 7): ";
        
            cin >> current_input;
            
            
            if ( binary_search(until_empty.begin(), until_empty.end(), item_key[current_input]) ){
                
                //Add input to standings
                //standings[item_key[current_input]] = standings[item_key[current_input]];
                
                //cout << "\n" << item_key[current_input] << " gone!" << endl; -- Works
                
                int place = NUMBER_OF_ELEMENTS - count;
                
                
                
                standings[item_key[current_input]] += point_key[place];
                
                
                //Remove element from vector
                until_empty.erase(until_empty.begin() + ( (find(until_empty.begin(), until_empty.end(), item_key[current_input] ) - until_empty.begin() ) ) );
                
                cout << endl;
                
                count++;
            }
            
            else{
                cout << "Please answer the question\n" << endl;
                continue;
            }
            
            
            
            //until_empty.erase(until_empty.begin() + current_input - 1);
            
        }
        
        //Print standings
        
        keepRunning = false;
    }
    
    //print standings
    for (auto const &pair: standings) {
        cout << "{" << pair.first << ": " << pair.second << "}\n" << endl;
    }
    
    
    return 0;
}
