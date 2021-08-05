public class SecondObserver extends Observer{
    
    public SecondObserver(StateData stateData){
        this.localCopy = stateData;
        this.localCopy.addObserver(this);
    }

    @Override
    public void update(){
        System.out.println("Second Observer received update = "+localCopy.currentTeam);
    }

}
