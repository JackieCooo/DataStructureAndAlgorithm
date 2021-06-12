/**
 ******************************************************************************
 * @file    Graph.h
 * @author  Jackie
 * @version V1.0
 * @date    2021-06-05
 * @brief   ͼģ��ͷ�ļ�
 ******************************************************************************
 */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <algorithm>

#define Infinite -1

using namespace std;

template<class T>
class Graph{
private:
    vector< vector<T>* >* mat = nullptr;  // �ڽӾ���
    int g_size = 0;
public:
    Graph() = default;
    ~Graph();
    void createGraph();
    void createGraph(string& filepath);
    void traversalWithDFS(int start);
    void traversalWithBFS(int start);
    void findShortestWayUsingDijkstra(int start);
    void findShortestWayUsingFloyd(int start);
    void createMinimumSpanningTreeUsingPrim(int start);
    void createMinimumSpanningTreeUsingKruskal();
private:
    void dfs(int thisNode, vector<bool>& vis);
    int f_find(vector<int>& f_set, int n);
    static bool cmp(const pair< pair<int, int>, T >& a, const pair< pair<int, int>, T >& b);
};

/**
  * @brief  �˺���Ϊ��������
  * @param None
  * @retval None
  */
template<class T>
Graph<T>::~Graph() {
    for(auto i : *mat){  // ���Ԫ���ͷ�
        delete i;
    }
    delete mat;
}

/**
  * @brief  �˺���ͨ���ֶ����봴��ͼ
  * @param None
  * @retval None
  */
template<class T>
void Graph<T>::createGraph() {
    int v;
    auto* res = new vector< vector<T>* >;
    cout << "����ڵ���: ";
    cin >> v;
    g_size = v;
    cout << "��������ͼ���ڽӾ���: " << endl;
    for(int i = 0; i < v; i++){  // �����ڽӾ���
        auto* tmp = new vector<T>;
        for (int j = 0; j < v; ++j) {
            T val;
            cin >> val;
            tmp->push_back(val);
        }
        res->push_back(tmp);
    }
    mat = res;
    cout << "�����ɹ�" << endl;
}

/**
  * @brief  �˺���ͨ���ⲿ�ļ����봴��ͼ
  * @param filepath �ļ���·��
  * @retval None
  */
template<class T>
void Graph<T>::createGraph(string &filepath) {
    ifstream ifs;
    ifs.open(filepath, ios::in);
    if(ifs.is_open()){
        auto* res = new vector< vector<T>* >;
        while(!ifs.eof()){
            int v;
            ifs >> v;
            g_size = v;
            for(int i = 0; i < v; i++){  // �����ڽӾ���
                auto* tmp = new vector<T>;
                for (int j = 0; j < v; ++j) {
                    T val;
                    ifs >> val;
                    tmp->push_back(val);
                }
                res->push_back(tmp);
            }
            mat = res;
        }
        cout << "�����ɹ�" << endl;
    }
    else{
        cout << "�ļ���ʧ��" << endl;
    }
}

/**
  * @brief  �˺����������ͼ
  * @param start ��ʼ�����Ľڵ����
  * @retval None
  */
template<class T>
void Graph<T>::traversalWithDFS(int start) {
    vector<bool> vis(g_size, false);  // ��¼�ڵ��Ƿ����
    cout << "�������Ϊ: ";
    dfs(start, vis);
    cout << endl;
}

/**
  * @brief  �˺���Ϊ��������ĵݹ�ʵ��
  * @param thisNode ��ǰ�ڵ�
  * @param vis �ѷ��ʽڵ�����
  * @retval None
  */
template<class T>
void Graph<T>::dfs(int thisNode, vector<bool>& vis) {
    if(vis[thisNode]){  // �˽ڵ��ѷ��ʹ�
        return;
    }
    cout << thisNode << " ";
    vis[thisNode] = true;  // ����ѷ��ʽڵ�
    for (int i = 0; i < g_size; ++i) {  // ��������ǰ��
        if((*(*mat)[thisNode])[i] != Infinite && !vis[i]){  // Ѱ���б�������δ�����ʵĽڵ�
            dfs(i, vis);
        }
    }
}

