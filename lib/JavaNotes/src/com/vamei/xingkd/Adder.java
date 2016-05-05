package com.vamei.xingkd;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

/**
 Java 是通过ActionListener 对象实现消息响应的，每个每一个ActionListener
 的子类都需要实现 actionPerformed（ActionEvent e) 来实现响应函数的。也就是说
 Java 已经规定了响应函数的函数名。
 * @author xkd
 *
 */
public class Adder implements ActionListener {
	JFrame AdderFrame;
	JTextField TOprand1;
	JTextField TOprand2;
	JLabel LAdd, LSum;
	JButton BAdd, BClear, BText;
	JPanel JP1, JP2;
	
	public Adder()
	{
//		AdderFrame
		AdderFrame = new JFrame("AddFrame");
		TOprand1 = new JTextField("0.0");
		TOprand2 = new JTextField("0.0");
		LAdd	 = new JLabel(" + ");
		LSum	 = new JLabel(" =  ");
		BAdd	 = new JButton("Add");
		BClear	 = new JButton("Clearn");
		BText	 = new JButton("text");
		JP1		 = new JPanel();
		JP2		 = new JPanel();
		BAdd.addActionListener(this);
		BClear.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				TOprand1.setText("0.0");
				TOprand2.setText("0.0");
				LSum.setText(" = ");
			}
		});
		
		AdderFrame.add(JP1);
		JP1.add(TOprand1);
		JP1.add(LAdd);
		JP1.add(TOprand2);
		JP1.add(LSum);
		
		AdderFrame.add(JP2);
		JP2.add(BAdd);
		JP2.add(BClear);
		JP2.add(BText);
		AdderFrame.getContentPane().setLayout(new BorderLayout());
		AdderFrame.getContentPane().add(JP1, BorderLayout.NORTH);
		AdderFrame.getContentPane().add(JP2, BorderLayout.SOUTH);
		
		BText.addActionListener(new Text(BText));
		AdderFrame.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent event)
			{
				System.exit(0);
			}
		});
		
		AdderFrame.pack();
		AdderFrame.setVisible(true);
		AdderFrame.setResizable(false);
		AdderFrame.setSize(300, 200);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		double sum = (double)(Double.valueOf(TOprand1.getText()).doubleValue() + 
				Double.valueOf(TOprand2.getText()).doubleValue());
		LSum.setText(" = " + sum);
	}
}

class Text implements ActionListener
{
	JButton pText;
	
	public Text(JButton btn)
	{
		pText = btn;
	}
	public void actionPerformed(ActionEvent e)
	{
		System.out.println("xingkongdao");
		pText.setText("zhengsihua");
	}
}