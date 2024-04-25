/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package t7_tangguanliang_assignment2;

/**
 *
 * @author gltan
 */
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Iterator;
public class T7_TangGuanLiang_Assignment2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ArrayList<ToyCar> tc = new ArrayList<>(); // bulid an arraylist
        userMenu(tc);
    }
    // prompt user to enter what they want in the menu
    // given choice to user to select what to input
    public static void userMenu(ArrayList tc){
        int select;
        Scanner input = new Scanner(System.in);
        do{
        System.out.println("-------------------------------------");
        System.out.println("1. Add inventory");
        System.out.println("2. Remove inventory");
        System.out.println("3. Show all inventory");
        System.out.println("4. Search inventory by car model");
        System.out.println("5. Search inventory by car price");
        System.out.println("6. Search inventory by car battery duration");
        System.out.println("7. Quit");
        System.out.println("Your selection: ");
        select = input.nextInt();
        switch(select){
            case 1 :
                addInventory(tc);
            case 2 :
                removeInventory(tc);
            case 3 :
                showAllInventory(tc);
                break;
            case 4 :
                searchCarModel(tc);
                break;
            case 5 :
                searchCarPrice(tc);
                break;
            case 6 :
                searchCarBattery(tc);
                break;
            case 7 :
                exitSystem(tc);
                break;
            default :
                System.out.println("Invalid enter. \nPlease choose between 1-7: ");
            }
        }while (select != 7);
    }
    // a menu for option 1 
    // to let user choose which type of toy car they want to input
    public static void addInventory(ArrayList<ToyCar> tc){
        Scanner kboard = new Scanner(System.in);
        System.out.println("Choose type of toy car to add");
        System.out.println("1. Self pedaling toy car");
        System.out.println("2. Battery-powered toy car");
        System.out.println("3. Back to Menu");
        System.out.println("Your selection: ");
        int type = kboard.nextInt();
        
        // if user choose other than 1, 2 and 3, it will print invalid message.
        if (type >= 1 && type <= 3){
            switch(type){
                case 1:
                    addPedalToyCar(tc);
                case 2:
                    addBatteryToyCar(tc);
                    // go back to main menu
                case 3:
                    userMenu(tc);
            }
        }else{
            System.out.println("Invalid enter. Please choose 1, 2 or 3. ");
            addInventory(tc);
        }
    }
    // if user choose 1 in addInventory menu
    // it will prompt user to add info of self pedaling toy car to arraylist
    public static void addPedalToyCar(ArrayList<ToyCar> tc){
        String record;
        do{
            Scanner input = new Scanner(System.in);
            System.out.println("Model Code: ");
            String code = input.nextLine();
            
            // if user input the same model code again, it will remind user and will not add into arraylist.
            boolean outcome = false;
            Iterator<ToyCar> itr = tc.iterator();
            while(itr.hasNext()){
                ToyCar tCar = itr.next();
                if(tCar.getToyCarCode().equals(code)){
                    System.out.println("This model code is already exist.");
                    addInventory(tc);
                    outcome = true;
                    break;
                }
            }
            
            System.out.println("Price: ");
            double price = input.nextDouble();
            System.out.println("Quantity: ");
            int qty = input.nextInt();
            
            // add info to arraylist
            ToyCar toycar = new ToyCar(code, price, qty);
            tc.add(toycar);
            
            // ask user want to enter new info or not
            // it will come back to addInventory menu to let user choose
            // if user don't want to input, just choose 3 in menu to go back to main menu.
            System.out.println("Enter another record? (y/n)");
            record = input.nextLine();
            input.nextLine();
        }while (record.equals("y"));
        addInventory(tc);
    }
    // if user choose 2 in addInventory menu
    // it will prompt user to add info of battery-powered toy car to arraylist
    public static void addBatteryToyCar(ArrayList<ToyCar> tc){
        String record;
        do{
            Scanner input = new Scanner(System.in);
            System.out.println("Model Code: ");
            String code = input.nextLine();
            boolean outcome = false;
            Iterator<ToyCar> itr = tc.iterator();
            while(itr.hasNext()){
                ToyCar tCar = itr.next();
                if(tCar.getToyCarCode().equals(code)){
                    System.out.println("This model code is already exist");
                    addInventory(tc);
                    outcome = true;
                    break;
                }
            }
            
            System.out.println("Price: ");
            double price = input.nextDouble();
            System.out.println("Quantity: ");
            int qty = input.nextInt();
            System.out.println("Battery duration: ");
            int batteryTime = input.nextInt();
            System.out.println("Charging duration: ");
            int chargeTime = input.nextInt();
        
            ToyCarElec toycarElec = new ToyCarElec(code, price, qty, batteryTime, chargeTime);
            tc.add(toycarElec);
       
            System.out.println("Enter another record? (y/n)");
            record = input.nextLine();
            input.nextLine();  
        }while (record.equals("y"));
        addInventory(tc);
    }
    // option 2 in main menu
    // let user to choose what to remove from arraylist by entering model code
    public static void removeInventory(ArrayList<ToyCar> tc){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter model code: ");
        String deleteCode = input.nextLine();
        
        // if model code that user input is same as in arraylist and quantity is more than 0, program will ask user to confirm want to delete or not
        // if user enter y, program will delete the whole info that under that model code.
        // if user enter n, program will print unsuccessfully message and not delete it.
        // if user enter model code that not exist in arraylist, it will print invalid message.
        boolean found = false;
        Iterator<ToyCar> itr = tc.iterator();
        while(itr.hasNext()){
            ToyCar tCar = itr.next();
            if(tCar.getToyCarCode().equals(deleteCode) && tCar.getToyCarQuantity() > 0){
                Scanner kboard = new Scanner(System.in);
                System.out.println("Remove? (y/n)");
                String answer = kboard.nextLine();
                if (answer.equals("y")){
                    itr.remove();
                    found = true;
                    break;
                }else{
                    System.out.println("Remove unsuccessfully.");
                }
                // if model code that user input is same as in arraylist but quantity is equal to 0,
                //program will just delete without asking user again.
            }else if(tCar.getToyCarCode().equals(deleteCode) && tCar.getToyCarQuantity() == 0){
                itr.remove();
            }       
        }
        if (found){
            System.out.println("Remove successfully.");
        }else{
            System.out.println("That model code was not found.");
        }
    }
    // option 3 in main menu
    public static void showAllInventory(ArrayList<ToyCar> tc){
        // print all inventory
        for (int i = 0; i < tc.size(); i++){
            System.out.println(tc.get(i).toString());
        }
    }
    // option 4 in main menu
    // user enter car model to search same car model in arraylist and display it.
    // if don't have same car model, it will print invalid messsage.
    public static void searchCarModel(ArrayList<ToyCar> tc){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Model Code: ");
        String code = input.nextLine();
        boolean outcome = false;
        for (ToyCar tCar : tc){
            if (tCar.getToyCarCode().equals(code)){
                System.out.println(tCar);
                outcome = true;
            }
        }
        if (outcome == false){
            System.out.println("No such model code.");
            
        }
    }
    // option 5 in main menu
    // user enter lower and upper bound of car price to search car price that between them in arraylist and display it.
    // if don't have, it will print invalid messsage.
    public static void searchCarPrice(ArrayList<ToyCar> tc){
        Scanner input = new Scanner(System.in);
        System.out.println("Lower bound of price: ");
        double lowBound = input.nextDouble();
        System.out.println("Upper bound of price: ");
        double upBound = input.nextDouble();
        int count = 0;
        for (int i = 0; i < tc.size(); i++){
            if (tc.get(i).getToyCarPrice() >= lowBound && tc.get(i).getToyCarPrice() <= upBound){
               System.out.println(tc.get(i).toString());
               count++;
            }
        }
        if (count == 0){
            System.out.println("Cannot found any result.");
        }
    }
    // option 6 in main menu
    // user enter car battery to search car battery that higher or equal that it in arraylist and display it.
    // if don't have, it will print invalid messsage.
    public static void searchCarBattery(ArrayList<ToyCar> tc){
       Scanner input = new Scanner(System.in);
       System.out.println("Battery duration: ");
       double batteryTime = input.nextDouble();
       int count = 0;
       for (ToyCar tCar : tc){
           // downcast method
           if (tCar instanceof ToyCarElec){
               ToyCarElec tCar1 = (ToyCarElec)tCar;
               for (int i = 0; i < tc.size(); i++){
                   if (tCar1.getToyCarBatteryDuration() >= batteryTime){
                       System.out.println(tc.get(i).toString());
                       count++;          
                   }
               }
               if(count == 0){
                   System.out.println("Cannot found any result");
               }
           }
       }      
    }
    // option 7 in main menu
    // exit and terminate the program
    public static void exitSystem(ArrayList<ToyCar> tc){
        System.out.println("Quitting program..........");
        System.exit(0); 
    }
}
// base class 
class ToyCar{
   // instance variable
   private String tCarCode;
   public double tCarPrice;
   public int tCarQuantity;
   
