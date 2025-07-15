#ifndef _GL4ES_STRING_UTILS_H_
#define _GL4ES_STRING_UTILS_H_

extern const char* AllSeparators;

#define InplaceReplaceSimple gl4es_inplace_replace_simple

int isDigit(char value);
int isValidFunctionName(char value);
char * InplaceReplaceByIndex(char* pBuffer, int* size, int startIndex, int endIndex, const char* replacement);
char * InplaceInsertByIndex(char * source, int *sourceLength, int insertPoint, const char *insertedString);
const char* FindString(const char* pBuffer, const char* S);
char* gl4es_find_string_nc(char* pBuffer, const char* S);
int gl4es_count_string(const char* pBuffer, const char* S);
char* gl4es_resize_if_needed(char* pBuffer, int *size, int addsize);
char* InplaceReplace(char* pBuffer, int* size, const char* S, const char* D);
char* gl4es_append(char* pBuffer, int* size, const char* S);
char* InplaceInsert(char* pBuffer, const char* S, char* master, int* size);
char* GetLine(char* pBuffer, int num);
int CountLine(const char* pBuffer);
int gl4es_getline_for(const char* pBuffer, const char* S); // get the line number for 1st occurent of S in pBuffer
char* gl4es_str_next(char *pBuffer, const char* S); // mostly as strstr, but go after the substring if found
//"blank" (space, tab, cr, lf,":", ",", ";", ".", "/")
char* gl4es_next_str(char* pBuffer);   // go to next non "blank"
char* gl4es_prev_str(char* Str, char* pBuffer);    // go to previous non "blank"
char* gl4es_next_blank(char* pBuffer);   // go to next "blank"
char* gl4es_next_line(char* pBuffer);   // go to next new line (crlf not included)

const char* GetNextStr(char* pBuffer); // get a (static) copy of next str (until next separator), can be a simple number or separator also

// those function don't try to be smart with separators...
int gl4es_countstring_simple(char* pBuffer, const char* S);
char* gl4es_inplace_replace_simple(char* pBuffer, int* size, const char* S, const char* D);


#endif // _GL4ES_STRING_UTILS_H_
