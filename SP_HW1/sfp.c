#include "sfp.h"
#include <stdlib.h>
#include <string.h>

sfp int2sfp(int input){
	sfp ans = 0;
	int answer[18] = {0};
	
	if(input < 0)
	{
		answer[0] = 1;
	}
	else
	{
		answer[0] = 0;
	}
	
	int mant[11] = {0};
	int position1 = 0;
	while(1)
	{
		mant[position1] = input % 2;
		input = input / 2;
		position1++;
		
		if(input == 0)
			break;
	}
	
	position1--;
	int exp1 = position1 + 15;
	
	int exp[6] = {0};
	int position2 = 0;
	while(1)
	{
		exp[position2] = exp1 % 2;
		exp1 = exp1 / 2;
		position2++;
		
		if(exp1 == 0)
			break;
	}
	position2 -= 1;
	int i = 1;
	for(i; i < 6; i++)
	{
		if(position2 < 0)
		{
			answer[i] = 0;
		}
		else
		{
			answer[i] = exp[position2];
			position2--;
		}
	}
	
	for(int i = 6; i < 15; i++)
	{
		if(position1 < 0)
		{
			answer[i] = 0;
		}
		else
		{
			answer[i] = mant[position1];
			position1--;
		}
	}
	
	for(int i = 0; i < 16; i++)
	{
		ans += answer[i] * pow(2, i);
	}
	
	return ans;
}

int sfp2int(sfp input){
	int bin[16] = {0};
	int position = 0;
	
	while(1)
	{
		bin[position] = input % 2;
		input = input / 2;
		position++;
		
		if(input == 0)
			break;
	}
	position -= 1;

	int bin2[10] = {0};
	int cnt = 6;
	int position2 = 0;
	
	while(cnt != position+1)
	{
		bin2[position2] = bin[cnt];
		position2++;
		cnt++;
	}

	int ans = 0;
	for(int i = 0; i < position2; i++)
	{
		ans += bin2[i] * pow(2, position2 - i - 1);
	}
	return ans;
}

sfp float2sfp(float input){
	sfp ans = 0;
	int answer[16] = {0};
	
	if(input < 0)
	{
		answer[0] = 1;
		input = input * (-1);
	}
	else
	{
		answer[0] = 0;
	}
	
	
	int i1 = 66, j, temp;
	char box[66] = {0};
	
	temp = (long)input;
	input = input - (double)temp;
	
	while(temp)
	{
		box[--i1] = '0' + temp%2;
		temp /= 2;
	}
	temp = i1;
	
	for(i1 = 0; i1+temp < 66; i1++)
	{
		box[i1] = box[i1+temp];
	}
	temp = 65 - temp;
	
	i1 = temp + 1;
	while(input && i1 < 66)
	{
		input *= 2;
		box[i1++] = '0' + (int)input;
		input -= (int)input;
	}
	
	j = 0;
	int ind = 0;
	for(j; j < i1; j++)
	{
		if(box[j] == '1')
		{
			ind = j;
			break;
		}
	}
	
	int E = temp - ind;
	int exp1 = E + 15;
	
	int exp[6] = {0};
	int position2 = 0;
	while(1)
	{
		exp[position2] = exp1 % 2;
		exp1 = exp1 / 2;
		position2++;
		
		if(exp1 == 0)
			break;
	}
	
	position2 -= 1;
	
	int p = position2+1;
	int cnt = 1;
	while(p != 5)
	{
		answer[cnt] = 0;
		cnt++;
		p++;
	}
	
	for(cnt; cnt < 6; cnt++)
	{
		answer[cnt] = exp[position2];
		position2--;
	}
	
	for(int i = 6; i < 15; i++)
	{
		if(ind+1 >= i1)
		{
			answer[i] = 0;
		}
		else
		{
			answer[i] = box[ind+1] - '0';
			ind++;
		}
	}
	
	for(int i = 0; i < 16; i++)
	{
		ans += answer[i] * pow(2, i);
	}
	
	return ans;
}

