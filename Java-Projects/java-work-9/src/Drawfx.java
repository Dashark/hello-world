import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Polyline;
import javafx.stage.Stage;
import java.util.DoubleSummaryStatistics;
public class Drawfx extends Application
{
    @Override
    public void start(Stage primaryStage)
    {
        Polyline polyline=new Polyline();
        ObservableList<Double>list=polyline.getPoints();
        Double scaleFactor=0.0125;
        for(int x=-100;x<=100;x++)
        {
            list.add(x+200.0);
            list.add(200.0+scaleFactor*(-x)*x);
        }
        Pane pane =new Pane();
        pane.getChildren().add(polyline);
        Scene scene =new Scene(pane,400,400);
        primaryStage.setTitle("f(x)=x*x");
        primaryStage.setScene(scene);
        primaryStage.show();
    }


}
