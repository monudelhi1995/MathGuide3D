#include "MMatrix.h"

#include "MVector.h"

MMatrix MMatrix::operator+(const MMatrix& Matrix) const
{
	auto _Values = static_cast<float*>(malloc(sizeof(float) * Row * Column));
	for(int i = 0; i < Row*Column ; i++)
	{
		_Values[i] = Values[i] + Matrix.Values[i];
	}
	return {_Values, Row, Column};
}

MMatrix MMatrix::operator-(const MMatrix& Matrix) const
{
	auto _Values = static_cast<float*>(malloc(sizeof(float) * Row * Column));
	for(int i = 0; i < Row*Column ; i++)
	{
		_Values[i] = Values[i] - Matrix.Values[i];
	}
	return {_Values, Row, Column};
}

MMatrix MMatrix::operator*(const float& Multiplier) const
{
	auto _Values = static_cast<float*>(malloc(sizeof(float) * Row * Column));
	for(int i = 0; i < Row*Column ; i++)
	{
		_Values[i] = Values[i] * Multiplier;
	}
	return {_Values, Row, Column};
}

MVector MMatrix::ToMVector() const
{
	return {Values[0], Values[1], Values[2]};
}

MMatrix MMatrix::operator*(const MMatrix& Matrix) const
{
	if (Column != Matrix.Row)
	{
		UE_LOG(LogTemp, Warning, TEXT("Muliplying Matrix row column are not equal, so you cann't multiply them together"))
		return *this;
	}
	float* _Values = (float*)malloc(sizeof(float) * Row *  Matrix.Column);
	int _ValueIndex = 0;
	for (int RowIndex = 1; RowIndex <= Row; RowIndex++)
	{
		for (int Matrix2ColumnIndex = 1; Matrix2ColumnIndex <= Matrix.Column; Matrix2ColumnIndex++)
		{
			_Values[_ValueIndex] = 0;

			for (int Matrix1ColumnIndex = 1; Matrix1ColumnIndex <= Column; Matrix1ColumnIndex++)			//you can also take M2 Row as they are same
			{
				_Values[_ValueIndex] += GetValueAt(RowIndex, Matrix1ColumnIndex) *	Matrix.GetValueAt(Matrix1ColumnIndex, Matrix2ColumnIndex);
			}
			_ValueIndex++;
		}
	}
	return {_Values, Row, Matrix.Column};
}


float MMatrix::GetValueAt(const int& _Row, const int& _Column) const
{
	return Values[(_Row - 1) * Column + _Column - 1];
}