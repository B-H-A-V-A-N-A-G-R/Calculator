
// CalculatorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include <afxwin.h>
#include <afxext.h>
#include <afxdlgs.h>
#include <afxcontrolbars.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_display);
	/* DDX_Control(pDX, IDC_BUTTON_UNDO, m_undo);
	DDX_Control(pDX, IDC_BUTTON_MODULUS, m_modulus);
	DDX_Control(pDX, IDC_BUTTON_CLEAR, m_clear);
	DDX_Control(pDX, IDC_BUTTON_UNDO, m_undo);
	DDX_Control(pDX, IDC_BUTTON_DIVIDE, m_divide);
	DDX_Control(pDX, IDC_BUTTON_7, m_seven);
	DDX_Control(pDX, IDC_BUTTON_8, m_eight);
	DDX_Control(pDX, IDC_BUTTON_9, m_nine);
	DDX_Control(pDX, IDC_BUTTON_MULTIPLY, m_multiply);
	DDX_Control(pDX, IDC_BUTTON_4, m_four);
	DDX_Control(pDX, IDC_BUTTON_5, m_five);
	DDX_Control(pDX, IDC_BUTTON_6, m_six);
	DDX_Control(pDX, IDC_BUTTON_MINUS, m_minus);
	DDX_Control(pDX, IDC_BUTTON_1, m_one);
	DDX_Control(pDX, IDC_BUTTON_2, m_two);
	DDX_Control(pDX, IDC_BUTTON_3, m_three);
	DDX_Control(pDX, IDC_BUTTON_PLUS, m_plus);
	DDX_Control(pDX, IDC_BUTTON_0, m_zero);
	DDX_Control(pDX, IDC_BUTTON_PERIOD, m_period);
	DDX_Control(pDX, IDC_BUTTON_EQUALS, m_equals);*/
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR,		&CCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_UNDO,		&CCalculatorDlg::OnBnClickedButtonUndo)
	ON_BN_CLICKED(IDC_BUTTON_MODULUS,	&CCalculatorDlg::OnBnClickedButtonModulus)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE,	&CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY,	&CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_MINUS,		&CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_PLUS,		&CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_PERIOD,	&CCalculatorDlg::OnBnClickedButtonPeriod)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS,	&CCalculatorDlg::OnBnClickedButtonEquals)
	//ON_COMMAND(IDD_CALCULATOR_DIALOG,	&CCalculatorDlg::OnSize)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Create a font
		m_font.CreatePointFont(160, _T("Arial")); // 16-point font

	// Apply the font to the edit control
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1); // Replace IDC_EDIT1 with your edit control's ID
	if (pEdit)
	{
		pEdit->SetFont(&m_font);
	}

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::SaveState()
{
	CalculatorState state;
	state.currentInput = curr_input;
	state.result = result;
	state.operatorUsed = Operator;

	st.push(state);
}

void CCalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: Clear the text editor
	curr_input.Empty();
	result = 0;
	Operator = '\0';
	m_display.SetWindowTextW(curr_input);
}


void CCalculatorDlg::OnBnClickedButtonUndo()
{
	// TODO: Add your control notification handler code here
	if (!st.empty())
	{
		CalculatorState prevState = st.top();  // Get the last state
		st.pop();  // Remove it from the stack

		// Restore state
		curr_input = prevState.currentInput;
		result = prevState.result;
		Operator = prevState.operatorUsed;

		// Update display
		m_display.SetWindowText(curr_input);
	}
	else
	{
		m_display.SetWindowText(_T("Nothing to undo"));
	}
}


void CCalculatorDlg::OnBnClickedButtonModulus()
{
	if (Operator == '\0')
	{
		SaveState();
		result = _ttof(curr_input); //convert CString to double
	}
	Operator = '%';
	CString displayText;
	if (!curr_input.IsEmpty()) {
		displayText.Format(_T("%s%c"), curr_input, Operator); // Use curr_input if not empty
	}
	else {
		displayText.Format(_T("%g%c"), result, Operator);    // Use result if curr_input is empty
	}

	m_display.SetWindowTextW(displayText);
	curr_input.Empty();
}


