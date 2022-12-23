public class ScoreList {
    private String name;
    private int id;
    private String className;
    private double middleScore;
    private double finalScore;
    private double totalScore;

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    public ScoreList(String name, int id, String className, double middleScore, double finalScore) {
        this.name = name;
        this.id = id;
        this.className = className;
        this.middleScore = middleScore;
        this.finalScore = finalScore;
        this.totalScore=(middleScore+finalScore)/2;
    }



    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getMiddleScore() {
        return middleScore;
    }

    public void setMiddleScore(double middleScore) {
        this.middleScore = middleScore;
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", id=" + id +
                ", middleScore=" + middleScore +
                ", finalScore=" + finalScore +
                ", totalScore=" + totalScore +
                '}';
    }

    public double getFinalScore() {
        return finalScore;
    }

    public void setFinalScore(double finalScore) {
        this.finalScore = finalScore;
    }

    public double getTotalScore() {
        return totalScore;
    }
}
