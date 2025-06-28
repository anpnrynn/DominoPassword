
// DominoPasswordDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "DominoPassword.h"
#include "DominoPasswordDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDominoPasswordDlg dialog



CDominoPasswordDlg::CDominoPasswordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DOMINOPASSWORD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	colorDefault = RGB(253, 253, 253); // Default color for buttons
	colorRed = RGB(255, 0, 0); // Red color for buttons
	colorGreen = RGB(0, 255, 0); // Green color for buttons
	colorBlue = RGB(0, 0, 255); // Blue color for buttons

	resetData();
	
}


void CDominoPasswordDlg::resetData()
{
	pattern = 1;
	shuffledData[0] = 0;
	strcpy_s(initialData, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz!$'*+,-./:;<=>?^_`~$'*+,-./:;<=>?^_`");
	strcpy_s(initialData2, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`~!@#$%^&*()_+-={}|[]\\\\:\\\";'<>?,./^&*()_+-={}|[]\";");
	int i = 0;
	while (i < 108) {
		activeButton[i] = 0;
		i++;
	}
	versionToUse = 1; // Default version
	memset(shuffledData, 0, sizeof(shuffledData)); // Clear the shuffled data
}

void CDominoPasswordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDominoPasswordDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDominoPasswordDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDominoPasswordDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDominoPasswordDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDominoPasswordDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDominoPasswordDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDominoPasswordDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDominoPasswordDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDominoPasswordDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDominoPasswordDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CDominoPasswordDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CDominoPasswordDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CDominoPasswordDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CDominoPasswordDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CDominoPasswordDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CDominoPasswordDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CDominoPasswordDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CDominoPasswordDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CDominoPasswordDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CDominoPasswordDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CDominoPasswordDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CDominoPasswordDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CDominoPasswordDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CDominoPasswordDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &CDominoPasswordDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CDominoPasswordDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CDominoPasswordDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CDominoPasswordDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &CDominoPasswordDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CDominoPasswordDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CDominoPasswordDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON31, &CDominoPasswordDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON32, &CDominoPasswordDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON33, &CDominoPasswordDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON34, &CDominoPasswordDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON35, &CDominoPasswordDlg::OnBnClickedButton35)
	ON_BN_CLICKED(IDC_BUTTON36, &CDominoPasswordDlg::OnBnClickedButton36)
	ON_BN_CLICKED(IDC_BUTTON37, &CDominoPasswordDlg::OnBnClickedButton37)
	ON_BN_CLICKED(IDC_BUTTON38, &CDominoPasswordDlg::OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON39, &CDominoPasswordDlg::OnBnClickedButton39)
	ON_BN_CLICKED(IDC_BUTTON40, &CDominoPasswordDlg::OnBnClickedButton40)
	ON_BN_CLICKED(IDC_RADIO1, &CDominoPasswordDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDominoPasswordDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDominoPasswordDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CDominoPasswordDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CDominoPasswordDlg message handlers

BOOL CDominoPasswordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO1);
	if (pButton)
	{
		pButton->SetCheck(BST_CHECKED); // Set the first radio button as checked
	}
	//pattern = 2;
	//loadButtons(); // Load buttons with the initial pattern
	//pattern = 1;
	//loadButtons(); // Load buttons with the initial pattern
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDominoPasswordDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDominoPasswordDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDominoPasswordDlg::changeColor(CButton* pButton, COLORREF color)
{
	if (pButton)
	{
		pButton->ModifyStyle(0, BS_OWNERDRAW);
		CBrush brush(color);
		CRect rect;
		pButton->GetClientRect(&rect);
		rect.DeflateRect(4, 4);
		CClientDC dc(pButton);
		dc.FillRect(&rect, &brush);
	}
}


void CDominoPasswordDlg::resetButtons()
{
	for (int i = 0; i < 36; i++)
	{
		CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON5 + i);
		if (pButton)
		{
			//pButton->SetWindowText(_T("Button " + std::to_wstring(i + 1).c_str()));
			changeColor(pButton, colorDefault); // Reset button color to default
			
		}
	}
	for (int i = 0; i < 108; i++)
	{
		activeButton[i] = 0; // Reset all buttons to inactive
	}
	CStatic* staticPattern = (CStatic*)GetDlgItem(IDC_STATIC_PATTERN);
	if (staticPattern)
	{
		CString strPattern;
		strPattern.Format(_T("Pattern: %d/3"), pattern);
		staticPattern->SetWindowText(strPattern);
	}
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	if (pEdit)
	{
		pEdit->SetWindowText(_T("")); // Clear the edit control
	}
	CEdit* pPinEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	if (pPinEdit)
	{
		pPinEdit->SetWindowText(_T("")); // Clear the PIN edit control
	}
	memset(shuffledData, 0, sizeof(shuffledData)); // Clear the shuffled data
	CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_MSG);
	if (pStatic)
	{
		pStatic->SetWindowText(_T("Set pin and click Generate")); // Clear the static message
	}
}

