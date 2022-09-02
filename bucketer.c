#include <stdio.h>
#include <assert.h>

struct CountsByUsage {
  int lowCount;
  int mediumCount;
  int highCount;
};

struct CountsByUsage countBatteriesByUsage(const int* cycles, int nBatteries) {
  struct CountsByUsage counts = {0, 0, 0};
  for(int i=0;i<nBatteries;i++){
      if(cycles[i]<400){
         counts.lowCount++;
      }
      else if(cycles[i]>400&&cycles[i]<919){
         counts.mediumCount++;
      }
      else {
         counts.highCount++;
      }
  }
  return counts;
}

void testBucketingByNumberOfCycles() {
  const int chargeCycleCounts[] = {100, 300, 500, 600, 900, 1000};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 2);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 1);
  printf("Done counting :)\n");
}
void testBucketingByNumberOfCycles2(){
  const int chargeCycleCounts[] = {100, 300, 350,390};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 4);
  assert(counts.mediumCount == 0);
  assert(counts.highCount == 0);
  printf("Done counting :)\n");
}
void testBucketingByNumberOfCycles3(){
  const int chargeCycleCounts[] = {919,920,1001};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 0);
  assert(counts.mediumCount == 0);
  assert(counts.highCount == 3);
  printf("Done counting :)\n");
}
void testBucketingByNumberOfCycles4(){
  const int chargeCycleCounts[] = {401,600,918};
  const int numberOfBatteries = sizeof(chargeCycleCounts) / sizeof(chargeCycleCounts[0]);
  printf("Counting batteries by usage cycles...\n");
  struct CountsByUsage counts = countBatteriesByUsage(chargeCycleCounts, numberOfBatteries);
  assert(counts.lowCount == 0);
  assert(counts.mediumCount == 3);
  assert(counts.highCount == 0);
  printf("Done counting :)\n");
}


int main() {
  testBucketingByNumberOfCycles();
  testBucketingByNumberOfCycles2();
  testBucketingByNumberOfCycles3();
  return 0;
}
