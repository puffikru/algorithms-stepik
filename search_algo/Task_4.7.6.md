$X = 42$ `- всего деревьев`

$A = 2$ `- Кол-во деревьев в день 1`

$K = 4$ `- Интервал отдыха 1`

$B = 3$ `- Кол-во деревьев в день 2`

$M = 3$ `- Интервал отдыха 2`

$T = 11$ `- Время затраченное на вырубку всех деревьев`


$Holliday_1 = T / K$ `11 / 4 = 2`

$Holliday_2 = T / M$ `11 / 3 = 3`

$Workdays_1 = T - Holliday_1$ `11 - 2 = 9`

$Workdays_2 = T - Holliday_2$ `11 - 3 = 8`

```(cpp)
if (T >= K * M) {
	BothHolliday = T % (K * M);
	T--;
}
```

$WorkerHalfCount_1 = Holliday_2$ `3`

$WorkerHalfCount_2 = Holliday_1$ `2`

$CommonDays_1 = Workdays_1 - WorkerHalfCount_1$ `9 - 3 = 6`

$CommonDays_2 = Workdays_2 - WorkerHalfCount_2$ `8 - 2 = 6`

$CommonDays_1 == CommonDays_2$ `true`

$CommonTrees = (A + B) * CommonDays_1$ `(2 + 3) * 6 = 30`

$WorkerHalfTrees_1 = WorkerHalfCount_1 * A$ `3 * 2 = 6`

$WorkerHalfTrees_2 = WorkerHalfCount_2 * B$ `2 * 3 = 6`

$TotalTrees = CommonTrees + WorkerHalfTrees_1 + WorkerHalfTrees_2$ `30 + 6 + 6 = 42`

$TotalTrees == X$ `true`

