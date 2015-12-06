#define PLANE_COUNT 9
#define COUNT 11
Pairl init();
int addPlane(Pairl head, char (*plane)[100]);
Pairl createplaneList(FILE *pf);
int search(Pairl head, Pairl *arr, char (*options)[100], int maxPrice,  int isDiscount, int hasLeft);
extern char flightPrintInfo[COUNT][100];