float sfp2float(sfp input){
	int bin[16] = {0};
	int position = 0;
	
	while(1)
	{
		bin[position] = input % 2;
		input = input / 2;
		position++;
		
		if(input == 0)
			break;
	}
	position -= 1;

	int bin2[10] = {0};
	int cnt = 6;
	int position2 = 0;
	
	for(position2; cnt <= position; position2++)
	{
		bin2[position2] = bin[cnt];
		cnt++;
	}
	position2--;
	int e = 0;
	int exp = 0;
	
	for(int i = 1; i < 6; i++)
	{
		e = bin[i];
		exp += e * pow(2, 5 - i);
	}
	
	int E = exp - 15;
	
	int integer[10] = {0};
	int flt[10] = {0};
	int counter1 = 0;
	
	float ans = 0;
	int bin3[10] = {0};
	
	if(E < 0)
	{
		int counter = 0;
		while(E != 0)
		{
			bin3[counter++] = 0;
			E++;
		}
		bin3[counter++] = 1;
		for(int i = 0; i <= position2; i++)
		{
			bin3[counter++] = bin2[i];
		}
		
		counter--;
		for(int i = 0; i <= counter; i++)
		{
			ans += bin3[i] * pow(0.5, i);
		}
		if(bin[0] == 1)
		{
			ans = ans * (-1);
		}
		return ans;
	}
	
	for(int i = E; i <= position2; i++)
	{
		flt[counter1] = bin2[i];
		counter1++;
	}
	counter1--;
	
	int counter2 = 0;
	for(int i = E -1; i >= 0; i--)
	{
		integer[counter2] = bin2[i];
		counter2++;
	}
	integer[counter2] = 1;
	
	for(int i = 0; i <= counter1; i++)
	{
		ans += flt[i] * pow(0.5, i+1);
	}
	
	for(int i = 0; i <= counter2; i++)
	{
		ans += integer[i] * pow(2, i);
	}
	
	if(bin[0] == 1)
	{
		ans = ans * (-1);
	}
	return ans;
}

sfp sfp_add(sfp a, sfp b){
	char *bin1 = sfp2bits(a);
    char *bin2 = sfp2bits(b);

    int exp1 = 0;
    int exp2 = 0;
    for(int i = 1; i < 6; i++)
    {
	   	exp1 += (bin1[i] - '0') * pow(2, 5-i);
	   	exp2 += (bin2[i] - '0') * pow(2, 5-i);
    }
    
    int mant1 = 0;
    int mant2 = 0;
    char* m1 = (char*)malloc(sizeof(char)*10);
    char* m2 = (char*)malloc(sizeof(char)*10);
	int counter = 0;
	
    for(int i = 6;  i < 16; i++)
    {
    	mant1 += (bin1[i] - '0') * pow(2, 15- i);
    	mant2 += (bin2[i] - '0') * pow(2, 15 -i);
    	m1[counter] = bin1[i];
    	m2[counter] = bin2[i];
    	counter++;
	}
	counter--;
    int s = 0;

    if(exp1 < exp2)
    {
	   s = exp2 - exp1;
	   mant1 = mant1 >> 1;
	   mant1 += 512;
	   mant1 = mant1 >> s-1;
	   for(int i = counter; i >= 0; i--)
		{
			m1[i] = mant1 % 2 + '0';
			mant1 = mant1 / 2;
		}
    
    }
    else if(exp1 > exp2)
    {
	   	s = exp1 - exp2;
	   	mant2 = mant2 >> 1;
	   	mant2 += 512;
	   	mant2 = mant2 >> s-1;
		for(int i = counter; i >= 0; i--)
		{
			m2[i] = mant2 % 2 + '0';
			mant2 = mant2 / 2;
		}
	}
    int sum = 0;
    int temp = 0;

    int ans[10] = {0};
    int i = 9;
    int counter2 = 9;
    for(i; i >= 0; i--)
    {
	   	sum = temp + (m1[i] - '0') + (m2[i] - '0');
	   	if(sum == 0)
	   	{
	   		temp = 0;
	   		ans[counter2] = 0;
	   	}
	   	else if(sum == 1)
	   	{
	   		temp = 0;
	   		ans[counter2] = 1;
	   	}
	   	else if(sum == 2)
	   	{
	   		temp = 1;
	   		ans[counter2] = 0;
	   	}
	   	else if(sum == 3)
	   	{
	   		temp = 1;
	   		ans[counter2] = 1;
	   	}
	   	counter2--;
    }
    if(temp == 1)
    {
   	 	ans[counter2] == 1;
    }
    int bin3[16] = {0};

    for(int i = 0; i < 6; i++)
    {
	    if(exp1 > exp2)
	   	{
	   		bin3[i] = bin1[i] - '0';
	   	}
	   	else if(exp1 < exp2)
	   	{
	   		bin3[i] = bin2[i] - '0';
	   	}
    }
	int cnt = 0;
    for(int i = 6; i < 16; i++)
    {
   	 	bin3[i] = ans[cnt];
   	 	cnt++;
    }
    
	for(int i = 0; i < 16; i++)
	{
		printf("%d", bin3[i]);
	}
	printf("\n");
	
	int exp = 0;
	for(int i = 1; i < 6; i++)
	{
		exp += bin3[i] * pow(2, 5-i);
	}
	int E = exp - 15;
	
	int integer[10] = {0};
	int fl[10] = {0};
	
	integer[0] = 1;
	for(int i = 0; i < E; i++)
	{
		integer[i+1] = bin3[i+6];
		fl[i] = bin3[i+6+E];
	}
	
	int i1 = 0;
	float f1 = 0;
	for(int i = 0; i < 10; i++)
	{
		i1 += integer[i] * pow(2, E - i);
		f1 += fl[i] * pow(0.5, i+1);
	}
	
	float answer1 = (float)i1 + f1;
	sfp answer = float2sfp(answer1);
    return answer;
}

