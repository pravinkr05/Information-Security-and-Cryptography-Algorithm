/******************************************************************************

Apply encryption and decryption using playfair cipher.(Key matrix is A at bottom left and Z at top right)                

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;


char keyMatrix[5][5] = {
  {'v', 'w', 'x', 'y', 'z'}, {'q', 'r', 's', 't', 'u'}, {'l', 'm', 'n', 'o',
							 'p'}, {'f', 'g', 'h',
								'j', 'k'},
    {'a', 'b', 'c', 'd', 'e'}
};


vector < int >
findIndex (char ch)
{
  for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
	{
	  if (keyMatrix[i][j] == ch)
	    return
	    {
	    i, j};
	}
    }
  return
  {
  -1, -1};
}

string
playfairCipherEncryption (string pt)
{
  string cipher = "";
  for (int i = 0; i < pt.length (); i++)
    {
      char ch1 = tolower (pt[i++]);
      char ch2 = 'x'; //add padding
      if (i < pt.length ())
	    ch2 = tolower (pt[i]);
 
//  i and j, equally encrypt using key matrix, since only j is present in key matrix so changes i to j.
      if (ch1 == 'i')
     	ch1 = 'j';
      if (ch2 == 'i')
	    ch2 = 'j';
	    
      vector < int >ind1 = findIndex (ch1);
      vector < int >ind2 = findIndex (ch2);

      
      if (ind1[0] == ind2[0]) //charater in same row
	{
	  cipher += keyMatrix[ind1[0]][(ind1[1] + 1) % 5];
	  cipher += keyMatrix[ind2[0]][(ind2[1] + 1) % 5];
	}
      else if (ind1[1] == ind2[1]) //charater in same column
	{
	  cipher += keyMatrix[(ind1[0] + 1) % 5][ind1[1]];
	  cipher += keyMatrix[(ind2[0] + 1) % 5][ind2[1]];
	}
      else //charater in different row and different column
	{
	  cipher += keyMatrix[ind1[0]][ind2[1]];
	  cipher += keyMatrix[ind2[0]][ind1[1]];
	}
    }
  return cipher;

}

string
playfairCipherDecryption (string cipher)
{
  string plain = "";

  for (int i = 0; i < cipher.length (); i++)
    {
      char ch1 = tolower (cipher[i++]);
      char ch2 = 'x';
      if (i < cipher.length ())
	    ch2 = tolower (cipher[i]);

      if (ch1 == 'i')
	    ch1 = 'j';
      if (ch2 == 'i')
	    ch2 = 'j';
	    
      vector < int >ind1 = findIndex (ch1);
      vector < int >ind2 = findIndex (ch2);

      if (ind1[0] == ind2[0])
	{
	  plain += keyMatrix[ind1[0]][(5 + ind1[1] - 1) % 5];
	  plain += keyMatrix[ind2[0]][(5 + ind2[1] - 1) % 5];
	}
      else if (ind1[1] == ind2[1])
	{
	  plain += keyMatrix[(5 + ind1[0] - 1) % 5][ind1[1]];
	  plain += keyMatrix[(5 + ind2[0] - 1) % 5][ind2[1]];
	}
      else
	{
	  plain += keyMatrix[ind1[0]][ind2[1]];
	  plain += keyMatrix[ind2[0]][ind1[1]];
	}
    }
  return plain;
}

string
removeSpace (string pt)
{
  string temp = "";
  for (int i = 0; i < pt.length (); i++)
    {
      if (pt[i] >= 'a' && pt[i] <= 'z')
	temp += pt[i];
      if (pt[i] >= 'A' && pt[i] <= 'Z')
	temp += pt[i];
    }
  return temp;
}

int
main ()
{
  string pt = "mepchmroot ybmeu akhaq";
  pt = removeSpace(pt);
  cout << "Original plantext : " << pt << endl;
  string cipher = playfairCipherEncryption (pt);
  cout << "After encryption ciphertext : " << cipher << endl;
  string plain = playfairCipherDecryption (cipher);
  cout << "After decryption plaintext : " << plain << endl;
  return 0;
}
