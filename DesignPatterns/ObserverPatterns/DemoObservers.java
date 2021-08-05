import java.util.ArrayList;
import java.util.Arrays;


public class DemoObservers {
    
    public static void main(String[] args) {
        
        StateData stateData = new StateData();
        stateData.setCurrentTeam("India");

        new FirstObserver(stateData);
        new SecondObserver(stateData);

        String[] teams = {"India", "England", "Australia", "NewZealand"};

        
        Arrays.stream(teams).forEach(team->{
            try{
                Thread.sleep(750);
                stateData.setCurrentTeam(team);
            }
            catch(InterruptedException interruptedException){
                interruptedException.printStackTrace();
            }
            
        });        


    }

}