sfp sfp_mul(sfp a, sfp b){
	char *bin1 = sfp2bits(a);
    char *bin2 = sfp2bits(b);
    
    int exp1[5] = {0};
    int exp2[5] = {0};
    int counter = 0;
	for(int i = 1; i < 6; i++)
	{
		exp1[counter] = bin1[i] - '0';
		exp2[counter] = bin2[i] - '0';
		counter++;
	}
		
	int e1 = 0;
	int e2 = 0;
	for(int i = 0; i < 5; i++)
	{
		e1 += exp1[i] * pow(2, 5-i);
		e2 += exp2[i] * pow(2, 5-i);
	}
	
	e1 = e1 - 15;
	e2 = e2 - 15;
	
	int E = e1 + e2;
	
	int arr[11] = {1};
	int counter1 = 0;
	int val = 1;
	for(int i = 9; i >= 0; i--)
	{
		for(int j = 9; j >= 0; j--)
		{
			val = (bin1[j] - '0') * (bin2[i] - '0');
			arr[counter1] += val;
			counter1++;
		}
		counter1 = 1;
	}
	
	int ans[16] = {0};
	if(bin1[0] == bin2[0])
		ans[0] = 0;
	else if(bin1[0] != bin2[0])
		ans[0] = 1;
	
	for(int i = 1; i < 6; i++)
	{
		ans[i] = E % 2;
		E = E / 2;
	}
	
	int counter2 = 1;
	for(int i = 6; i < 16; i++)
	{
		ans[i] = arr[counter2];
		counter2++;
	}
	
	sfp answer = 0;
	for(int i = 0; i < 16; i ++)
	{
		answer += ans[i] * pow(2, 16-i);
	}
	
	return answer;
}

char* sfp2bits(sfp result){
	char* answer = (char*)malloc(sizeof(char)*16);
	
	int bin[17] = {0};
	int position = 0;
	while(1)
	{
		bin[position] = result % 2;
		result = result / 2;
		position++;
		
		if(result == 0)
			break;
	}
	position -= 1;
	
	for(int i = 0; i < 6; i++)
	{
		answer[i] = bin[i] + '0';
	}
	
	for(int i = 6; i < 15; i++)
	{
		if(bin[6] == 0)
		{
			if(bin[i])
			{
				answer[i] = bin[i] +'0'; 
			}
			else
			{
				answer[i] = '0';
			}
		}
		else if(bin[6] == 1)
		{
			if(bin[i+1])
			{
				answer[i] = bin[i+1] +'0'; 
			}
			else
			{
				answer[i] = '0';
			}
		}
	}
	answer = strcat(answer, "0");
	return answer;
}

char* sfp_comp(sfp a, sfp b){
	char *bin1 = sfp2bits(a);
    char *bin2 = sfp2bits(b);
    
    if(bin1[0] != bin2[0])
    {
    	if(bin1[0] == 1)
    	{
    		return "<";
		}
		else if(bin2[0] == 1)
		{
			return ">";
		}
	}
	else if(bin1[0] == bin2[0])
	{
		int exp1[5] = {0};
		int exp2[5] = {0};
		int counter = 0;
		for(int i = 1; i < 6; i++)
		{
			exp1[counter] = bin1[i] + '0';
			exp2[counter] = bin2[i] + '0';
			counter++;
		}
		
		int e1 = 0;
		int e2 = 0;
		for(int i = 0; i < 5; i++)
		{
			e1 += exp1[i] * pow(2, 5-i);
			e2 += exp2[i] * pow(2, 5-i);
		}
		
		if(e1 > e2)
		{
			return ">";
		}
		else if(e1 < e2)
		{
			return "<";
		}
		else
		{
			return "=";
		}
	}
}
