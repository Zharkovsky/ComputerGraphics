#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
protected:
	int size;
	int offsetX, offsetY;
private:
	bool isDragging;
	int previousX, previousY;
public:
	Figure(int size, int offsetX, int offsetY) : size(size), offsetX(offsetX), offsetY(offsetY), isDragging(false), previousX(0), previousY(0)
	{
	}
	void Clear(HDC dc)
	{
		RECT rect;
		GetClientRect(WindowFromDC(dc), &rect);
		FillRect(dc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
	}
	virtual void Draw(HDC dc) = 0;
	virtual bool InnerPoint(int X, int Y) = 0;
	void MoveTo(int X, int Y)
	{
		offsetX = X;
		offsetY = Y;
	}
	void Move(int X, int Y)
	{
		offsetX += X;
		offsetY += Y;
	}
	void StartDragging(int X, int Y)
	{
		isDragging = true;
		previousX = X;
		previousY = Y;
	}
	void Drag(int X, int Y)
	{
		offsetX += (X - previousX);
		previousX = X;
		offsetY += (Y - previousY);
		previousY = Y;
	}
	void StopDragging()
	{
		isDragging = false;
	}
	bool IsDragging()
	{
		return isDragging;
	}

	void Resize(int resize)
	{
		size += resize;
		size = max(0, size);
	}
};

#endif FIGURE_H
