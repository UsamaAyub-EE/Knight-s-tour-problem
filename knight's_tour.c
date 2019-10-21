#include<stdio.h>
void check_access(short);
void reduce_access();
short check_neighbour(short,short);
short move=0,board[8][8],i,j,horizontal[]={2,1,-1,-2,-2,-1,1,2},vertical[]={-1,-2,-2,-1,1,2,2,1};
short access[8][8];
int main()
{
	short count=0,counter=0;
	printf("From %d row and %d column, ",8,8);
	for(i=j=7,board[i][j]=1;;++move)
	{
		if(move>7)
			move=0;
		if(++counter==1000)
			break;
		i+=vertical[move];
		j+=horizontal[move];
		if(i<0||i>7||j<0||j>7)
		{
			i-=vertical[move];
			j-=horizontal[move];
			continue;
		}
		else if(board[i][j]==1)
		{
			i-=vertical[move];
			j-=horizontal[move];
			continue;
		}
		else
		{
			reduce_access();
			check_access(move);
			printf("Moved to %d row and %d column\n",i+1,j+1);
			printf("From %d row and %d column, ",i+1,j+1);
			board[i][j]=1;
			move=0;
		}
	}
	puts("");
	for(i=0;i<8;++i)
	{
		for(j=0;j<8;++j)
		{
			if(board[i][j]==1)
			{
				printf("*");
				count++;
			}
			else
				printf("#");
		}
			puts("");
	}
	printf("The moves are %d\n",count);
	return 0;
}
void check_access(short movee)
{
	i-=vertical[movee];
	j-=horizontal[movee];
	short ii=i,jj=j;
	i+=vertical[movee];
	j+=horizontal[movee];
	for(move=0;move<8;++move)
	{
		ii+=vertical[move];
		jj+=horizontal[move];
		if(board[ii][jj]==1)
		{
			ii-=vertical[move];
			jj-=horizontal[move];
			continue;
		}
		if(ii<0||ii>7||jj<0||jj>7)
		{
			ii-=vertical[move];
			jj-=horizontal[move];
			continue;
		}
		if(access[ii][jj]<access[i][j])
		{
			i=ii;
			j=jj;
			return;
		}
		else
		{
			ii-=vertical[move];
			jj-=horizontal[move];
		}
	}
}
void reduce_access()
{
	int p,q;
	for(p=0;p<8;p++)
	{
		for(q=0;q<8;q++)
		{
			access[p][q]=check_neighbour(p,q);
		}
	}
}
short check_neighbour(short l,short m)
{
	short movee,count=0;
	for(movee=0;movee<8;++movee)
	{
		l+=vertical[movee];
		m+=horizontal[movee];
		if(board[l][m]==1)
		{
			l-=vertical[movee];
			m-=horizontal[movee];
			continue;
		}
		if(l<0||l>7||m<0||m>7)
		{
			l-=vertical[movee];
			m-=horizontal[movee];
			continue;
		}
		l-=vertical[movee];
		m-=horizontal[movee];
		++count;
	}
	return count;
}
