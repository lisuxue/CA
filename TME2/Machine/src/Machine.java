import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Machine {

	private ArrayList<Integer> plateaux;
	private Integer[] registres;
	private ArrayList<ArrayList<Integer>> coll_tab_plateaux;
	private char console;
	private int indExec;
	
	public int A,B,C,D; //portion de plateaux
	
	public Machine() {
		plateaux = new ArrayList<>();
		registres = new Integer[8];
		coll_tab_plateaux = new ArrayList(new ArrayList<>());
		console = ' ';
		indExec = 0;
		for(int i = 0;i<registres.length;i++) registres[i] = 0;
	}
	

	
	public void lecture(Integer plateau) {
		String mot = Integer.toBinaryString(plateau); //plateau en binaire
		//recup le opCode
		String opCodeBin = mot.substring(0, 4); 
		int code = Integer.parseInt(opCodeBin, 2);
		//recup les registres a b c 
		int c = Integer.parseInt(mot.substring(29,31),2);
		int b = Integer.parseInt(mot.substring(26,28),2);
		int a = Integer.parseInt(mot.substring(23,25),2);
		
		switch (code) {
		case 0:
			mouv_cond(a,b,c);
			break;
		case 1:
			ind_tab(a,b,c);
			break;
		case 2:
			mod_tab(a,b,c);
			break;
		case 3:
			add(a,b,c);
			break;
		case 4:
			mul(a,b,c);
			break;
		case 5:
			div(a,b,c);
			break;
		case 6:
			not_and(a,b,c);
			break;
		case 7:
			stop(a,b,c);
			break;
		case 8:
			alloc(a,b,c);
			break;
		case 9:
			aband(a,b,c);
			break;
		case 10:
			exit(a,b,c);
			break;
		case 11:
			enter(a,b,c);
			break;
		case 12:
			load_prog(a,b,c);
			break;
		case 13:
			ortho(a,b,c);
			break;
		default:
			System.out.println("opcode non valide : "+code);
			break;
		}
	}



	public void ortho(int a,int b,int c) {

		
	}



	public void load_prog(int a,int b,int c) {

		ArrayList<Integer> copie = (ArrayList<Integer>)(coll_tab_plateaux.get(registres[b]).clone());
		coll_tab_plateaux.set(0, copie);
		indExec = registres[c];
	
	}



	public void enter(int a,int b,int c) {
		Scanner sc = new Scanner(System.in);
		Integer entree = null;
		Boolean fin = false;
		if(sc.hasNextLine()) {
			String s = sc.nextLine();
			if(s.length() == 0) {
				registres[c] = 0xFFFFFFFF;
			}else {
				try {
					entree = Integer.parseInt(s);
				}catch(Exception e) {
					fin = true; //on considère que tout les entrées qui ne correspondent pas à un format integer, sont prit comme fin 
				}
			if(fin)
				registres[c] = 0xFFFFFFFF;
			else
				registres[c] = entree;
			}
		}
		sc.close();
	}



	public void exit(int a,int b,int c) {
		if(registres[c]<=255) {
			if(registres[c]>= 0 ) {
				System.out.println(registres[c]);
			}
		}else
			System.out.println("Error exit");
	}



	public void aband(int a,int b,int c) {
		coll_tab_plateaux.remove((int)registres[c]);
	}



	public void alloc(int a,int b,int c) {

		ArrayList<Integer> l = new ArrayList<>(registres[c]);
		for (int i = 0 ;i<l.size();i++) {
			l.set(i,0);
		}
		coll_tab_plateaux.add(l);
		registres[b] = coll_tab_plateaux.indexOf(l);
	}



	public void stop(int a,int b,int c) {

		System.exit(0);
	}



	public void not_and(int a,int b,int c) {

		registres[a] = ~(registres[b] & registres[c]); 
	}



	public void div(int a,int b,int c) {

		registres[a]= (int) ((registres[b] / registres[c]) % Math.pow(2,32));
	}



	public void mul(int a,int b,int c) {

		registres[a]= (int) ((registres[b] * registres[c]) % Math.pow(2,32));
	}



	public void add(int a,int b,int c) {

		registres[a]= (int) ((registres[b] + registres[c]) % Math.pow(2,32));
	}



	public void mod_tab(int a,int b,int c) {

		coll_tab_plateaux.get(registres[a]).set(registres[b],registres[c]);
	}



	public void ind_tab(int a,int b,int c) {

		registres[a] = coll_tab_plateaux.get(registres[b]).get(registres[c]);
	}
	
	private void mouv_cond(int a, int b, int c) {

		if(registres[c]!=0)
			registres[a]=registres[b];
	}

	public ArrayList<byte[]> read(String filename) {
		ArrayList<byte[]> l = new ArrayList<>();
		try {
			FileInputStream f = new FileInputStream(filename);
			byte[] bTab = new byte[4];
			while (f.read(bTab) != -1) {
				l.add(bTab);
			}
			f.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public static void main(String[] args) {
		Machine m1 = new Machine();
		/*La machine lit le contenu du parchemin de programme et le stocke dans coll_tab_plateaux[0][0]
		 * 
		 * */
		//System.out.println(Integer.toBinaryString(Integer.MAX_VALUE));
		byte[] b = new byte[4];
		System.out.println("avant le read");
		ArrayList<byte[]> l = m1.read("src/benchsum/fact.um");
		for(int i=0;i<l.size();i++) {   ///que faire ????
			System.out.println("yo");
			System.out.println(l.get(i));
		}
		
		
		
	}
}



/*
 * System.out.println("kjhkkjkjk");
			try {
				entree = sc.nextInt();
				System.out.println(entree);
			}catch(InputMismatchException e) {  //le type de donnée en entrée n'est pas integer 
				if((sc.nextLine()).length() == 0 )  // si la ligne est vide, fin d'entree signalée
					fin = true;
				else 
					fin = true;
			}catch(NoSuchElementException e) {
				System.out.println("Le flux est terminé");
			}catch(IllegalStateException e) {
				System.out.println("Le scanner est déjà fermé");
			}finally {
				if(fin) { //fin signalée
					//registres[c] = 0xFFFFFFFF;
					System.out.println("false pas dentree");
				}else {
					//registres[c] = entree;
					System.out.println("jgjhgjgj");
				}
			}
 * */
