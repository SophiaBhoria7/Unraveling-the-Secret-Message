// Programmer: Sophia Bhoria
// Date: 9/16/2024
// Purpose: This file contains a main program to encrypt and decrypt messages using Caesar Cipher with special rules.


#include <iostream>
#include <string>
#include <cctype> // For isupper(), islower(), isalpha(), isdigit()

using namespace std;


int main() {
  // Define constants for shift value, vowel bonus, and maximum shift
  const int SHIFT_DECISION_LETTER = 20;
  const int VOWEL_BONUS = 27;
  const int MAX_SHIFT = 40;

  // Decryption of the acceptance letter
  string decisionLetter = "Bottub! Alyyncham zlig nby nqchefcha niqylm iz nby Imwul Uwuxygs iz Guacw! Qy'ly vovvfcha ipyl qcnb yrwcnygyhn ni fyn sio ehiq nbun sio, sym, sio bupy yhwbuhnyx om uff uhx mywolyx u mjin un iol yhwbuhncha yhwfupy! Vyzily sio juwe siol vuam uhx mjyff viiem, lygygvyl ni vlcha hin domn nby womniguls ycabn quhxm zil iol mjyffvchxcha ijyhcha qyye wylygihcym von ufmi u nlomns wugyf! Nbymy guahczcwyhn wlyunolym ulyh'n domn zil mbiq, nbys'ly nby jylzywn jufm zil qctulxm qbcttcha uvion ih nblcffcha uxpyhnolym. Xoy ni u jozzs jozz iz chzfuncih nbun'm vyqcnwbyx iol ywihigs, nby nocncih zyy cm jyaayx un u guacwuf $50,000 jyl mygymnyl. Qy wuh'n qucn ni ombyl sio nblioab iol uhwcyhn, cps-wipylyx ulwbqusm uhx chni nby byuln iz guacw cnmyfz. Ayn lyuxs ni mncl jincihm, wbulg gsnbcwuf vyumnm, uhx jylbujm, wbuhay nby wiolmy iz nby wimgim!";

  // Welcome message and initial information
  cout << "Welcome to the Oscar Academy of Magic Caesar Cipher Program!" << endl;
  cout << "Unraveling the secret acceptance decision letter from the Oscar Academy of Magic…" << endl;
  cout << "Using a shift value of 20…" << endl;

  // Decrypting the acceptance letter using a shift of 20
  for (std::string::size_type i = 0; i < decisionLetter.length(); i++) {
    char &c = decisionLetter[i];
    if (isalpha(c)) {
      // Determine the base character for shifting (A or a)
      char base = isupper(c) ? 'A' : 'a';
      // Apply Caesar cipher decryption logic for letters
      c = (c - base - SHIFT_DECISION_LETTER + 26) % 26 + base;
    }
    else if (isdigit(c)) {
      // Apply Caesar cipher decryption logic for digits
      c = (c - '0' - SHIFT_DECISION_LETTER + 10) % 10 + '0';
    }
  }

  // Display the decrypted acceptance letter
  cout << "The acceptance letter says: " << decisionLetter << endl << endl;

  // User interaction loop
  string userInput;
  char choice;
  do {
    // Prompt the user for encryption or decryption choice
    cout << "Do you want to encrypt or decrypt a message? (e/d): ";
    cin >> choice;
    cin.ignore(); // Ignore the remaining newline in the buffer

    // Prompt the user for the message
    cout << "Enter the message: ";
    getline(cin, userInput);

    // Prompt the user for the shift value
    int shift;
    cout << "Enter the shift value (1-40): ";
    cin >> shift;

    // Validate the shift value
    while (shift < 1 || shift > MAX_SHIFT) {
      cout << "Invalid shift value! Enter a value between 1 and 40: ";
      cin >> shift;
    }

    // Process the message (encryption or decryption)
    for (std::string::size_type i = 0; i < userInput.length(); i++) {
      char &c = userInput[i];
      if (isalpha(c)) {
        // Determine the base character for shifting (A or a)
        char base = isupper(c) ? 'A' : 'a';
        int adjustedShift = shift;

        // Apply vowel enhancement (shift + VOWEL_BONUS)
        if (string("aeiouAEIOU").find(c) != string::npos) {
          adjustedShift += VOWEL_BONUS;
        }
        // Apply special rule for letters between 'e'/'E' and 'n'/'N'
        else if (tolower(c) > 'e' && tolower(c) < 'n') {
          if ((int)c % 2 == 0) {
            // Even ASCII value: apply the shift
          } else {
            continue; // Odd ASCII value: letter remains unchanged
          }
        }

        // Apply encryption or decryption based on user choice
        if (choice == 'e') {
          // Encryption: Shift forward
          c = (c - base + adjustedShift) % 26 + base;
        } else if (choice == 'd') {
          // Decryption: Simply shift back
          c = (c - base - shift + 26) % 26 + base;
        }
      } else if (isdigit(c)) {
        // Process numbers 0-9
        if (choice == 'e') {
          // Encryption: Shift forward
          c = (c - '0' + shift) % 10 + '0';
        } else if (choice == 'd') {
          // Decryption: Shift backward
          c = (c - '0' - shift + 10) % 10 + '0';
        }
      }
    }

    // Output the processed message
    cout << (choice == 'e' ? "Encrypted" : "Decrypted") << " message: " << userInput << endl;

    // Ask the user if they want to continue
    cout << "Would you like to continue the program? (y/n): ";
    cin >> choice;

  } while (choice == 'y' || choice == 'Y');

  // Farewell message
  cout << "Thanks for using the Oscar Academy of Magic Caesar Cipher Program!" << endl;
  cout << "Keep making magic!" << endl;

  return 0;
}