void CDominoPasswordDlg::loadButtons()
{
	int i = (pattern - 1 ) * 36;
	int n = (pattern - 1) * 36 + 36;
	COLORREF color = colorDefault;
	switch (pattern) {
		case 1:
			color = colorRed; // Change button color to red
			break;
		case 2:
			color = colorGreen; // Change button color to green
			break;
		case 3:
			color = colorBlue; // Change button color to blue
			break;
	}
	for (; i < n; i++)
	{
		CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON5 + i - ( (pattern - 1)*36 ) );
		if (pButton)
		{
			if( activeButton[i] == 1 )
				changeColor(pButton, color); // Set button color to red
			else
				changeColor(pButton, colorDefault); // Reset button color to default
		}
	}
	CStatic* staticPattern = (CStatic*)GetDlgItem(IDC_STATIC_PATTERN);
	if (staticPattern)
	{
		CString strPattern;
		strPattern.Format(_T("Pattern: %d/3"), pattern);
		staticPattern->SetWindowText(strPattern);
	}
	

}


void gen1_rotate(char* data, int count, int n) {
	char tmpdata[128];
	memcpy(tmpdata, data, count);
	memcpy(data, &data[count], n - count);
	memcpy(&data[n - count], tmpdata, count);
}


void gen1_swapchars(char* data, int i, int j, int n) {
	char tmp = 0;
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}


void gen1_shuffle(char* data, int pin) {
	int n = strlen(data);
	int k = 1;
	for (int j = 0; j < pin; j++) {
		char* s1 = &data[0];
		char* s2 = &data[n / 2];

		for (int i = 0; i < n / 4; i++) {
			if (k % 2 == 0) {
				gen1_swapchars(s1, i, n / 2 - i - 1, n / 2);
				gen1_swapchars(s2, i, n / 2 - i - 1, n / 2);
			}
			else {
				gen1_swapchars(s1, i, n / 2 - i - 2, n / 2);
				gen1_swapchars(s2, i, n / 2 - i - 2, n / 2);
			}
			k++;
		}
		gen1_rotate(s1, 13, n / 2);
		gen1_rotate(s2, 17, n / 2);
		gen1_rotate(data, 23, n);
	}
	return;
}




void gen1_1_rotate(char* data, int count, int n) {
	char tmpdata[128];
	memcpy(tmpdata, data, count);
	memcpy(data, &data[count], n - count);
	memcpy(&data[n - count], tmpdata, count);
}


void gen1_1_swapchars(char* data, int i, int j, int n) {
	char tmp = 0;
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}


int gen1_1_rotatevalue(int pin, unsigned int* shiftkeys) {
	int i = 0;
	static int rotatevalues[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0 };
	while (shiftkeys[i] != 0) {
		if (pin < shiftkeys[i]) {
			return 0;
		}
		else {

			if (pin % shiftkeys[i] == 0) {
				return rotatevalues[i];
			}
		}
		i++;
	}
	return 0;
}

static unsigned int shiftkeys[40] = { 3500, 301390, 0 };

