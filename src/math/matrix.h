/**
 * @brief Basic matrix template.
 * 
 * @tparam R Number of rows.
 * @tparam C Number of columns.
 */
template <int R, int C>
struct Matrix {
    float mat[R][C] = {};

    Matrix() = default;
    constexpr Matrix(const float (&list)[R][C]);

    /**
     * @brief Print matrix to stdout.
     */
    void print() const;

    template <int _R, int _C>
    Matrix<R, _C> operator*(const Matrix<_R, _C>& o) const;
};

template <int R, int C>
inline constexpr Matrix<R, C>::Matrix(const float (&list)[R][C]) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            mat[i][j] = list[i][j];
        }
    }
}

template <int R, int C>
inline void Matrix<R, C>::print() const {
    for (int r = 0; r < R; r++) {
        printf("{ ");
        for (int c = 0; c < C; c++) {
            printf("%f ", mat[r][c]);
        }
        printf("}\n");
    }
}

template <int R, int C>
template <int _R, int _C>
inline Matrix<R, _C> Matrix<R, C>::operator*(const Matrix<_R, _C>& o) const {
    static_assert(C == _R);

    Matrix<R, _C> result = {};

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < _C; ++j) {
            for (int k = 0; k < _R; ++k) {
                result.mat[i][j] += this->mat[i][k] * o.mat[k][j];
            }
        }
    }

    return result;
}
