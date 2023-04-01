#include "Integral.h"

Integral::Integral(std::function<float(float)> _fun)
{
	fun = _fun;
}

pair Integral::rectangle_method(float start, float end, float eps, char type)
{
	if (start > end) {
		throw "Incorrect interval";
	}

    int n = 1;
    float step1 = 0;
    float step2 = 0;

    float dltX = 0;


    float ans = 0;
    float new_ans = 0;

    while (dltX > eps || n == 1) {
        step1 = (end - start) / n;
        step2 = (end - start) / (2 * n);
        float fst_step;
        ans = 0;
        new_ans = 0;
        switch (type) {
        case 'l':
            fst_step = start + 0 * step1;
            break;
        case 'r':
            fst_step = start + 1 * step1;
            break;
        default:
            fst_step = start + 0.5 * step1;
            break;
        }

        for (int i = 0; i < n; i++)
            ans += fun(fst_step + i * step1);

        for (int i = 0; i < (2 * n); i++)
            new_ans += fun(fst_step + i * step2);
        n++;
        dltX = fabs(step2 * new_ans - step1 * ans);
    }
    return { step1 * ans, n };
}

pair Integral::trapetion_method(float start, float end, float eps)
{
    if (start > end) {
        throw "Incorrect interval";
    }

    int n = 1;
    float step1 = 0;
    float step2 = 0;

    float dltX = 0;


    float ans = 0;
    float new_ans = 0;

    while (dltX > eps || n == 1) {
        step1 = (end - start) / n;
        step2 = (end - start) / (2 * n);
        float fst_step = start;
        ans = 0;
        new_ans = 0;

        for (int i = 0; i < n - 1; i++)
            ans += (fun(fst_step + i * step1) + fun(fst_step + (i + 1) * step1)) / 2;

        for (int i = 0; i < (2 * n); i++)
            new_ans += (fun(fst_step + i * step2) + fun(fst_step + (i + 1) * step2)) / 2;
        n++;
        dltX = fabs(step2 * new_ans - step1 * ans);
    }
    return { step1 * ans, n };
}

pair Integral::simpson_method(float start, float end, float eps)
{
    int n = 1;
    float dx = 0;
    float ans = 0;
    float new_ans = 0;
    float dltX = 0;
    float d2x = 0;

    while (dltX > eps || n == 1) {
        ans = new_ans = 0;
        dx = (end - start) / n;
        d2x = (end - start) / (2 * n);
        for (int i = 0; i < n; i++) {
            float x1 = start + i * dx;
            float x2 = start + (i + 1) * dx;
            ans += ((x2 - x1) / 6.0) * (fun(x1) + 4.0 * fun(0.5 * (x1 + x2)) + fun(x2));
        }
        for (int i = 0; i < 2 * n; i++) {
            float x1 = start + i * d2x;
            float x2 = start + (i + 1) * d2x;
            new_ans += ((x2 - x1) / 6.0) * (fun(x1) + 4.0 * fun(0.5 * (x1 + x2)) + fun(x2));
        }
        n++;
        dltX = fabs(new_ans - ans);
    }

    return { ans, n };
}
