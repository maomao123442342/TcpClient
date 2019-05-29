#include "TcpClient.h"


TcpClient::TcpClient(QWidget *parent)
{
	TcpClient_Init_UI();
	TcpClient_Init_Connect();
}

void TcpClient::TcpClient_Init_UI()
{
	QString localIP = getLocalIP();//本机IP
	ExitButton = new QPushButton(QIcon(":/QtGuiApplication3/Resources/ExitButton.png"), "", this);
	ExitButton->setObjectName(QStringLiteral("exitButton"));
	ExitButton->setFlat(true);
	ExitButton->raise();
	ExitButton->setIconSize(QSize(20, 20));
	ExitButton->setGeometry(QRect(325, 10, 20, 20));
	ExitButton->setFocusPolicy(Qt::NoFocus);
	ExitButton->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");
	connect(ExitButton, SIGNAL(clicked()), this, SLOT(close()));

	//最小化按钮设置
	Minimize = new QPushButton(QIcon(":/QtGuiApplication3/Resources/Mini.png"), "", this);
	Minimize->setObjectName(QStringLiteral("Minimize"));
	Minimize->setFlat(true);
	Minimize->raise();
	Minimize->setIconSize(QSize(20, 20));
	Minimize->setGeometry(QRect(305, 10, 20, 20));
	Minimize->setFocusPolicy(Qt::NoFocus);
	Minimize->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");
	connect(Minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));


	LabSocketState = new QLabel("Socket state:", this);
	LabSocketState->setGeometry(QRect(20, 410, 300, 10));


	ConnectServer = new QPushButton("START", this);
	ConnectServer->setGeometry(QRect(30, 50, 50, 50));

	DisconnectServer = new QPushButton("STOP", this);
	DisconnectServer->setGeometry(QRect(90, 50, 50, 50));

	ClearText = new QPushButton("CLEAR", this);
	ClearText->setGeometry(QRect(150, 50, 50, 50));

	Exit = new QPushButton("EXIT", this);
	Exit->setGeometry(QRect(215, 50, 50, 50));

	SendMess = new QPushButton("SEND", this);
	SendMess->setGeometry(QRect(295, 170, 40, 20));

	ServerAddress = new QLabel("Server Address:", this);
	ServerAddress->setGeometry(QRect(20, 110, 80, 20));

	comboServer = new QComboBox(this);
	comboServer->setGeometry(QRect(105, 110, 120, 20));
	comboServer->setEditable(true);

	ServerPort = new QLabel("Server Port:", this);
	ServerPort->setGeometry(QRect(20, 140, 80, 20));

	spinPort = new QSpinBox(this);
	spinPort->setRange(0, 1000000);
	spinPort->setGeometry(QRect(105, 140, 100, 20));

	Title = new QLabel(this);
	Title->setGeometry(QRect(20, 20, 300, 20));
	Title->setText("Tcp Client---Local IP:" + localIP);
	
	editMsg = new QLineEdit(this);
	editMsg->setGeometry(QRect(20, 170, 270, 20));

	plainTextEdit = new QTextEdit(this);
	plainTextEdit->setGeometry(QRect(20, 200, 310, 200));
	plainTextEdit->setReadOnly(true);

	tcpSocket = new QTcpSocket();
	this->setWindowTitle("TCP Client");
	this->setWindowFlags(Qt::FramelessWindowHint);
	//窗口拖动
	QWidgetResizeHandler *movewin = new QWidgetResizeHandler(this);
	movewin->setMovingEnabled(true);
	this->setWindowOpacity(0.9);
	setAttribute(Qt::WA_TranslucentBackground);
	//this->setModal(true);
	this->setFixedSize(350, 650);//设置主窗口大小固定，不可修改
}

