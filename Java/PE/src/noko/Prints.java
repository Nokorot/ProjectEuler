package noko;

import java.util.Arrays;

public class Prints {

	public static String multi_print_separator = "\t";
	
	public static String toString(Object obj) {
		if (obj == null)
			return "NULL";
		if (obj.getClass().isArray()) {
			if (obj instanceof boolean[])
				return Arrays.toString((boolean[]) obj);
			if (obj instanceof byte[])
				return Arrays.toString((byte[]) obj);
			if (obj instanceof char[])
				return Arrays.toString((char[]) obj);
			if (obj instanceof double[])
				return Arrays.toString((double[]) obj);
			if (obj instanceof float[])
				return Arrays.toString((float[]) obj);
			if (obj instanceof int[])
				return Arrays.toString((int[]) obj);
			if (obj instanceof long[])
				return Arrays.toString((long[]) obj);
			if (obj instanceof short[])
				return Arrays.toString((short[]) obj);
			return Arrays.deepToString((Object[]) obj);
		}
		return obj.toString();
	}
	
	public static void printJ(String seperator, Object... args) {
		String[] strs = new String[args.length];
		for(int i=0; i<args.length; i++) 
			strs[i] = toString(args[i]);
		System.out.println(String.join(seperator, strs));
	}
	
	public static void print(Object... args) {
		printJ(multi_print_separator, args);
	}
	
	public static void println(Object... args) {
		printJ("\n", args);
	}
	
	public static void printf(String format, Object... args) {
		System.out.printf(format, args);
	}
	
	public static void main(String[] args) {
		println(new int[] {1,2,3}, new String[] {"1","2","3"}, new int[][] {new int[] {1,1},new int[] {2,2},new int[] {3,3}}, "\n");
		print(toString(new int[] {1,2,3}));
		print(toString(new String[] {"1","2","3"}));
		print(toString(new int[][] {new int[] {1,1},new int[] {2,2},new int[] {3,3}}));
	}
}
