#include "StdAfx.h"
#include "Texture.h"
#include <gl/glut.h>

GLuint Texture::Num=1;
Texture::Texture(void)
{
	id=0;
}

GLuint Texture::Init(string name)
{
	picname=name;
	GLuint text=Num;
	AUX_RGBImageRec *TextureImage=0;
	if((TextureImage=auxDIBImageLoad(picname.c_str()))!=NULL)
	{
		glGenTextures(1,&text);
		glBindTexture(GL_TEXTURE_2D,text);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	// Linear Filtering
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	// Linear Filtering

		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
		if(TextureImage->data)
			free(TextureImage->data);
		free(TextureImage);
		id=Num;
		Num++;
		
		return Num-1;
	}
	return 0;
}
GLuint Texture::getId()
{
	return id;
}
Texture::~Texture(void)
{
}
