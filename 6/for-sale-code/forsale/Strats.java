package forsale;


import java.util.ArrayList;
import java.util.*;
public class Strats implements Strategy{
  public int bid(PlayerRecord p, AuctionState a){
    
    int bidMinimum = 1+a.getCurrentBid();
    int lowcard = 30;
    int highcard = 0;
    int cardQuality = 0;
    ArrayList<Card> cardsInAuction = a.getCardsInAuction();
    if(a.getCardsInDeck().size()==0){
      return p.getCash();
    }
    for(int i=0;i<cardsInAuction.size();i++){
      cardQuality = cardsInAuction.get(i).getQuality();
      if(cardQuality > highcard){
        highcard = cardQuality;
      }
      if(cardQuality < lowcard){
        lowcard = cardQuality;
      }
    }
    if(bidMinimum > p.getCash()/2){
      return 0;
    }
    if(bidMinimum == 1){
      return 2;
    }
    if(lowcard>=15 && highcard<=27){
      if(bidMinimum <= 4){
        return bidMinimum;
      }
    }
    if(lowcard==0 || highcard <= 28){
      return bidMinimum;
    }
    if(bidMinimum<=4){
      return bidMinimum;
    }
    return 0;
  }

  public Card chooseCard(PlayerRecord p, SaleState s){
    ArrayList<Integer> cardsInSale = s.getChequesAvailable();
    ArrayList<Integer> cardsInDeck = s.getChequesRemaining();
    ArrayList<Card> hand = p.getCards();
    double averageDeck = 0;
    double averageSale = 0;
    int deckSize = cardsInDeck.size();
    int handSize = hand.size();
    Collections.sort(hand);
    for(int i = 0; i<deckSize;i++) {
      averageDeck+=cardsInDeck.get(i)/deckSize;
    }
    for(int i = 0; i<5; i++){
      averageSale+=cardsInSale.get(i)/5;
      if(cardsInSale.get(i) == 15){
        return hand.get(handSize-1);
      }
      if(cardsInSale.get(i) == 0){
        return hand.get((handSize/2));
      }
    }
    if(averageSale>averageDeck){
      return hand.get(handSize-1);
    }else{
      return hand.get(0);
    }
  }
  
}


