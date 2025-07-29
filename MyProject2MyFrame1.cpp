#include "MyProject2MyFrame1.h"

#include "BG_ICMP.h"


extern int QueueSize;
extern std::vector<aNetDevice> ScanList;



MyProject2MyFrame1::MyProject2MyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	// Give the frame/app an icon
	SetIcon(wxICON(sample));

	InitICMP();
	m_grid2->SetColLabelValue(0, "ADZ");
	m_grid2->SetColSize(0, 40);
	
	m_grid2->SetColLabelValue(1, "IP");
	m_grid2->SetColSize(0, 150);

	m_grid2->SetColLabelValue(2, "Host Name");
	//m_grid2->SetColSize(0, 150);
	
	m_grid2->SetColLabelValue(3, "#Ping\r\nTries");
	m_grid2->SetColSize(3, 85);

	m_grid2->SetColLabelValue(4, "#Ping\r\nSuccess");
	m_grid2->SetColSize(4, 85);

	m_grid2->SetColLabelValue(5, "RTT [ms]");
	m_grid2->SetColLabelValue(6, "Last Ping");
	m_grid2->SetColSize(6, 260);

	m_grid2->SetColLabelValue(7, "Notes");
	m_grid2->SetColSize(7, 300);

	m_grid2->SetColFormatNumber(3);
	m_grid2->SetColFormatNumber(4);
	//m_grid2->SetColFormatFloat(4, 3, 2);
	//m_grid2->SetColFormatDate(4, 3, 2);


	BuildScanList();

	ScanIPList();
	ShowScanList();

	if (m_timer1.IsRunning())
	{
		m_BN_RunPeriodic->SetLabel("Stop Periodic");
	}
	else
	{
		m_BN_RunPeriodic->SetLabel("Start Periodic");
	}



}

void MyProject2MyFrame1::m_comboBoxSitesOnCombobox(wxCommandEvent& event)
{
	BuildScanList();
}

void MyProject2MyFrame1::BuildScanList(void)
{
	int numRows = m_grid2->GetNumberRows();
	// Begin a batch operation for performance, especially with many rows
	m_grid2->BeginBatch();
	// Iterate backward and delete each row
	for (int i = numRows - 1; i >= 0; --i) {
		m_grid2->DeleteRows(i, 1); // Delete 1 row starting at index i
	}
	m_grid2->EndBatch();

	m_textAliveCount->SetValue("0");
	m_textDeadCount->SetValue("0");
	m_textZombieCount->SetValue("0");



	std::vector<std::pair<std::string, std::string>> ipNlist;

	auto t = m_comboBoxSites->GetValue();

	if ("22 Wing" == t)
	{
		ipNlist.push_back(std::make_pair("1.3.129.1", "ARISTA 7200"));
		ipNlist.push_back(std::make_pair("1.3.129.2", "ARISTA 720"));
		ipNlist.push_back(std::make_pair("1.3.129.3", "Taclane CT"));
		ipNlist.push_back(std::make_pair("8.8.8.8", "Google"));
	}
	if ("3 Wing" == t)
	{
		ipNlist.push_back(std::make_pair("1.3.37.1", "ARISTA 7200"));
		ipNlist.push_back(std::make_pair("1.3.37.2", "ARISTA 720"));
		ipNlist.push_back(std::make_pair("1.3.37.3", "Taclane CT"));
		ipNlist.push_back(std::make_pair("8.8.8.8", "Google"));
	}
	if ("4 Wing" == t)
	{
		ipNlist.push_back(std::make_pair("1.3.56.1", "ARISTA 7200"));
		ipNlist.push_back(std::make_pair("1.3.56.2", "ARISTA 720"));
		ipNlist.push_back(std::make_pair("1.3.56.3", "Taclane CT"));
		ipNlist.push_back(std::make_pair("8.8.8.8", "Google"));
	}
	if ("TSIL" == t)
	{
		ipNlist.push_back(std::make_pair("192.168.123.1", "BATS-D"));
		ipNlist.push_back(std::make_pair("192.168.1.1", "ARISTA"));

	}
	if ("RSIL" == t)
	{
		ipNlist.push_back(std::make_pair("192.168.1.1", "ASUS"));
		ipNlist.push_back(std::make_pair("192.168.2.1", "Bell"));
		ipNlist.push_back(std::make_pair("192.168.1.7", "Lair?"));
		ipNlist.push_back(std::make_pair("192.168.1.8", "T-Link8"));
		ipNlist.push_back(std::make_pair("192.168.1.9", "T-Link9"));
		ipNlist.push_back(std::make_pair("192.168.1.18", "HP Printer"));
		ipNlist.push_back(std::make_pair("192.168.1.19", "Printer"));
		ipNlist.push_back(std::make_pair("192.168.1.121", "ESX"));
		ipNlist.push_back(std::make_pair("192.168.1.136", "ADS-B"));

		ipNlist.push_back(std::make_pair("192.168.1.200", "NAS"));
		ipNlist.push_back(std::make_pair("192.168.1.251", "NTP"));

		ipNlist.push_back(std::make_pair("192.168.1.196", "Legion"));
		ipNlist.push_back(std::make_pair("8.8.8.8", "Google"));
	}

	else
	{
		ipNlist.push_back(std::make_pair("8.8.8.8", "Google"));
	}

	CreateScanList(ipNlist);
	numRows = ipNlist.size();

	m_grid2->AppendRows(numRows);
	//delete m_grid2;
	//m_grid2->CreateGrid(numRows, 8);


	int i = 0;
	for (auto a : ScanList)  SetRow(a, i++);

	pme("Created Scan List");
}

