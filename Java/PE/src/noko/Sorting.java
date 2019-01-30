package noko;

import java.util.Arrays;

public class Sorting<T> {
	    
    public static void radixsort(SortKey<Object> sk, Object[] vals) {
    	int[] keys = new int[vals.length];
    	for (int i=0; i<vals.length; i++)
    		keys[i] = sk.getKey(vals[i]);
    	radixsort(keys, vals); 
    }
    
	
	public static int getMax(int arr[]) { 
        int mx = arr[0]; 
        for (int i = 1; i < arr.length; i++) 
            if (arr[i] > mx) 
                mx = arr[i]; 
        return mx; 
    }
	
    //	Sorts according to the d'th hex-digit.
	public static void countSortHex(int arr[], int d) {
		countSortHex(arr, new int[16], new int[arr.length], d);
	}
	
    private static void countSortHex(int arr[], int[] count, int[] output, int d) { 
        int i, n=arr.length; 
        for (i = 0; i < arr.length; i++) 
            count[ (arr[i] >> (4*d)) & 0xf ]++; 
  
        for (i = 1; i < 16; i++) 
            count[i] += count[i - 1]; 
  
        for (i = n - 1; i >= 0; i--) { 
            output[count[ (arr[i] >> (4*d)) & 0xf ] - 1] = arr[i]; 
            count[ (arr[i] >> (4*d)) & 0xf ]--; 
        }
        for (i = 0; i < n; i++) 
            arr[i] = output[i]; 
    } 
  
    public static void radixsort(int arr[]) { 
    	int m = getMax(arr); 

    	int[] output = new int[arr.length];
    	int[] count = new int[16];
    	
        for (int d = 0; (m >> 4*d) > 0; d++) 
            countSortHex(arr, count, output, d); 
    } 
    
    private static void countSortHex(int[] keys, Object[] vals, int[] okeys, Object[] ovals, int[] count, int d) {
    	Arrays.fill(count, 0);
    	int i, n=keys.length; 
        for (i = 0; i < n; i++) 
            count[ (keys[i] >> (4*d)) & 0xf ]++; 
  
        for (i = 1; i < 16; i++) 
            count[i] += count[i - 1]; 
  
        for (i = n - 1; i >= 0; i--) { 
            okeys[count[ (keys[i] >> (4*d)) & 0xf ] - 1] = keys[i];
            ovals[count[ (keys[i] >> (4*d)) & 0xf ] - 1] = vals[i]; 
            count[ (keys[i] >> (4*d)) & 0xf ]--; 
        }

        for (i = 0; i < n; i++) { 
            keys[i] = okeys[i]; 
            vals[i] = ovals[i]; 
        }
    }
    
    private static void radixsort(int keys[], Object[] vals, int[] okeys, Object[] ovals, int[] count) {
    	int m = getMax(keys); 

        for (int d = 0; (m >> 4*d) > 0; d++) 
            countSortHex(keys, vals, okeys, ovals, count, d); 
    }
    
    public static void radixsort(int keys[], Object[] vals) {
    	radixsort(keys, vals, new int[keys.length], new Object[keys.length], new int[16]); 
    }
    
    private static void radixsort(String[] vals, int[] okeys, Object[] ovals, int[] count) {
    	int[] keys = new int[vals.length];
    	
    	int ml = 0;
    	for(String s : vals)
    		if (s.length() > ml)
    			ml = s.length();

        for (int d=ml-1; d>=0; d--) {
//    	for (int d=0; d<ml; d++) {
        	for(int i=0; i < vals.length; i++)
        		keys[i] = vals[i].length() > d ? vals[i].charAt(d) : 0;
        	countSortHex(keys, vals, okeys, ovals, count, d);
        }	
    }
    
    public static void radixsort(String[] vals) {
    	radixsort(vals, new int[vals.length], new Object[vals.length], new int[16]);
    }

}
interface SortKey<T> {
	public int getKey(T o);
}
