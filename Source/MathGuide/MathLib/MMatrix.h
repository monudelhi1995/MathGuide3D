#pragma once
#include "MathGuide/Utils/MUtils.h"

class MVector;

class MMatrix
{
public:
	float* Values;
	int Row;
	int Column;

	MMatrix(float* _Values, int _Row, int _Column) : Row(_Row), Column(_Column)
	{
		Values = (float*)malloc(sizeof(float)*Row*Column);
		for(int i = 0; i < Row*Column ; i++)
		{
			Values[i] = _Values[i];
		}
	}

	friend std::ostream& operator<<(std::ostream& stream, const MMatrix& Matrix)
	{
		FString ToPrint = "Your Matrrix is \n";
		for(int i =0; i< Matrix.Row * Matrix.Column; i++)
		{
			ToPrint = ToPrint + FString::SanitizeFloat(Matrix.Values[i]) + " ";
			if((i+1) % Matrix.Column ==0)
				ToPrint = ToPrint + "\n";
		}
		MDM(ToPrint)
		return stream;
	}

	MMatrix operator+(const MMatrix& Matrix) const;
	MMatrix operator-(const MMatrix& Matrix) const;
	MMatrix operator*(const MMatrix& Matrix) const;
	float GetValueAt(const int& _Row, const int& _Column) const;
	MMatrix operator*(const float& Multiplier) const;
	MVector ToMVector() const;
};
