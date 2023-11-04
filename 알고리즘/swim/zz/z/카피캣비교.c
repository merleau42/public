#include <stdlib.h>
#include <stdio.h>

char *src, *obj, *find;
char *src, *dest;
int n, size;
int i;

n = strlen(src);										//! [strdup]
dest = (char *)malloc((n + 1) * sizeof(char));			//! [strdup]
if (dest == NULL)			return (NULL);				//! [strdup]

if (find[0] == 0)			return src;					//> strstr
if (size <= 0)				return strlen(src);			//: strlcpy
if (size <= strlen(dest) )	return strlen(src)+size; 	//: strlcat

		i < size - 1 - strlen(dest)		//: strlcat
		i < size - 1					//: strlcpy
		i < n							/// strncpy, strncat
i=0;		&&
while (src[i] !=0)						//" 공통
{
	write(1, &src[i], 1);				//" putstr
	dest[i] = src[i];					/// 모든 cpy, strdup
	dest[strlen(dest) + i] = src[i];	/// 모든 cat

	if (src[i] == find[0] &&		
	strcmp(src+i, find)==0) return (src+i);//> strstr

	if ( i >= n ) return 0;				//< strncmp
	if (str1[i] != str2[i]) break;		//< strcmp, strncmp

	i++;								//" 공통
}

while (i < n) dest[i++] = 0;			/// strncpy
dest[i] = 0;							/// strcpy, strlcpy, [strdup]
dest[strlen(dest) + i] = 0;				/// 모든 cat

return i;								//" strlen
return dest;							/// (n)cpy, (n)cat, strdup
return strlen(dest);					//: strlcpy
return strlen(src) + strlen(dest);		//: strlcat
return src[i] - obj[i];					//< cmp 공통
return (void *) 0;						//> strstr