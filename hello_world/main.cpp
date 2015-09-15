#include "wx_pch.h"
class HelloWorldApp: public wxApp
{
        virtual bool OnInit();
};

class HelloWorldFrame: public wxFrame
{
    public:
        HelloWorldFrame ( const wxString& titile, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize );
        void OnQuit ( wxCommandEvent& event );
        void OnAbout ( wxCommandEvent& event );
    private:
        DECLARE_EVENT_TABLE()
};

DECLARE_APP( HelloWorldApp )
IMPLEMENT_APP( HelloWorldApp )

enum {
    ID_Quit = 1,
    ID_About
};

BEGIN_EVENT_TABLE(HelloWorldFrame, wxFrame)
    EVT_MENU(ID_Quit,HelloWorldFrame::OnQuit)
    EVT_MENU(ID_About,HelloWorldFrame::OnAbout)
END_EVENT_TABLE()
//=======================================================================方法实现===========================================
    bool HelloWorldApp::OnInit()
    {
        HelloWorldFrame* frame = new HelloWorldFrame ( "HELLO WORLD" );
        frame-> Show ( true );
        SetTopWindow ( frame );
        return true;
    }

    HelloWorldFrame::HelloWorldFrame ( const wxString & title, const wxPoint & pos, const wxSize & size ) : wxFrame ( ( wxFrame* ) NULL, -1, title, pos,  size )
    {
        wxMenu* menuFile = new wxMenu;
        menuFile->Append ( ID_Quit, _T ( "E&xit" ) );

        wxMenu* menuHelp = new wxMenu;
        menuHelp->Append ( ID_About, _T ( "&Help" ) );

        wxMenuBar* menuBar = new wxMenuBar;
        menuBar->Append ( menuFile, _T ( "&File" ) );
        menuBar->Append ( menuHelp, _T ( "&Help" ) );

        SetMenuBar( menuBar );

        CreateStatusBar();
        SetStatusText("welcome to wxWidgets!");
    }

    void HelloWorldFrame::OnQuit ( wxCommandEvent & event  )
    {
        Close( true );
    }

    void HelloWorldFrame::OnAbout( wxCommandEvent &  event   )
    {
        wxMessageBox( "This is a wxWidgets` sample", "About hello world", wxOK );
    }


