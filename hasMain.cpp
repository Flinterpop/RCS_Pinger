// Start of wxWidgets "Hello World" Program
#include <wx/wx.h>

#include "MyProject2MyFrame1.h"

class MyApp : public wxApp
{
public:
    bool OnInit() override;

    ~MyApp() override
    {

    };


};

wxIMPLEMENT_APP(MyApp);



bool MyApp::OnInit()
{
    MyProject2MyFrame1* frame = new MyProject2MyFrame1(NULL);
    frame->Show(true);

    return true;
}