void gen1_1_shuffle(char* data, int pin, char *shuffled) {
	int n = 108;
	int k = 1;
	int j = 0;
	int random[6] = { 23, 13, 17, 7, 11 };
	for (; j < pin; j++) {
		char* s1 = &data[0];
		char* s2 = &data[n / 2];

		for (int i = 0; i < n / 4; i++) {
			if (k % 2 == 0) {
				gen1_1_swapchars(s1, i, n / 2 - i - 1, n / 2);
				gen1_1_swapchars(s1 + random[3], i, n / 2 - i - 1 - random[2], n / 2);
				gen1_1_swapchars(s2, i, n / 2 - i - 1, n / 2);
				gen1_1_swapchars(s1 + random[4], i, n / 2 - i - 1 - random[4], n / 2);
			}
			else {
				gen1_1_swapchars(s1, i, n / 2 - i - 2, n / 2);
				gen1_1_swapchars(s1 + random[3], i, n / 2 - i - 2 - random[3], n / 2);
				gen1_1_swapchars(s2, i, n / 2 - i - 2, n / 2);
				gen1_1_swapchars(s1 + random[4], i, n / 2 - i - 2 - random[4], n / 2);
			}
			gen1_1_swapchars(s1, i, random[1] + i, n / 2);
			gen1_1_swapchars(s2, i, random[2] + i, n / 2);
			k++;
		}
		gen1_1_rotate(s1, random[1], n / 2);
		gen1_1_rotate(s2, random[2], n / 2);
		gen1_1_rotate(data, random[0], n - random[0]);
		gen1_1_rotate(s1, random[3], n - random[3]);
		gen1_1_rotate(&s1[random[3]], random[4], n / 2);

		int nrotate = 0;
		if ((nrotate = gen1_1_rotatevalue(pin, shiftkeys)) != 0) {
			//if( algo_info->pin % 3500 == 0 ){
			strcpy_s(shuffled, 108, (const char *)data);
			gen1_1_rotate(shuffled, nrotate, n - nrotate);
		}
		//printf("INFO: nrotate = %d \n", nrotate );
	}
	return;
}


void gen2_rotate(char* data, int count, int n) {
	char tmpdata[128];
	memcpy(tmpdata, data, count);
	memcpy(data, &data[count], n - count);
	memcpy(&data[n - count], tmpdata, count);
}


void gen2_swapchars(char* data, int i, int j, int n) {
	char tmp = 0;
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

void gen2_shuffle(char* data, int pin) {
	int n = 108;
	int k = 1;
	int random[4] = { 23, 13, 17 };
	for (int j = 0; j < pin; j++) {
		char* s1 = &data[0];
		char* s2 = &data[n / 2];

		for (int i = 0; i < n / 4; i++) {
			if (k % 2 == 0) {
				gen2_swapchars(s1, i, n / 2 - i - 1, n / 2);
				gen2_swapchars(s2, i, n / 2 - i - 1, n / 2);
			}
			else {
				gen2_swapchars(s1, i, n / 2 - i - 2, n / 2);
				gen2_swapchars(s2, i, n / 2 - i - 2, n / 2);
			}
			k++;
		}
		gen2_rotate(s1, random[1], n / 2);
		gen2_rotate(s2, random[2], n / 2);
		gen2_rotate(data, random[0], n);
	}
	return;
}



void gen2_1_rotate(char* data, int count, int n) {
	char tmpdata[128];
	memcpy(tmpdata, data, count);
	memcpy(data, &data[count], n - count);
	memcpy(&data[n - count], tmpdata, count);
}


void gen2_1_swapchars(char* data, int i, int j, int n) {
	char tmp = 0;
	tmp = data[i];
	data[i] = data[j];
	data[j] = tmp;
}

int gen2_1_rotatevalue(int pin, unsigned int* shiftkeys) {
	int i = 0;
	static int rotatevalues[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 0 };
	while (shiftkeys[i] != 0) {
		if (pin < shiftkeys[i]) {
			return 0;
		}
		else {

			if (pin % shiftkeys[i] == 0) {
				return rotatevalues[i];
			}
		}
		i++;
	}
	return 0;
}

void gen2_1_shuffle(char* data, int pin, char *shuffled) {
	int n = 108;
	int j = 0;
	int k = 1;
	int random[6] = { 23, 13, 17,  7, 11 };
	for (; j < pin; j++) {
		char* s1 = &data[0];
		char* s2 = &data[n / 2];

		for (int i = 0; i < n / 4; i++) {
			if (k % 2 == 0) {
				gen2_1_swapchars(s1, i, n / 2 - i - 1, n / 2);
				gen2_1_swapchars(s1 + random[3], i, n / 2 - i - 1 - random[2], n / 2);
				gen2_1_swapchars(s2, i, n / 2 - i - 1, n / 2);
				gen2_1_swapchars(s1 + random[4], i, n / 2 - i - 1 - random[4], n / 2);
			}
			else {
				gen2_1_swapchars(s1, i, n / 2 - i - 2, n / 2);
				gen2_1_swapchars(s1 + random[3], i, n / 2 - i - 2 - random[3], n / 2);
				gen2_1_swapchars(s2, i, n / 2 - i - 2, n / 2);
				gen2_1_swapchars(s1 + random[4], i, n / 2 - i - 2 - random[4], n / 2);
			}
			gen2_1_swapchars(s1, i, random[1] + i, n / 2);
			gen2_1_swapchars(s2, i, random[2] + i, n / 2);
			k++;
		}
		gen2_1_rotate(s1, random[1], n / 2);
		gen2_1_rotate(s2, random[2], n / 2);
		gen2_1_rotate(data, random[0], n - random[0]);
		gen2_1_rotate(s1, random[3], n - random[3]);
		gen2_1_rotate(&s1[random[3]], random[4], n / 2);

		int nrotate = 0;
		if ((nrotate = gen2_1_rotatevalue(pin, shiftkeys)) != 0) {
			//if( algo_info->pin % 3500 == 0 ){
			strcpy_s(shuffled, 108, data);
			gen2_1_rotate(shuffled, nrotate, n - nrotate);
		}
		//printf("INFO: nrotate = %d \n", nrotate );
	}
	return;
}



void CDominoPasswordDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here  
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON1);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	int pin = 0;
	if (pEdit)
	{
		CString strPin;
		pEdit->GetWindowText(strPin);
		if (strPin.IsEmpty())
		{
			AfxMessageBox(_T("Please enter a PIN."));
			return;
		}
		pin = _ttoi(strPin); // Convert CString to int
		if (pin <= 0)
		{
			AfxMessageBox(_T("PIN must be a positive integer."));
			return;
		}
	}
	if (pButton)
	{
		if (versionToUse == 1) {
			char shuffle[128];
			strcpy_s(shuffle, initialData);
			gen1_shuffle(shuffle, pin);
			strcpy_s(shuffledData, shuffle);
		}
		else if (versionToUse == 2) {
			char shuffle[128];
			strcpy_s(shuffle, initialData);
			gen1_1_shuffle(shuffle, pin, shuffledData);
			strcpy_s(shuffledData, shuffle);
		}
		else if (versionToUse == 3) {
			char shuffle[128];
			strcpy_s(shuffle, initialData2);
			gen2_shuffle(shuffle, pin);
			strcpy_s(shuffledData, shuffle);
		}
		else {
			char shuffle[128];
			strcpy_s(shuffle, initialData2);
			gen2_1_shuffle(shuffle, pin, shuffledData);
			strcpy_s(shuffledData, shuffle);
		}
		//changeColor(pButton, colorDefault); // Change button color to red
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_MSG);
		if (pStatic)
		{
			pStatic->SetWindowText(_T("Shuffled string generated, now set pattern")); // Set the static message to show the generated password
		}
	}
}

