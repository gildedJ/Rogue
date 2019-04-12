#pragma once

float Q_rsqrt(float number)
{
  const float x2 = number * 0.5F;
  const float threehalfs = 1.5F;

  union {
    float f;
    uint32_t i;
  } conv = { number }; // member 'f' set to value of 'number'.
  conv.i = 0x5f3759df - (conv.i >> 1);
  conv.f *= (threehalfs - (x2 * conv.f * conv.f));
  return conv.f;
}

struct Vector2 {
  Vector2() : X(0.0f), Y(0.0f) {}
  Vector2(const int& x, const int& y) : X((float)x), Y((float)y) {}
  Vector2(const float& x, const float& y) : X(x), Y(y) {}

  float X;
  float Y;

  inline Vector2& operator+=(const Vector2& v) { X += v.X; Y += v.Y; return *this; }
  inline Vector2& operator-=(const Vector2& v) { X -= v.X; Y -= v.Y; return *this; }
  inline Vector2& operator*=(const Vector2& v) { X *= v.X; Y *= v.Y; return *this; }
  inline Vector2& operator*=(const int& scalar) { X *= scalar; Y *= scalar; return *this; }
  inline Vector2& operator*=(const float& scalar) { X *= scalar; Y *= scalar; return *this; }
  inline Vector2& operator/=(const Vector2& v) { X /= v.X; Y /= v.Y; return *this; }
  inline Vector2& operator/=(const int& scalar) { X /= scalar; Y /= scalar; return *this; }
  inline Vector2& operator/=(const float& scalar) { X /= scalar; Y /= scalar; return *this; }
  inline Vector2 operator+(const Vector2& other) const { Vector2 result = *this; result += other; return result; }
  inline Vector2 operator-(const Vector2& other) const { Vector2 result = *this; result -= other; return result; }
  inline Vector2 operator*(const Vector2& other) const { Vector2 result = *this; result *= other; return result; }
  inline Vector2 operator/(const Vector2& other) const { Vector2 result = *this; result /= other; return result; }
  inline Vector2 operator*(const float scalar) const { return Vector2(X * scalar, Y * scalar); }
  inline Vector2 operator*(const int scalar) const { return Vector2(X * scalar, Y * scalar); }
  inline Vector2 operator/(const float scalar) const { return Vector2(X / scalar, Y / scalar); }
  inline Vector2 operator/(const int scalar) const { return Vector2(X / scalar, Y / scalar); }

  inline float length() {
    float result = sqrt(X*X + Y*Y);
    return result;
  }

  inline Vector2 normalize() {
    float magnitude = length();
    Vector2 result = *this;
    result /= magnitude;
    return result;
  }
};

struct Vector2i {
  Vector2i() : X(0), Y(0) {}
  Vector2i(const int& x, const int& y) : X(x), Y(y) {}
  Vector2i(const float& x, const float& y) : X((int)x), Y((int)y) {}

  int X;
  int Y;

  inline Vector2i& operator+=(const Vector2i& v) { X += v.X; Y += v.Y; return *this; }
  inline Vector2i& operator-=(const Vector2i& v) { X -= v.X; Y -= v.Y; return *this; }
  inline Vector2i& operator*=(const Vector2i& v) { X *= v.X; Y *= v.Y; return *this; }
  inline Vector2i& operator*=(const int& scalar) { X *= scalar; Y *= scalar; return *this; }
  inline Vector2i& operator*=(const float& scalar) { X *= scalar; Y *= scalar; return *this; }
  inline Vector2i& operator/=(const Vector2i& v) { X /= v.X; Y /= v.Y; return *this; }
  inline Vector2i& operator/=(const int& scalar) { X /= scalar; Y /= scalar; return *this; }
  inline Vector2i& operator/=(const float& scalar) { X /= scalar; Y /= scalar; return *this; }
  inline Vector2i operator+(const Vector2i& other) const { Vector2i result = *this; result += other; return result; }
  inline Vector2i operator-(const Vector2i& other) const { Vector2i result = *this; result -= other; return result; }
  inline Vector2i operator*(const Vector2i& other) const { Vector2i result = *this; result *= other; return result; }
  inline Vector2i operator/(const Vector2i& other) const { Vector2i result = *this; result /= other; return result; }
  inline Vector2i operator*(const float scalar) const { return Vector2i(X * scalar, Y * scalar); }
  inline Vector2i operator*(const int scalar) const { return Vector2i(X * scalar, Y * scalar); }
  inline Vector2i operator/(const float scalar) const { return Vector2i(X / scalar, Y / scalar); }
  inline Vector2i operator/(const int scalar) const { return Vector2i(X / scalar, Y / scalar); }
};