void MyProject2MyFrame1::m_BN_LoadHostListOnButtonClick( wxCommandEvent& event )
{
	BuildScanList();
}

void MyProject2MyFrame1::m_BN_RunOnceOnButtonClick( wxCommandEvent& event )
{
	pme("Starting Single Scan");
	ScanIPList();
	ShowScanList();

	auto a = this->GetSize();
	pme("Size: %d %d", a.x, a.y);
	pme("Timer is %srunning", m_timer1.IsRunning() ? "":"not ");

}

void MyProject2MyFrame1::m_BN_RunPeriodicOnButtonClick( wxCommandEvent& event )
{
	if (m_timer1.IsRunning())
	{
		m_timer1.Stop();
		m_BN_RunPeriodic->SetLabel("Stop Periodic");
	}
	else
	{
		m_timer1.Start();
		m_BN_RunPeriodic->SetLabel("Start Periodic");
	}

	ShowScanList();

}

void MyProject2MyFrame1::m_timer1OnTimer( wxTimerEvent& event )
{
	pme("Scan..");
	ScanIPList();
	ShowScanList();
}



MyProject2MyFrame1::~MyProject2MyFrame1()
{
	ShutDownICMP();
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

		//pme("%c Index: %03d  Ping Count %03d IP: %s reply: %ld Status: %d",s, x, ScanList[x].pingCounter, ScanList[x].IPtoPing, ScanList[x].RoundTripTime, ScanList[x].PingStatus);
		if (0!= ScanList[x].PingStatus) pme("%c Index: %03d  Ping Count %03d IP: %s reply: %ld Status: %d", s, x, ScanList[x].pingCounter, ScanList[x].IPtoPing, ScanList[x].RoundTripTime, ScanList[x].PingStatus);
		//int age = (int)ScanList[x].st.wSecond;

		
		SetRow(ScanList[x], x);
	}

	char buf[40];
	sprintf(buf, "%d", AliveCount);
	m_textAliveCount->SetValue(buf);
	sprintf(buf, "%d", DeadCount);
	m_textDeadCount->SetValue(buf);
	sprintf(buf, "%d", ZombieCount);
	m_textZombieCount->SetValue(buf);

	//pme("Jobs in Queue: %d", QueueSize);

	//TP_POOL_STACK_INFORMATION SI;
	//bool val = QueryThreadpoolStackInformation(pool,&SI);
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

void MyProject2MyFrame1::SetRow(aNetDevice a, int row)
{
	char buf[40];

	if (NEVERPINGED == a.myStatus) {
		m_grid2->SetCellTextColour(row, 0, *wxBLACK);
		m_grid2->SetCellValue(row, 0, "N");
	}
	else if (ALIVE == a.myStatus)
	{
		m_grid2->SetCellTextColour(row, 0, *wxGREEN);
		m_grid2->SetCellValue(row, 0, "Alive");
	}
	else if (ZOMBIE == a.myStatus)
	{
		m_grid2->SetCellTextColour(row, 0, *wxGREEN);
		m_grid2->SetCellValue(row, 0, "Zombie");
	}
	else if (DEAD == a.myStatus)
	{
		m_grid2->SetCellTextColour(row, 0, *wxRED);
		m_grid2->SetCellValue(row, 0, "Dead"); //DEAD
	}

	m_grid2->SetCellValue(row, 1, a.IPtoPing);
	m_grid2->SetCellValue(row, 2, a.endPointName);


	sprintf(buf, "%03d", a.pingTries);
	m_grid2->SetCellValue(row, 3, buf);

	sprintf(buf, "%03d", a.pingCounter);
	m_grid2->SetCellValue(row, 4, buf);

	if (NEVERPINGED == a.myStatus) m_grid2->SetCellValue(row, 5, "-");
	else if ((ALIVE == a.myStatus) || (ZOMBIE== a.myStatus))
	{
		sprintf(buf, "%d", (int)a.RoundTripTime);
		m_grid2->SetCellValue(row, 5, buf);
	}
	else
	{
		m_grid2->SetCellValue(row, 5, "-");
	}

	//DTG
	if ((NEVERPINGED != a.myStatus) && (true == a.wasAliveAtLeastOnce))
	{
		sprintf(buf, "%04d-%02d-%02d at %02d:%02d:%02d", a.st.wYear, a.st.wMonth, a.st.wDay, a.st.wHour, a.st.wMinute, a.st.wSecond);
		m_grid2->SetCellValue(row, 6, buf);
	}

	//Status
	auto t = ICMP_Status.find(a.PingStatus);
	if (t != ICMP_Status.end()) 
	{
		std::string T = t->second;
		sprintf(buf, "%s", T.c_str());
		m_grid2->SetCellValue(row, 7, buf);
	}
	else
	{
		m_grid2->SetCellValue(row, 7, "no map");
	}

}




