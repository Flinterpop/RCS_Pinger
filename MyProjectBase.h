///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/grid.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar3;
		wxMenu* m_menu4;
		wxStaticText* m_staticText4;
		wxComboBox* m_comboBoxSites;
		wxButton* m_BN_RunOnce;
		wxButton* m_BN_RunPeriodic;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textAliveCount;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textDeadCount;
		wxStaticText* m_static3;
		wxTextCtrl* m_textZombieCount;
		wxGrid* m_grid2;
		wxTextCtrl* m_textCtrl3;
		wxTimer m_timer1;

		// Virtual event handlers, override them in your derived class
		virtual void m_menuItemAboutOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxSitesOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_BN_RunOnceOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_BN_RunPeriodicOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_timer1OnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("R&CS Ping Tester"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1485,1000 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, const wxString& name = wxT("wx Pinger") );

		~MyFrame1();

};

