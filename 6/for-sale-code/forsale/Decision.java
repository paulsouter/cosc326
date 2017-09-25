
package forsale;

import java.util.*;
import java.util.ArrayList;

class Decision {
  
  // private double[] chromosomes;
  //  private ArrayList<ArrayList<double[]>> chromosomesS;
  //private PlayerRecord p;
  private AuctionState a;
  private ArrayList<int[]> pR;
  
  Decision(){};
  
  public int bid(PlayerRecord p, AuctionState a){
    
//    this.a = a;
//    ArrayList<Card> cards = a.getCardsInAuction();
//    int max = 0;
//    int min = 0;
//    int diff= 0;
//    int diff2 = 0;
//    int locdiff=0;
//    
//        for (Card c : cards){
//      if (c.getQuality() > max)
//        max = c.getQuality();
//      if (c.getQuality() < min)
//        min = c.getQuality();
//    }
//    //  diff = a.getCardsInAuction().get(0).getQuality();
//    for(int i=1; i<a.getCardsInAuction().size(); i++){
//    //  System.out.println(a.getCardsInAuction().get(i));
//      if(a.getCardsInAuction().get(i).getQuality() -a.getCardsInAuction().get(i-1).getQuality() > diff2){
//        diff2 = a.getCardsInAuction().get(i).getQuality() -a.getCardsInAuction().get(i-1).getQuality();
//        locdiff = i;
//      }
//    }
//    for (Card c : cards){
//      if (c.getQuality() > max)
//        max = c.getQuality();
//      if (c.getQuality() < min)
//        min = c.getQuality();
//    }
//    diff = max - min;
//    
//    if(a.getPlayersInAuction().size() ==2 && diff >20){
//      return 0;
//    }
//    double bidyes = 0;
//    
//    if(locdiff <= 3){
//      if(diff > 15)
//        bidyes = 100;
//      else{
//        if(a.getCurrentBid() < 4){
//      //    bidyes = 100;
//        }
//      }     
//    }
//    else if(locdiff <= 5){
//      if(diff > 15)
//        bidyes = 100;
//      else{
//        if(a.getCurrentBid() < 5){
//       //   bidyes = 100;
//        }
//      }   
//    }else{
//      if(diff > 20){
//        bidyes = 100;
//      }
//      if(diff2 < 6){
//     //  bidyes = 100; 
//      }
//    }
//   // System.out.println(bidyes);
//    if(bidyes > 10){
//      return a.getCurrentBid() +1;
//    }else
//      return 0;
////    
    this.a = a;
    ArrayList<Card> cards = a.getCardsInAuction();
    int max = 0;
    int min = 0;
    int diff= 0;
    
    
    for (Card c : cards){
      if (c.getQuality() > max)
        max = c.getQuality();
      if (c.getQuality() < min)
        min = c.getQuality();
    }
    diff = max - min;
    if(a.getPlayersInAuction().size() ==2 && diff >20){
      return 0;
    }
    double bidyes = 0;
    Random rand = new Random();
    double ran = rand.nextInt(10);
    while (ran == 0)
      ran =rand.nextInt(10);
   // System.out.println("rand :"+ran);
    // System.out.println("players "+a.getPlayersInAuction().size()
    if(p.getCards().size() ==0)
      bidyes =(ran*diff/2)/a.getPlayersInAuction().size();
    else
      bidyes = (((ran/2)*p.getCards().size()*diff)/1.5)/a.getPlayersInAuction().size();
    if(a.getPlayersInAuction().size() == 2)
      bidyes = -100;
    if(p.getCards().size() == 5){
      bidyes = 100;
    }
    if(bidyes > 10){
      return a.getCurrentBid() +1;
    }else
      return 0;
  }
  
  
  public Card chooseCard(PlayerRecord p, SaleState s){
    int diff= s.getChequesAvailable().get(4) - s.getChequesAvailable().get(0);
    Random rand = new Random();
    int card = rand.nextInt(p.getCards().size());
    if(diff >7 && card != p.getCards().size()-1){
      card = p.getCards().size()-1;
    }
    if(diff < 5 && card != 0){
      card--;
    }
    if(diff == 3)
      return p.getCards().get(0);
    if(p.getCards().size() == 1)
      return p.getCards().get(0);
    int cards = p.getCards().size();
////    while(card > cards -1)
////      card--;
    //  System.out.println(card);
    return p.getCards().get(card);
  }
}
