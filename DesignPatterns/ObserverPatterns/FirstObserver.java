public class FirstObserver extends Observer{
    
    public FirstObserver(StateData stateData){
        this.localCopy = stateData;
        this.localCopy.addObserver(this);
    }

    @Override
    public void update(){        
        System.out.println("First Observer received update: "+localCopy.currentTeam);
    }

}
