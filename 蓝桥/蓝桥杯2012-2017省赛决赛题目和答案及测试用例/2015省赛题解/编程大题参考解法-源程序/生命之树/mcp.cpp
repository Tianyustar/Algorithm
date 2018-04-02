
#include <iostream>
using namespace std;

inline int GetMax( int a, int b){ return a>b?a:b;}
inline int GetMax( int a, int b, int c){ return GetMax(GetMax(a,b),c);}

const int N_Infinite = 0x7fffffff * -1;		// ...负无穷值 
class Vertex;
class Edge{									// ...边 
public:
	Edge *m_next;							// ...出度顶点的下一条边 
	Vertex *m_to;							// ...本边的指向 
	Edge():m_next(NULL),m_to(NULL){}
};

class Vertex{								// ...顶点 
public:
	Edge *m_edge;
	int  m_val,m_maxSon,m_maxAll;			// ...结点权值, 最大子树和(不含根顶点), 最大子树和(含自身根顶点) 
	bool m_block;							// ...阻塞标志 : 为true时表示正在阻塞, 不可遍历 
	Vertex():m_edge(NULL),m_val(0),m_block(false),m_maxSon(N_Infinite),m_maxAll(0){}
	void Add( Vertex *to,Edge* E){			// ...增加一条连接到顶点to的边 
		E->m_next = m_edge;
		E->m_to = to;
		m_edge = E;
	}
};

class Graph{								// ...图 
	public:
		Edge	*ESet;						// ...边集 
		Vertex  *VSet;						// ...顶点集 
		int		ESize;						// ...边的数量 
		Graph( int N ){
			ESet = new Edge[2*N];
			VSet = new Vertex[N+1];
			ESize = 0;
		}
		~Graph(){ delete ESet;delete VSet;}
		void Add( int v1, int v2 ){			// ...在图中的v1与v2顶点间添加一条边 
			VSet[v1].Add(VSet+v2,ESet+ESize++);
			VSet[v2].Add(VSet+v1,ESet+ESize++);
		}
		static void DFS( Vertex *V ){		// ...遍历搜寻以顶点V为根的树的最大子树信息 
			V->m_block = true;				// ...开始阻塞自身 
			V->m_maxAll = V->m_val;
			for( Edge *e = V->m_edge; e!=NULL;e=e->m_next){	// ...遍历所有下属子树 
				if( e->m_to->m_block == false ){
					DFS( e->m_to );
					V->m_maxSon = GetMax( e->m_to->m_maxAll, e->m_to->m_maxSon, V->m_maxSon);
					V->m_maxAll += GetMax( e->m_to->m_maxAll,0);
				}
			}
			V->m_block = false;				// ...解除阻塞 
		}
		int GetVal(){						// ...获取图中的最大子树和 
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
