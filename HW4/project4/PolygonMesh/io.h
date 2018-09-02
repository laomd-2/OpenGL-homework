#pragma once

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <GL/glut.h>
#include <iostream>
using namespace std;
using namespace OpenMesh;

typedef const char * Model;

//文件读取有关的
TriMesh_ArrayKernelT<> mesh;
Model models[] = {"cow.obj", "cactus.ply", "Armadillo.off"};
int index = 0;

GLuint showFaceList, showWireList;
int showstate = 1;

void readfile(const char* file) {
	// 请求顶点法线 vertex normals
	mesh.request_vertex_normals();
	//如果不存在顶点法线，则报错
	if (!mesh.has_vertex_normals())
	{
		cout << "Do not has vertex normals" << endl;
		return;
	}
	// 如果有顶点发现则读取文件

	if (!IO::read_mesh(mesh, file))
	{
		cout << "failed" << endl;
		return;
	}
	else 
		cout << "succeed" << endl;
	cout << endl;

	mesh.request_face_normals();
	mesh.update_normals();
	mesh.release_face_normals();
}

//初始化顶点和面
void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(2.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); //用来开启深度缓冲区的功能，启动后OPengl就可以跟踪Z轴上的像素，那么它只有在前面没有东西的情况下才会绘制这个像素，在绘制3d时，最好启用，视觉效果会比较真实
							 // ------------------- Lighting
	glEnable(GL_LIGHTING); // 如果enbale那么就使用当前的光照参数去推导顶点的颜色
	glEnable(GL_LIGHT0); //第一个光源，而GL_LIGHT1表示第二个光源
						 // ------------------- Display List
	showFaceList = glGenLists(1);
	showWireList = glGenLists(1);
	int temp = mesh.n_edges();

	// 绘制 wire
	glNewList(showWireList, GL_COMPILE);
	glDisable(GL_LIGHTING);
	glLineWidth(1.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	for (auto he_it = mesh.halfedges_begin(); he_it != mesh.halfedges_end(); ++he_it) {
		//链接这个有向边的起点和终点
		glVertex3fv(mesh.point(mesh.from_vertex_handle(*he_it)).data());
		glVertex3fv(mesh.point(mesh.to_vertex_handle(*he_it)).data());
	}
	glEnd();
	glEnable(GL_LIGHTING);
	glEndList();

	// 绘制flat
	glNewList(showFaceList, GL_COMPILE);
	for (auto f_it = mesh.faces_begin(); f_it != mesh.faces_end(); ++f_it) {
		glBegin(GL_TRIANGLES);
		for (auto fv_it = mesh.fv_iter(*f_it); fv_it.is_valid(); ++fv_it) {
			glNormal3fv(mesh.normal(*fv_it).data());
			glVertex3fv(mesh.point(*fv_it).data());
		}
		glEnd();
	}
	glEndList();
}

void readCurFile()
{
	cout << "reading " << models[index] << " ... ";
	readfile(models[index]);
	initGL();
}