void CDominoPasswordDlg::OnBnClickedAddChar(int n) {
	int charnum = (pattern - 1) * 36 + n; // Calculate the character index based on the pattern and button number
	char ch = shuffledData[charnum];
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
	int pin = 0;
	if (pEdit)
	{
		CString strPin;
		pEdit->GetWindowText(strPin);
		strPin.AppendChar(ch); // Append the character to the edit control
		pEdit->SetWindowText(strPin); // Set the updated text back to the edit control
	}
}

void CDominoPasswordDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	resetData();
	resetButtons();
}

void CDominoPasswordDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON1);
	if (pButton)
	{
		pattern--;
		if (pattern <= 0)
			pattern = 1;
		loadButtons();
		CStatic *staticPattern = (CStatic*)GetDlgItem(IDC_STATIC_PATTERN);
		if (staticPattern)
		{
			CString strPattern;
			strPattern.Format(_T("Pattern: %d/3"), pattern);
			staticPattern->SetWindowText(strPattern);
		}

	}
}

void CDominoPasswordDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON1);
	if (pButton)
	{
		pattern++;
		if (pattern > 3)
			pattern = 3;// Change button color to red
		loadButtons();
		CStatic* staticPattern = (CStatic*)GetDlgItem(IDC_STATIC_PATTERN);
		if (staticPattern)
		{
			CString strPattern;
			strPattern.Format(_T("Pattern: %d/3"), pattern);
			staticPattern->SetWindowText(strPattern);
		}
	}
}

void CDominoPasswordDlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}

