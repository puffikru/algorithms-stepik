#Task 4.7.5

$N = 40$
$x = 2s$
$y = 3s$

$P_1 = 1$
$Time_1 = 1 \cdot min = 2$

$Nok = 6$

$PagesCount_max = Nok / x = 3$
$PagesCount_min = Nok / y = 2$

$MainPartPages = (N - P_1) / (PagesCount_x + PagesCount_y) = 7$

$MainPartTime = MainPartPages \cdot nok = 42$

$LastPartPages = (N - P_1) % (PagesCount_x + PagesCount_y) = 4$

$Last_1 = LastPartPages \cdot x = 8$

$Last_2 = LastPartPages \cdot y = 12$

Если $Last_2 \cdot x > Last_1 \cdot y$
$LastTime = Last_2 \cdot x = 6$

Если $Last_2 \cdot x < Last_1 \cdot y$
$LastTime = Last_1 \cdot y = 6$

$TotalTime = Time_1 + MainPartTime + LastTime = 2 + 42 + 6 = 50$
