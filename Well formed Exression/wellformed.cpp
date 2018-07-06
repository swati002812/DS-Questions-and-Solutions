#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

int top = -1;                                     


int main(int argc, char* argv[])
{
	int len, i, brac=0;
	len = strlen(argv[1]);

for(i=0; i<len; i++)
{
	if(brac>=0)
	{
		if(argv[1][i] == '(')
		{
			brac++;
		}
		else if(argv[1][i] == ')')
		{
			if((argv[1][i-1] == '+')||(argv[1][i-1] == '-')||(argv[1][i-1] == '*')||(argv[1][i-1] == '/'))
			{
				cout<<"error\n";
				return 0;
			}
			else
			brac--;
		}
	}
	else
	{
		cout<<"error\n";
		return 0;
	}
}

	//paranthesization is proper or not
	if(brac != 0)
	{
		cout<<"error\n";
		return 0;
	}

	else
	{
	//infix to postfix

        int d=0,si=0, ai=0,k=0;
        char s[5], op[len], postfix[len], a[len];

        for(i=0;i<len;i++)
        {
                if(argv[1][i] == '(')
                brac++;

                else if((argv[1][i] == '+')||(argv[1][i] == '-')||(argv[1][i] == '*')||(argv[1][i] == '/'))
                {
                        top++;
                        op[top] = argv[1][i];
                }

                else if(argv[1][i] == ')')
                {
                        brac--;
			while(d<ai){
			postfix[k] = a[d];
	//		cout<<"value of k ="<<k<<" and its value is"<<postfix[k]<<endl; 
			d++;k++;
			
			}
			ai=0;
                        postfix[k]=op[top];
                        top--;
			d=0;
			k++;
                }
		
		else if(argv[1][i] == ' ')
		continue;

                else
                {
                        a[ai] = argv[1][i];
                        /*si++;
                        s[si] = '\0';
                        int x = atoi(s);
                        si=0;
                        a[ai] = x;
			*/
	//		cout<<"a["<<ai<<"] ="<<a[ai]<<endl;
			ai++;
                }
        }
/*
	for(i=0; i<k; i++)
	cout<<postfix[i];
	cout<<endl;
*/


//evalute postfix expression
      
        ai=0;
	d=0;
	si=0;
	int bi, flag=0;
        top =-1;
 	int arr[k];      
        for(i=0; i<k; i++)
        {
                if(postfix[i] == '+')
                {
                        if(top>=1){
  //                      cout<<"+++"<<i<<endl;
                        ai = arr[top];
                        top--;
                        bi = arr[top];
                        //cout<<"ai = "<<ai<<"    bi = "<<bi<<endl;
                        arr[top] = bi+ai;
    //                    cout<<"top in + ="<<top<<"   arr["<<top<<"]= "<<arr[top];
                        continue;
                        }
                        else{
                      //  cout<<"invalid\n";
                        flag =1;
                        break;
                        }
                }

                else if(postfix[i] == '-')
                {
                        if(top>=1){
    //                  cout<<"---"<<i<<endl;
			ai = arr[top];
                        top--;
                        bi = arr[top];
                        arr[top] = bi-ai;
      //                  cout<<"top in + ="<<top<<"   arr["<<top<<"]= "<<arr[top];
			continue;
                        }
                        else{
                        //cout<<"invalid\n";
                        flag=1;
                        break;}
                }
		else if(postfix[i] == '*')
                {
                        if(top>=1){
//		cout<<"***"<<i<<endl;
                        ai = arr[top];
                        top--;
                        bi = arr[top];
                        arr[top] = bi*ai;
//			cout<<"top in + ="<<top<<"   arr["<<top<<"]= "<<arr[top];
                        continue;
                        }
                        else{
                        //cout<<"invalid\n";
                        flag=1;
                        break;
                        }
                }

                else if(postfix[i] == '/')
                {

                        if(top>=1){
  //                      cout<<"///"<<i<<endl;
			ai = arr[top];
			if(ai != 0){
                        top--;
                        bi = arr[top];
                        arr[top] = bi/ai;
                        //continue;
			}

			else{//if division by zero condition
			cout<<"division by zero"<<endl;
			return 0;
			}
//			cout<<"top in + ="<<top<<"   arr["<<top<<"]= "<<arr[top];
			continue;
                        }
                        else{
                        //cout<<"invalid\n";
                        flag=1;
                        break;}
                }
                else
                {
                        s[si] = postfix[i];
                        si++;
                        s[si] = '\0';
                        top++;
//			cout<<"Number wali condition : "<<"\ntop = "<<top;
                        int x = atoi(s);
                        arr[top] = x;
//			cout<<"   x = "<<x<<"   arr[top]=  "<<arr[top]<<endl;
                        si=0;
                }
  //      cout<<"i = "<<i<<"\ntop = "<<top<<"\na["<<top<<"]= "<<arr[top]<<endl;
        }

//cout<<"top = "<<top;
//cout<<endl<<"a[top] = "<<a[top]<<endl;
if(flag == 0){
        if(top != 0)
        cout<<"invalid"<<endl;

        else
        {
                if((a[top] == '+')||(a[top] == '-')||(a[top] == '*')||(a[top] == '/'))
                cout<<"invalid"<<endl;

                else
                cout<<arr[top]<<endl;
        }
}

} // end of 'else' paranthesization wala
return 0;
}
