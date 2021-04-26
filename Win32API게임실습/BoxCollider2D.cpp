#include "framework.h"

BoxCollider2D::BoxCollider2D()
{
	this->x = 0;
	this->y = 0;

	this->width  = 0;
	this->height = 0;
}

BoxCollider2D::BoxCollider2D(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;

	this->width  = width;
	this->height = height;
}

BoxCollider2D::~BoxCollider2D()
{}

void BoxCollider2D::getBoundingBox(float& x, float& y, float& width, float& height)
{
	x = this->x;
	y = this->y;

	width  = this->width;
	height = this->height;
}

void BoxCollider2D::translate(float tx, float ty)
{
	this->x += tx;
	this->y += ty;
}