struct Dimension
{
  float Width;
  float Height;
};

struct Vector3 {
  Vector3() : X(0.0f), Y(0.0f), Z(0.0f) {}
  Vector3(const int& x, const int& y, const int& z) : X((float)x), Y((float)y), Z((float)z) {}
  Vector3(const float& x, const float& y, const float& z) : X(x), Y(y), Z(z) {}
  union {
    struct {
      float X;
      float Y;
      float Z;
    };
    struct {
      float Red;
      float Green;
      float Blue;
    };
  };

  inline Vector3& operator+=(const Vector3& v) { X += v.X; Y += v.Y; Z += v.Z; return *this; }
  inline Vector3& operator-=(const Vector3& v) { X -= v.X; Y -= v.Y; Z -= v.Z; return *this; }
  inline Vector3& operator*=(const Vector3& v) { X *= v.X; Y *= v.Y; Z *= v.Z; return *this; }
  inline Vector3& operator*=(const int& scalar) { X *= scalar; Y *= scalar; Z *= scalar; return *this; }
  inline Vector3& operator*=(const float& scalar) { X *= scalar; Y *= scalar; return *this; }
  inline Vector3& operator/=(const Vector3& v) { X /= v.X; Y /= v.Y; Z /= v.Z; return *this; }
  inline Vector3& operator/=(const int& scalar) { X /= scalar; Y /= scalar; Z /= scalar; return *this; }
  inline Vector3& operator/=(const float& scalar) { X /= scalar; Y /= scalar; Z /= scalar; return *this; }
  inline Vector3 operator+(const Vector3& other) const { Vector3 result = *this; result += other; return result; }
  inline Vector3 operator-(const Vector3& other) const { Vector3 result = *this; result -= other; return result; }
  inline Vector3 operator*(const Vector3& other) const { Vector3 result = *this; result *= other; return result; }
  inline Vector3 operator/(const Vector3& other) const { Vector3 result = *this; result /= other; return result; }
  inline Vector3 operator*(const float scalar) const { return Vector3(X * scalar, Y * scalar, Z * scalar); }
  inline Vector3 operator*(const int scalar) const { return Vector3(X * scalar, Y * scalar, Z * scalar); }
  inline Vector3 operator/(const float scalar) const { return Vector3(X / scalar, Y / scalar, Z / scalar); }
  inline Vector3 operator/(const int scalar) const { return Vector3(X / scalar, Y / scalar, Z / scalar); }
};

struct Vector3i {
  Vector3i() : X(0), Y(0), Z(0) {}
  Vector3i(const int& x, const int& y, const int& z) : X(x), Y(y), Z(z) {}
  Vector3i(const float& x, const float& y, const float& z) : X((int)x), Y((int)y), Z((int)z) {}

  int X;
  int Y;
  int Z;


