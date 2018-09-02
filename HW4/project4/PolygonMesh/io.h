#pragma once

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <GL/glut.h>
#include <iostream>
using namespace std;
using namespace OpenMesh;

typedef const char * Model;

//�ļ���ȡ�йص�
TriMesh_ArrayKernelT<> mesh;
Model models[] = {"cow.obj", "cactus.ply", "Armadillo.off"};
int index = 0;

GLuint showFaceList, showWireList;
int showstate = 1;

void readfile(const char* file) {
	// ���󶥵㷨�� vertex normals
	mesh.request_vertex_normals();
	//��������ڶ��㷨�ߣ��򱨴�
	if (!mesh.has_vertex_normals())
	{
		cout << "Do not has vertex normals" << endl;
		return;
	}
	// ����ж��㷢�����ȡ�ļ�

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

//��ʼ���������
void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(2.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST); //����������Ȼ������Ĺ��ܣ�������OPengl�Ϳ��Ը���Z���ϵ����أ���ô��ֻ����ǰ��û�ж���������²Ż����������أ��ڻ���3dʱ��������ã��Ӿ�Ч����Ƚ���ʵ
							 // ------------------- Lighting
	glEnable(GL_LIGHTING); // ���enbale��ô��ʹ�õ�ǰ�Ĺ��ղ���ȥ�Ƶ��������ɫ
	glEnable(GL_LIGHT0); //��һ����Դ����GL_LIGHT1��ʾ�ڶ�����Դ
						 // ------------------- Display List
	showFaceList = glGenLists(1);
	showWireList = glGenLists(1);
	int temp = mesh.n_edges();

	// ���� wire
	glNewList(showWireList, GL_COMPILE);
	glDisable(GL_LIGHTING);
	glLineWidth(1.0f);
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	for (auto he_it = mesh.halfedges_begin(); he_it != mesh.halfedges_end(); ++he_it) {
		//�����������ߵ������յ�
		glVertex3fv(mesh.point(mesh.from_vertex_handle(*he_it)).data());
		glVertex3fv(mesh.point(mesh.to_vertex_handle(*he_it)).data());
	}
	glEnd();
	glEnable(GL_LIGHTING);
	glEndList();

	// ����flat
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