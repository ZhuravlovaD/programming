import builtins


def create(howMany, startingEl, stepIn):
    massive = [startingEl]
    for i in range(1, howMany):
        massive.append(massive[i - 1] + stepIn)
    sort(massive)
    return massive


def sort(massive):
    for i in range(1, len(massive)):
        temp = massive[i]
        j = i - 1
        while (j >= 0 and temp < massive[j]):
            massive[j + 1] = massive[j]
            j = j - 1
        massive[j + 1] = temp


def print(massive):
    builtins.print(massive)


howMany = int(input("Введите колличество элементов массива: "))
startingEl = int(input("Введите начальный элемент массива: "))
stepIn = int(input("Введите шаг прогрессии: "))

print(create(howMany, startingEl, stepIn))