  inline Vector3i& operator+=(const Vector3i& v) { X += v.X; Y += v.Y; Z += v.Z; return *this; }
  inline Vector3i& operator-=(const Vector3i& v) { X -= v.X; Y -= v.Y; Z -= v.Z; return *this; }
  inline Vector3i& operator*=(const Vector3i& v) { X *= v.X; Y *= v.Y; Z *= v.Z; return *this; }
  inline Vector3i& operator*=(const int& scalar) { X *= scalar; Y *= scalar; Z *= scalar; return *this; }
  inline Vector3i& operator*=(const float& scalar) { X *= scalar; Y *= scalar; return *this; }
  inline Vector3i& operator/=(const Vector3i& v) { X /= v.X; Y /= v.Y; Z /= v.Z; return *this; }
  inline Vector3i& operator/=(const int& scalar) { X /= scalar; Y /= scalar; Z /= scalar; return *this; }
  inline Vector3i& operator/=(const float& scalar) { X /= scalar; Y /= scalar; Z /= scalar; return *this; }
  inline Vector3i operator+(const Vector3i& other) const { Vector3i result = *this; result += other; return result; }
  inline Vector3i operator-(const Vector3i& other) const { Vector3i result = *this; result -= other; return result; }
  inline Vector3i operator*(const Vector3i& other) const { Vector3i result = *this; result *= other; return result; }
  inline Vector3i operator/(const Vector3i& other) const { Vector3i result = *this; result /= other; return result; }
  inline Vector3i operator*(const float scalar) const { return Vector3i(X * scalar, Y * scalar, Z * scalar); }
  inline Vector3i operator*(const int scalar) const { return Vector3i(X * scalar, Y * scalar, Z * scalar); }
  inline Vector3i operator/(const float scalar) const { return Vector3i(X / scalar, Y / scalar, Z / scalar); }
  inline Vector3i operator/(const int scalar) const { return Vector3i(X / scalar, Y / scalar, Z / scalar); }
};

struct Vector4 {
  Vector4() : X(0.0f), Y(0.0f), Z(0.0f), W(0.0f) {}
  Vector4(const int& x, const int& y, const int& z, const int& w) : X((float)x), Y((float)y), Z((float)z), W((float)w) {}
  Vector4(const float& x, const float& y, const float& z, const float& w) : X(x), Y(y), Z(z), W(w) {}
  union {
    struct {
      float X;
      float Y;
      float Z;
      float W;
    };
    struct {
      float Red;
      float Green;
      float Blue;
      float Alpha;
    };
  };
  inline Vector4& operator+=(const Vector4& v) { X += v.X; Y += v.Y; Z += v.Z; W += v.W; return *this; }
  inline Vector4& operator-=(const Vector4& v) { X -= v.X; Y -= v.Y; Z -= v.Z; W -= v.W; return *this; }
  inline Vector4& operator*=(const Vector4& v) { X *= v.X; Y *= v.Y; Z *= v.Z; W *= v.W; return *this; }
  inline Vector4& operator*=(const int& scalar) { X *= scalar; Y *= scalar; Z *= scalar; W *= scalar; return *this; }
  inline Vector4& operator*=(const float& scalar) { X *= scalar; Y *= scalar; Z *= scalar; W *= scalar; return *this; }
  inline Vector4& operator/=(const Vector4& v) { X /= v.X; Y /= v.Y; Z /= v.Z; W /= v.W; return *this; }
  inline Vector4& operator/=(const int& scalar) { X /= scalar; Y /= scalar; Z /= scalar; W /= scalar; return *this; }
  inline Vector4& operator/=(const float& scalar) { X /= scalar; Y /= scalar; Z /= scalar; W /= scalar; return *this; }
  inline Vector4 operator+(const Vector4& other) const { Vector4 result = *this; result += other; return result; }
  inline Vector4 operator-(const Vector4& other) const { Vector4 result = *this; result -= other; return result; }
  inline Vector4 operator*(const Vector4& other) const { Vector4 result = *this; result *= other; return result; }
  inline Vector4 operator/(const Vector4& other) const { Vector4 result = *this; result /= other; return result; }
  inline Vector4 operator*(const float scalar) const { return Vector4(X * scalar, Y * scalar, Z * scalar, W * scalar); }
  inline Vector4 operator*(const int scalar) const { return Vector4(X * scalar, Y * scalar, Z * scalar, W * scalar); }
  inline Vector4 operator/(const float scalar) const { return Vector4(X / scalar, Y / scalar, Z / scalar, W / scalar); }
  inline Vector4 operator/(const int scalar) const { return Vector4(X / scalar, Y / scalar, Z / scalar, W / scalar); }
};

using Quaternion = Vector4;
using Color = Vector4;