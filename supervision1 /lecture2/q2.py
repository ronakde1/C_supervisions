
def merge(combarr, start, middle):

    pos = start

    leftidx = 0
    rightidx = middle
    end = start + (middle - start) * 2
    copy1 = combarr[start:middle]

    while pos < end and leftidx < middle - start and rightidx < end:
        if copy1[leftidx] < combarr[rightidx]:
            combarr[pos] = copy1[leftidx]
            leftidx += 1
        else:
            combarr[pos] = combarr[rightidx]
            rightidx += 1
        pos += 1

    while leftidx < middle - start:
        combarr[pos] = copy1[leftidx]
        leftidx += 1
        pos += 1



def mergesort(arr, start=0, end=None):
    if end is None:
        end = len(arr)
    if end - start <= 1:
        return
    middle = (start + end) // 2
    mergesort(arr, start, middle)
    mergesort(arr, middle, end)
    merge(arr, start, middle)


# test
merge([1,3,5,7,2,4,6,8],0,4)

