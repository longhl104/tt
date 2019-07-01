int pnpoly(int nvert, float *vertx, float *verty, float testx, float testy)
{
  int i, j, c = 0;
  for (i = 0, j = nvert-1; i < nvert; j = i++) {
    if ( ((verty[i]>testy) != (verty[j]>testy)) &&
     (testx < (vertx[j]-vertx[i]) * (testy-verty[i]) / (verty[j]-verty[i]) + vertx[i]) )
       c = !c;
  }
  return c;
}

Danh sách tham số: nvert số đỉnh của đa giác. vertx - mảng chứa tọa độ x của các đỉnh trong đa giác.
verty tương tự như vertx nhưng là tọa độ y. testx tọa độ x điểm cần kiểm tra. testy tọa độ y điểm cần kiểm tra
Giá trị trả về là kiểu int. 0 là điểm đó nằm ở ngoài, 1 là điểm đó ở trong đa giác
