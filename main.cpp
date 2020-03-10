#include<iostream>
#include <fstream>
#include<cstdlib>
#include<vector>
using namespace std;

struct lib
{
	long long int B;
	long long int D;
	long long int BPD;
	std::vector<int> books;
};

struct out
{long long int nlib;
std::vector<int> books;
};

long long int n_books;
long long int n_lib;
long long int n_day;
std::vector<int> score(0);
std::vector<lib> all_libs(0);





bool find_b(int Book,int N_lib);

int main()
{


	ifstream fin("f_libraries_of_the_world.txt");
    ofstream fout("f_libraries_of_the_world.out");
	fin>>n_books>>n_lib>>n_day;
	cout<<n_books<<n_lib<<n_day;

	for (int i = 0; i < n_books; ++i)
			{
				int n;
				fin>>n;
				score.push_back(n);

			}


	for (int i = 0; i < n_lib; ++i)
		{
			lib ll{};

			fin>>ll.B>>ll.D>>ll.BPD;


			for (int j = 0; j < ll.B; ++j)
			{

				int n;
				fin>>n;
				ll.books.push_back(n);

			}
			all_libs.push_back(ll);



		}







/*

		std::cout<<"all book , lib & day ";
		std::cin>>n_books>>n_lib>>n_day;


		std::cout<<"score of books ";
		for (int i = 0; i < n_books; ++i)
		{
			int n;
			std::cin>>n;
			score.push_back(n);
		}

		///libs

		for (int i = 0; i < n_lib; ++i)
		{
			lib ll{};
			std::cout<<"b , d ,bpd in lib "<<i;
			cin>>ll.B>>ll.D>>ll.BPD;

			std::cout<<"id of each books in lib "<<i;
			for (int j = 0; j < ll.B; ++j)
			{

				int n;
				cin>>n;
				ll.books.push_back(n);

			}
			all_libs.push_back(ll);

			std::cout<<"\n";

		}
*/
		/////////////////////////////////////////////////
		int last_lib=0;
		std::vector<out> output();

		for (int i = 0; i < n_lib; ++i)
		{
			for (int j = 0; j < all_libs[i].books.size(); ++j)
			{
				for (int k = j; k < all_libs[i].books.size(); ++k)
				{
					if(score.at(all_libs[i].books.at(j))>score.at(all_libs[i].books.at(k)))
					{
						int tem;
						tem=all_libs[i].books.at(j);
						all_libs[i].books.at(j)=all_libs[i].books.at(k);
						all_libs[i].books.at(k)=tem;

					}
				}

			}

		}
		

		for (int i = 0; i < n_lib && n_day>0; ++i)

		{
			last_lib++;
			n_day=n_day-all_libs[i].D;
			if(n_day==0)break;
			if(!((n_day* (all_libs[i].BPD))>(all_libs[i].B)))
			{
				int rr=all_libs[i].books.size()-(n_day* (all_libs[i].BPD));
				for (int j = 0; j < all_libs[i].books.size(); )
				{
					if(find_b(all_libs[i].books.at(j),i) && rr>0)
					{
						std::vector<int>::iterator it=all_libs[i].books.begin()+j;
						//std::cout<<"\n "<<j<<"deleted "<<*it;
						all_libs[i].books.erase(it);
						rr--;

						j=0;
						continue;
					}
					++j;
				}

			}



		}
        //6 2 7
		//1 2 3 6 5 4

		//5 2 2
		//0 1 2 3 4

		//4 3 1
		//3 2 5 0



		fout<<last_lib<<"\n";
		for (int i = 0; i < last_lib ; ++i){
			fout<<i<<" "<<all_libs[i].books.size()<<"\n";
			for (int j = 0; j < all_libs[i].books.size() ; ++j)
				fout<<all_libs[i].books.at(j)<<" ";

			fout<<"\n";
		}









		return 0;
}

bool find_b(int Book,int N_lib)
{
	for (int i = 0; i < N_lib; ++i)
	{

		for (int j = 0; j < all_libs[i].books.size(); ++j)
		{
			if(Book==all_libs[i].books[j])
			return true;

		}

	}
return false;


}