void CCalculatorDlg::OnBnClickedButtonDivide()
{
	// TODO: Add your control notification handler code here
	if (Operator == '\0')
	{
		SaveState();
		result = _ttof(curr_input); //convert CString to double
	}
	Operator = '/';
	CString displayText;
	if (!curr_input.IsEmpty()) {
		displayText.Format(_T("%s%c"), curr_input, Operator); // Use curr_input if not empty
	}
	else {
		displayText.Format(_T("%g%c"), result, Operator);    // Use result if curr_input is empty
	}

	m_display.SetWindowTextW(displayText);
	curr_input.Empty();
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: Add your control notification handler code here
	if (Operator == '\0')
	{
		SaveState();
		result = _ttof(curr_input); //convert CString to double
	}
	Operator = '*';
	CString displayText;
	if (!curr_input.IsEmpty()) {
		displayText.Format(_T("%s%c"), curr_input, Operator); // Use curr_input if not empty
	}
	else {
		displayText.Format(_T("%g%c"), result, Operator);    // Use result if curr_input is empty
	}

	m_display.SetWindowTextW(displayText);
	curr_input.Empty();
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: Add your control notification handler code here
	if (Operator == '\0')
	{
		SaveState();
		result = _ttof(curr_input); //convert CString to double
	}
	Operator = '-';
	CString displayText;
	if (!curr_input.IsEmpty()) {
		displayText.Format(_T("%s%c"), curr_input, Operator); // Use curr_input if not empty
	}
	else {
		displayText.Format(_T("%g%c"), result, Operator);    // Use result if curr_input is empty
	}

	m_display.SetWindowTextW(displayText);
	curr_input.Empty();
}


void CCalculatorDlg::OnBnClickedButtonPlus()
{
	if (Operator == '\0')
	{
		SaveState();
		result = _ttof(curr_input); //convert CString to double
	}
	Operator = '+';
	CString displayText;
	if (!curr_input.IsEmpty()) {
		displayText.Format(_T("%s%c"), curr_input, Operator); // Use curr_input if not empty
	}
	else {
		displayText.Format(_T("%g%c"), result, Operator);    // Use result if curr_input is empty
	}

	m_display.SetWindowTextW(displayText);
	curr_input.Empty();
}


void CCalculatorDlg::OnBnClickedButtonPeriod()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T(".");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("7");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("8");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("9");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("4");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("5");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("6");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("1");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("2");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("3");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButton0()
{
	// TODO: Add your control notification handler code here
	SaveState();  // Save current state
	curr_input = curr_input + _T("0");
	m_display.SetWindowText(curr_input);
}


void CCalculatorDlg::OnBnClickedButtonEquals()
{
	// TODO: Add your control notification handler code here
	double second_operand = _ttof(curr_input);
	int flag = 0;
	switch (Operator)
	{
		case '+':
			result += second_operand; break;
		case '-':
			result -= second_operand; break;
		case '/':
			if (second_operand != 0.0)
				result /= second_operand;
			else 
			{
				flag = 1;
				m_display.SetWindowTextW(_T("Error"));
			}
			break;
		case '*':
			result *= second_operand; break;
		case '%':
			int first = static_cast<int>(result);
			int second = static_cast<int>(second_operand);
			if (second != 0.0)
				result = first % second;
			else
			{
				flag = 1;
				m_display.SetWindowTextW(_T("Error"));
			}
			break;
	}
	if (flag == 0)
	{
		curr_input.Format(_T("%g"), result); //convert double to CString
		m_display.SetWindowTextW(curr_input);
	}
}