   // constructor
   public ToyCar(String tCCode, double tCPrice, int tCQuantity){
      this.tCarCode = tCCode;
      this.tCarPrice = tCPrice;
      this.tCarQuantity = tCQuantity;
   }
   // get and set method
   public String getToyCarCode(){
       return tCarCode;
   }
   public double getToyCarPrice(){
       return tCarPrice;
   }
   public int getToyCarQuantity(){
       return tCarQuantity;
   }
   // Validation
   public void setToyCarPrice(double newPrice){
       if (newPrice > 0)
           tCarPrice = newPrice;
   }
   public void setToyCarQuantity(int newQty){
       if (newQty >= 0)
           tCarQuantity = newQty;
   }
   public double getTotalInventory(){
       return tCarPrice * tCarQuantity;
   }
   public double getInsuranceCost(){
       return getTotalInventory() * 0.02;
   }
   public String toString(){
       return getToyCarCode() + " " + getToyCarQuantity() + " " + getToyCarQuantity() + " " + getTotalInventory() + " " + getInsuranceCost();
   }     
}
// sub class
class ToyCarElec extends ToyCar{
    private int tCarBattery;
    private int tCarCharging;
    
    public ToyCarElec(String tCCode, double tCPrice, int tCQuantity, int tCBattery, int tCCharging){
        // get from the base class
        super(tCCode, tCPrice, tCQuantity);
        tCarBattery = tCBattery;
        tCarCharging = tCCharging;
    }
    public int getToyCarBatteryDuration(){
        return tCarBattery;
    }
    public int getToyCarChargingDuration(){
        return tCarCharging;
    }
    @Override
    public double getInsuranceCost(){
        return super.getTotalInventory() * 0.10;
    }
    public String toString(){
        return super.getToyCarCode() + " " + super.getToyCarPrice() + " " + super.getToyCarQuantity() + " " + getToyCarBatteryDuration() + " "
                + getToyCarChargingDuration() + " " + super.getTotalInventory() + " " + getInsuranceCost();
    }
}