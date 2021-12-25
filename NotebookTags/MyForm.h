#pragma once
#include "Note.h"
#include "Tag.h"
namespace NotebookTags {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Directory::CreateDirectory("..\\Notes");
			Directory::CreateDirectory("..\\Tags");
			RefreshListNotes();
			RefreshNotesWithTag();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^ ListNotes;
	private: System::Windows::Forms::Label^ NoteBox;
	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::TextBox^ TextNote;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::MenuStrip^ UpperList;
	private: System::Windows::Forms::ToolStripMenuItem^ Note;
	private: System::Windows::Forms::ToolStripMenuItem^ AddNotes;
	private: System::Windows::Forms::ToolStripMenuItem^ DeleteNote;
	private: System::Windows::Forms::ToolStripMenuItem^ SaveNote;
	private: System::Windows::Forms::ToolStripMenuItem^ Tag;
	private: System::Windows::Forms::ToolStripMenuItem^ AddTag;
	private: System::Windows::Forms::ToolStripMenuItem^ DeleteTag;

	private: System::Windows::Forms::PictureBox^ CloseButton;
	private: System::Windows::Forms::Panel^ UpPanel;
	private: System::Windows::Forms::ToolStripMenuItem^ ImportantTag;
	private: System::Windows::Forms::ToolStripMenuItem^ WorkTag;
	private: System::Windows::Forms::Label^ TagBox;
	private: System::Windows::Forms::TextBox^ TagText;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ NotesWithTag;









	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ListNotes = (gcnew System::Windows::Forms::ListBox());
			this->NoteBox = (gcnew System::Windows::Forms::Label());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->TextNote = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->UpperList = (gcnew System::Windows::Forms::MenuStrip());
			this->Note = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AddNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DeleteNote = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveNote = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Tag = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AddTag = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ImportantTag = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->WorkTag = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DeleteTag = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CloseButton = (gcnew System::Windows::Forms::PictureBox());
			this->UpPanel = (gcnew System::Windows::Forms::Panel());
			this->TagBox = (gcnew System::Windows::Forms::Label());
			this->TagText = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NotesWithTag = (gcnew System::Windows::Forms::ListBox());
			this->UpperList->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CloseButton))->BeginInit();
			this->UpPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// ListNotes
			// 
			this->ListNotes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(161)), static_cast<System::Int32>(static_cast<System::Byte>(161)),
				static_cast<System::Int32>(static_cast<System::Byte>(161)));
			this->ListNotes->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ListNotes->Dock = System::Windows::Forms::DockStyle::Left;
			this->ListNotes->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ListNotes->ForeColor = System::Drawing::Color::Black;
			this->ListNotes->ItemHeight = 33;
			this->ListNotes->Location = System::Drawing::Point(0, 36);
			this->ListNotes->Name = L"ListNotes";
			this->ListNotes->Size = System::Drawing::Size(194, 364);
			this->ListNotes->TabIndex = 0;
			this->ListNotes->Click += gcnew System::EventHandler(this, &MyForm::ListNotes_Click);
			// 
			// NoteBox
			// 
			this->NoteBox->AutoSize = true;
			this->NoteBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NoteBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->NoteBox->Location = System::Drawing::Point(219, 39);
			this->NoteBox->Name = L"NoteBox";
			this->NoteBox->Size = System::Drawing::Size(53, 25);
			this->NoteBox->TabIndex = 1;
			this->NoteBox->Text = L"Note";
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(194, 36);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 364);
			this->splitter1->TabIndex = 0;
			this->splitter1->TabStop = false;
			// 
			// TextNote
			// 
			this->TextNote->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(204)), static_cast<System::Int32>(static_cast<System::Byte>(204)),
				static_cast<System::Int32>(static_cast<System::Byte>(204)));
			this->TextNote->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TextNote->Location = System::Drawing::Point(224, 67);
			this->TextNote->Multiline = true;
			this->TextNote->Name = L"TextNote";
			this->TextNote->Size = System::Drawing::Size(520, 291);
			this->TextNote->TabIndex = 2;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// UpperList
			// 
			this->UpperList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->UpperList->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.35F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->UpperList->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->Note, this->Tag });
			this->UpperList->Location = System::Drawing::Point(0, 0);
			this->UpperList->Name = L"UpperList";
			this->UpperList->Size = System::Drawing::Size(895, 38);
			this->UpperList->TabIndex = 0;
			this->UpperList->Text = L"menuStrip1";
			this->UpperList->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::menuStrip1_MouseDown);
			this->UpperList->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::menuStrip1_MouseMove);
			// 
			// Note
			// 
			this->Note->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->AddNotes, this->DeleteNote,
					this->SaveNote
			});
			this->Note->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Note->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->Note->MergeAction = System::Windows::Forms::MergeAction::Replace;
			this->Note->Name = L"Note";
			this->Note->Size = System::Drawing::Size(106, 34);
			this->Note->Text = L"Заметка";
			// 
			// AddNotes
			// 
			this->AddNotes->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(164)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->AddNotes->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddNotes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
				static_cast<System::Int32>(static_cast<System::Byte>(9)));
			this->AddNotes->Name = L"AddNotes";
			this->AddNotes->Size = System::Drawing::Size(180, 28);
			this->AddNotes->Text = L"Добавить";
			this->AddNotes->Click += gcnew System::EventHandler(this, &MyForm::AddNote_Click);
			// 
			// DeleteNote
			// 
			this->DeleteNote->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(164)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->DeleteNote->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteNote->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
				static_cast<System::Int32>(static_cast<System::Byte>(9)));
			this->DeleteNote->Name = L"DeleteNote";
			this->DeleteNote->Size = System::Drawing::Size(180, 28);
			this->DeleteNote->Text = L"Удалить";
			this->DeleteNote->Click += gcnew System::EventHandler(this, &MyForm::DeleteNote_Click);
			// 
			// SaveNote
			// 
			this->SaveNote->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(164)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->SaveNote->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SaveNote->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
				static_cast<System::Int32>(static_cast<System::Byte>(9)));
			this->SaveNote->Name = L"SaveNote";
			this->SaveNote->Size = System::Drawing::Size(180, 28);
			this->SaveNote->Text = L"Сохранить";
			this->SaveNote->Click += gcnew System::EventHandler(this, &MyForm::SaveNote_Click);
			// 
			// Tag
			// 
			this->Tag->AutoSize = false;
			this->Tag->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->Tag->Checked = true;
			this->Tag->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Tag->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->Tag->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->AddTag, this->DeleteTag });
			this->Tag->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Tag->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->Tag->MergeAction = System::Windows::Forms::MergeAction::Insert;
			this->Tag->MergeIndex = 0;
			this->Tag->Name = L"Tag";
			this->Tag->Padding = System::Windows::Forms::Padding(0);
			this->Tag->Size = System::Drawing::Size(49, 34);
			this->Tag->Text = L"Тег";
			// 
			// AddTag
			// 
			this->AddTag->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(164)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->AddTag->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ImportantTag,
					this->WorkTag
			});
			this->AddTag->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddTag->ForeColor = System::Drawing::Color::Black;
			this->AddTag->Name = L"AddTag";
			this->AddTag->Size = System::Drawing::Size(180, 28);
			this->AddTag->Text = L"Добавить";
			// 
			// ImportantTag
			// 
			this->ImportantTag->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(164)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->ImportantTag->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ImportantTag->Name = L"ImportantTag";
			this->ImportantTag->Size = System::Drawing::Size(180, 26);
			this->ImportantTag->Text = L"Important";
			this->ImportantTag->Click += gcnew System::EventHandler(this, &MyForm::ImportantTag_Click);
			// 
			// WorkTag
			// 
			this->WorkTag->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(164)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->WorkTag->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WorkTag->Name = L"WorkTag";
			this->WorkTag->Size = System::Drawing::Size(180, 26);
			this->WorkTag->Text = L"Work";
			this->WorkTag->Click += gcnew System::EventHandler(this, &MyForm::WorkTag_Click);
			// 
			// DeleteTag
			// 
			this->DeleteTag->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(135)), static_cast<System::Int32>(static_cast<System::Byte>(164)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->DeleteTag->Font = (gcnew System::Drawing::Font(L"Lucida Bright", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteTag->Name = L"DeleteTag";
			this->DeleteTag->Size = System::Drawing::Size(180, 28);
			this->DeleteTag->Text = L"Удалить";
			this->DeleteTag->Click += gcnew System::EventHandler(this, &MyForm::DeleteTag_Click);
			// 
			// CloseButton
			// 
			this->CloseButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->CloseButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CloseButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CloseButton.Image")));
			this->CloseButton->Location = System::Drawing::Point(876, 0);
			this->CloseButton->Name = L"CloseButton";
			this->CloseButton->Size = System::Drawing::Size(19, 20);
			this->CloseButton->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->CloseButton->TabIndex = 0;
			this->CloseButton->TabStop = false;
			this->CloseButton->Click += gcnew System::EventHandler(this, &MyForm::CloseButton_Click);
			// 
			// UpPanel
			// 
			this->UpPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(250)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(102)));
			this->UpPanel->Controls->Add(this->CloseButton);
			this->UpPanel->Controls->Add(this->UpperList);
			this->UpPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->UpPanel->Location = System::Drawing::Point(0, 0);
			this->UpPanel->Name = L"UpPanel";
			this->UpPanel->Size = System::Drawing::Size(895, 36);
			this->UpPanel->TabIndex = 0;
			// 
			// TagBox
			// 
			this->TagBox->AutoSize = true;
			this->TagBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TagBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->TagBox->Location = System::Drawing::Point(750, 39);
			this->TagBox->Name = L"TagBox";
			this->TagBox->Size = System::Drawing::Size(41, 25);
			this->TagBox->TabIndex = 3;
			this->TagBox->Text = L"Tag";
			// 
			// TagText
			// 
			this->TagText->BackColor = System::Drawing::Color::DimGray;
			this->TagText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->TagText->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->TagText->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->TagText->ForeColor = System::Drawing::Color::Aqua;
			this->TagText->Location = System::Drawing::Point(747, 67);
			this->TagText->Margin = System::Windows::Forms::Padding(0);
			this->TagText->Multiline = true;
			this->TagText->Name = L"TagText";
			this->TagText->ReadOnly = true;
			this->TagText->Size = System::Drawing::Size(148, 47);
			this->TagText->TabIndex = 0;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(247)), static_cast<System::Int32>(static_cast<System::Byte>(252)),
				static_cast<System::Int32>(static_cast<System::Byte>(252)));
			this->label1->Location = System::Drawing::Point(750, 114);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(134, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Notes with tag";
			// 
			// NotesWithTag
			// 
			this->NotesWithTag->BackColor = System::Drawing::Color::DimGray;
			this->NotesWithTag->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->NotesWithTag->Font = (gcnew System::Drawing::Font(L"Lucida Sans Typewriter", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NotesWithTag->ForeColor = System::Drawing::Color::LightGray;
			this->NotesWithTag->ItemHeight = 18;
			this->NotesWithTag->Location = System::Drawing::Point(747, 142);
			this->NotesWithTag->Name = L"NotesWithTag";
			this->NotesWithTag->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->NotesWithTag->Size = System::Drawing::Size(148, 216);
			this->NotesWithTag->Sorted = true;
			this->NotesWithTag->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(895, 400);
			this->Controls->Add(this->NotesWithTag);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TagText);
			this->Controls->Add(this->TagBox);
			this->Controls->Add(this->TextNote);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->NoteBox);
			this->Controls->Add(this->ListNotes);
			this->Controls->Add(this->UpPanel);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MainMenuStrip = this->UpperList;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Note";
			this->TransparencyKey = System::Drawing::Color::Yellow;
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->UpperList->ResumeLayout(false);
			this->UpperList->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CloseButton))->EndInit();
			this->UpPanel->ResumeLayout(false);
			this->UpPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void RefreshListNotes();
	private: void RefreshTagText();
	private: void RefreshNotesWithTag();

	private: Point lastPoint;
	private: void RefreshCoordinates(System::Windows::Forms::MouseEventArgs^ e);

	private: System::Void menuStrip1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { RefreshCoordinates(e); }
	private: System::Void menuStrip1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { lastPoint = Point(e->X, e->Y); }
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { RefreshCoordinates(e); }
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) { lastPoint = Point(e->X, e->Y); }

	private: System::Void ListNotes_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SaveNote_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DeleteNote_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void AddNote_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void CloseButton_Click(System::Object^ sender, System::EventArgs^ e) { this->Close(); }
	private: System::Void ImportantTag_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void WorkTag_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DeleteTag_Click(System::Object^ sender, System::EventArgs^ e);
};
};