struct Date {
  int year;
  int month;
  int day;
};
void next_day(struct Date day);
void previous_day(struct Date day);
int equal(struct Date one, struct Date day);
void show(struct Date day) {
  printf();
}
int main() {
  struct Date today = {2018,3,20};
  struct Date day = {2018,3,20};
  show(day);
  for(int i=0;i<30;i++)
    next_day(day);
  show(day);
  for(int i=0;i<30;i++)
    previous_day(day);
  show(day);
  if(equal(today, day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
