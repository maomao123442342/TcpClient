#ifndef _TCPCLIENT_
#define _TCPCLIENT_

#include <QtGui>
#include <QtWidgets>
#include <qwidgetresizehandler_p.h>
#include <qsize.h>
#include <qevent.h>
#include <QTcpSocket>
#include <QHostInfo>
#include <QTcpServer>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qspinbox.h>
#include <qcombobox.h>

class TcpClient :public QWidget
{
	Q_OBJECT
public:
	explicit TcpClient(QWidget *parent = 0);
	~TcpClient();
private slots :
	void onSocketStateChange(QAbstractSocket::SocketState socketState);
	void onConnected(); //Client Socket connected
	void onDisconnected();//Client Socket disconnected
	void onSocketReadyRead();

	void ConnectServer_Button();
	void DisconnectServer_Button();
	void Send_Button();
	void Clear_Button();
private:
	void TcpClient_Init_UI();
	void TcpClient_Init_Connect();
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent * event);
	QPushButton* Play;
	QPushButton* Minimize;
	QPushButton* ExitButton;
	//Tcpsocket
	QPushButton *ConnectServer;
	QPushButton *DisconnectServer;
	QPushButton *ClearText;
	QPushButton *Exit;
	QPushButton *SendMess;

	QLabel *ServerAddress;
	QLabel *ServerPort;
	QLabel *Lablisten;
	QLabel *LabSocketState;
	QLabel *Title;
	QLineEdit *editMsg;   //输入发送信息框
	QTextEdit *plainTextEdit; //公告栏
	QSpinBox *spinPort; //监听端口
	QComboBox *comboServer; //监听地址

	QTcpSocket *tcpSocket;//Tcp通信的socket
	QString getLocalIP();//获取本机IP地址

protected:
	//void closeEvent(QCloseEvent *event);
};


#endif


