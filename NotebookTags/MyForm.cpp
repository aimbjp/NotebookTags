#include "MyForm.h"

using namespace System;
using namespace Windows::Forms;

[STAThreadAttribute]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	NotebookTags::MyForm form;
	Application::Run(% form);
	
}

void NotebookTags::MyForm::RefreshListNotes()
{
	this->ListNotes->Items->Clear();
	auto files = Directory::GetFiles("..\\Notes\\");
	for (int i = 0; i < files->Length; i++) {
		this->ListNotes->Items->Add(Path::GetFileName(files[i]));
	}

}

void NotebookTags::MyForm::RefreshTagText()
{
	auto name = ListNotes->Text;
	if (File::Exists("..\\Tags\\" + name))
	{
		this->TagText->Text = File::ReadAllText("..\\Tags\\" + name, System::Text::Encoding::Default);
	}
	else
	{
		this->TagText->Text = "No tag";
	}
	RefreshNotesWithTag();
}

void NotebookTags::MyForm::RefreshNotesWithTag()
{
	this->NotesWithTag->Items->Clear();
	auto files = Directory::GetFiles("..\\Tags\\");
	for (int i = 0; i < files->Length; i++) {
		this->NotesWithTag->Items->Add(Path::GetFileName(files[i]));
	}
}

void NotebookTags::MyForm::RefreshCoordinates(System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		this->Left += e->X - lastPoint.X;
		this->Top += e->Y - lastPoint.Y;
	}
}

System::Void NotebookTags::MyForm::AddNote_Click(System::Object^ sender, System::EventArgs^ e)
{
	auto ifNoteCreated = Note::CreateNote();
	String^ name = ListNotes->Text;
	this->TextNote->Text = "New note has been added!";
	RefreshListNotes();
}

System::Void NotebookTags::MyForm::ImportantTag_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = ListNotes->Text;
	if (name != "")
	{
		ImportantTag::CreateTag(toStandardString(name));
		RefreshTagText();
	}
	else
	{
		this->TagText->Text = "Choose note from list.";
	}
}

System::Void NotebookTags::MyForm::WorkTag_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = ListNotes->Text;
	if (name != "")
	{
		WorkTag::CreateTag(toStandardString(name));
		RefreshTagText();
	}
	else
	{
		this->TagText->Text = "Choose note from list.";
	}
}

System::Void NotebookTags::MyForm::DeleteTag_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = ListNotes->Text;
	if (name != "" && this->TagText->Text != "No tag")
	{
		MyTag::DeleteTag(toStandardString(name));
		this->TagText->Text = "Deleted...";
		RefreshNotesWithTag();
	}
	else if (this->TagText->Text != "No tag")
	{
		this->TagText->Text = "Choose note from list.";
	}

}

System::Void NotebookTags::MyForm::ListNotes_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = ListNotes->Text;
	if (name != "")
	{
		this->TextNote->Text = File::ReadAllText("..\\Notes\\" + name, System::Text::Encoding::Default);
		this->NoteBox->Text = name;
		RefreshTagText();
	}
}

System::Void NotebookTags::MyForm::SaveNote_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = ListNotes->Text;
	if (name != "")
	{
		std::ofstream note = Note::OpenNoteForWrite(toStandardString(name));
		note << toStandardString(this->TextNote->Text);
		this->NoteBox->Text = name + " has been saved!";
		note.close();
	}
	else
	{
		this->NoteBox->Text = "Choose note from list.";

	}
}

System::Void NotebookTags::MyForm::DeleteNote_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = ListNotes->Text;
	if (name != "")
	{
		Note::DeleteNote(toStandardString(name));
		MyTag::DeleteTag(toStandardString(name));
		this->TextNote->Text = name + " has been deleted...";
		RefreshListNotes();
		RefreshTagText();
		this->TagText->Text = "Deleted...";
	}
	else
	{
		this->NoteBox->Text = "Choose note from list.";
	}
}

