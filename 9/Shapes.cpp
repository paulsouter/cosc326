#include <iostream>
#include "Shapes.hpp"

using namespace std;

void Shapes:: shape1(int *carpet[], int startlocx, int startlocy) {

	int *tempCarpet []= carpet;
	int x[] = { startlocx, startlocx, startlocx + 1, startlocx + 1 };
	int y[] = { startlocy, startlocy + 1, startlocy + 1, startlocy + 2 };

	int place = 0;
	while(x[place] < tempCarpet.length() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 1 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape2(int **carpet, int startlocx, int startlocy) {

	int **tempCarpet = carpet;
	int x[] = { startlocx, startlocx -1, startlocx - 1, startlocx -2 };
	int y[] = { startlocy, startlocy, startlocy - 1, startlocy -1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 2;
		place++;
	}
	if (place != 4)
		cout << "shape 2 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape3(int **carpet, int startlocx, int startlocy) {

	int **tempCarpet = carpet;
	int x[] = { startlocx, startlocx, startlocx - 1, startlocx - 1 };
	int y[] = { startlocy, startlocy + 1, startlocy + 1, startlocy + 2 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 3;
		place++;
	}
	if (place != 4)
		cout << "shape 3 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape4(int **carpet, int startlocx, int startlocy) {

	int **tempCarpet = carpet;
	int x[] = { startlocx, startlocx -1, startlocx - 1, startlocx - 2 };
	int y[] = { startlocy, startlocy, startlocy - 1, startlocy -1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 4;
		place++;
	}
	if (place != 4)
		cout << "shape 4 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape5(int **carpet, int startlocx, int startlocy) {

	int **tempCarpet = carpet;
	int x[] = { startlocx, startlocx, startlocx, startlocx + 1 };
	int y[] = { startlocy, startlocy + 1, startlocy + 2, startlocy + 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 5 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape6(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx - 1, startlocx - 2, startlocx - 1 };
	int y[] = { startlocy, startlocy, startlocy, startlocy + 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 6 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape7(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx, startlocx , startlocx - 1 };
	int y[] = { startlocy, startlocy - 1, startlocy - 2, startlocy - 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 7 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape8(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx + 1, startlocx + 2, startlocx + 1 };
	int y[] = { startlocy, startlocy, startlocy, startlocy -1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 8 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape9(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx, startlocx, startlocx + 1 };
	int y[] = { startlocy, startlocy +1, startlocy +2, startlocy +2 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 9 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape10(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx - 1, startlocx - 2, startlocx - 2 };
	int y[] = { startlocy, startlocy, startlocy, startlocy + 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 10 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape11(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx - 1, startlocx - 2, startlocx - 2 };
	int y[] = { startlocy, startlocy, startlocy, startlocy - 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 11 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape12(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx + 1, startlocx + 2, startlocx + 2 };
	int y[] = { startlocy, startlocy, startlocy, startlocy - 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 12 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape13(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx, startlocx, startlocx - 1 };
	int y[] = { startlocy, startlocy +1, startlocy +2, startlocy + 2 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 13 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape14(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx - 1, startlocx - 2, startlocx - 2 };
	int y[] = { startlocy, startlocy, startlocy, startlocy - 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 14 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape15(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx, startlocx, startlocx + 1 };
	int y[] = { startlocy, startlocy - 1, startlocy - 2, startlocy - 2 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 15 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape16(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx + 1, startlocx + 2, startlocx + 2 };
	int y[] = { startlocy, startlocy, startlocy, startlocy + 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 16 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape17(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx + 1, startlocx + 1, startlocx };
	int y[] = { startlocy, startlocy + 1, startlocy , startlocy + 1 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 17 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape18(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx + 1, startlocx + 2, startlocx + 3 };
	int y[] = { startlocy, startlocy, startlocy, startlocy};

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 18 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

void Shapes::shape19(int **carpet, int startlocx, int startlocy) {

	int tempCarpet = carpet;
	int x[] = { startlocx, startlocx, startlocx, startlocx };
	int y[] = { startlocy, startlocy + 1, startlocy + 2, startlocy+3 };

	int place = 0;
	while (x[place] < tempCarpet.size() && y[place] < tempCarpet[x[place]].size() && tempCarpet[x[place]][y[place]] == 0 && place < 4) {//checks if the location is in the bounds and if something is in there.
		tempCarpet[x[place]][y[place]] = 1;
		place++;
	}
	if (place != 4)
		cout << "shape 8 doesn't fit" << endl;
	else
		carpet = tempCarpet;
}

