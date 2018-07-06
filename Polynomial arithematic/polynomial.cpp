#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main(int argc, char *argv[])
{
	int len1, len2,i,count1=0,count2=0;
	len1 = strlen(argv[1]); 
	len2 = strlen(argv[3]);
//	cout<<len1<<"    "<<len2<<endl;

	for(i=0;i<len1;i++)
	{
		if(argv[1][i] == 'x')
		{
			count1++;
			continue;
		}
	}	

	for(i=0;i<len2;i++)
        {
		if(argv[1][i] == 'x')
		{
	         	count2++;
	                continue;
		}
	}

//cout<<"count1 :"<<count1<<" count2 :"<<count2<<endl;

int coe1[count1],coe2[count2],pow1[count1],pow2[count2];
int x, si=0, ai=0, bi=0, flag=0;
char s[100];

for(i=0;i<len1;i++)
{
	if((argv[1][0] == '-')&&(i==0))
	{
        	s[si] = argv[1][0];
        	si++;
		continue;
	}
	else if((argv[1][i] == 'x') && (flag == 0))
	{
		s[si] = '\0';
		x = atoi(s);
		coe1[ai]=x;
		ai++;
		si=0;
		continue;
	}
	else if((argv[1][i] == 'x') && (flag == 1))
	{
		s[si] ='\0';
		x = atoi(s);
	//	cout<<"x1 = "<<x<<endl;
		coe1[ai]=x;
	//	cout<<endl<<"coe1["<<ai<<"] = "<<coe1[ai]<<endl;
		ai++;
		si=0;
		flag = 0;
		continue;
	}
	else if(argv[1][i] == '+')
	{
		s[si] = '\0';
		x = atoi(s);
		pow1[bi]=x;
		bi++;
		si=0;
		continue;
	}
	else if(argv[1][i] == '-')
	{
		s[si] = '\0';
		x = atoi(s);
		pow1[bi]=x;
		bi++;
		si=0;
		flag=1;
	}
	else if(argv[1][i] == ' ')
	{
		continue;
	}
	s[si] = argv[1][i];
	si++;
}

s[si]='\0';
x = atoi(s);
pow1[bi] = x;
bi++;

ai=0;
bi=0;
si=0;
flag=0;
s[si] = '\0';
/*
for(i=0;i<count1;i++)
{
	cout<<"coe1["<<i<<"]= "<<coe1[i]<<endl;
	cout<<"pow1["<<i<<"]= "<<pow1[i]<<endl;
}

*/
for(i=0;i<len2;i++)
{
	if((argv[3][0] == '-')&&(i==0))
	{
        	s[si] = argv[3][0];
        	si++;
		continue;
	}

        else if((argv[3][i] == 'x') && (flag == 0))
        {
                s[si] = '\0';
                x = atoi(s);
                coe2[ai]=x;
                ai++;
                si=0;
                continue;
        }
	else if((argv[3][i] == 'x') && (flag == 1))
	{
		s[si] = '\0';
		x = atoi(s);
		//cout<<"x2 = "<<x<<endl;
		coe2[ai]=x;
		//cout<<"2nd array 1st value = "<<coe2[ai]<<endl;
		ai++;
		si=0;
		flag = 0;
		continue;
	}
        else if(argv[3][i] == '+')
        {
                s[si] = '\0';
                x = atoi(s);
                pow2[bi]=x;
                bi++;
                si=0;
                continue;
        }
	else if(argv[3][i] == '-')
	{
		s[si] = '\0';
		x = atoi(s);
		pow2[bi]=x;
		bi++;
		si=0;
		flag = 1;
	}
        else if(argv[3][i] == ' ')
        {
                continue;
        }
        s[si] = argv[3][i];
        si++;
}

s[si]='\0';
x = atoi(s);
pow2[bi] = x;
bi++;

/*
for(i=0;i<count2;i++)
{
        cout<<"coe2["<<i<<"]= "<<coe2[i]<<endl;
        cout<<"pow2["<<i<<"]= "<<pow2[i]<<endl;
}
*/

int count11 = count1;
int count3 = count1 + count2;
int coe3[count3], pow3[count3],k=0;
int count22 = count2; 
int j=0;
i=0;
if((strcmp(argv[2], "+")) == 0)
{ //cout<<"+ wali cond"<<endl;
while((count11 != 0)&&(count22 !=0))
{
	if(pow1[i] == pow2[j]){
	coe3[k] = coe1[i]+coe2[j];
	pow3[k] = pow1[i];
	i++;
	j++;
	count11--;
	count22--;
	//cout<<"11 : "<<i<<" "<<j<<" "<<count11<<" "<<count22<<endl;
	}

	else if(pow1[i] < pow2[j]){
	coe3[k] = coe2[j];
	pow3[k] = pow2[j];
	j++;
	count22--;
	//cout<<"12 : "<<i<<" "<<j<<" "<<count11<<" "<<count22<<endl;
	}

	else if(pow1[i] > pow2[j]){
	coe3[k] = coe1[i];
	pow3[k] = pow1[i];
	i++;
	count11--;
	//cout<<"13 : "<<i<<" "<<j<<" "<<count11<<" "<<count22<<endl;
	}

	k++;
	//cout<<"k in + cond : "<<k<<endl;
}
}//end of "+"


else if((strcmp(argv[2], "-")) == 0)
{ //cout<<"- wali cond"<<endl;
while((count11 != 0)&&(count22 != 0))
{
        if(pow1[i] == pow2[j]){
        coe3[k] = coe1[i]-coe2[j];
        pow3[k] = pow1[i];
        i++;
        j++;
	count11--;
	count22--;
        }

        else if(pow1[i] < pow2[j]){
        coe3[k] = (-1)*coe2[j];
        pow3[k] = pow2[j];
        j++;
	count22--;
        }

        else if(pow1[i] > pow2[j]){
        coe3[k] = coe1[i];
        pow3[k] = pow1[i];
        i++;
	count11--;
        }

        k++;
}
}//end of "-"

if((count11 == 0) && (count22 == 0))
{
//cout<<" 1st cond k= "<<k<<endl;
}

else if(count11 == 0){
while(count22 != 0){

if((strcmp(argv[2], "-")) == 0)
coe3[k] = coe2[j]*(-1);
else
coe3[k] = coe2[j];

pow3[k] = pow2[j];
j++; k++;
count22--;
//cout<<"count11 = 0 k value= "<<k<<endl;
}
}

else if(count22 == 0){
while(count11 != 0){
coe3[k] = coe1[i];
pow3[k] = pow1[i];
i++; k++;
count11--;
//cout<<"count22 = 0 k value= "<<k<<endl;
}
}
/*
cout<<"no of elements to be printed (k) : "<<k<<endl;
for(i=0;i<k;i++)
{
        cout<<"coe3["<<i<<"]= "<<coe3[i]<<endl;
        cout<<"pow3["<<i<<"]= "<<pow3[i]<<endl;
}
*/

int var = 0;

while((coe3[var] == 0)&&(var<k))
{
	var++;
}

if(var!= k)
{
cout<<coe3[var]<<"x"<<pow3[var]; 
for(i=var+1;i<k;i++)
{
	if(coe3[i] != 0)
	{
		if(coe3[i] >= 0)
		cout<<" + "<<coe3[i]<<"x"<<pow3[i];

		else
		cout<<" - "<<coe3[i]*(-1)<<"x"<<pow3[i];
	}

	else
	continue;
	
}
}

cout<<endl;

return 0;
}
