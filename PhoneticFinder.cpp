#include "PhoneticFinder.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <ctype.h>
using namespace std;


namespace phonetic
{
		string find(string text, string word)	
		{

			string text_tmp = phonetic::str_clear(text);

			string word_tmp = phonetic::str_clear(word);
			
			int word_char_i=0;
			char word_char[word.length()];
			for ( char& w : word_tmp ) {
				word_char[word_char_i] = w;
				word_char_i++;
			}

			int t_start=0;
			int t_key=0;
			int w_key=0;
			int w_end=(word.length() - 1);

			bool wait_space  = false;

			bool check_space = false;
			bool check_found = false;

			for ( char& t : text_tmp ) {

				if ( check_found == true ) {
					
				} else if ( check_space == true ) {
					if ( t == ' ' ) {
						check_space = false;
						check_found = true;
					} else {
						check_space = false;
						check_found = false;
						w_key = 0;
					}
				} else if ( wait_space == true ) {
					if ( t == ' ' ) {
						wait_space = false;
					} else {
						wait_space = true;
					}
				} else if ( t == word_char[w_key] ) {

					if ( w_key == 0 ){
						t_start = t_key;
					}

					// Check math did you found.
					if ( w_key == w_end ) {
						if ( ( 1 + t_key ) == text.length() ) {
							check_found = true;
						} else {
							check_space = true;
						}
					}

					w_key++;

				} else {
					check_space = false;
					check_found = false;
					wait_space  = true;
					w_key = 0;
				}

				t_key++;
			}

			/*cout << "Word TEMP: " + word_tmp + "\nText TEMP: " + text_tmp + "\n";

			cout << "Word: " + word + "\nText: " + text + "\nFound: ";
			if ( check_found == true ){
				cout << "true";
			} else {
				cout << "false";
			}
			cout << "\nIn: ";
			if ( check_found == true ){
				cout << to_string(t_start);
			} else {
				cout << "-1";
			}
			cout << "\nResult: ";*/

			if ( check_found == true ) {
				//cout << std::string(&text[t_start], &text[ t_start + w_end + 1 ]) + "\n";
				return std::string(&text[t_start], &text[ t_start + w_end + 1 ]);
			} else {
				//cout << "none\n";
				throw runtime_error("The word: " + word + " is not in the text.");
				return "";
			}

			//return "-------------------------";

		};

		string str_clear(string str) {
			std::transform(str.begin(), str.end(), str.begin(),
    		[](unsigned char c){ return std::tolower(c); });
			std::replace( str.begin(), str.end(), 'w', 'v');
			std::replace( str.begin(), str.end(), 'f', 'b');
			std::replace( str.begin(), str.end(), 'p', 'b');
			std::replace( str.begin(), str.end(), 'j', 'g');
			std::replace( str.begin(), str.end(), 'k', 'c');
			std::replace( str.begin(), str.end(), 'q', 'c');
			std::replace( str.begin(), str.end(), 'z', 's');
			std::replace( str.begin(), str.end(), 't', 'd');
			std::replace( str.begin(), str.end(), 'u', 'o');
			std::replace( str.begin(), str.end(), 'y', 'i');
			return str;
		};

};
