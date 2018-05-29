import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Arc;
import javafx.scene.shape.ArcType;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Test extends Application {
    @Override
    public void start(Stage primaryStage) {
        Pane pane1=new Pane();
        Arc arc1=new Arc(180,100,80,80,0,72);
        arc1.setFill(Color.RED);
        arc1.setType(ArcType.ROUND);
        Arc arc2=new Arc(180,100,80,80,72,36);
        arc2.setFill(Color.BLUE);
        arc2.setType(ArcType.ROUND);
        Arc arc3=new Arc(180,100,80,80,108,108);
        arc3.setFill(Color.GREEN);
        arc3.setType(ArcType.ROUND);
        Arc arc4=new Arc(180,100,80,80,216,144);
        arc4.setFill(Color.ORANGE);
        arc4.setType(ArcType.ROUND);
        pane1.getChildren().addAll(new Text(250,60,"项目：20%"),arc1,new Text(145,15,"测试：10%"),arc2,new Text(1,140,"期中考试：30%"),arc3,new Text(240,170,"期末考试：40%"),arc4);
        Scene scene=new Scene(pane1,350,200);
        primaryStage.setTitle("总成绩组成");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
