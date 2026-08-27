
int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {

    int res = 0;


    for (int i = 0; i < boxTypesSize - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < boxTypesSize; j++) {
            if (boxTypes[j][1] > boxTypes[maxIndex][1]) {
                maxIndex = j;
            }
        }

      
        int* temp = boxTypes[i];
        boxTypes[i] = boxTypes[maxIndex];
        boxTypes[maxIndex] = temp;
    }


    for (int i = 0; i < boxTypesSize; i++) {

        int boxesToTake;

        if (boxTypes[i][0] < truckSize)
            boxesToTake = boxTypes[i][0];
        else
            boxesToTake = truckSize;

        truckSize -= boxesToTake;

        res += boxesToTake * boxTypes[i][1];

        if (truckSize == 0)
            break;
    }

    return res;
}