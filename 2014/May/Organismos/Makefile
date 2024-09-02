pro2.exe: pro2.o Cjt_Organismo.o Ranking.o Organismo.o 
	g++ -o pro2.exe pro2.o Ranking.o Cjt_Organismo.o Organismo.o 

pro2.o: pro2.cpp 
	g++ -c pro2.cpp -D_GLIBCXX_DEBUG 

Cjt_Organismo.o: Cjt_Organismo.cpp
	g++ -c Cjt_Organismo.cpp -D_GLIBCXX_DEBUG 

Organismo.o: Organismo.cpp
	g++ -c Organismo.cpp -D_GLIBCXX_DEBUG 

Ranking.o: Ranking.cpp 
	g++ -c Ranking.cpp -D_GLIBCXX_DEBUG 




clean:
	rm *.o
	rm *.exe

