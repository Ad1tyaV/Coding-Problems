import java.util.*;

public class StateData {
    
    String currentTeam;
    List<Observer> observers = new ArrayList<Observer>();

    public void setCurrentTeam(String currentTeam){
        this.currentTeam = currentTeam;
        notifyObservers();
    }

    public void addObserver(Observer observer){
        observers.add(observer);
    }

    public void notifyObservers(){

        observers.stream().forEach(observer->{
            observer.update();
        });

    }

}
