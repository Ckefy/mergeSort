#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k=5;
    int n=20;
    vector < vector < int > > masses (k, vector <int> (n/k));
    for (int i=0; i<k; i++){
        for (int j=0; j<n/k; j++)
            masses[i][j]=j;
    }
    for (int i=0; i<k; i++){
        for (int j=0; j<n/k; j++)
            cout<<masses[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    //////////////
    //////////////
    //////////////
    int i1=0, i2=1, now=0;
    vector <int> temp;
    while (masses.size()!=1){
        while (i1<masses.size() || i2<masses.size()){
            temp.resize(0);
            if (i1<masses.size() && i2<masses.size()){ //если есть оба массива
                    int i=0, j=0;
                    while (i<masses[i1].size() || j<masses[i2].size()){
                        if (j==masses[i2].size() || (i<masses[i1].size() && masses[i1][i]<masses[i2][j])){
                            temp.push_back (masses[i1][i]);
                            i++;
                        }
                        else{
                            temp.push_back (masses[i2][j]);
                            j++;
                        }
                    }
            }
            else if (i1<masses.size()){
                int i=0;
                while (i<masses[i1].size()){
                    temp.push_back(masses[i1][i]);
                    i++;
                }
            }
            masses[now].resize(temp.size());
            for (int i=0; i<temp.size(); i++)
                masses[now][i]=temp[i];
            now++; i1+=2; i2+=2;
        }
        k=(k%2==0)?(k/2):(k/2+1);
        now=0;
        i1=0;
        i2=1;
        masses.resize(k);
        /*for (int i=0; i<masses.size(); i++){
            for (int j=0; j<masses[i].size(); j++){
                cout<<masses[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/
    }
    for (int i=0; i<masses[0].size(); i++)
        cout<<masses[0][i]<<' ';
}
