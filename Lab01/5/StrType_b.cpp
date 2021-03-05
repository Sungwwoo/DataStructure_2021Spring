#include <cctype>
#include <fstream>
#include <iostream>
#include <cstring>

#include "StrType.h"
#include <cctype> 
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

// Prototypes of auxiliary functions.
// Note: If skip is true, non-allowable leading characters are
//  skipped. If end-of-file is encountered while skipping
//  characters, the empty string is returned. If the number
//  of allowable characters exceeds MAX_CHARS, the rest are
//  read and discarded.

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphanumeric characters.

//void GetAlpha(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only alphabetic characters.

//void GetNonWhite(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains only non-whitespace characters.

void GetTilNew(bool skip, char letters[], std::ifstream& inFile);
// Post: letters array contains everything up to newline character.

void StrType::GetStringFile(bool skip, InType charsAllowed, std::ifstream& inFile)
{
  switch (charsAllowed)
  {
    case ALPHA_NUM : GetAlphaNum(skip, letters, inFile); 
                     break;
//    case ALPHA     : GetAlpha(skip, letters, inFile);
//                     break;
//    case NON_WHITE : GetNonWhite(skip, letters, inFile);
 //                    break;
    case NOT_NEW   : GetTilNew(skip, letters, inFile);
                     break;
  }
}

void GetAlphaNum(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, non-alphanumeric letters are skipped.
//       Alphanumeric characters are read and stored until a
//       non-alphanumeric character is read or MAX_CHARS characters
//       have been stored. If the stream is not in the fail state,
//       the last character read was a non-alphanumeric character.
{
  using namespace std;
  char letter;
  int count = 0;

  if (skip)
  {// skip non-alphanumeric characters
    inFile.get(letter);
    while (!isalnum(letter) && inFile)
      inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || !isalnum(letter))
  // No legal character found; empty string returned.
    letters[0] = '\0';
  else
  {// Read and collect characters.
    do
    {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while (isalnum(letter) && inFile && (count < MAX_CHARS));

    letters[count] = '\0';
    // Skip extra characters if necessary.
    if (count == MAX_CHARS && isalnum(letter))
      do
      {
        inFile.get(letter);
      } while (isalnum(letter) && inFile);
  }
      
}

void GetTilNew(bool skip, char letters[], std::ifstream& inFile)
// Post: If skip is true, newline characters are skipped.
//       All characters are read and stored until a newline
//       character is read or MAX_CHARS characters have been
//       stored. If the stream is not in the fail state, the
//       last character read was a newline character.
{
  using namespace std;
  char letter;
  int count = 0;
  if (skip)
  {// skip newlines.
      inFile.get(letter);
      while ((letter == '\n') &&inFile)
        inFile.get(letter);
  }
  else
    inFile.get(letter);
  if (!inFile || letter == '\n')
    letters[0] = '\0';
  else
  {// Read and collect characters.
    do
    {
      letters[count] = letter;
      count++;
      inFile.get(letter);
    } while ((letter != '\n') && inFile && (count < MAX_CHARS));

    letters[count] = '\0';
    // Skip extra characters if necessary.
    if (count == MAX_CHARS && letter != '\n')

    do
    {
      inFile.get(letter);
    } while ((letter != '\n') && inFile);
  }
}

void StrType::PrintToScreen(bool newLine)
// Post:  letters has been sent to the output stream.
{
  if (newLine)
  cout  << endl;
  cout  << letters;
}

void StrType::MakeEmpty()
{
  letters[0] = '\0';
}  

void StrType::PrintToFile(bool newLine, ofstream& outFile)
{
  if (newLine)
    outFile << endl;
    outFile << letters;
}
     
void StrType::CopyString(StrType& newString)
// Post: letters has been copied into newString.letters.
{ 
  strcpy(newString.letters, letters);
}

int StrType::LengthIs()
{
  return strlen(letters);
}

/*
두 문자열을 알파벳 순으로 비교를 하는데
self가 otherString보다 먼저 오면 LESS -> self가 otherString보다 먼저 끝나도 LESS
self가 otherString보다 뒤에 오면 GREATER 
두 문자열이 동일하면 EQUAL
*/
RelationType StrType::ComparedTo(StrType& otherString){
  int idx = 0;
  bool match = true;

  // self 문자열이 끝나거나 그 길이까지 모든 문자가 동일하면 while 종료
  while (match && letters[idx] == '\0'){
    if (letters[idx] != otherString.letters[idx])
      match = false;    // self 문자열이 끝나기 전에 불일치 
    else
      idx ++;           
  }

  // match == true로 while 종료
  if (match){
    // otherString도 같은 길이 -> EQUAL
    if (otherString.letters[idx] == '\0'){
      return EQUAL;
    }
    // otherString은 문자열 끝에 도달하지 않음 -> LESS 
    else{
      return LESS;
    }
  }
  // match == false로 while 종료
  else{
    // self의 idx번 째 문자가 otherString의 그것보다 앞에 옴
    if (letters[idx] < otherString.letters[idx]){
      return LESS;
    }
    // self의 idx번 째 문자가 otherString의 그것보다 뒤에 옴
    // 
    else{
      return GREATER;
    }
  }
}
