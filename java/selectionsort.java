import java.util.*;
import java.io.*;

class selectionsort {
    public void selsort(int[] arr) {
        int sIndex = 0;
        int smallestIndex = 0;
        Integer tmp = null;
        int i = 0;
        int count = arr.length;

        while (sIndex < count) {
            smallestIndex = sIndex;
            for (i = sIndex; i < count; i++) {
                if (arr[i] < arr[smallestIndex]) {
                    smallestIndex = i;
                }
            }
            if (sIndex < smallestIndex) {
                tmp = arr[smallestIndex];
                arr[smallestIndex] = arr[sIndex];
                arr[sIndex] = tmp;
            }
            sIndex++;
        }
    }

    public void run() {
        double start = 0;
        double after_read = 0;
        double after_sort = 0;
        String inputfile = "/Users/alex/temp/random_numbers.txt";
        List<Integer> data = new ArrayList<Integer>();
        int[] intData;

        // start
        start = System.currentTimeMillis() / 1000.0;
        System.out.println("Start: "+start);

        // Fill vector:
        try {
            BufferedReader br = new BufferedReader(new FileReader(inputfile));
            String line;
            while ((line = br.readLine()) != null) {
               data.add(Integer.parseInt(line));
            }
            intData = new int[data.size()];
            for (int i = 0; i < data.size(); i++) {
                intData[i] = data.get(i);
            }
            after_read = System.currentTimeMillis() / 1000.0;

            // sort array:
            this.selsort(intData);

            after_sort = System.currentTimeMillis() / 1000.0;
            System.out.println("Fill time: "+(after_read - start));
            System.out.println("Sort time: "+(after_sort - after_read));
            System.out.println("First nr: "+intData[0]+", last nr: "+intData[intData.length-1]+", count: "+intData.length);
        } catch (Exception e) {
        }






    }

    public static void main(String[] args) {
        new selectionsort().run();
    }
}
