#include "MyProject2MyFrame1.h"

#include "BG_ICMP.h"

extern int QueueSize;
extern std::vector<aNetDevice> ScanList;


MyProject2MyFrame1::MyProject2MyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	// Give the frame an icon
	SetIcon(wxICON(sample));

	InitICMP();
	m_grid2->SetColLabelValue(0, "ADZ");
	m_grid2->SetColLabelValue(1, "IP");
	m_grid2->SetColLabelValue(2, "Host Name");
	m_grid2->SetColLabelValue(3, "Ping Count");
	m_grid2->SetColLabelValue(4, "RTT [ms]");
	m_grid2->SetColLabelValue(5, "Last Ping");

	// We can set the sizes of individual rows and columns in pixels
	//m_grid2->SetRowSize(0, 60);

	// We can specify the some cells will store numeric
	// values rather than strings. Here we set grid column 5
	// to hold floating point values displayed with width of 6
	// and precision of 2
	m_grid2->SetColFormatNumber(3);
	m_grid2->SetColFormatNumber(4);
	//m_grid2->SetColFormatFloat(4, 3, 2);
	//m_grid2->SetColFormatDate(4, 3, 2);

	//m_grid2->SetColSize(4, 80);
	m_grid2->SetColSize(5,260);

}


void MyProject2MyFrame1::SetRow(aNetDevice a, int row)
{
	char buf[40];
	m_grid2->SetCellTextColour(row, 0, *wxGREEN);

	if (NEVERPINGED == a.myStatus) {
		m_grid2->SetCellTextColour(row, 0, *wxBLACK);
		m_grid2->SetCellValue(row, 0, "N");
	}
	else if (ALIVE == a.myStatus) m_grid2->SetCellValue(row, 0, "A");
	else if (ZOMBIE == a.myStatus) m_grid2->SetCellValue(row, 0, "Z");
	else if (DEAD == a.myStatus)
	{
		m_grid2->SetCellTextColour(row, 0, *wxRED);
		m_grid2->SetCellValue(row, 0, "D"); //DEAD
	}

	m_grid2->SetCellValue(row, 1, a.IPtoPing);
	m_grid2->SetCellValue(row, 2, a.endPointName);


	sprintf(buf, "%03d", a.pingCounter);
	m_grid2->SetCellValue(row, 3, buf);
	if (NEVERPINGED == a.myStatus) m_grid2->SetCellValue(row, 4, "-");
	else if (DEAD != a.myStatus)
	{
		sprintf(buf, "%d", (int)a.RoundTripTime);
		m_grid2->SetCellValue(row, 4, buf);
	}
	//m_grid2->SetCellValue(row, 4, buf);


	//DTG
	if ((NEVERPINGED != a.myStatus) && (true == a.wasAliveAtLeastOnce))
	{
		sprintf(buf, "%04d-%02d-%02d at %02d:%02d:%02d", a.st.wYear, a.st.wMonth, a.st.wDay, a.st.wHour, a.st.wMinute, a.st.wSecond);
		m_grid2->SetCellValue(row, 5, buf);
	}
}

void MyProject2MyFrame1::pme(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	char buf[200];
	vsprintf(buf, fmt, args);
	m_textCtrl3->AppendText(buf);
	m_textCtrl3->AppendText("\r\n");
	va_end(args);
}



void MyProject2MyFrame1::m_BN_LoadHostListOnButtonClick( wxCommandEvent& event )
{
	std::vector<std::pair<std::string, std::string>> ipNlist;
	ipNlist.push_back(std::make_pair("192.168.1.1", "ASUS"));
	ipNlist.push_back(std::make_pair("192.168.1.99", "X99"));
	ipNlist.push_back(std::make_pair("192.168.1.121", "ESX"));
	ipNlist.push_back(std::make_pair("192.168.1.8", "T-Link8"));
	ipNlist.push_back(std::make_pair("192.168.1.196", "Legion"));
	ipNlist.push_back(std::make_pair("8.8.8.8", "Google"));
	CreateScanList(ipNlist);

	int i = 0;
	for (auto a : ScanList)  SetRow(a, i++);

	pme("Created Scan List");

}

