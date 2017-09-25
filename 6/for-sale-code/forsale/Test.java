/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package forsale;

import java.util.ArrayList;
import java.util.*;
/**
 *
 * @author MichaelAlbert
 */
public class Test {
  
  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    String[][] place = new String[6][2];
    
    // A null strategy - never bid, always play your top card.
    Strategy s = new Strategy() {
      
      @Override
      public int bid(PlayerRecord p, AuctionState a) {
        return -1;
      }
      
      @Override
      public Card chooseCard(PlayerRecord p, SaleState s) {
        return p.getCards().get(0);
      }
      
    };
    
    // A random strategy - make a random bid up to your amount remaining,
    // choose a rand card to sell.
    Strategy r = new Strategy() {
      
      @Override
      public int bid(PlayerRecord p, AuctionState a) {
        return (int) (1 + (Math.random() * p.getCash()));
      }
      
      @Override
      public Card chooseCard(PlayerRecord p, SaleState s) {
        return p.getCards().get((int) (Math.random() * p.getCards().size()));
      }
      
    };
    
    Strategy P = new Strategy() {
      Decision decision = new Decision();
      
      @Override
      public int bid(PlayerRecord p, AuctionState a) {
        return decision.bid(p, a);
      }
      
      @Override
      public Card chooseCard(PlayerRecord p, SaleState s) {
        return decision.chooseCard(p, s);
      }
    };
    
    
    Strategy L = new Strategy() {
      Strats strat = new Strats();
      
      @Override
      public int bid(PlayerRecord p, AuctionState a) {
        return strat.bid(p, a);
      }
      
      @Override
      public Card chooseCard(PlayerRecord p, SaleState s) {
        return strat.chooseCard(p, s);
      }
    };
    for (int i = 0; i < 25000; i++) {
      ArrayList<Player> players = new ArrayList<Player>();
        players.add(new Player("P1", P));
        players.add(new Player("P2", P));
        players.add(new Player("P3", r));
        players.add(new Player("L1", s));
        players.add(new Player("L2", L));     
        players.add(new Player("L3", L));
        Collections.shuffle(players);
        if(i==0){
          for (int j = 0; j < 6; j++) {
            place[j][0] = players.get(j).getName();
            place[j][1] = "0";
          }
        }
      
      GameManager g = new GameManager(players);
      g.run();
      for (String p[] : place) {
        if (g.getWinner().getName() == p[0]) {
          p[1] = Integer.toString(Integer.parseInt(p[1]) + 1);
        }
      }
    }
    for(int i =0; i< 6; i++){
      System.out.println(place[i][0] + " : " + place[i][1]);
    }
//    //   for(int i =0; i < 10; i++){
//    GameManager g = new GameManager(players);
//    g.run();
//    System.out.println(g.getLog());
    
  }
  
}
