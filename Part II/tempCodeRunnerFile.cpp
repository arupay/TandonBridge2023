  int userInputArr[SIZE], currInt;
  cout << "Please enter 6 integers separated by a space: " << endl;
  for (int index = 0; index < SIZE; index++) {
    cin >> currInt;
    userInputArr[index] = currInt;
  }
  oddKeepsEvensFlip(userInputArr, SIZE);
  printArr(userInputArr, SIZE);