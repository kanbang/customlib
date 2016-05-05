package com.vamei.java;
import javax.swing.*;

import java.net.*;
import java.io.*;
import java.awt.Container;
import java.awt.event.*;
public class javaNetwork {
	
	public static void testInetAddress()
	{
		try
		{
		  InetAddress address = InetAddress.getByName("www.baidu.com");
		  String domainName = address.getHostName();
		  String ip = address.getHostAddress();

		  System.out.println("domainName = " + domainName);
		  System.out.println("ip = " + ip);
		  
		  InetAddress local = InetAddress.getLocalHost();
		  domainName = local.getHostName();
		  ip 		= local.getHostAddress();
		  System.out.println("domainName = " + domainName);
		  System.out.println("ip = " + ip);			
		}
		catch(UnknownHostException e)
		{
			e.printStackTrace();
		}
	}
	
	public static void testUrl()
	{
		URL oUrl;
		try
		{
			oUrl = new URL("http://www.weixueyuan.net:80/");		
			URLConnection urlConnect = oUrl.openConnection();
			urlConnect.connect();
			OutputStream ostream  = urlConnect.getOutputStream();
			InputStream istream = urlConnect.getInputStream();
			
		}
		catch(MalformedURLException e)
		{
			System.out.println("error URL : " + e);
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}		
	}
	
	public static void testDownNetFile()
	{
		DownNetFile file = new DownNetFile();
	}
}

class DownNetFile extends JFrame implements ActionListener {
	// 此处只能初始化变量，不能通过实例调用方法。方法要在函数中调用
	JTextField infield = new JTextField(30);
	JTextArea showArea = new JTextArea();
	JButton btn = new JButton("download");
	JPanel panel = new JPanel();
	DownNetFile pOwner = this;
	
//	map.put()
	DownNetFile()
	{
		super(" read network text file application");
		Container con = this.getContentPane();
		panel.add(infield);
		panel.add(btn);
		
		JScrollPane jsp = new JScrollPane(showArea);
		btn.addActionListener(this);
		con.add(panel, "North");
		con.add(jsp, "Center");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

//		KeyStroke enter = KeyStroke.getKeyStroke(KeyEvent.VK_ENTER, 0);
//		ActionMap map = infield.getActionMap();
//		InputMap inputMap = infield.getInputMap(infield.WHEN_FOCUSED);
//		inputMap.put(enter,"Kind_of_Input");
//		
		infield.addKeyListener(new KeyAdapter() {
			public void keyPressed(KeyEvent e)
			{
				super.keyPressed(e);
				if(e.getKeyCode() == KeyEvent.VK_ENTER)
				{
					System.out.println("xingkongdao");
					pOwner.readByURL(pOwner.infield.getText());
					DownNetFile.this.infield.getText();
				}
			}
		});
//		map.put("Kind_of_Input", new AbstractAction(){
//			public void actionPerformed(ActionEvent e)
//			{
//				
//				System.out.println(infield.getText());
//			}
//		});
		
//		map.put("Kind_of_Input", new Action(this));
		setSize(500,400);
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		readByURL(infield.getText());
	}
	
	public void readByURL(String urlName)
	{
		try
		{
			URL url = new URL(urlName);
			URLConnection tc = url.openConnection();
			InputStreamReader in = new InputStreamReader(tc.getInputStream());
			BufferedReader buffer = new BufferedReader(in);
			String inline;
			while((inline = buffer.readLine()) != null)
			{
				showArea.append(inline + "\n");
			}
		}
		catch(MalformedURLException e)
		{
			e.printStackTrace();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}

class Action extends AbstractAction
{
	DownNetFile pFile;
	
	Action(DownNetFile file)
	{
		pFile = file;
	}
	public void actionPerformed(ActionEvent e)
	{
		pFile.readByURL(pFile.infield.getText());
	}
}