/*void CCalculatorDlg::OnSize(UINT nType, int cx, int cy)
{
	// TODO: Add your command handler code here
	CDialogEx::OnSize(nType, cx, cy);

	// Resize the edit control and button based on the dialog size
	if (m_display.GetSafeHwnd() != nullptr)
	{
		// Resize the edit control (e.g., making it half of the dialog width and 1/3 of the dialog height)
		m_display.MoveWindow(10, 10, cx - 20, cy / 5);
	}
	if (m_modulus.GetSafeHwnd() != nullptr && m_clear.GetSafeHwnd() != nullptr && m_undo.GetSafeHwnd() != nullptr && m_divide.GetSafeHwnd() != nullptr && m_seven.GetSafeHwnd() != nullptr
		&& m_eight.GetSafeHwnd() != nullptr && m_nine.GetSafeHwnd() != nullptr && m_multiply.GetSafeHwnd() != nullptr && m_four.GetSafeHwnd() != nullptr
		&& m_five.GetSafeHwnd() != nullptr && m_six.GetSafeHwnd() != nullptr && m_minus.GetSafeHwnd() != nullptr && m_one.GetSafeHwnd() != nullptr && m_two.GetSafeHwnd() != nullptr
		&& m_three.GetSafeHwnd() != nullptr && m_plus.GetSafeHwnd() != nullptr && m_zero.GetSafeHwnd() != nullptr && m_period.GetSafeHwnd() != nullptr && m_equals.GetSafeHwnd() != nullptr)
	{
		// Calculate the number of buttons in each row and column
		const int buttonWidth = (cx - 40) / 4;   // Four buttons per row, with margin
		const int buttonHeight = (cy - 60) / 5;   // Five rows of buttons, with margin

		// Position buttons dynamically
		// Row 1
		m_modulus.MoveWindow(10, cy / 5 + 10, buttonWidth, buttonHeight);  // Button 1
		m_clear.MoveWindow(10 + buttonWidth + 5, cy / 5 + 10, buttonWidth, buttonHeight);  // Button 2
		m_undo.MoveWindow(10 + 2 * (buttonWidth + 5), cy / 5 + 10, buttonWidth, buttonHeight);  // Button 3
		m_divide.MoveWindow(10 + 3 * (buttonWidth + 5), cy / 5 + 10, buttonWidth, buttonHeight);  // Button 4

        // Row 2
		m_seven.MoveWindow(10, cy / 5 + buttonHeight + 15, buttonWidth, buttonHeight);  // Button 5
		m_eight.MoveWindow(10 + buttonWidth + 5, cy / 5 + buttonHeight + 15, buttonWidth, buttonHeight);  // Button 6
		m_nine.MoveWindow(10 + 2 * (buttonWidth + 5), cy / 5 + buttonHeight + 15, buttonWidth, buttonHeight);  // Button 7
		m_multiply.MoveWindow(10 + 3 * (buttonWidth + 5), cy / 5 + buttonHeight + 15, buttonWidth, buttonHeight);  // Button 8

        // Row 3
		m_four.MoveWindow(10, cy / 5 + 2 * (buttonHeight + 20), buttonWidth, buttonHeight);  // Button 9
		m_five.MoveWindow(10 + buttonWidth + 5, cy / 5 + 2 * (buttonHeight + 20), buttonWidth, buttonHeight);  // Button 10
		m_six.MoveWindow(10 + 2 * (buttonWidth + 5), cy / 5 + 2 * (buttonHeight + 20), buttonWidth, buttonHeight);  // Button 11
		m_minus.MoveWindow(10 + 3 * (buttonWidth + 5), cy / 5 + 2 * (buttonHeight + 20), buttonWidth, buttonHeight);  // Button 12

        // Row 4
		m_one.MoveWindow(10, cy / 5 + 3 * (buttonHeight + 25), buttonWidth, buttonHeight);  // Button 13
		m_two.MoveWindow(10 + buttonWidth + 5, cy / 5 + 3 * (buttonHeight + 25), buttonWidth, buttonHeight);  // Button 14
		m_three.MoveWindow(10 + 2 * (buttonWidth + 5), cy / 5 + 3 * (buttonHeight + 25), buttonWidth, buttonHeight);  // Button 15
		m_plus.MoveWindow(10 + 3 * (buttonWidth + 5), cy / 5 + 3 * (buttonHeight + 25), buttonWidth, buttonHeight);  // Button 16

        // Row 5
		m_zero.MoveWindow(10, cy / 5 + 4 * (buttonHeight + 30), buttonWidth, buttonHeight);  // Button 17
		m_period.MoveWindow(10 + buttonWidth + 5, cy / 5 + 4 * (buttonHeight + 30), buttonWidth, buttonHeight);  // Button 18
		m_equals.MoveWindow(10 + 2 * (buttonWidth + 5), cy / 5 + 4 * (buttonHeight + 30), buttonWidth, buttonHeight);  // Button 19
	}
}*/