/**
  * @brief  �˺����������ͼ
  * @param start ��ʼ�����Ľڵ����
  * @retval None
  */
template<class T>
void Graph<T>::traversalWithBFS(int start) {
    cout << "�������Ϊ: ";
    queue<int> q;  // ��Ŵ���չ�ڵ�
    vector<bool> vis(g_size, false);  // ��¼�ڵ��Ƿ����
    q.push(start);  // ѹ����ʼ�ڵ�
    while(!q.empty()){
        int tmp = q.front();
        if(vis[tmp]){  // �˽ڵ��ѱ�����
            q.pop();
            continue;
        }
        vis[tmp] = true;  // ����ѷ���
        cout << tmp << " ";
        for (int i = 0; i < g_size; ++i) {
            if((*(*mat)[tmp])[i] != Infinite && !vis[i]){  // Ѱ���б�������δ�����ʵĽڵ�
                q.push(i);  // ѹ�����չ�ڵ�
            }
        }
        q.pop();  // �ѷ��ʽڵ㵯��
    }
    cout << endl;
}

/**
  * @brief  �˺���ʹ��Dijkstra�㷨Ѱ�����·��
  * @param start ��ʼ��
  * @retval None
  */
template<class T>
void Graph<T>::findShortestWayUsingDijkstra(int start) {
    vector<T> dis(g_size, 0);  // �����ʼ�����������̾���
    vector<bool> vis(g_size, false);  // ��¼�ڵ��Ƿ��ѷ���

    for (int i = 0; i < g_size; ++i) {  // ��ʼ��dis
        dis[i] = (*(*mat)[start])[i];
    }

    int cnt = 0;  // ������֪��̾���Ķ�������
    while(cnt != g_size){
        int index = 0;  // dis����С�����±�
        int minDis = INT_MAX;  // ��С����
        for(int i = 0; i < g_size; i++){  // Ѱ��dis����С��δ�����Ľڵ�
            if(dis[i] != Infinite && dis[i] < minDis && !vis[i]){
                index = i;
                minDis = dis[i];
            }
        }
        vis[index] = true;  // ����ѷ���
        ++cnt;
        for (int i = 0; i < g_size; ++i) {
            if(!vis[i] && (*(*mat)[index])[i] != Infinite && ((dis[index] + (*(*mat)[index])[i] < dis[i]) || (dis[i] == Infinite))){  // �����ʼ�ڵ㵽��ǽڵ��ٵ��˽ڵ�ľ���С��dis����ʼ�ڵ㵽�˽ڵ�ľ���
                dis[i] = dis[index] + (*(*mat)[index])[i];
            }
        }
    }

    for (int i = 0; i < g_size; ++i) {
        cout << "�ӽڵ�" << start << "���ڵ�" << i << "����̾���Ϊ" << dis[i] << endl;
    }
}

/**
  * @brief  �˺���ʹ��Floyd�㷨Ѱ�����·��
  * @param start ��ʼ��
  * @retval None
  */
template<class T>
void Graph<T>::findShortestWayUsingFloyd(int start) {
    vector< vector<T> > tmp;
    for (int i = 0; i < g_size; ++i) {  // �����ڽӾ���
        vector<T> tmpRow;
        for (int j = 0; j < g_size; ++j) {
            tmpRow.push_back((*(*mat)[i])[j]);
        }
        tmp.push_back(tmpRow);
    }

    for (int i = 0; i < g_size; ++i) {
        for (int j = 0; j < g_size; ++j) {
            for (int k = 0; k < g_size; ++k) {
                if(tmp[j][i] != Infinite && tmp[i][k] != Infinite && (tmp[j][k] > tmp[j][i] + tmp[i][k] || tmp[j][k] == Infinite)) {
                    tmp[j][k] = tmp[j][i] + tmp[i][k];
                }
            }
        }
    }

    for (int i = 0; i < g_size; ++i) {
        cout << "�ӽڵ�" << start << "���ڵ�" << i << "����̾���Ϊ" << tmp[start][i] << endl;
    }
}

/**
  * @brief  �˺���ʹ��Prim�㷨������С������
  * @param start ��ʼ��
  * @retval None
  */
