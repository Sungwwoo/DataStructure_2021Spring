#include <new>
#include "TextEditor.h"

TextEditor::TextEditor()  // Class constructor
{
	LineType* header;
	LineType* trailer;
	header = new LineType;
	trailer = new LineType;
	ItemType text1[80] = "---Top of file---";
	for (int i = 0; text1[i] != '\0'; i++)
		header->info[i] = text1[i];
	header->back = NULL;
	header->next = trailer;
	listData = header;
	ItemType text2[80] = "---Bottom of file---";
	for (int i = 0; text2[i] != '\0'; i++)
		trailer->info[i] = text2[i];
	trailer->back = header;
	trailer->next = NULL;
	currentLine = header;
	length = 0;
}

TextEditor::~TextEditor()
// Class destructor
{
	MakeEmpty();
}

bool TextEditor::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
	LineType* location;
	try
	{
		location = new LineType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}

int TextEditor::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}

void TextEditor::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	LineType* tempPtr;

	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}


void TextEditor::InsertItem(ItemType* newData)
// item is in the list; length has been incremented.
{
	LineType* newLine;
	newLine = new LineType;
	for (int i = 0; newData[i] != '\0'; i++){
		newLine->info[i] = newData[i];
	}
	if (currentLine->next == NULL){	
		// currentLine == trailer일 경우 currentLine Top쪽으로 한 번 이동시킨 후 삽입
		currentLine = currentLine->back;
	}
	newLine->next = currentLine->next;
	newLine->back = currentLine;
	currentLine->next = newLine;
	newLine->next->back = newLine;
	currentLine = newLine;

	length++;
}



void TextEditor::ResetList()
// Post: Current position has been initialized.
{
	currentLine = listData;
}


void TextEditor::GetNextItem(ItemType* item)
// Post:  Current position has been updated; item is current item.
{
	if (currentLine == NULL)
		currentLine = listData;
	else
		currentLine = currentLine->next;

	for (int i = 0; currentLine->info[i] != '\0'; i++)
		item[i] = currentLine->info[i];
}

void TextEditor::GoToTop() {
	while (currentLine->back != NULL)
		currentLine = currentLine->back;
	currentLine = currentLine->next;
}

void TextEditor::GoToBottom() {
	while (currentLine->next != NULL)
		currentLine = currentLine->next;
	currentLine = currentLine->back;
}

/* 	
*	GoToTop(), GoToBottom()은 데이터의 양에 따라 계산량이 선형적으로 증가한다.
*	GoToTop(), GoToBottom()의 time complexity가 O(1)이 되려면
*	class 멤버 변수에 header, trailer의 주소를 저장하도록 하면 된다.
*/