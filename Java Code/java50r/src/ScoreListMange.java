import java.util.ArrayList;

public class ScoreListMange {
    private ArrayList<ScoreList> list = null;

    public ScoreListMange() {
        list = new ArrayList<>();
    }

    public ScoreListMange(ArrayList<ScoreList> list) {
        this.list = list;
    }

    public double getAverage() {
        double average = 0.0;
        int i = 0;
        for (ScoreList each : list) {
            average += each.getTotalScore();
            i++;
        }
        return average / i;
    }

    public String numberOfEveryScore() {
        String result = "";
        result += "90分以上的人如下：";
        for (ScoreList each : list) {
            if (each.getTotalScore() >= 90) {
                result += each.toString();
                result += "\n";
            }
        }
        result += "\n";
        result += "80--89分的人如下：";
        for (ScoreList each : list) {
            if (each.getTotalScore() >= 80 && each.getTotalScore() < 90) {
                result += each.toString();
                result += "\n";
            }
        }
        result += "\n";
        result += "70--79分的人如下：";
        for (ScoreList each : list) {
            if (each.getTotalScore() >= 70 && each.getTotalScore() < 80) {
                result += each.toString();
                result += "\n";
            }
        }
        result += "\n";
        result += "60--69分的人如下：";
        for (ScoreList each : list) {
            if (each.getTotalScore() >= 60 && each.getTotalScore() < 70) {
                result += each.toString();
                result += "\n";
            }
        }
        result += "\n";
        result += "60分以下的人如下：";
        for (ScoreList each : list) {
            if (each.getTotalScore() < 60) {
                result += each.toString();
                result += "\n";
            }
        }
        result += "\n";
        return result;
    }

    public String getStudentById(int id) {
        for (ScoreList each : list) {
            if (each.getId() == id) {
                return each.toString();
            }
        }
        return "NOT FOUND";
    }

    public String getHighest() {
        double score = 0.0;
        int id = 0;
        for (ScoreList each : list) {
            if (each.getTotalScore() > score) {
                score = each.getTotalScore();
                id = each.getId();
            }
        }
        if (id == 0) {
            return "NOT FOUND";
        }
        return getStudentById(id);
    }

    public void add(ScoreList scoreList) {
        this.list.add(scoreList);
        return;
    }
}