template<class T>
void Graph<T>::createMinimumSpanningTreeUsingPrim(int start) {
    vector<bool> vis(g_size, false);  // ��¼�ڵ��Ƿ��Ѽ�����С������
    list< pair<int, int> > dis; // ��¼���ڵ㵽δ����ڵ�ľ���
    T sum = 0;  // ��¼��̾���
    cout << "�ڵ�����˳��Ϊ: " << start << " ";
    vis[start] = true;  // �����ʼ�ڵ��Ѽ���
    for (int i = 0; i < g_size; ++i) {
        if((*(*mat)[start])[i] != Infinite && start != i){
            dis.emplace_back(start, i);
        }
    }
    for (int i = 0; i < g_size-1; ++i) {  // ��ʼ�ڵ��Ѽ��룬����ֻ����n-1���ڵ�
        int index = -1;  // Ŀ��ڵ����
        T minDis = INT_MAX;  // ����
        for (auto &j : dis) {  // �Ӻ�ѡ����ѡ����̱�
            if((*(*mat)[j.first])[j.second] < minDis){
                minDis = (*(*mat)[j.first])[j.second];
                index = j.second;
            }
        }
        vis[index] = true;  // ��Ǽ���
        sum += minDis;
        cout << index << " ";
        vector< _List_iterator< pair<int, int> > > tmp;
        for (auto j = dis.begin(); j != dis.end(); j++) {  // ����dis��ȥ�������ϵĽڵ�
            if(vis[j->second]){
                tmp.push_back(j);
            }
        }
        for (auto &j : tmp) {
            dis.erase(j);
        }
        for (int j = 0; j < g_size; ++j) {  // ����dis�����Ӻ�ѡ�ڵ�
            if((*(*mat)[index])[j] != Infinite && index != j && !vis[j]){
                dis.emplace_back(index, j);
            }
        }
    }
    cout << endl << "��̾���Ϊ: " << sum << endl;
}

/**
  * @brief  �˺���ʹ��Kruskal�㷨������С������
  * @param None
  * @retval None
  */
template<class T>
void Graph<T>::createMinimumSpanningTreeUsingKruskal() {
    vector<int> f(g_size, 0);  // ���鼯�������ж��Ƿ��л�
    vector< pair< pair<int, int>, T > > dis;  // ��¼���б�
    T sum = 0;  // ��¼��̾���
    for (int i = 0; i < f.size(); ++i) {  // ��ʼ�����鼯
        f[i] = i;
    }
    for (int i = 0; i < g_size; ++i) {  // �������б�
        for (int j = i+1; j < g_size; ++j) {
            if((*(*mat)[i])[j] != Infinite) {
                dis.push_back(make_pair(make_pair(i, j), (*(*mat)[i])[j]));
            }
        }
    }
    sort(dis.begin(), dis.end(), cmp);  // �����б�����
    int cnt = 0;  // ��¼�Ѽ������
    cout << "�߼����˳��Ϊ: ";
    for (int i = 0; cnt != g_size-1; ++i) {
        int f1 = f_find(f, dis[i].first.first);
        int f2 = f_find(f, dis[i].first.second);
        if(f1 != f2){  // ����ͬһ���������ϲ�
            f[f2] = f1;
            ++cnt;
            sum += dis[i].second;
            cout << dis[i].first.first << "-" << dis[i].first.second << " ";
        }
    }
    cout << endl << "��̾���Ϊ: " << sum << endl;
}

/**
  * @brief  �˺���Ϊ���鼯�Ĳ��Һ���
  * @param f_set ���鼯������
  * @param n Ҫ���ҵ�Ԫ��
  * @retval ���ز���Ԫ�صĸ��ڵ�
  */
template<class T>
int Graph<T>::f_find(vector<int>& f_set, int n) {
    while(f_set[n] != n) n = f_set[n];
    return n;
}

/**
  * @brief  �˺���Ϊsort�����Ļص�����
  * @param a Ԫ��1
  * @param b Ԫ��2
  * @retval true aС��b
  * @retval false a����b
  */
template<class T>
bool Graph<T>::cmp(const pair<pair<int, int>, T> &a, const pair<pair<int, int>, T> &b) {
    return a.second < b.second;
}
