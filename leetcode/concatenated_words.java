package dev.rohit;

import dev.rohit.observer.WeatherData;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Trie{
  public char letter;
  public List<Trie> children;

  public boolean isTerminal;

  public Trie(char letter, boolean isTerminal){
    this.letter = letter;
    this.isTerminal = isTerminal;
    children = new ArrayList<>();
  }
}

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    sc.nextLine();
    List<String> words = new ArrayList<>();
    for(int i = 0; i < n; ++i){
      words.add(sc.nextLine());
    }
    for(String word : solve(words)){
      System.out.println(word);
    }
  }

  public static List<String> solve(List<String> words){
    final Trie root = new Trie('@', false);
    final List<String> answer = new ArrayList<>();
    for(String word : words){
      addWord(word, root);
    }
    for(String word : words){
      if(check(word, root)){
        answer.add(word);
      }
    }
    return answer;
  }

  public static boolean check_second(String word, Trie root, int index){
    Trie curr = root;
    for(int i = index; i < word.length(); ++i){
      char letter = word.charAt(i);
      for(int j = 0; j < curr.children.size(); ++j){
        if(letter == curr.children.get(j).letter){
          if(curr.children.get(j).isTerminal){
            return true;
          }
          curr = curr.children.get(j);
        }
      }
    }
    return false;
  }


  public static boolean check(String word, Trie root){
    Trie curr = root;
    for(int i = 0; i < word.length(); ++i){
      char letter = word.charAt(i);
      boolean found = false;
      for(int j = 0; j < curr.children.size(); ++j){
        if(letter == curr.children.get(j).letter){
          found = true;
          if(curr.children.get(j).isTerminal){
            if(check_second(word, root, i + 1)){
              return true;
            }
          }
          curr = curr.children.get(j);
        }
      }
      if(!found){
        return false;
      }
    }
    return false;
  }

  public static void addWord(String word, Trie root){
    Trie curr = root;
    for(int i = 0; i < word.length(); ++i){
      char letter = word.charAt(i);
      boolean found = false;
      for(int j = 0; j < curr.children.size(); ++j){
        if(letter == curr.children.get(j).letter){
          found = true;
          curr = curr.children.get(j);
          break;
        }
      }
      if(!found){
        Trie newNode = new Trie(word.charAt(i), (i == (word.length() - 1)));
        curr.children.add(newNode);
        curr = newNode;
      }
    }
  }

}


/*********** Leet code version **********/

    class Trie{
  public char letter;
  public List<Trie> children;

  public boolean isTerminal;

  public Trie(char letter, boolean isTerminal){
    this.letter = letter;
    this.isTerminal = isTerminal;
    children = new ArrayList<>();
  }
}

class Solution {



    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        return solve(Arrays.stream(words).collect(Collectors.toList()));
    }

    public List<String> solve(List<String> words){
    final Trie root = new Trie('@', false);
    final List<String> answer = new ArrayList<>();
    for(String word : words){
      addWord(word, root);
    }
    for(String word : words){
      if(check(word, root)){
        answer.add(word);
      }
    }
    return answer;
  }

  public boolean check_second(String word, Trie root, int index){
    Trie curr = root;
    for(int i = index; i < word.length(); ++i){
      char letter = word.charAt(i);
      for(int j = 0; j < curr.children.size(); ++j){
        if(letter == curr.children.get(j).letter){
          if(curr.children.get(j).isTerminal){
            return true;
          }
          curr = curr.children.get(j);
        }
      }
    }
    return false;
  }


  public boolean check(String word, Trie root){
    Trie curr = root;
    for(int i = 0; i < word.length(); ++i){
      char letter = word.charAt(i);
      boolean found = false;
      for(int j = 0; j < curr.children.size(); ++j){
        if(letter == curr.children.get(j).letter){
          found = true;
          if(curr.children.get(j).isTerminal){
            if(check_second(word, root, i + 1)){
              return true;
            }
          }
          curr = curr.children.get(j);
        }
      }
      if(!found){
        return false;
      }
    }
    return false;
  }

  public void addWord(String word, Trie root){
    Trie curr = root;
    for(int i = 0; i < word.length(); ++i){
      char letter = word.charAt(i);
      boolean found = false;
      for(int j = 0; j < curr.children.size(); ++j){
        if(letter == curr.children.get(j).letter){
          found = true;
          curr = curr.children.get(j);
          break;
        }
      }
      if(!found){
        Trie newNode = new Trie(word.charAt(i), (i == (word.length() - 1)));
        curr.children.add(newNode);
        curr = newNode;
      }
    }
  }
}