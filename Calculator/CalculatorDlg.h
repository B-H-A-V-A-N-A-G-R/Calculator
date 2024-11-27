
// CalculatorDlg.h : header file
//

#pragma once
#include <stack>

// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void SaveState();
	DECLARE_MESSAGE_MAP()
public:
	CString curr_input;
	double result;
	char Operator;
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonUndo();
	afx_msg void OnBnClickedButtonModulus();
	afx_msg void OnBnClickedButtonDivide();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonPeriod();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonEquals();

	struct CalculatorState {
		CString currentInput;
		double result;
		char operatorUsed;
	};

	std::stack<CalculatorState> st;
	afx_msg void OnSize(UINT nType, int cx, int cy);

	CEdit m_display;
	CFont m_font;
	/* CButton m_modulus;
	CButton m_clear;
	CButton m_undo;
	CButton m_divide;
	CButton m_seven;
	CButton m_eight;
	CButton m_nine;
	CButton m_multiply;
	CButton m_four;
	CButton m_five;
	CButton m_six;
	CButton m_minus;
	CButton m_one;
	CButton m_two;
	CButton m_three;
	CButton m_plus;
	CButton m_zero;
	CButton m_period;
	CButton m_equals;*/
};


