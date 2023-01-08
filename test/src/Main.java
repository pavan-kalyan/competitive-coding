import java.util.*;

class Main {

    public static void main(String[] args) {

        String inp = "[\"YoungWilliamSanNJose,\", \"95112CA649-601St\", \"17th\"],\n" +
                "[\"84049UTN99-1\", \"100P\", \"atric\", \"iaM\", \"idw\", \"ay,Flo\", \"res\", \"W\"],\n" +
                "[\"Carol82901Baker\", \"ElkStS\", \"prings,1\", \"469-14\", \"01\", \"W\", \"Y\", \"Rock\"],\n" +
                "[\"81639Hayden,HarrisCOMargaretRdCo\", \"6911108-11000\"],\n" +
                "[\"James67042S\", \"t,KSKingNE\", \"35thDora\", \"do,El\"],\n" +
                "[\"741191633Tulsa,BoulderAve,\", \"HarrisOKDon\", \"n\", \"aS\"],\n" +
                "[\"72703MallF\", \"ayetteville,ARCo\", \"ok4074James\", \"Ave,\"],\n" +
                "[\"BarbaraSuite105,M\", \"ay3867\", \"2RogersBlvd2868Southa\", \"ven,MS\"],\n" +
                "[\"40391Ave,KYBettyWinches\", \"ter,TaylorLex\", \"ington145\", \"2W\"],\n" +
                "[\"37604TNWWalnut415JohnsonRobertSt,GonzalesCi\", \"ty\", \",\"],\n" +
                "[\"Rd,28604NC\", \"HowardHawthorneBeech\", \"1\", \"10Mountain,Kimber\", \"l\", \"y\"],\n" +
                "[\"MariaVA24149RinerRd,Collins4330Ri\", \"n\", \"e\", \"r,\"],\n" +
                "[\"Frederick,21701M\", \"D489MorganWSt,\", \"SharonPa\", \"t\", \"r\", \"ic\", \"k\"],\n" +
                "[\"Dr,MurphyPAHersheypar\", \"k17033H\", \"elenHer\", \"shey\", \",\", \"1\", \"0\", \"0\"],\n" +
                "[\"101NewYork,NYSusanParkA\", \"ve,10178Thompson\"],\n" +
                "[\"AndersonNorthville,\", \"NYNY-30,12134D\", \"or\", \"o\", \"th\", \"y\"],\n" +
                "[\"RobertRd63Killington\", \",05751VTJacksonCurrie\", \"r\"]";

        List<String> names = ;




        //first name last name
        Map<String, List<String>> m = new HashMap<>();

        List<List<String>> input = new ArrayList<>();


        Set<String> firstNames = new HashSet<>();
        Set<String> lastNames = new HashSet<>();
        List<String> concats = new ArrayList<>();
        for (int i=0;i< input.size();i++) {
            String res = "";
            for (int j=0;j<input.get(i).size();j++) {
                res += input.get(i).get(j);
            }
            concats.add(res);
        }

        List<String> res = new ArrayList<>();
        for (int i=0;i<concats.size();i++) {

            for (Map.Entry<String, List<String>> e : m.entrySet()) {

                String firstName = e.getValue().get(0);
                String lastName = e.getValue().get(1);
                if (concats.contains(firstName) && concats.contains(lastName)) {
                    res.add(e.getKey());
                }
            }
        }

        for (String answer : res) {
            System.out.println(answer);
        }
    }
}
