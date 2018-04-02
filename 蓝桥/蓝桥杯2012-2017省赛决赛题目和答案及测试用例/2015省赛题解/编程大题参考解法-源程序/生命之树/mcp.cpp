
#include <iostream>
using namespace std;

inline int GetMax( int a, int b){ return a>b?a:b;}
inline int GetMax( int a, int b, int c){ return GetMax(GetMax(a,b),c);}

const int N_Infinite = 0x7fffffff * -1;		// ...������ֵ 
class Vertex;
class Edge{									// ...�� 
public:
	Edge *m_next;							// ...���ȶ������һ���� 
	Vertex *m_to;							// ...���ߵ�ָ�� 
	Edge():m_next(NULL),m_to(NULL){}
};

class Vertex{								// ...���� 
public:
	Edge *m_edge;
	int  m_val,m_maxSon,m_maxAll;			// ...���Ȩֵ, ���������(����������), ���������(�����������) 
	bool m_block;							// ...������־ : Ϊtrueʱ��ʾ��������, ���ɱ��� 
	Vertex():m_edge(NULL),m_val(0),m_block(false),m_maxSon(N_Infinite),m_maxAll(0){}
	void Add( Vertex *to,Edge* E){			// ...����һ�����ӵ�����to�ı� 
		E->m_next = m_edge;
		E->m_to = to;
		m_edge = E;
	}
};

class Graph{								// ...ͼ 
	public:
		Edge	*ESet;						// ...�߼� 
		Vertex  *VSet;						// ...���㼯 
		int		ESize;						// ...�ߵ����� 
		Graph( int N ){
			ESet = new Edge[2*N];
			VSet = new Vertex[N+1];
			ESize = 0;
		}
		~Graph(){ delete ESet;delete VSet;}
		void Add( int v1, int v2 ){			// ...��ͼ�е�v1��v2��������һ���� 
			VSet[v1].Add(VSet+v2,ESet+ESize++);
			VSet[v2].Add(VSet+v1,ESet+ESize++);
		}
		static void DFS( Vertex *V ){		// ...������Ѱ�Զ���VΪ�����������������Ϣ 
			V->m_block = true;				// ...��ʼ�������� 
			V->m_maxAll = V->m_val;
			for( Edge *e = V->m_edge; e!=NULL;e=e->m_next){	// ...���������������� 
				if( e->m_to->m_block == false ){
					DFS( e->m_to );
					V->m_maxSon = GetMax( e->m_to->m_maxAll, e->m_to->m_maxSon, V->m_maxSon);
					V->m_maxAll += GetMax( e->m_to->m_maxAll,0);
				}
			}
			V->m_block = false;				// ...������� 
		}
		int GetVal(){						// ...��ȡͼ�е���������� 
			DFS( VSet+1 );
			return GetMax( VSet[1].m_maxAll, VSet[1].m_maxSon );
		}
};

int main(int argc, char** argv) 
{
	int N,v1,v2;
	cin >> N;
	Graph G(N);
	for( int i = 1; i <= N; ++i )
		cin >> G.VSet[i].m_val;
	for( int i = 1; i < N; ++i){
		cin >> v1 >> v2;
		G.Add(v1,v2);
	}
	cout << G.GetVal();
	return 0;
}