void MyProject2MyFrame1::m_BN_RunOnceOnButtonClick( wxCommandEvent& event )
{
	pme("Starting Single Scan");
	ScanIPList();
	ShowScanList();
}

void MyProject2MyFrame1::m_BN_RunPeriodicOnButtonClick( wxCommandEvent& event )
{

	
	//ShowScanList();
	int i = 0;
	for (auto a : ScanList)  SetRow(a, i++);

}



void MyProject2MyFrame1::ShowScanList()
{
	int AliveCount = 0;
	int DeadCount = 0;
	int ZombieCount = 0;


	for (int x = 0; x < ScanList.size(); x++)
	{
		if (ScanList[x].myStatus == ALIVE) AliveCount++;
		else if (ScanList[x].myStatus == DEAD) DeadCount++;
		else if (ScanList[x].myStatus == ZOMBIE) ZombieCount++;

		char s = 'A';    // for alive
		if (ScanList[x].myStatus == ZOMBIE) s = 'Z';      //for zombie
		if (ScanList[x].myStatus == DEAD) s = 'D';      //for Dead
		//printf("%c Index: %03d  Ping Count %03d IP: %s reply: %ld\r\n",s, x, ScanList[x].pingCounter, ScanList[x].IPtoPing, ScanList[x].RoundTripTime);
		pme("%c Index: %03d  Ping Count %03d IP: %s reply: %ld",s, x, ScanList[x].pingCounter, ScanList[x].IPtoPing, ScanList[x].RoundTripTime);
		int age = (int)ScanList[x].st.wSecond;
		char lastAliveDTG[40];
		sprintf(lastAliveDTG, "%04d-%02d-%02d at %02d:%02d:%02d", ScanList[x].st.wYear, ScanList[x].st.wMonth, ScanList[x].st.wDay, ScanList[x].st.wHour, ScanList[x].st.wMinute, ScanList[x].st.wSecond);
		pme("%c  IP: %s \t%s \tPing Count %03d reply: %ld  last:%s", s, ScanList[x].IPtoPing, ScanList[x].endPointName.c_str(), ScanList[x].pingCounter, ScanList[x].RoundTripTime, lastAliveDTG);
		
		SetRow(ScanList[x], x);
		
	}

	//printf("There are %d ALIVE, %d DEAD, and %d ZOMBIEs\r\n", AliveCount, DeadCount, ZombieCount);
	//printf("Jobs in Queue: %d\r\n", QueueSize);
	pme("There are %d ALIVE, %d DEAD, and %d ZOMBIEs", AliveCount, DeadCount, ZombieCount);
	pme("Jobs in Queue: %d", QueueSize);


	//TP_POOL_STACK_INFORMATION SI;
	//bool val = QueryThreadpoolStackInformation(pool,&SI);


}

//wxMessageBox("8 Wing", "TB Clicked", wxOK | wxICON_INFORMATION);


/*
void MyProject2MyFrame1::m_tool8OnToolClicked( wxCommandEvent& event )
{


// We can specify the some cells will store numeric
// values rather than strings. Here we set grid column 5
// to hold floating point values displayed with width of 6
// and precision of 2
m_grid2->SetColFormatFloat(3, 3, 2);
m_grid2->SetCellValue(0, 3, "3.1415");

m_grid2->SetReadOnly(0, 3);

m_grid2->SetCellValue(0, 0, "192.168.1.99");
m_grid2->SetCellValue(0, 1, "ASUS RTX");
m_grid2->SetCellValue(0, 2, "45");
m_grid2->SetCellValue(1, 3, "4.23");
m_grid2->SetCellValue(0, 4, "2025-07-27 at 09:32:00");

// Colours can be specified for grid cell contents
m_grid2->SetCellBackgroundColour(0, 3, *wxLIGHT_GREY);
m_grid2->SetCellTextColour(0, 3, *wxGREEN); //PEN_GREEN
m_grid2->SetCellTextColour(1, 3, *wxRED);


m_grid2->SetCellValue(1, 3, "45.23");

m_grid2->SetCellValue(4, 3, "1.02");

m_grid2->AutoSize();





}
*/


MyProject2MyFrame1::~MyProject2MyFrame1()
{
	ShutDownICMP();

}