void TcpClient::TcpClient_Init_Connect()
{
	connect(ConnectServer, SIGNAL(clicked()), this, SLOT(ConnectServer_Button()));
	connect(DisconnectServer, SIGNAL(clicked()), this, SLOT(DisconnectServer_Button()));
	connect(SendMess, SIGNAL(clicked()), this, SLOT(Send_Button()));
	connect(tcpSocket, SIGNAL(connected()), this, SLOT(onConnected()));
	connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
	connect(tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChange(QAbstractSocket::SocketState socketState)));
	connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}
void TcpClient::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.drawPixmap(0, 0, QPixmap(":/QtGuiApplication3/Resources/background.png"));
}

void TcpClient::mouseMoveEvent(QMouseEvent * event)
{
	if (event->MouseMove)
		this->close();
}

TcpClient::~TcpClient()
{
	//delete Play;
	//delete Minimize;
	//delete ExitButton;
}



QString TcpClient::getLocalIP()
{
	QString hostName = QHostInfo::localHostName();            //获取本地主机名
	QHostInfo hostInfo = QHostInfo::fromName(hostName);
	QString localIP = "";
	QList<QHostAddress> addList = hostInfo.addresses();
	if (!addList.isEmpty())
	for (int i = 0; i < addList.count(); i++)
	{
		QHostAddress ahost = addList.at(i);
		if (QAbstractSocket::IPv4Protocol == ahost.protocol())
		{
			localIP = ahost.toString(); break;
		}
	}
	return localIP;
}


void TcpClient::onSocketStateChange(QAbstractSocket::SocketState socketState) //
{
	switch (socketState) //socket状态变化时
	{
	case QAbstractSocket::UnconnectedState:
		LabSocketState->setText("Socket State:UnconnectedState");
		break;
	case QAbstractSocket::HostLookupState:
		LabSocketState->setText("Socket State:HostLookupState");
		break;
	case QAbstractSocket::ConnectedState:
		LabSocketState->setText("Socket State:ConnectedState");
		break;
	case QAbstractSocket::ConnectingState:
		LabSocketState->setText("Socket State:ConnectingState...");
		break;
	case QAbstractSocket::BoundState:
		LabSocketState->setText("Socket State:BoundState");
		break;
	case QAbstractSocket::ClosingState:
		LabSocketState->setText("Socket State:ClosingState...");
		break;
	case QAbstractSocket::ListeningState:
		LabSocketState->setText("Socket State:ListeningState...");
		break;
	}
}

void TcpClient::ConnectServer_Button()
{
	QString addr = comboServer->currentText();
	quint16 port = spinPort->value();
	tcpSocket->connectToHost(addr, port);
	onSocketStateChange(tcpSocket->state());
}


void TcpClient::DisconnectServer_Button()
{
	if (tcpSocket->state() == QAbstractSocket::ConnectedState)
		tcpSocket->disconnectFromHost();
	onSocketStateChange(tcpSocket->state());
}
void TcpClient::Send_Button()
{
	QString msg = editMsg->text();
	plainTextEdit->append("[out]" + msg);
	//editMsg->clear();
	editMsg->setFocus();
	QByteArray str = msg.toUtf8();
	str.append('\n');
	tcpSocket->write(str);
}

void TcpClient::onConnected()
{
	plainTextEdit->append("**connected to server");
	plainTextEdit->append("**peer address:" + tcpSocket->peerAddress().toString());
	plainTextEdit->append("**peer port:" + QString::number(tcpSocket->peerPort()));
	ConnectServer->setEnabled(false);
	DisconnectServer->setEnabled(true);
}
void TcpClient::onDisconnected()
{
	plainTextEdit->append("**Disconnected...");
	ConnectServer->setEnabled(true);
	DisconnectServer->setEnabled(false);
}
void TcpClient::onSocketReadyRead()
{
	//while (tcpSocket->canReadLine())
		plainTextEdit->append("[in]" + tcpSocket->readAll());
}
void TcpClient::Clear_Button()
{
	//plainTextEdit->clearMask
}