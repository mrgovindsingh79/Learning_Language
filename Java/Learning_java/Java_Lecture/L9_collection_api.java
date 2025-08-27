import java.util.*;

public class L9_collection_api {
    public static void main(String[] args) {
        System.out.println("Collection API in Java");
        ArrayList<Integer> nums = new ArrayList<Integer>();
        nums.add(10);
        nums.add(2);
        nums.add(3);
        nums.add(4);
        System.out.println(nums);
        System.out.println("Element at index 2: " + nums.get(2));
        nums.remove(2);
        System.out.println("After removing element at index 2: " + nums);
        System.out.println("Size of arraylist: " + nums.size());

        for (int i = 0; i < nums.size(); i++) {
            System.out.println("Element at index " + i + ": " + nums.get(i));
        }
        nums.sort(null);
        System.out.println(nums);
        nums.sort(Comparator.reverseOrder());
        System.out.println(nums);



        HashSet<Integer> set = new HashSet<Integer>();
        set.add(1);
        set.add(2);
        set.add(3);
        set.add(2); //duplicate value will not be added
        System.out.println("HashSet: " + set);

        HashMap<String, Integer> map = new HashMap<String, Integer>();
        map.put("One", 1);
        map.put("Two", 2);
        map.put("Three", 3);    
        System.out.println("HashMap: " + map);
        System.out.println("Value for key 'Two': " + map.get("Two"));

        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            System.out.println("Key: " + entry.getKey() + " Value: " + entry.getValue());
        }

        Map<String, Integer> mp = new HashMap<String, Integer>();
        mp.put("A", 1);
        mp.put("B", 2);
        mp.put("C", 3);
        System.out.println("Map: " + mp);
        for (String key : mp.keySet()) {
            System.out.println("Key: " + key + " Value: " + mp.get(key));
        }
    }
}
