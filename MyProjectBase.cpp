///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MyProjectBase.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxSize( 1485,1000 ), wxSize( 1500,1000 ) );

	m_statusBar1 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
	m_menubar3 = new wxMenuBar( 0 );
	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItemAbout;
	m_menuItemAbout = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItemAbout );

	m_menubar3->Append( m_menu4, _("Help") );

	this->SetMenuBar( m_menubar3 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Site Selector"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer91->Add( m_staticText4, 0, wxALL|wxEXPAND, 5 );

	m_comboBoxSites = new wxComboBox( this, wxID_ANY, _("RSIL"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_comboBoxSites->Append( _("22 Wing") );
	m_comboBoxSites->Append( _("3 Wing") );
	m_comboBoxSites->Append( _("4 Wing") );
	m_comboBoxSites->Append( _("TSIL") );
	m_comboBoxSites->Append( _("RSIL") );
	bSizer91->Add( m_comboBoxSites, 0, wxALL|wxEXPAND, 5 );


	bSizer2->Add( bSizer91, 1, wxEXPAND, 5 );

	m_BN_RunOnce = new wxButton( this, wxID_ANY, _("Run Once"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_BN_RunOnce, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5 );

	m_BN_RunPeriodic = new wxButton( this, wxID_ANY, _("Run Periodic"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_BN_RunPeriodic, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Alive"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer5->Add( m_staticText1, 0, wxALL, 5 );

	m_textAliveCount = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_textAliveCount, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Dead Count"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL, 5 );

	m_textDeadCount = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_textDeadCount, 0, wxALL, 5 );


	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_static3 = new wxStaticText( this, wxID_ANY, _("Zombie Count"), wxDefaultPosition, wxDefaultSize, 0 );
	m_static3->Wrap( -1 );
	bSizer8->Add( m_static3, 0, wxALL, 5 );

	m_textZombieCount = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_textZombieCount, 0, wxALL, 5 );


	bSizer2->Add( bSizer8, 1, wxEXPAND, 5 );


	bSizer18->Add( bSizer2, 1, wxFIXED_MINSIZE, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );

	m_grid2 = new wxGrid( this, wxID_ANY, wxPoint( -1,-1 ), wxSize( -1,-1 ), 0 );

	// Grid
	m_grid2->CreateGrid( 9, 8 );
	m_grid2->EnableEditing( false );
	m_grid2->EnableGridLines( true );
	m_grid2->EnableDragGridSize( false );
	m_grid2->SetMargins( 0, 0 );

	// Columns
	m_grid2->EnableDragColMove( false );
	m_grid2->EnableDragColSize( true );
	m_grid2->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grid2->EnableDragRowSize( true );
	m_grid2->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grid2->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_TOP );
	bSizer28->Add( m_grid2, 0, wxALIGN_LEFT|wxALL|wxEXPAND, 5 );


	bSizer18->Add( bSizer28, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,400 ), wxHSCROLL|wxTE_MULTILINE|wxTE_WORDWRAP );
	bSizer9->Add( m_textCtrl3, 0, wxALL|wxEXPAND, 10 );


	bSizer18->Add( bSizer9, 1, wxALIGN_BOTTOM|wxEXPAND, 5 );


	this->SetSizer( bSizer18 );
	this->Layout();
	m_timer1.SetOwner( this, m_timer1.GetId() );
	m_timer1.Start( 5000 );


	this->Centre( wxBOTH );

	// Connect Events
	m_menu4->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::m_menuItemAboutOnMenuSelection ), this, m_menuItemAbout->GetId());
	m_comboBoxSites->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrame1::m_comboBoxSitesOnCombobox ), NULL, this );
	m_BN_RunOnce->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_BN_RunOnceOnButtonClick ), NULL, this );
	m_BN_RunPeriodic->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_BN_RunPeriodicOnButtonClick ), NULL, this );
	this->Connect( m_timer1.GetId(), wxEVT_TIMER, wxTimerEventHandler( MyFrame1::m_timer1OnTimer ) );
}

MyFrame1::~MyFrame1()
{
}
