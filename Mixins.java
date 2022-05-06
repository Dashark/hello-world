/**
 * 组合模式
 * 在 TaggableImpl 中实现打标签的逻辑
 *  Post 类和 TaggableImpl 类都实现 Taggable 接口
 * Post 类中创建一个 TaggableImpl 实例并在实现 Taggable 时将相应方法调用委托过去。
 */


import java.util.List;
import java.util.ArrayList;

interface Entity {
    public int getId();
    public int getKind();
}

interface Taggable {
    public void addTag(int tagId);
    public List<Integer> getTags();
}

class TaggableImpl implements Taggable {
    private Entity target;

    public TaggableImpl(Entity target) {
        this.target = target;
    }

    public void addTag(int tagId) {
        int id = target.getId();
        int kind = target.getKind();
        System.out.println("insert into ... values "
                + id + ", "
                + kind + ", "
                + tagId + ")");
    }

    public ArrayList<Integer> getTags() {
        // query from database
        return new ArrayList<Integer>();
    }
}

class Post implements Entity, Taggable {
    public final static int KIND = 1001;

    private Taggable taggable;
    private int id;
    private String title;

    public Post(int id, String title) {
        this.id = id;
        this.title = title;
        this.taggable = new TaggableImpl(this);
    }

    public int getId() {
        return id;
    }

    public int getKind() {
        return KIND;
    }

    public void addTag(int tagId) {
        taggable.addTag(tagId);  // delegate
    }

    public ArrayList<Integer> getTags() {
        return taggable.getTags();  // delegate
    }
}