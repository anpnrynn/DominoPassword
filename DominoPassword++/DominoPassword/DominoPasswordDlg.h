
// DominoPasswordDlg.h : header file
//

#pragma once

#include <afxwin.h> // For MFC classes
#include <afxext.h> // For extended MFC classes
#include <afxdisp.h> // For OLE automation classes
#include <afxdtctl.h> // For MFC support for Internet Explorer 4 Common Controls
#include <afxcmn.h> // For MFC support for Windows Common Controls

// CDominoPasswordDlg dialog
class CDominoPasswordDlg : public CDialogEx
{
// Construction
public:
	CDominoPasswordDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DOMINOPASSWORD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


	COLORREF colorDefault; // Default color for buttons
	COLORREF colorRed;// Red color for buttons
	COLORREF colorGreen; // Green color for buttons
	COLORREF colorBlue; // Blue color for buttons

	int  pattern;
	int  activeButton[108];
	char shuffledData[128];

	int  versionToUse;
	char initialData[128];
	char initialData2[128];

	void changeColor(CButton* pButton, COLORREF color); // Function to change button color
	void resetData(); // Function to reset data
	void resetButtons(); // Function to reset button states
	void loadButtons();
	void OnBnClickedColorChange(CButton* pButton, int id);
	void OnBnClickedAddChar(int n);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnBnClickedButton30();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton33();
	afx_msg void OnBnClickedButton34();
	afx_msg void OnBnClickedButton35();
	afx_msg void OnBnClickedButton36();
	afx_msg void OnBnClickedButton37();
	afx_msg void OnBnClickedButton38();
	afx_msg void OnBnClickedButton39();
	afx_msg void OnBnClickedButton40();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
};
