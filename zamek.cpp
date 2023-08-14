#include <iostream>

using namespace std;

int calculateStartPoint(int question, int last){
    if (question == 1) return last;
    else return (question - 2);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    float knightSpeed = 10;
    float monsterSpeed = 20;
    int chamberNumber;
    int questionsNumber;
    cin >> chamberNumber;
    cin >> questionsNumber;
    int chambersLengthPrefixSum[chamberNumber + 1];
    int lastElementIndex = chamberNumber;
    chambersLengthPrefixSum[lastElementIndex] = 0;
    cin >> chambersLengthPrefixSum[0];
    for (int i = 1; i < chamberNumber; i++)
    {
        cin >> chambersLengthPrefixSum[i];
        chambersLengthPrefixSum[i] += chambersLengthPrefixSum[i - 1];
    }
    int question[2];
    float knightDistance, monsterDistance;
    int lastElement = chambersLengthPrefixSum[chamberNumber - 1];
    for (int i = 0; i < questionsNumber; i++)
    {
        cin >> question[0];
        cin >> question[1];
        if (question[0] >= question[1]){
            cout << "NIE\n";
            continue;
        }
        monsterDistance = lastElement - chambersLengthPrefixSum[calculateStartPoint(question[0], lastElementIndex)];
        knightDistance = lastElement - chambersLengthPrefixSum[calculateStartPoint(question[1], lastElementIndex)];
        if (knightDistance / knightSpeed > monsterDistance / monsterSpeed) cout << "NIE\n";
        else cout << "TAK\n";
    }
    return 1;
}