void CDominoPasswordDlg::OnBnClickedColorChange(CButton* pButton, int id) {
	switch (pattern) {

	case 1:
		activeButton[id] = 1; // Activate button
		changeColor(pButton, colorRed); // Change button color to red
		break;

	case 2:
		activeButton[36+id] = 1; // Activate button
		changeColor(pButton, colorGreen); // Change button color to red
		break;

	case 3:
		activeButton[36 +36 + id] = 1; // Activate button
		changeColor(pButton, colorBlue); // Change button color to red
		break;
	}
}

void CDominoPasswordDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON5);
	int id =  pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if( pButton )
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(0);
	}
}

void CDominoPasswordDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON6);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(1);
	}
}

void CDominoPasswordDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON7);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(2);
	}
}

void CDominoPasswordDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON8);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(3);
	}
}

void CDominoPasswordDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON9);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(4);
	}
}

void CDominoPasswordDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON10);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(5);
	}
}

void CDominoPasswordDlg::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON11);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(6);
	}
}

void CDominoPasswordDlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON12);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(7);
	}
}

void CDominoPasswordDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON13);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(8);
	}
}

void CDominoPasswordDlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON14);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(9);
	}
}

void CDominoPasswordDlg::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON15);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(10);
	}
}

void CDominoPasswordDlg::OnBnClickedButton16()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON16);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(11);
	}
}

void CDominoPasswordDlg::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON17);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(12);
	}
}

void CDominoPasswordDlg::OnBnClickedButton18()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON18);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(13);
	}
}

void CDominoPasswordDlg::OnBnClickedButton19()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON19);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(14);
	}
}

void CDominoPasswordDlg::OnBnClickedButton20()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON20);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(15);
	}
}

void CDominoPasswordDlg::OnBnClickedButton21()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON21);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(16);
	}
}

void CDominoPasswordDlg::OnBnClickedButton22()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON22);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(17);
	}
}

void CDominoPasswordDlg::OnBnClickedButton23()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON23);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(18);
	}
}

void CDominoPasswordDlg::OnBnClickedButton24()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON24);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(19);
	}
}

void CDominoPasswordDlg::OnBnClickedButton25()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON25);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(20);
	}
}

void CDominoPasswordDlg::OnBnClickedButton26()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON26);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(21);
	}
}

void CDominoPasswordDlg::OnBnClickedButton27()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON27);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(22);
	}
}

void CDominoPasswordDlg::OnBnClickedButton28()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON28);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(23);
	}
}

void CDominoPasswordDlg::OnBnClickedButton29()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON29);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(24);
	}
}

void CDominoPasswordDlg::OnBnClickedButton30()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON30);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(25);
	}
}

void CDominoPasswordDlg::OnBnClickedButton31()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON31);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(26);
	}
}

void CDominoPasswordDlg::OnBnClickedButton32()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON32);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(27);
	}
}

void CDominoPasswordDlg::OnBnClickedButton33()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON33);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(28);
	}
}

void CDominoPasswordDlg::OnBnClickedButton34()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON34);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(29);
	}
}

void CDominoPasswordDlg::OnBnClickedButton35()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON35);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(30);
	}
}

void CDominoPasswordDlg::OnBnClickedButton36()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON36);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(31);
	}
}

void CDominoPasswordDlg::OnBnClickedButton37()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON37);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(32);
	}
}

void CDominoPasswordDlg::OnBnClickedButton38()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON38);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(33);
	}
}

void CDominoPasswordDlg::OnBnClickedButton39()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON39);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(34);
	}
}

void CDominoPasswordDlg::OnBnClickedButton40()
{
	// TODO: Add your control notification handler code here
	if (shuffledData[0] == 0)
		return;
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON40);
	int id = pButton->GetDlgCtrlID() - IDC_BUTTON5; // Get the ID of the button
	if (pButton)
	{
		OnBnClickedColorChange(pButton, id); // Call the color change function
		OnBnClickedAddChar(35);
	}
}

void CDominoPasswordDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO1);
	if (pButton)
	{
		versionToUse = 1;
	}
}

void CDominoPasswordDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO1);
	if (pButton)
	{
		versionToUse = 2;
	}
}

void CDominoPasswordDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO1);
	if (pButton)
	{
		versionToUse = 3;
	}
}

void CDominoPasswordDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	CButton* pButton = (CButton*)GetDlgItem(IDC_RADIO1);
	if (pButton)
	{
		versionToUse = 4;
	}
}

