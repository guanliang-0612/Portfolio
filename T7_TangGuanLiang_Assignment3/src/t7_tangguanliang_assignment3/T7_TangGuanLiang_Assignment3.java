/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package t7_tangguanliang_assignment3;

/**
 *
 * @author gltan
 */
import javax.swing.*;
import java.awt.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.event.*;
import java.util.ArrayList;

public class T7_TangGuanLiang_Assignment3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        new QuotationApp().setVisible(true);
    }
    
}
class QuotationApp extends JFrame{
    private JTextField txCode, txQty, txPrice, txDiscount, txTotal;
    private JButton bnLoad, bnPrev, bnNext;
    private ArrayList<QuotationItem> item;
    
    public QuotationApp(){
        createUI();
    }
    public void createUI(){
        this.setTitle("Quotation Management");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
        
        txCode = new JTextField();
        txCode.setEditable(false);
        txQty = new JTextField();
        txQty.setEditable(false);
        txPrice = new JTextField();
        txPrice.setEditable(false);
        txDiscount = new JTextField();
        txDiscount.setEditable(false);
        txTotal = new JTextField();
        txTotal.setEditable(false);
        bnLoad = new JButton("Load");
        bnPrev = new JButton("Prev");
        bnNext = new JButton("Next");
        
        Container uiPane = this.getContentPane();
        uiPane.add(new JLabel("Code"));
        uiPane.add(txCode);
        uiPane.add(new JLabel("Quantity"));
        uiPane.add(txQty);
        uiPane.add(new JLabel("Price"));
        uiPane.add(txPrice);
        uiPane.add(new JLabel("Discount"));
        uiPane.add(txDiscount);
        uiPane.add(new JLabel("Total"));
        uiPane.add(txTotal);
        uiPane.add(new JLabel(""));
        uiPane.add(bnLoad);
        uiPane.add(new JLabel(""));
        uiPane.add(bnPrev);
        uiPane.add(new JLabel(""));
        uiPane.add(bnNext);
        
        this.pack();
        
        addEventHandler();
        
    }
    
    private void addEventHandler(){
        
    }
}
class QuotationItem{
    // instance variable
    private String code;
    private int quantity;
    private double price, discount;
    
    // constructor
    public QuotationItem(String code, int quantity, double price, double discount){
        this.code = code;
        this.quantity = quantity;
        this.price = price;
        this.discount = discount;
    }
    // get and set method
    public String getCode(){
        return code;
    }
    public int getQuantity(){
        return quantity;
    }
    public double getPrice(){
        return price;
    }
    public double getDiscount(){
        return discount;
    }
    public void setQuantity(int newQty){
        if (newQty >= 0)
            quantity = newQty;
    }
    public void setPrice(double newPrice){
        if (newPrice >= 0)
            price = newPrice;
    }
    public void setDiscount(double newDiscount){
        if (newDiscount >= 0)
            discount = newDiscount;
    }
    // instance method
    public double getTotal(){
        return (quantity * price) - discount;
    }
    public String toString(){
        return code + "," + quantity + "," + price + "," + discount;
    }  
}
