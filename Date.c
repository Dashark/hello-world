struct Date {
  int year;
  int month;
  int day;
};
int month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int month2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
void next_day(struct Date day);
void previous_day(struct Date day);
int equal(struct Date one, struct Date day);
bool 
void show(struct Date day) {
  printf();
}
void next_day(struct Date day){
  if(isrunyue){
  }
  if(day.day+1>)
}
void previous_day(struct Date day){
  day.
}
int equal(struct Date one, struct Date day){
  if()
}
void show(struct Date day) {
  printf("%d %d %d\n",day.year,day.month,day.day);
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
